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

#include <aws/cognito-sync-manager/DataSetRecordsRepository.h>
#include <mutex>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSMap.h>

namespace Aws
{
    namespace Utils
    {
        namespace Json
        {
            class JsonValue;
        }
    }
    namespace CognitoSyncManager
    {
        class DefaultDataSetRecordsRepository : public DataSetRecordsRepository
        {
        public:
            DefaultDataSetRecordsRepository(const char* dataSetName, const char* identityPoolId, const char* identityId);
            DefaultDataSetRecordsRepository(const char* dataSetName, const char* identityPoolId, const char* identityId, const char* syncFilePath);

            const Aws::Vector<Aws::CognitoSync::Model::Record>& GetAllRecords() const override;
            bool RecordExitsByKey(const char* key) const override;
            void PutRecord(const Aws::CognitoSync::Model::Record&) override;
            void PutAllRecords(const Aws::Vector<Aws::CognitoSync::Model::Record>&) override;
            const Aws::CognitoSync::Model::Record& GetRecord(const char* key) const override;
            void DeleteRecord(const char* key) override;
            int64_t GetSyncCount() const override;
            void SetSyncCount(int64_t syncCount) override;

        private:
            Utils::Json::JsonValue LoadJsonDocFromFile() const;
            void PersistChangesToFile(const Utils::Json::JsonValue&) const;
            void LoadAndParseDoc();
            void CopyStateToDoc();

            std::mutex m_fileLock;
            Aws::String m_filePath;
            Aws::UnorderedMap<Aws::String, Aws::CognitoSync::Model::Record> m_records;
            Aws::Vector<Aws::CognitoSync::Model::Record> m_recordsList;
        };
    }

}
