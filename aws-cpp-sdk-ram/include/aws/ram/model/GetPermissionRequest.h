﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/ram/RAM_EXPORTS.h>
#include <aws/ram/RAMRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace RAM
{
namespace Model
{

  /**
   */
  class AWS_RAM_API GetPermissionRequest : public RAMRequest
  {
  public:
    GetPermissionRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "GetPermission"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>The ARN of the permission.</p>
     */
    inline const Aws::String& GetPermissionArn() const{ return m_permissionArn; }

    /**
     * <p>The ARN of the permission.</p>
     */
    inline bool PermissionArnHasBeenSet() const { return m_permissionArnHasBeenSet; }

    /**
     * <p>The ARN of the permission.</p>
     */
    inline void SetPermissionArn(const Aws::String& value) { m_permissionArnHasBeenSet = true; m_permissionArn = value; }

    /**
     * <p>The ARN of the permission.</p>
     */
    inline void SetPermissionArn(Aws::String&& value) { m_permissionArnHasBeenSet = true; m_permissionArn = std::move(value); }

    /**
     * <p>The ARN of the permission.</p>
     */
    inline void SetPermissionArn(const char* value) { m_permissionArnHasBeenSet = true; m_permissionArn.assign(value); }

    /**
     * <p>The ARN of the permission.</p>
     */
    inline GetPermissionRequest& WithPermissionArn(const Aws::String& value) { SetPermissionArn(value); return *this;}

    /**
     * <p>The ARN of the permission.</p>
     */
    inline GetPermissionRequest& WithPermissionArn(Aws::String&& value) { SetPermissionArn(std::move(value)); return *this;}

    /**
     * <p>The ARN of the permission.</p>
     */
    inline GetPermissionRequest& WithPermissionArn(const char* value) { SetPermissionArn(value); return *this;}


    /**
     * <p>The identifier for the version of the permission.</p>
     */
    inline int GetPermissionVersion() const{ return m_permissionVersion; }

    /**
     * <p>The identifier for the version of the permission.</p>
     */
    inline bool PermissionVersionHasBeenSet() const { return m_permissionVersionHasBeenSet; }

    /**
     * <p>The identifier for the version of the permission.</p>
     */
    inline void SetPermissionVersion(int value) { m_permissionVersionHasBeenSet = true; m_permissionVersion = value; }

    /**
     * <p>The identifier for the version of the permission.</p>
     */
    inline GetPermissionRequest& WithPermissionVersion(int value) { SetPermissionVersion(value); return *this;}

  private:

    Aws::String m_permissionArn;
    bool m_permissionArnHasBeenSet;

    int m_permissionVersion;
    bool m_permissionVersionHasBeenSet;
  };

} // namespace Model
} // namespace RAM
} // namespace Aws