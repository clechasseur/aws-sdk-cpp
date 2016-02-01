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

#include <aws/cognito-sync-manager/DataSetUpdatedListener.h>
#include <aws/cognito-sync/CognitoSyncClient.h>
#include <aws/cognito-sync-manager/CognitoSyncManager_EXPORTS.h>

namespace Aws
{
    namespace CognitoSyncManager
    {
        class AWS_COGNITO_SYNC_MGR_API DefaultDataSetUpdatedListener : public DataSetUpdatedListener
        {

        public:
            DefaultDataSetUpdatedListener(const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& client, const Aws::String& identityPoolId,
                                         const Aws::String& identityId, const Aws::String& dataSetName);

            ~DefaultDataSetUpdatedListener() { UnSubscribe(); }

            void Subscribe() override;
            void UnSubscribe() override;

        private:
            void OnListRecordsCompleted(const Aws::CognitoSync::CognitoSyncClient*, const Aws::CognitoSync::Model::ListRecordsRequest&,
                                        const Aws::CognitoSync::Model::ListRecordsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&);

            std::atomic<bool> m_continue;
            std::atomic<int64_t> m_syncCount;
            int64_t m_pollFrequency;

        };
    }
}
