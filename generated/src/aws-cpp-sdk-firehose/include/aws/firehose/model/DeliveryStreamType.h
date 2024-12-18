﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/firehose/Firehose_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Firehose
{
namespace Model
{
  enum class DeliveryStreamType
  {
    NOT_SET,
    DirectPut,
    KinesisStreamAsSource,
    MSKAsSource,
    DatabaseAsSource
  };

namespace DeliveryStreamTypeMapper
{
AWS_FIREHOSE_API DeliveryStreamType GetDeliveryStreamTypeForName(const Aws::String& name);

AWS_FIREHOSE_API Aws::String GetNameForDeliveryStreamType(DeliveryStreamType value);
} // namespace DeliveryStreamTypeMapper
} // namespace Model
} // namespace Firehose
} // namespace Aws
