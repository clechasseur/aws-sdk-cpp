﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/appconfig/AppConfig_EXPORTS.h>
#include <aws/appconfig/AppConfigRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace AppConfig
{
namespace Model
{

  /**
   */
  class ListHostedConfigurationVersionsRequest : public AppConfigRequest
  {
  public:
    AWS_APPCONFIG_API ListHostedConfigurationVersionsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ListHostedConfigurationVersions"; }

    AWS_APPCONFIG_API Aws::String SerializePayload() const override;

    AWS_APPCONFIG_API void AddQueryStringParameters(Aws::Http::URI& uri) const override;


    ///@{
    /**
     * <p>The application ID.</p>
     */
    inline const Aws::String& GetApplicationId() const{ return m_applicationId; }
    inline bool ApplicationIdHasBeenSet() const { return m_applicationIdHasBeenSet; }
    inline void SetApplicationId(const Aws::String& value) { m_applicationIdHasBeenSet = true; m_applicationId = value; }
    inline void SetApplicationId(Aws::String&& value) { m_applicationIdHasBeenSet = true; m_applicationId = std::move(value); }
    inline void SetApplicationId(const char* value) { m_applicationIdHasBeenSet = true; m_applicationId.assign(value); }
    inline ListHostedConfigurationVersionsRequest& WithApplicationId(const Aws::String& value) { SetApplicationId(value); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithApplicationId(Aws::String&& value) { SetApplicationId(std::move(value)); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithApplicationId(const char* value) { SetApplicationId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The configuration profile ID.</p>
     */
    inline const Aws::String& GetConfigurationProfileId() const{ return m_configurationProfileId; }
    inline bool ConfigurationProfileIdHasBeenSet() const { return m_configurationProfileIdHasBeenSet; }
    inline void SetConfigurationProfileId(const Aws::String& value) { m_configurationProfileIdHasBeenSet = true; m_configurationProfileId = value; }
    inline void SetConfigurationProfileId(Aws::String&& value) { m_configurationProfileIdHasBeenSet = true; m_configurationProfileId = std::move(value); }
    inline void SetConfigurationProfileId(const char* value) { m_configurationProfileIdHasBeenSet = true; m_configurationProfileId.assign(value); }
    inline ListHostedConfigurationVersionsRequest& WithConfigurationProfileId(const Aws::String& value) { SetConfigurationProfileId(value); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithConfigurationProfileId(Aws::String&& value) { SetConfigurationProfileId(std::move(value)); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithConfigurationProfileId(const char* value) { SetConfigurationProfileId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The maximum number of items to return for this call. If
     * <code>MaxResults</code> is not provided in the call, AppConfig returns the
     * maximum of 50. The call also returns a token that you can specify in a
     * subsequent call to get the next set of results.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }
    inline ListHostedConfigurationVersionsRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>A token to start the list. Use this token to get the next set of results.
     * </p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }
    inline ListHostedConfigurationVersionsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>An optional filter that can be used to specify the version label of an
     * AppConfig hosted configuration version. This parameter supports filtering by
     * prefix using a wildcard, for example "v2*". If you don't specify an asterisk at
     * the end of the value, only an exact match is returned.</p>
     */
    inline const Aws::String& GetVersionLabel() const{ return m_versionLabel; }
    inline bool VersionLabelHasBeenSet() const { return m_versionLabelHasBeenSet; }
    inline void SetVersionLabel(const Aws::String& value) { m_versionLabelHasBeenSet = true; m_versionLabel = value; }
    inline void SetVersionLabel(Aws::String&& value) { m_versionLabelHasBeenSet = true; m_versionLabel = std::move(value); }
    inline void SetVersionLabel(const char* value) { m_versionLabelHasBeenSet = true; m_versionLabel.assign(value); }
    inline ListHostedConfigurationVersionsRequest& WithVersionLabel(const Aws::String& value) { SetVersionLabel(value); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithVersionLabel(Aws::String&& value) { SetVersionLabel(std::move(value)); return *this;}
    inline ListHostedConfigurationVersionsRequest& WithVersionLabel(const char* value) { SetVersionLabel(value); return *this;}
    ///@}
  private:

    Aws::String m_applicationId;
    bool m_applicationIdHasBeenSet = false;

    Aws::String m_configurationProfileId;
    bool m_configurationProfileIdHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_versionLabel;
    bool m_versionLabelHasBeenSet = false;
  };

} // namespace Model
} // namespace AppConfig
} // namespace Aws
