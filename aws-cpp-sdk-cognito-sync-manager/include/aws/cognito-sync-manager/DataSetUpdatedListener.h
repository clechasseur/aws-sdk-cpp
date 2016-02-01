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

#include <aws/cognito-sync-manager/CognitoSyncManager_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <functional>

namespace Aws
{
    namespace CognitoSync
    {
        class CognitoSyncClient;
    }

    namespace CognitoSyncManager
    {
        class AWS_COGNITO_SYNC_MGR_API SyncUpdate
        {

        public:
            inline const Aws::String& GetSource() const
            {
                return m_source;
            }

            inline void SetSource(const Aws::String& source)
            {
                m_source = source;
            }

            inline const Aws::String& GetIdentityPoolId() const
            {
                return m_identityPoolId;
            }

            inline void SetIdentityPoolId(const Aws::String& identityPoolId)
            {
                m_identityPoolId = identityPoolId;
            }

            inline const Aws::String& GetIdentityId() const
            {
                return m_identityId;
            }

            inline void SetIdentityId(const Aws::String& identityId)
            {
                m_identityId = identityId;
            }

            inline const Aws::String& GetDataSetName() const
            {
                return m_dataSetName;
            }

            inline void SetDataSetName(const Aws::String& dataSetName)
            {
                m_dataSetName = dataSetName;
            }

            inline int64_t GetSyncCount() const
            {
                return m_syncCount;
            }

            inline void SetSyncCount(int64_t syncCount)
            {
                m_syncCount = syncCount;
            }

        private:
            Aws::String m_source;
            Aws::String m_identityPoolId;
            Aws::String m_identityId;
            Aws::String m_dataSetName;
            int64_t m_syncCount;
        };

        class AWS_COGNITO_SYNC_MGR_API DataSetUpdatedListener
        {
        public:
            DataSetUpdatedListener(const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& client,
                                   const Aws::String identityPoolId, const Aws::String& identityId, const Aws::String& dataSetName) :
                    m_client(client), m_identityPoolId(identityPoolId), m_identityId(identityId), m_dataSetName(dataSetName)
            {}

            virtual ~DataSetUpdatedListener() = default;
            virtual void Subscribe() = 0;
            virtual void UnSubscribe() = 0;

            void RegisterDataSetUpdatedCallback(const std::function<void(const SyncUpdate&)>& callback) { m_callback = callback; };
            const std::function<void(const SyncUpdate&)>& GetCallback() const { return m_callback; }

        protected:
            std::function<void(const SyncUpdate&)> m_callback;
            std::shared_ptr<Aws::CognitoSync::CognitoSyncClient> m_client;
            Aws::String m_identityPoolId;
            Aws::String m_identityId;
            Aws::String m_dataSetName;
        };

        class AWS_COGNITO_SYNC_MGR_API DataSetUpdatedListenerFactory
        {
        public:
            virtual std::shared_ptr<DataSetUpdatedListener> CreateInstance() const = 0;
        };
    }
}
