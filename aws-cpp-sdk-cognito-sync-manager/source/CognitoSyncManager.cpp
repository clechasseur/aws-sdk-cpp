/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/cognito-sync-manager/CognitoSyncManager.h>
#include <aws/identity-management/auth/PersistentCognitoIdentityProvider.h>
#include <aws/identity-management/auth/CognitoCachingCredentialsProvider.h>
#include <aws/cognito-sync-manager/DataSetRecordsRepository.h>
#include <aws/cognito-sync-manager/DataSetUpdatedListener.h>
#include <aws/cognito-sync/model/ListRecordsRequest.h>
#include <aws/cognito-sync/CognitoSyncClient.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/memory/stl/AWSSet.h>
#include <aws/cognito-sync/model/RecordPatch.h>
#include <aws/cognito-sync/model/UpdateRecordsRequest.h>
#include <aws/cognito-sync-manager/DefaultDataSetRecordsRepository.h>
#include <aws/cognito-sync-manager/DefaultDataSetUpdatedListener.h>

using namespace Aws::CognitoSyncManager;
using namespace Aws::CognitoSync;
using namespace Aws::CognitoSync::Model;
using namespace Aws::CognitoIdentity;
using namespace Aws::Auth;
using namespace Aws::Client;

static const char* CLASS_TAG = "CognitoSyncManager";

CognitoSyncManager::CognitoSyncManager(const char* dataSetName, const char* identityPoolId, const char* accountId,
                   const ClientConfiguration& clientConfiguration,
                   const std::shared_ptr<DataSetRecordsRepository>& repository,
                   const std::shared_ptr<DataSetUpdatedListener>& listener)
{
    m_identityRepository = Aws::MakeShared<DefaultPersistentCognitoIdentityProvider>(CLASS_TAG, identityPoolId, accountId);
    auto cognitoClient = Aws::MakeShared<CognitoIdentityClient>(CLASS_TAG, AWSCredentials("", ""), clientConfiguration);
    auto credentialsProvider = Aws::MakeShared<CognitoCachingAuthenticatedCredentialsProvider>(CLASS_TAG, m_identityRepository, cognitoClient);
    m_syncClient = Aws::MakeShared<CognitoSyncClient>(CLASS_TAG, credentialsProvider, clientConfiguration);
    InitRepoAndListener(identityPoolId, dataSetName, repository, listener);
    m_listener->RegisterDataSetUpdatedCallback(std::bind(&CognitoSyncManager::OnSyncUpdate, this, std::placeholders::_1));
    m_listener->Subscribe();
}

CognitoSyncManager::CognitoSyncManager(const char* dataSetName, const std::shared_ptr<Aws::Auth::CognitoCachingCredentialsProvider>& credsProvider,
                   const Aws::Client::ClientConfiguration& clientConfiguration,
                   const std::shared_ptr<DataSetRecordsRepository>& repository,
                   const std::shared_ptr<DataSetUpdatedListener>& listener)
{
    m_identityRepository = credsProvider->GetIdentityProvider();
    m_syncClient = Aws::MakeShared<CognitoSyncClient>(CLASS_TAG, credsProvider, clientConfiguration);
    InitRepoAndListener(m_identityRepository->GetIdentityPoolId().c_str(), dataSetName, repository, listener);
    m_listener->RegisterDataSetUpdatedCallback(std::bind(&CognitoSyncManager::OnSyncUpdate, this, std::placeholders::_1));
    m_listener->Subscribe();
}

CognitoSyncManager::CognitoSyncManager(const char* dataSetName, const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& syncClient,
                   const std::shared_ptr<Aws::Auth::CognitoCachingCredentialsProvider>& credsProvider,
                   const std::shared_ptr<DataSetRecordsRepository>& repository,
                   const std::shared_ptr<DataSetUpdatedListener>& listener)
{
    m_identityRepository = credsProvider->GetIdentityProvider();
    m_syncClient = syncClient;
    InitRepoAndListener(m_identityRepository->GetIdentityPoolId().c_str(), dataSetName, repository, listener);
    m_listener->RegisterDataSetUpdatedCallback(std::bind(&CognitoSyncManager::OnSyncUpdate, this, std::placeholders::_1));
    m_listener->Subscribe();
}

void CognitoSyncManager::InitRepoAndListener(const char* identityPoolId, const char* dataSetName,
                                        const std::shared_ptr<DataSetRecordsRepository>& repository,
                                        const std::shared_ptr<DataSetUpdatedListener>& listener)
{
    if(repository)
    {
        m_recordsRepo = repository;
    }
    else
    {
        m_recordsRepo = Aws::MakeShared<DefaultDataSetRecordsRepository>(CLASS_TAG, dataSetName, identityPoolId, m_identityRepository->GetIdentityId().c_str());
    }

    if(listener)
    {
        m_listener = listener;
    }
    else
    {
        m_listener = Aws::MakeShared<DefaultDataSetUpdatedListener>(CLASS_TAG, m_syncClient, identityPoolId, m_identityRepository->GetIdentityId().c_str(), dataSetName);
    }
}

CognitoSyncManager::~CognitoSyncManager()
{
    m_listener->UnSubscribe();
}

const Aws::Vector<Aws::CognitoSync::Model::Record>& CognitoSyncManager::GetRecords() const
{
    return m_recordsRepo->GetAllRecords();
}

