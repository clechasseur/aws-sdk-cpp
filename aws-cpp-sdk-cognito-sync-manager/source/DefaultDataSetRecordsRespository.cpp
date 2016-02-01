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
#include <aws/cognito-sync-manager/DefaultDataSetRecordsRepository.h>
#include <aws/core/utils/FileSystemUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/logging/LogMacros.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <fstream>


using namespace Aws::CognitoSyncManager;
using namespace Aws::CognitoSync::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

static const char* LOG_TAG = "DefaultDataSetRecordsRepository";
static const char* RECORDS = "Records";
static const char* SYNC_COUNT= "SyncCount";

DefaultDataSetRecordsRepository::DefaultDataSetRecordsRepository(const char* dataSetName, const char* identityPoolId, const char* identityId) :
        DataSetRecordsRepository(dataSetName, identityPoolId, identityId)
{
    Aws::StringStream ss;
    ss << FileSystemUtils::GetHomeDirectory() << ".aws";
    FileSystemUtils::CreateDirectoryIfNotExists(ss.str().c_str());
    ss << FileSystemUtils::GetPathDelimiter() << "sync-data.json";
    m_filePath = ss.str();

    LoadAndParseDoc();
}

DefaultDataSetRecordsRepository::DefaultDataSetRecordsRepository(const char* dataSetName, const char* identityPoolId, const char* identityId, const char* filePath) :
        DataSetRecordsRepository(dataSetName, identityPoolId, identityId), m_filePath(filePath)
{
    LoadAndParseDoc();
}

const Aws::Vector<Record>& DefaultDataSetRecordsRepository::GetAllRecords() const
{
    return m_recordsList;
}

bool DefaultDataSetRecordsRepository::RecordExitsByKey(const char* key) const
{
    return m_records.find(key) != m_records.end();
}

void DefaultDataSetRecordsRepository::PutRecord(const Record& record)
{
    std::lock_guard<std::mutex> locker(m_fileLock);
    m_records[record.GetKey()] = record;
    m_recordsList.push_back(record);
    CopyStateToDoc();
}

void DefaultDataSetRecordsRepository::PutAllRecords(const Aws::Vector<Record>& records)
{
    std::lock_guard<std::mutex> locker(m_fileLock);
    for(auto& record : records)
    {
        m_records[record.GetKey()] = record;
        m_recordsList.push_back(record);
    }

    CopyStateToDoc();
}

const Record& DefaultDataSetRecordsRepository::GetRecord(const char* key) const
{
    return m_records.find(key)->second;
}

void DefaultDataSetRecordsRepository::DeleteRecord(const char* key)
{
    std::lock_guard<std::mutex> locker(m_fileLock);
    m_records.erase(key);
    for(auto iter = m_recordsList.begin(); iter != m_recordsList.end(); ++iter)
    {
        if(iter->GetKey() == key)
        {
            m_recordsList.erase(iter);
            continue;
        }
    }
    CopyStateToDoc();
}

int64_t DefaultDataSetRecordsRepository::GetSyncCount() const
{
    return m_syncCount;
}

void DefaultDataSetRecordsRepository::SetSyncCount(int64_t syncCount)
{
    std::lock_guard<std::mutex> locker(m_fileLock);
    m_syncCount = syncCount;
    CopyStateToDoc();
}

void DefaultDataSetRecordsRepository::LoadAndParseDoc()
{
    auto jsonDoc = LoadJsonDocFromFile();

    if (jsonDoc.ValueExists(m_identityId))
    {
        auto identityNode = jsonDoc.GetObject(m_identityId);

        if(jsonDoc.ValueExists(m_dataSet))
        {
            auto dataSetObj = identityNode.GetObject(m_dataSet);
            m_syncCount = dataSetObj.GetInt64(SYNC_COUNT);

            if (dataSetObj.ValueExists(RECORDS))
            {
                auto records = identityNode.GetArray(RECORDS);
                for (unsigned i = 0; i < records.GetLength(); ++i)
                {
                    Record recordObj = records[i];

                    m_records[recordObj.GetKey()] = recordObj;
                    m_recordsList.push_back(recordObj);
                }
            }
        }
    }
}

JsonValue DefaultDataSetRecordsRepository::LoadJsonDocFromFile() const
{
    std::ifstream infile(m_filePath.c_str());
    if (infile.is_open() && infile.good())
    {
        return JsonValue(infile);
    }
    else
    {
        AWS_LOGSTREAM_ERROR(LOG_TAG, "Failed reading from file " << m_filePath);
    }

    return JsonValue();
}

void DefaultDataSetRecordsRepository::PersistChangesToFile(const JsonValue& jsonValue) const
{
    //the assumption here is that we've already created the directory by the time we make it here.
    Aws::String identitiesFile = m_filePath;
    std::ofstream outfile(identitiesFile.c_str(), std::ios_base::trunc | std::ios_base::out);

    if (outfile.is_open() && outfile.good())
    {
        outfile << jsonValue.WriteReadable();
        outfile.flush();
        outfile.close();
    }
    else
    {
        AWS_LOG_ERROR(LOG_TAG, "Failed persisting changes to file.");
    }
}

void DefaultDataSetRecordsRepository::CopyStateToDoc()
{
    auto jsonDoc = LoadJsonDocFromFile();

    JsonValue dataSetValue;
    dataSetValue.WithInt64(SYNC_COUNT, m_syncCount);
    Array<JsonValue> recordsArray(m_records.size());

    for(unsigned i = 0; i < m_records.size(); ++i)
    {
        recordsArray[i] = m_recordsList[i].Jsonize();
    }

    dataSetValue.WithArray(RECORDS, std::move(recordsArray));
    jsonDoc.WithObject(m_identityId, std::move(dataSetValue));
    PersistChangesToFile(jsonDoc);
}