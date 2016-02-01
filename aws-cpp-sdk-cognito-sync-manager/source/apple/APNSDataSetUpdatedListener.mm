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
#include <aws/cognito-sync-manager/apple/APNSDataSetUpdatedListener.h>
#include <aws/cognito-sync/CognitoSyncClient.h>
#include <aws/cognito-sync/model/RegisterDeviceRequest.h>
#include <aws/core/utils/Outcome.h>
#include <aws/cognito-sync/model/SubscribeToDatasetRequest.h>
#include <aws/cognito-sync/model/UnsubscribeFromDatasetRequest.h>
#include <aws/core/utils/logging/LogMacros.h>

#import <AppKit/AppKit.h>

using namespace Aws::CognitoSync;
using namespace Aws::CognitoSync::Model;

using namespace Aws::CognitoSyncManager;

static const char* LOG_TAG = "APNSDataSetUpdateListener";

@interface AppDelegate : NSObject <NSApplicationDelegate> {

}
@property CognitoSyncClient* syncClient;
@property Aws::String identityId;
@property Aws::String identityPoolId;
@property Aws::String deviceId;
@property Aws::String dataSet;
@property DataSetUpdatedListener* listener;

@end

@implementation AppDelegate

- (void)application:(NSApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
    AWS_LOGSTREAM_INFO(LOG_TAG, "Device successfully registered with APNS with token " << [(NSString*)deviceToken UTF8String]);

    RegisterDeviceRequest registerDeviceRequest;
    registerDeviceRequest.WithPlatform(Platform::APNS)
        .WithToken([(NSString*)deviceToken UTF8String])
        .WithIdentityId(_identityId)
        .WithIdentityPoolId(_identityPoolId);

    auto registerOutcome = _syncClient->RegisterDevice(registerDeviceRequest);

    if(registerOutcome.IsSuccess())
    {
        _deviceId = registerOutcome.GetResult().GetDeviceId();
        AWS_LOGSTREAM_INFO(LOG_TAG, "Device successfully registered with Cognito-Sync with device Id " << _deviceId);

        SubscribeToDatasetRequest subscribeRequest;
        subscribeRequest.WithDeviceId(registerOutcome.GetResult().GetDeviceId())
                .WithIdentityId(_identityId)
                .WithIdentityPoolId(_identityPoolId)
                .WithDatasetName(_dataSet);
        _syncClient->SubscribeToDataset(subscribeRequest);
    }
    else
    {
        AWS_LOGSTREAM_ERROR(LOG_TAG, "Device registration failed with error. " << registerOutcome.GetError().GetMessage());
    }
}

- (void)application:(NSApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo
{
    NSString* source = [userInfo objectForKey: @"source"];
    NSString* identityPoolId = [userInfo objectForKey: @"identityPoolId"];
    NSString* identityId = [userInfo objectForKey: @"identityId"];
    NSString* datasetName = [userInfo objectForKey: @"datasetName"];
    int64_t syncCount = [[userInfo valueForKey: @"syncCount"] longLongValue];

    auto& callback = _listener->GetCallback();
    if(callback)
    {
        SyncUpdate syncUpdate;
        syncUpdate.SetSource([source UTF8String]);
        syncUpdate.SetIdentityPoolId([identityPoolId UTF8String]);
        syncUpdate.SetIdentityId([identityId UTF8String]);
        syncUpdate.SetDataSetName([datasetName UTF8String]);
        syncUpdate.SetSyncCount(syncCount);

        AWS_LOGSTREAM_TRACE(LOG_TAG, "Push notificaiton received: source = " << syncUpdate.GetSource() << " datasetname=" << syncUpdate.GetDataSetName()
                            << " sync Count=" << syncUpdate.GetSyncCount());

        callback(syncUpdate);
    }
}

@end

APNSDataSetUpdatedListener::APNSDataSetUpdatedListener(const std::shared_ptr<Aws::CognitoSync::CognitoSyncClient>& client,
                                                        const Aws::String identityPoolId, const Aws::String& identityId, const Aws::String& dataSet) :
    DataSetUpdatedListener(client, identityPoolId, identityId, dataSet)
{
    m_delegate = [[AppDelegate alloc] init];
    m_delegate.syncClient = m_client.get();
    m_delegate.identityPoolId = identityPoolId;
    m_delegate.identityId = identityId;
    m_delegate.dataSet = dataSet;
    m_delegate.listener = this;
}

APNSDataSetUpdatedListener::~APNSDataSetUpdatedListener()
{
    [AppDelegate release];
}

void APNSDataSetUpdatedListener::Subscribe()
{
    // Register for remote notifications.
    [NSApp registerForRemoteNotificationTypes:NSRemoteNotificationTypeBadge];
}

void APNSDataSetUpdatedListener::UnSubscribe()
{
    UnsubscribeFromDatasetRequest unsubscribeFromDatasetRequest;
    unsubscribeFromDatasetRequest.WithDatasetName(m_dataSetName)
                                 .WithDeviceId(m_delegate.deviceId)
                                 .WithIdentityId(m_identityId)
                                 .WithIdentityPoolId(m_identityPoolId);

    auto unsubscribeOutcome = m_client->UnsubscribeFromDataset(unsubscribeFromDatasetRequest);

    if(unsubscribeOutcome.IsSuccess())
    {
        AWS_LOGSTREAM_INFO(LOG_TAG, "Successfully unregistered deviceId " << m_delegate.deviceId);
        [NSApp unregisterForRemoteNotifications];
    }
    else
    {
        AWS_LOGSTREAM_ERROR(LOG_TAG, "Failed to unregister deviceId " << m_delegate.deviceId << " with error " << unsubscribeOutcome.GetError().GetMessage());
    }
}