void CognitoSyncManager::PutRecord(const char* key, const char* value)
{
    InitSyncSessionToken();

    RecordPatch recordPatch;
    recordPatch.WithKey(key)
               .WithValue(value)
               .WithOp(Operation::replace);

    if(!m_recordsRepo->RecordExitsByKey(key))
    {
        recordPatch.WithSyncCount(0);
    }
    else
    {
        auto& existingRecord = m_recordsRepo->GetRecord(key);
        recordPatch.WithSyncCount(existingRecord.GetSyncCount());
    }

    UpdateRecordsRequest updateRecordsRequest;
    updateRecordsRequest.WithDatasetName(m_recordsRepo->GetDataSetName())
                        .WithIdentityPoolId(m_identityRepository->GetIdentityPoolId())
                        .WithIdentityId(m_identityRepository->GetIdentityId())
                        .WithSyncSessionToken(m_syncSessionToken)
                        .AddRecordPatches(std::move(recordPatch));

    auto updateRecordsOutcome = m_syncClient->UpdateRecords(updateRecordsRequest);
    if (updateRecordsOutcome.IsSuccess())
    {
        Record record;
        record.WithKey(key).WithValue(value).WithSyncCount(updateRecordsOutcome.GetResult().GetRecords()[0].GetSyncCount());

        m_recordsRepo->PutRecord(record);
    }
    else
    {

    }
}

const Aws::String& CognitoSyncManager::GetRecord(const char* key)
{
    return m_recordsRepo->GetRecord(key).GetValue();
}

void CognitoSyncManager::DeleteRecord(const char* key)
{
    InitSyncSessionToken();

    if(m_recordsRepo->RecordExitsByKey(key))
    {
        auto& existingRecord = m_recordsRepo->GetRecord(key);

        RecordPatch recordPatch;
        recordPatch.WithKey(key)
                   .WithSyncCount(existingRecord.GetSyncCount())
                   .WithOp(Operation::remove);

        UpdateRecordsRequest updateRecordsRequest;
        updateRecordsRequest.WithDatasetName(m_recordsRepo->GetDataSetName())
                            .WithIdentityPoolId(m_identityRepository->GetIdentityPoolId())
                            .WithIdentityId(m_identityRepository->GetIdentityId())
                            .WithSyncSessionToken(m_syncSessionToken)
                            .AddRecordPatches(std::move(recordPatch));

        auto updateRecordsOutcome = m_syncClient->UpdateRecords(updateRecordsRequest);
        if (updateRecordsOutcome.IsSuccess())
        {
            m_recordsRepo->DeleteRecord(key);
        }

    }
}

//if we are out of sync, get the records for the dataset. Add to the repo, if it is missing, update if it has changed,
// delete if it is in the repo but not the server version.
void CognitoSyncManager::OnSyncUpdate(const SyncUpdate& update)
{
    if(m_recordsRepo->GetSyncCount() < update.GetSyncCount())
    {
        ListRecordsRequest listRecordsRequest;
        listRecordsRequest.WithDatasetName(update.GetDataSetName())
                          .WithIdentityPoolId(m_identityRepository->GetIdentityPoolId())
                          .WithIdentityId(m_identityRepository->GetIdentityId())
                          .WithLastSyncCount(m_recordsRepo->GetSyncCount());

        auto listRecordsOutcome = m_syncClient->ListRecords(listRecordsRequest);

        if(listRecordsOutcome.IsSuccess())
        {
            auto& latestRecords = listRecordsOutcome.GetResult().GetRecords();
            Aws::UnorderedSet<Aws::String> latestRecordsSet;
            for(auto& record : latestRecords)
            {
                if(!m_recordsRepo->RecordExitsByKey(record.GetKey().c_str()))
                {
                    m_recordsRepo->PutRecord(record);
                    if(m_onRecordAdded)
                    {
                        m_onRecordAdded(this, update.GetDataSetName(), record);
                    }
                    continue;
                }
                else if(m_recordsRepo->GetRecord(record.GetKey().c_str()).GetValue() != record.GetValue())
                {
                    m_recordsRepo->PutRecord(record);
                    if(m_onRecordUpdated)
                    {
                        m_onRecordUpdated(this, update.GetDataSetName(), record);
                    }
                    continue;
                }
                latestRecordsSet.insert(record.GetKey());
            }

            //we need to copy here so we don't mutate the underlying dataset.
            auto currentRecords = m_recordsRepo->GetAllRecords();
            for(auto& record : currentRecords)
            {
                //if cached record isn't in latestRecords pulled, remove it.
                if (latestRecordsSet.find(record.GetKey()) == latestRecordsSet.end())
                {
                    m_recordsRepo->DeleteRecord(record.GetKey().c_str());
                    if (m_onRecordDeleted)
                    {
                        m_onRecordDeleted(this, update.GetDataSetName(), record);
                    }
                }
            }
        }

    }

}

void CognitoSyncManager::InitSyncSessionToken()
{
    if(m_syncSessionToken.empty())
    {
        ListRecordsRequest request;
        request.WithIdentityPoolId(m_identityRepository->GetIdentityPoolId())
                    .WithIdentityId(m_identityRepository->GetIdentityId())
                    .WithDatasetName(m_recordsRepo->GetDataSetName());

        auto listRecordsOutcome = m_syncClient->ListRecords(request);
        if(listRecordsOutcome.IsSuccess())
        {
            auto& result = listRecordsOutcome.GetResult();
            m_syncSessionToken = result.GetSyncSessionToken();
        }
    }
}
