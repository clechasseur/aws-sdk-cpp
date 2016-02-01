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
#include <aws/cognito-sync-manager/DefaultDataSetUpdatedListener.h>
#include <aws/core/utils/Outcome.h>
#include <aws/cognito-sync/model/ListRecordsRequest.h>
#include <aws/core/utils/logging/LogMacros.h>

using namespace Aws::CognitoSyncManager;
using namespace Aws::CognitoSync;
using namespace Aws::CognitoSync::Model;

static const int64_t ONE_MINUTE= 60000;
static const char* LOG_TAG = "DefaultDataSetUpdatedListener";

DefaultDataSetUpdatedListener::DefaultDataSetUpdatedListener(const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& client, const Aws::String& identityPoolId,
                             const Aws::String& identityId, const Aws::String& dataSetName) :
        DataSetUpdatedListener(client, identityPoolId, identityId, dataSetName),
        m_continue(false),
        m_syncCount(0),
        m_pollFrequency(ONE_MINUTE)
{
}

void DefaultDataSetUpdatedListener::Subscribe()
{
    AWS_LOGSTREAM_INFO(LOG_TAG, "Subscribing to dataset " << m_dataSetName << " for identity " << m_identityId << " on identity pool " << m_identityPoolId);
    m_continue = true;
    ListRecordsRequest listRecordsRequest;
    listRecordsRequest.WithDatasetName(m_dataSetName)
            .WithIdentityId(m_identityId)
            .WithIdentityPoolId(m_identityPoolId)
            .WithLastSyncCount(m_syncCount);

    m_client->ListRecordsAsync(listRecordsRequest, std::bind(&DefaultDataSetUpdatedListener::OnListRecordsCompleted, this,
                                                std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void DefaultDataSetUpdatedListener::UnSubscribe()
{
    m_continue = false;
    AWS_LOGSTREAM_INFO(LOG_TAG, "Unsubscribing from dataSet " << m_dataSetName << " for identity " << m_identityId << " on identity pool " << m_identityPoolId);
};


void DefaultDataSetUpdatedListener::OnListRecordsCompleted(const Aws::CognitoSync::CognitoSyncClient*, const Aws::CognitoSync::Model::ListRecordsRequest& request,
                            const Aws::CognitoSync::Model::ListRecordsOutcome& outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&)
{
    if(m_continue)
    {
        AWS_LOGSTREAM_TRACE(LOG_TAG, "Received ListRecords result.");
        if(outcome.IsSuccess())
        {
            AWS_LOGSTREAM_TRACE(LOG_TAG, "Received ListRecords result. Operation was successful.");
            auto& result = outcome.GetResult();
            auto syncCount = result.GetDatasetSyncCount();

            if(syncCount > m_syncCount)
            {
                AWS_LOGSTREAM_INFO(LOG_TAG, "Found updated record with new sync count " << syncCount << " Old sync count was " << m_syncCount);
                m_syncCount = syncCount;
                SyncUpdate syncUpdate;
                syncUpdate.SetDataSetName(m_dataSetName);
                syncUpdate.SetIdentityId(m_identityId);
                syncUpdate.SetIdentityPoolId(m_identityPoolId);
                syncUpdate.SetSource("CognitoSync");
                syncUpdate.SetSyncCount(result.GetDatasetSyncCount());

                if(m_callback)
                {
                    AWS_LOGSTREAM_DEBUG(LOG_TAG, "Invoking callback to notify of changes.");
                    m_callback(syncUpdate);
                }
            }
        }
        else
        {
            AWS_LOGSTREAM_ERROR(LOG_TAG, "ListRecords call failed with error " << outcome.GetError().GetExceptionName() << " message: " << outcome.GetError().GetMessage());
        }

        if(m_continue)
        {
            AWS_LOGSTREAM_TRACE(LOG_TAG, "Sleeping for " << m_pollFrequency);
            std::this_thread::sleep_for(std::chrono::milliseconds(m_pollFrequency));

            if(m_continue)
            {
                ListRecordsRequest listRecordsRequest;
                listRecordsRequest.WithDatasetName(m_dataSetName)
                                  .WithIdentityId(m_identityId)
                                  .WithIdentityPoolId(m_identityPoolId)
                                  .WithLastSyncCount(m_syncCount);

                AWS_LOGSTREAM_TRACE(LOG_TAG, "Calling ListRecords again ");

                m_client->ListRecordsAsync(request, std::bind(&DefaultDataSetUpdatedListener::OnListRecordsCompleted, this,
                                                            std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
            }
        }
    }
}