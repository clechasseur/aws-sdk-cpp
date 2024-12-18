﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/cloudtrail/CloudTrail_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace CloudTrail
{
namespace Model
{
  class StartQueryResult
  {
  public:
    AWS_CLOUDTRAIL_API StartQueryResult();
    AWS_CLOUDTRAIL_API StartQueryResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_CLOUDTRAIL_API StartQueryResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>The ID of the started query.</p>
     */
    inline const Aws::String& GetQueryId() const{ return m_queryId; }
    inline void SetQueryId(const Aws::String& value) { m_queryId = value; }
    inline void SetQueryId(Aws::String&& value) { m_queryId = std::move(value); }
    inline void SetQueryId(const char* value) { m_queryId.assign(value); }
    inline StartQueryResult& WithQueryId(const Aws::String& value) { SetQueryId(value); return *this;}
    inline StartQueryResult& WithQueryId(Aws::String&& value) { SetQueryId(std::move(value)); return *this;}
    inline StartQueryResult& WithQueryId(const char* value) { SetQueryId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p> The account ID of the event data store owner. </p>
     */
    inline const Aws::String& GetEventDataStoreOwnerAccountId() const{ return m_eventDataStoreOwnerAccountId; }
    inline void SetEventDataStoreOwnerAccountId(const Aws::String& value) { m_eventDataStoreOwnerAccountId = value; }
    inline void SetEventDataStoreOwnerAccountId(Aws::String&& value) { m_eventDataStoreOwnerAccountId = std::move(value); }
    inline void SetEventDataStoreOwnerAccountId(const char* value) { m_eventDataStoreOwnerAccountId.assign(value); }
    inline StartQueryResult& WithEventDataStoreOwnerAccountId(const Aws::String& value) { SetEventDataStoreOwnerAccountId(value); return *this;}
    inline StartQueryResult& WithEventDataStoreOwnerAccountId(Aws::String&& value) { SetEventDataStoreOwnerAccountId(std::move(value)); return *this;}
    inline StartQueryResult& WithEventDataStoreOwnerAccountId(const char* value) { SetEventDataStoreOwnerAccountId(value); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const{ return m_requestId; }
    inline void SetRequestId(const Aws::String& value) { m_requestId = value; }
    inline void SetRequestId(Aws::String&& value) { m_requestId = std::move(value); }
    inline void SetRequestId(const char* value) { m_requestId.assign(value); }
    inline StartQueryResult& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}
    inline StartQueryResult& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}
    inline StartQueryResult& WithRequestId(const char* value) { SetRequestId(value); return *this;}
    ///@}
  private:

    Aws::String m_queryId;

    Aws::String m_eventDataStoreOwnerAccountId;

    Aws::String m_requestId;
  };

} // namespace Model
} // namespace CloudTrail
} // namespace Aws
