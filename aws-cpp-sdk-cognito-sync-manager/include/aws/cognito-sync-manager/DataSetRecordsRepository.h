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

#include <aws/cognito-sync/model/Record.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

namespace Aws
{
    namespace CognitoSyncManager
    {
        class DataSetRecordsRepository
        {
        public:
            DataSetRecordsRepository(const char* dataSetName, const char* identityPoolId, const char* identityId) :
                    m_dataSet(dataSetName),
                    m_identityPoolId(identityPoolId),
                    m_identityId(identityId),
                    m_syncCount(0)
            { }

            virtual ~DataSetRecordsRepository() = default;

            virtual const Aws::Vector<Aws::CognitoSync::Model::Record>& GetAllRecords() const = 0;
            virtual bool RecordExitsByKey(const char* key) const = 0;
            virtual void PutRecord(const Aws::CognitoSync::Model::Record&) = 0;
            virtual void PutAllRecords(const Aws::Vector<Aws::CognitoSync::Model::Record>&) = 0;
            virtual const Aws::CognitoSync::Model::Record& GetRecord(const char* key) const = 0;
            virtual void DeleteRecord(const char* key) = 0;
            virtual int64_t GetSyncCount() const = 0;
            virtual void SetSyncCount(int64_t syncCount) = 0;

            inline const Aws::String& GetDataSetName() const { return m_dataSet; }

        protected:
            Aws::String m_dataSet;
            Aws::String m_identityPoolId;
            Aws::String m_identityId;
            int64_t m_syncCount;
        };
    }
}

