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
#pragma once

#include <functional>
#include <memory>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/cognito-sync/model/Record.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/cognito-sync-manager/CognitoSyncManager_EXPORTS.h>

namespace Aws
{
    namespace CognitoSync
    {
        class CognitoSyncClient;
    }

    namespace Auth
    {
        class PersistentCognitoIdentityProvider;
        class CognitoCachingCredentialsProvider;
    }
    namespace CognitoSyncManager
    {
        class DataSetRecordsRepository;
        class DataSetUpdatedListener;
        class SyncUpdate;

        class AWS_COGNITO_SYNC_MGR_API CognitoSyncManager
        {
        public:
            CognitoSyncManager(const char* dataSetName, const char* identityPoolId, const char* accountId,
                               const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration(),
                               const std::shared_ptr<DataSetRecordsRepository>& repository = nullptr,
                               const std::shared_ptr<DataSetUpdatedListener>& listener = nullptr);

            CognitoSyncManager(const char* dataSetName, const std::shared_ptr<Aws::Auth::CognitoCachingCredentialsProvider>& credsProvider,
                               const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration(),
                               const std::shared_ptr<DataSetRecordsRepository>& repository = nullptr,
                               const std::shared_ptr<DataSetUpdatedListener>& listener = nullptr);

            CognitoSyncManager(const char* dataSetName, const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& syncClient,
                               const std::shared_ptr<Aws::Auth::CognitoCachingCredentialsProvider>& credsProvider,
                               const std::shared_ptr<DataSetRecordsRepository>& repository = nullptr,
                               const std::shared_ptr<DataSetUpdatedListener>& listener = nullptr);

            virtual ~CognitoSyncManager();

            virtual const Aws::Vector<Aws::CognitoSync::Model::Record>& GetRecords() const;
            virtual void PutRecord(const char* key, const char* value);
            virtual const Aws::String& GetRecord(const char* key);
            virtual void DeleteRecord(const char* key);

            inline void RegisterOnRecordAddedHandler(std::function<void(CognitoSyncManager* sender, const Aws::String&, const Aws::CognitoSync::Model::Record&)>&& callback)
            { m_onRecordAdded = callback; }

            inline void RegisterOnRecordUpdatedHandler(std::function<void(CognitoSyncManager* sender, const Aws::String&, const Aws::CognitoSync::Model::Record&)>&& callback)
            { m_onRecordUpdated = callback; }

            inline void RegisterOnRecordDeletedHandler(std::function<void(CognitoSyncManager* sender, const Aws::String&, const Aws::CognitoSync::Model::Record&)>&& callback)
            { m_onRecordDeleted = callback; }


        protected:
            std::function<void(CognitoSyncManager* sender, const Aws::String&, const Aws::CognitoSync::Model::Record&)> m_onRecordAdded;
            std::function<void(CognitoSyncManager* sender, const Aws::String&, const Aws::CognitoSync::Model::Record&)> m_onRecordUpdated;
            std::function<void(CognitoSyncManager* sender, const Aws::String&, const Aws::CognitoSync::Model::Record&)> m_onRecordDeleted;
            std::shared_ptr<Aws::CognitoSync::CognitoSyncClient> m_syncClient;
            std::shared_ptr<Aws::Auth::PersistentCognitoIdentityProvider> m_identityRepository;
            std::shared_ptr<DataSetRecordsRepository> m_recordsRepo;
            std::shared_ptr<DataSetUpdatedListener> m_listener;
            Aws::String m_syncSessionToken;

            virtual void OnSyncUpdate(const SyncUpdate&);
            void InitSyncSessionToken();

        private:
            void InitRepoAndListener(const char* identityPoolId, const char* dataSetName, const std::shared_ptr<DataSetRecordsRepository>& repository,
                                const std::shared_ptr<DataSetUpdatedListener>& listener);
        };
    }
}