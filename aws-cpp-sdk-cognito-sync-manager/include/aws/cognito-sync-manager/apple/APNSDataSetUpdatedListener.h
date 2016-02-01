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

#ifdef __OBJC__
@class AppDelegate;
#else
class AppDelegate;
#endif

namespace Aws
{
    namespace CognitoSync
    {
        class CognitoSyncClient;
    }

    namespace CognitoSyncManager
    {
        class APNSDataSetUpdatedListener : public DataSetUpdatedListener
        {
        public:
            APNSDataSetUpdatedListener(const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& client,
                                       const Aws::String identityPoolId, const Aws::String& identityId, const Aws::String& dataSetName);
            ~APNSDataSetUpdatedListener();
            void Subscribe() override;
            void UnSubscribe() override;

        private:
            AppDelegate* m_delegate;
        };
    }
}