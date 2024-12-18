﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once

/* Generic header includes */
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2Errors.h>
#include <aws/core/client/GenericClientConfiguration.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2EndpointProvider.h>
#include <future>
#include <functional>
/* End of generic header includes */

/* Service model headers required in PinpointSMSVoiceV2Client header */
#include <aws/pinpoint-sms-voice-v2/model/AssociateOriginationIdentityResult.h>
#include <aws/pinpoint-sms-voice-v2/model/AssociateProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateConfigurationSetResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateEventDestinationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateOptOutListResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreatePoolResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateRegistrationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateRegistrationAssociationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateRegistrationAttachmentResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateRegistrationVersionResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateVerifiedDestinationNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteAccountDefaultProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteConfigurationSetResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteDefaultMessageTypeResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteDefaultSenderIdResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteEventDestinationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteKeywordResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteMediaMessageSpendLimitOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteOptOutListResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteOptedOutNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeletePoolResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteProtectConfigurationRuleSetNumberOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteRegistrationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteRegistrationAttachmentResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteRegistrationFieldValueResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteResourcePolicyResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteTextMessageSpendLimitOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteVerifiedDestinationNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteVoiceMessageSpendLimitOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeAccountAttributesResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeAccountLimitsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeConfigurationSetsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeKeywordsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeOptOutListsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeOptedOutNumbersResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribePhoneNumbersResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribePoolsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeProtectConfigurationsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationAttachmentsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationFieldDefinitionsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationFieldValuesResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationSectionDefinitionsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationTypeDefinitionsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationVersionsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeSenderIdsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeSpendLimitsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeVerifiedDestinationNumbersResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DisassociateOriginationIdentityResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DisassociateProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/DiscardRegistrationVersionResult.h>
#include <aws/pinpoint-sms-voice-v2/model/GetProtectConfigurationCountryRuleSetResult.h>
#include <aws/pinpoint-sms-voice-v2/model/GetResourcePolicyResult.h>
#include <aws/pinpoint-sms-voice-v2/model/ListPoolOriginationIdentitiesResult.h>
#include <aws/pinpoint-sms-voice-v2/model/ListProtectConfigurationRuleSetNumberOverridesResult.h>
#include <aws/pinpoint-sms-voice-v2/model/ListRegistrationAssociationsResult.h>
#include <aws/pinpoint-sms-voice-v2/model/ListTagsForResourceResult.h>
#include <aws/pinpoint-sms-voice-v2/model/PutKeywordResult.h>
#include <aws/pinpoint-sms-voice-v2/model/PutMessageFeedbackResult.h>
#include <aws/pinpoint-sms-voice-v2/model/PutOptedOutNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/PutProtectConfigurationRuleSetNumberOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/PutRegistrationFieldValueResult.h>
#include <aws/pinpoint-sms-voice-v2/model/PutResourcePolicyResult.h>
#include <aws/pinpoint-sms-voice-v2/model/ReleasePhoneNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/ReleaseSenderIdResult.h>
#include <aws/pinpoint-sms-voice-v2/model/RequestPhoneNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/RequestSenderIdResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SendDestinationNumberVerificationCodeResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SendMediaMessageResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SendTextMessageResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SendVoiceMessageResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetAccountDefaultProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetDefaultMessageFeedbackEnabledResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetDefaultMessageTypeResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetDefaultSenderIdResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetMediaMessageSpendLimitOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetTextMessageSpendLimitOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SetVoiceMessageSpendLimitOverrideResult.h>
#include <aws/pinpoint-sms-voice-v2/model/SubmitRegistrationVersionResult.h>
#include <aws/pinpoint-sms-voice-v2/model/TagResourceResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UntagResourceResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UpdateEventDestinationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UpdatePhoneNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UpdatePoolResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UpdateProtectConfigurationResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UpdateProtectConfigurationCountryRuleSetResult.h>
#include <aws/pinpoint-sms-voice-v2/model/UpdateSenderIdResult.h>
#include <aws/pinpoint-sms-voice-v2/model/VerifyDestinationNumberResult.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateRegistrationAttachmentRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeSenderIdsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/CreateProtectConfigurationRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeAccountAttributesRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteAccountDefaultProtectConfigurationRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteTextMessageSpendLimitOverrideRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationAttachmentsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeVerifiedDestinationNumbersRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeRegistrationTypeDefinitionsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeAccountLimitsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteMediaMessageSpendLimitOverrideRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeConfigurationSetsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DeleteVoiceMessageSpendLimitOverrideRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeOptOutListsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeSpendLimitsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribeProtectConfigurationsRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribePhoneNumbersRequest.h>
#include <aws/pinpoint-sms-voice-v2/model/DescribePoolsRequest.h>
/* End of service model headers required in PinpointSMSVoiceV2Client header */

namespace Aws
{
  namespace Http
  {
    class HttpClient;
    class HttpClientFactory;
  } // namespace Http

  namespace Utils
  {
    template< typename R, typename E> class Outcome;

    namespace Threading
    {
      class Executor;
    } // namespace Threading
  } // namespace Utils

  namespace Auth
  {
    class AWSCredentials;
    class AWSCredentialsProvider;
  } // namespace Auth

  namespace Client
  {
    class RetryStrategy;
  } // namespace Client

  namespace PinpointSMSVoiceV2
  {
    using PinpointSMSVoiceV2ClientConfiguration = Aws::Client::GenericClientConfiguration;
    using PinpointSMSVoiceV2EndpointProviderBase = Aws::PinpointSMSVoiceV2::Endpoint::PinpointSMSVoiceV2EndpointProviderBase;
    using PinpointSMSVoiceV2EndpointProvider = Aws::PinpointSMSVoiceV2::Endpoint::PinpointSMSVoiceV2EndpointProvider;

    namespace Model
    {
      /* Service model forward declarations required in PinpointSMSVoiceV2Client header */
      class AssociateOriginationIdentityRequest;
      class AssociateProtectConfigurationRequest;
      class CreateConfigurationSetRequest;
      class CreateEventDestinationRequest;
      class CreateOptOutListRequest;
      class CreatePoolRequest;
      class CreateProtectConfigurationRequest;
      class CreateRegistrationRequest;
      class CreateRegistrationAssociationRequest;
      class CreateRegistrationAttachmentRequest;
      class CreateRegistrationVersionRequest;
      class CreateVerifiedDestinationNumberRequest;
      class DeleteAccountDefaultProtectConfigurationRequest;
      class DeleteConfigurationSetRequest;
      class DeleteDefaultMessageTypeRequest;
      class DeleteDefaultSenderIdRequest;
      class DeleteEventDestinationRequest;
      class DeleteKeywordRequest;
      class DeleteMediaMessageSpendLimitOverrideRequest;
      class DeleteOptOutListRequest;
      class DeleteOptedOutNumberRequest;
      class DeletePoolRequest;
      class DeleteProtectConfigurationRequest;
      class DeleteProtectConfigurationRuleSetNumberOverrideRequest;
      class DeleteRegistrationRequest;
      class DeleteRegistrationAttachmentRequest;
      class DeleteRegistrationFieldValueRequest;
      class DeleteResourcePolicyRequest;
      class DeleteTextMessageSpendLimitOverrideRequest;
      class DeleteVerifiedDestinationNumberRequest;
      class DeleteVoiceMessageSpendLimitOverrideRequest;
      class DescribeAccountAttributesRequest;
      class DescribeAccountLimitsRequest;
      class DescribeConfigurationSetsRequest;
      class DescribeKeywordsRequest;
      class DescribeOptOutListsRequest;
      class DescribeOptedOutNumbersRequest;
      class DescribePhoneNumbersRequest;
      class DescribePoolsRequest;
      class DescribeProtectConfigurationsRequest;
      class DescribeRegistrationAttachmentsRequest;
      class DescribeRegistrationFieldDefinitionsRequest;
      class DescribeRegistrationFieldValuesRequest;
      class DescribeRegistrationSectionDefinitionsRequest;
      class DescribeRegistrationTypeDefinitionsRequest;
      class DescribeRegistrationVersionsRequest;
      class DescribeRegistrationsRequest;
      class DescribeSenderIdsRequest;
      class DescribeSpendLimitsRequest;
      class DescribeVerifiedDestinationNumbersRequest;
      class DisassociateOriginationIdentityRequest;
      class DisassociateProtectConfigurationRequest;
      class DiscardRegistrationVersionRequest;
      class GetProtectConfigurationCountryRuleSetRequest;
      class GetResourcePolicyRequest;
      class ListPoolOriginationIdentitiesRequest;
      class ListProtectConfigurationRuleSetNumberOverridesRequest;
      class ListRegistrationAssociationsRequest;
      class ListTagsForResourceRequest;
      class PutKeywordRequest;
      class PutMessageFeedbackRequest;
      class PutOptedOutNumberRequest;
      class PutProtectConfigurationRuleSetNumberOverrideRequest;
      class PutRegistrationFieldValueRequest;
      class PutResourcePolicyRequest;
      class ReleasePhoneNumberRequest;
      class ReleaseSenderIdRequest;
      class RequestPhoneNumberRequest;
      class RequestSenderIdRequest;
      class SendDestinationNumberVerificationCodeRequest;
      class SendMediaMessageRequest;
      class SendTextMessageRequest;
      class SendVoiceMessageRequest;
      class SetAccountDefaultProtectConfigurationRequest;
      class SetDefaultMessageFeedbackEnabledRequest;
      class SetDefaultMessageTypeRequest;
      class SetDefaultSenderIdRequest;
      class SetMediaMessageSpendLimitOverrideRequest;
      class SetTextMessageSpendLimitOverrideRequest;
      class SetVoiceMessageSpendLimitOverrideRequest;
      class SubmitRegistrationVersionRequest;
      class TagResourceRequest;
      class UntagResourceRequest;
      class UpdateEventDestinationRequest;
      class UpdatePhoneNumberRequest;
      class UpdatePoolRequest;
      class UpdateProtectConfigurationRequest;
      class UpdateProtectConfigurationCountryRuleSetRequest;
      class UpdateSenderIdRequest;
      class VerifyDestinationNumberRequest;
      /* End of service model forward declarations required in PinpointSMSVoiceV2Client header */

      /* Service model Outcome class definitions */
      typedef Aws::Utils::Outcome<AssociateOriginationIdentityResult, PinpointSMSVoiceV2Error> AssociateOriginationIdentityOutcome;
      typedef Aws::Utils::Outcome<AssociateProtectConfigurationResult, PinpointSMSVoiceV2Error> AssociateProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<CreateConfigurationSetResult, PinpointSMSVoiceV2Error> CreateConfigurationSetOutcome;
      typedef Aws::Utils::Outcome<CreateEventDestinationResult, PinpointSMSVoiceV2Error> CreateEventDestinationOutcome;
      typedef Aws::Utils::Outcome<CreateOptOutListResult, PinpointSMSVoiceV2Error> CreateOptOutListOutcome;
      typedef Aws::Utils::Outcome<CreatePoolResult, PinpointSMSVoiceV2Error> CreatePoolOutcome;
      typedef Aws::Utils::Outcome<CreateProtectConfigurationResult, PinpointSMSVoiceV2Error> CreateProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<CreateRegistrationResult, PinpointSMSVoiceV2Error> CreateRegistrationOutcome;
      typedef Aws::Utils::Outcome<CreateRegistrationAssociationResult, PinpointSMSVoiceV2Error> CreateRegistrationAssociationOutcome;
      typedef Aws::Utils::Outcome<CreateRegistrationAttachmentResult, PinpointSMSVoiceV2Error> CreateRegistrationAttachmentOutcome;
      typedef Aws::Utils::Outcome<CreateRegistrationVersionResult, PinpointSMSVoiceV2Error> CreateRegistrationVersionOutcome;
      typedef Aws::Utils::Outcome<CreateVerifiedDestinationNumberResult, PinpointSMSVoiceV2Error> CreateVerifiedDestinationNumberOutcome;
      typedef Aws::Utils::Outcome<DeleteAccountDefaultProtectConfigurationResult, PinpointSMSVoiceV2Error> DeleteAccountDefaultProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<DeleteConfigurationSetResult, PinpointSMSVoiceV2Error> DeleteConfigurationSetOutcome;
      typedef Aws::Utils::Outcome<DeleteDefaultMessageTypeResult, PinpointSMSVoiceV2Error> DeleteDefaultMessageTypeOutcome;
      typedef Aws::Utils::Outcome<DeleteDefaultSenderIdResult, PinpointSMSVoiceV2Error> DeleteDefaultSenderIdOutcome;
      typedef Aws::Utils::Outcome<DeleteEventDestinationResult, PinpointSMSVoiceV2Error> DeleteEventDestinationOutcome;
      typedef Aws::Utils::Outcome<DeleteKeywordResult, PinpointSMSVoiceV2Error> DeleteKeywordOutcome;
      typedef Aws::Utils::Outcome<DeleteMediaMessageSpendLimitOverrideResult, PinpointSMSVoiceV2Error> DeleteMediaMessageSpendLimitOverrideOutcome;
      typedef Aws::Utils::Outcome<DeleteOptOutListResult, PinpointSMSVoiceV2Error> DeleteOptOutListOutcome;
      typedef Aws::Utils::Outcome<DeleteOptedOutNumberResult, PinpointSMSVoiceV2Error> DeleteOptedOutNumberOutcome;
      typedef Aws::Utils::Outcome<DeletePoolResult, PinpointSMSVoiceV2Error> DeletePoolOutcome;
      typedef Aws::Utils::Outcome<DeleteProtectConfigurationResult, PinpointSMSVoiceV2Error> DeleteProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<DeleteProtectConfigurationRuleSetNumberOverrideResult, PinpointSMSVoiceV2Error> DeleteProtectConfigurationRuleSetNumberOverrideOutcome;
      typedef Aws::Utils::Outcome<DeleteRegistrationResult, PinpointSMSVoiceV2Error> DeleteRegistrationOutcome;
      typedef Aws::Utils::Outcome<DeleteRegistrationAttachmentResult, PinpointSMSVoiceV2Error> DeleteRegistrationAttachmentOutcome;
      typedef Aws::Utils::Outcome<DeleteRegistrationFieldValueResult, PinpointSMSVoiceV2Error> DeleteRegistrationFieldValueOutcome;
      typedef Aws::Utils::Outcome<DeleteResourcePolicyResult, PinpointSMSVoiceV2Error> DeleteResourcePolicyOutcome;
      typedef Aws::Utils::Outcome<DeleteTextMessageSpendLimitOverrideResult, PinpointSMSVoiceV2Error> DeleteTextMessageSpendLimitOverrideOutcome;
      typedef Aws::Utils::Outcome<DeleteVerifiedDestinationNumberResult, PinpointSMSVoiceV2Error> DeleteVerifiedDestinationNumberOutcome;
      typedef Aws::Utils::Outcome<DeleteVoiceMessageSpendLimitOverrideResult, PinpointSMSVoiceV2Error> DeleteVoiceMessageSpendLimitOverrideOutcome;
      typedef Aws::Utils::Outcome<DescribeAccountAttributesResult, PinpointSMSVoiceV2Error> DescribeAccountAttributesOutcome;
      typedef Aws::Utils::Outcome<DescribeAccountLimitsResult, PinpointSMSVoiceV2Error> DescribeAccountLimitsOutcome;
      typedef Aws::Utils::Outcome<DescribeConfigurationSetsResult, PinpointSMSVoiceV2Error> DescribeConfigurationSetsOutcome;
      typedef Aws::Utils::Outcome<DescribeKeywordsResult, PinpointSMSVoiceV2Error> DescribeKeywordsOutcome;
      typedef Aws::Utils::Outcome<DescribeOptOutListsResult, PinpointSMSVoiceV2Error> DescribeOptOutListsOutcome;
      typedef Aws::Utils::Outcome<DescribeOptedOutNumbersResult, PinpointSMSVoiceV2Error> DescribeOptedOutNumbersOutcome;
      typedef Aws::Utils::Outcome<DescribePhoneNumbersResult, PinpointSMSVoiceV2Error> DescribePhoneNumbersOutcome;
      typedef Aws::Utils::Outcome<DescribePoolsResult, PinpointSMSVoiceV2Error> DescribePoolsOutcome;
      typedef Aws::Utils::Outcome<DescribeProtectConfigurationsResult, PinpointSMSVoiceV2Error> DescribeProtectConfigurationsOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationAttachmentsResult, PinpointSMSVoiceV2Error> DescribeRegistrationAttachmentsOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationFieldDefinitionsResult, PinpointSMSVoiceV2Error> DescribeRegistrationFieldDefinitionsOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationFieldValuesResult, PinpointSMSVoiceV2Error> DescribeRegistrationFieldValuesOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationSectionDefinitionsResult, PinpointSMSVoiceV2Error> DescribeRegistrationSectionDefinitionsOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationTypeDefinitionsResult, PinpointSMSVoiceV2Error> DescribeRegistrationTypeDefinitionsOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationVersionsResult, PinpointSMSVoiceV2Error> DescribeRegistrationVersionsOutcome;
      typedef Aws::Utils::Outcome<DescribeRegistrationsResult, PinpointSMSVoiceV2Error> DescribeRegistrationsOutcome;
      typedef Aws::Utils::Outcome<DescribeSenderIdsResult, PinpointSMSVoiceV2Error> DescribeSenderIdsOutcome;
      typedef Aws::Utils::Outcome<DescribeSpendLimitsResult, PinpointSMSVoiceV2Error> DescribeSpendLimitsOutcome;
      typedef Aws::Utils::Outcome<DescribeVerifiedDestinationNumbersResult, PinpointSMSVoiceV2Error> DescribeVerifiedDestinationNumbersOutcome;
      typedef Aws::Utils::Outcome<DisassociateOriginationIdentityResult, PinpointSMSVoiceV2Error> DisassociateOriginationIdentityOutcome;
      typedef Aws::Utils::Outcome<DisassociateProtectConfigurationResult, PinpointSMSVoiceV2Error> DisassociateProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<DiscardRegistrationVersionResult, PinpointSMSVoiceV2Error> DiscardRegistrationVersionOutcome;
      typedef Aws::Utils::Outcome<GetProtectConfigurationCountryRuleSetResult, PinpointSMSVoiceV2Error> GetProtectConfigurationCountryRuleSetOutcome;
      typedef Aws::Utils::Outcome<GetResourcePolicyResult, PinpointSMSVoiceV2Error> GetResourcePolicyOutcome;
      typedef Aws::Utils::Outcome<ListPoolOriginationIdentitiesResult, PinpointSMSVoiceV2Error> ListPoolOriginationIdentitiesOutcome;
      typedef Aws::Utils::Outcome<ListProtectConfigurationRuleSetNumberOverridesResult, PinpointSMSVoiceV2Error> ListProtectConfigurationRuleSetNumberOverridesOutcome;
      typedef Aws::Utils::Outcome<ListRegistrationAssociationsResult, PinpointSMSVoiceV2Error> ListRegistrationAssociationsOutcome;
      typedef Aws::Utils::Outcome<ListTagsForResourceResult, PinpointSMSVoiceV2Error> ListTagsForResourceOutcome;
      typedef Aws::Utils::Outcome<PutKeywordResult, PinpointSMSVoiceV2Error> PutKeywordOutcome;
      typedef Aws::Utils::Outcome<PutMessageFeedbackResult, PinpointSMSVoiceV2Error> PutMessageFeedbackOutcome;
      typedef Aws::Utils::Outcome<PutOptedOutNumberResult, PinpointSMSVoiceV2Error> PutOptedOutNumberOutcome;
      typedef Aws::Utils::Outcome<PutProtectConfigurationRuleSetNumberOverrideResult, PinpointSMSVoiceV2Error> PutProtectConfigurationRuleSetNumberOverrideOutcome;
      typedef Aws::Utils::Outcome<PutRegistrationFieldValueResult, PinpointSMSVoiceV2Error> PutRegistrationFieldValueOutcome;
      typedef Aws::Utils::Outcome<PutResourcePolicyResult, PinpointSMSVoiceV2Error> PutResourcePolicyOutcome;
      typedef Aws::Utils::Outcome<ReleasePhoneNumberResult, PinpointSMSVoiceV2Error> ReleasePhoneNumberOutcome;
      typedef Aws::Utils::Outcome<ReleaseSenderIdResult, PinpointSMSVoiceV2Error> ReleaseSenderIdOutcome;
      typedef Aws::Utils::Outcome<RequestPhoneNumberResult, PinpointSMSVoiceV2Error> RequestPhoneNumberOutcome;
      typedef Aws::Utils::Outcome<RequestSenderIdResult, PinpointSMSVoiceV2Error> RequestSenderIdOutcome;
      typedef Aws::Utils::Outcome<SendDestinationNumberVerificationCodeResult, PinpointSMSVoiceV2Error> SendDestinationNumberVerificationCodeOutcome;
      typedef Aws::Utils::Outcome<SendMediaMessageResult, PinpointSMSVoiceV2Error> SendMediaMessageOutcome;
      typedef Aws::Utils::Outcome<SendTextMessageResult, PinpointSMSVoiceV2Error> SendTextMessageOutcome;
      typedef Aws::Utils::Outcome<SendVoiceMessageResult, PinpointSMSVoiceV2Error> SendVoiceMessageOutcome;
      typedef Aws::Utils::Outcome<SetAccountDefaultProtectConfigurationResult, PinpointSMSVoiceV2Error> SetAccountDefaultProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<SetDefaultMessageFeedbackEnabledResult, PinpointSMSVoiceV2Error> SetDefaultMessageFeedbackEnabledOutcome;
      typedef Aws::Utils::Outcome<SetDefaultMessageTypeResult, PinpointSMSVoiceV2Error> SetDefaultMessageTypeOutcome;
      typedef Aws::Utils::Outcome<SetDefaultSenderIdResult, PinpointSMSVoiceV2Error> SetDefaultSenderIdOutcome;
      typedef Aws::Utils::Outcome<SetMediaMessageSpendLimitOverrideResult, PinpointSMSVoiceV2Error> SetMediaMessageSpendLimitOverrideOutcome;
      typedef Aws::Utils::Outcome<SetTextMessageSpendLimitOverrideResult, PinpointSMSVoiceV2Error> SetTextMessageSpendLimitOverrideOutcome;
      typedef Aws::Utils::Outcome<SetVoiceMessageSpendLimitOverrideResult, PinpointSMSVoiceV2Error> SetVoiceMessageSpendLimitOverrideOutcome;
      typedef Aws::Utils::Outcome<SubmitRegistrationVersionResult, PinpointSMSVoiceV2Error> SubmitRegistrationVersionOutcome;
      typedef Aws::Utils::Outcome<TagResourceResult, PinpointSMSVoiceV2Error> TagResourceOutcome;
      typedef Aws::Utils::Outcome<UntagResourceResult, PinpointSMSVoiceV2Error> UntagResourceOutcome;
      typedef Aws::Utils::Outcome<UpdateEventDestinationResult, PinpointSMSVoiceV2Error> UpdateEventDestinationOutcome;
      typedef Aws::Utils::Outcome<UpdatePhoneNumberResult, PinpointSMSVoiceV2Error> UpdatePhoneNumberOutcome;
      typedef Aws::Utils::Outcome<UpdatePoolResult, PinpointSMSVoiceV2Error> UpdatePoolOutcome;
      typedef Aws::Utils::Outcome<UpdateProtectConfigurationResult, PinpointSMSVoiceV2Error> UpdateProtectConfigurationOutcome;
      typedef Aws::Utils::Outcome<UpdateProtectConfigurationCountryRuleSetResult, PinpointSMSVoiceV2Error> UpdateProtectConfigurationCountryRuleSetOutcome;
      typedef Aws::Utils::Outcome<UpdateSenderIdResult, PinpointSMSVoiceV2Error> UpdateSenderIdOutcome;
      typedef Aws::Utils::Outcome<VerifyDestinationNumberResult, PinpointSMSVoiceV2Error> VerifyDestinationNumberOutcome;
      /* End of service model Outcome class definitions */

      /* Service model Outcome callable definitions */
      typedef std::future<AssociateOriginationIdentityOutcome> AssociateOriginationIdentityOutcomeCallable;
      typedef std::future<AssociateProtectConfigurationOutcome> AssociateProtectConfigurationOutcomeCallable;
      typedef std::future<CreateConfigurationSetOutcome> CreateConfigurationSetOutcomeCallable;
      typedef std::future<CreateEventDestinationOutcome> CreateEventDestinationOutcomeCallable;
      typedef std::future<CreateOptOutListOutcome> CreateOptOutListOutcomeCallable;
      typedef std::future<CreatePoolOutcome> CreatePoolOutcomeCallable;
      typedef std::future<CreateProtectConfigurationOutcome> CreateProtectConfigurationOutcomeCallable;
      typedef std::future<CreateRegistrationOutcome> CreateRegistrationOutcomeCallable;
      typedef std::future<CreateRegistrationAssociationOutcome> CreateRegistrationAssociationOutcomeCallable;
      typedef std::future<CreateRegistrationAttachmentOutcome> CreateRegistrationAttachmentOutcomeCallable;
      typedef std::future<CreateRegistrationVersionOutcome> CreateRegistrationVersionOutcomeCallable;
      typedef std::future<CreateVerifiedDestinationNumberOutcome> CreateVerifiedDestinationNumberOutcomeCallable;
      typedef std::future<DeleteAccountDefaultProtectConfigurationOutcome> DeleteAccountDefaultProtectConfigurationOutcomeCallable;
      typedef std::future<DeleteConfigurationSetOutcome> DeleteConfigurationSetOutcomeCallable;
      typedef std::future<DeleteDefaultMessageTypeOutcome> DeleteDefaultMessageTypeOutcomeCallable;
      typedef std::future<DeleteDefaultSenderIdOutcome> DeleteDefaultSenderIdOutcomeCallable;
      typedef std::future<DeleteEventDestinationOutcome> DeleteEventDestinationOutcomeCallable;
      typedef std::future<DeleteKeywordOutcome> DeleteKeywordOutcomeCallable;
      typedef std::future<DeleteMediaMessageSpendLimitOverrideOutcome> DeleteMediaMessageSpendLimitOverrideOutcomeCallable;
      typedef std::future<DeleteOptOutListOutcome> DeleteOptOutListOutcomeCallable;
      typedef std::future<DeleteOptedOutNumberOutcome> DeleteOptedOutNumberOutcomeCallable;
      typedef std::future<DeletePoolOutcome> DeletePoolOutcomeCallable;
      typedef std::future<DeleteProtectConfigurationOutcome> DeleteProtectConfigurationOutcomeCallable;
      typedef std::future<DeleteProtectConfigurationRuleSetNumberOverrideOutcome> DeleteProtectConfigurationRuleSetNumberOverrideOutcomeCallable;
      typedef std::future<DeleteRegistrationOutcome> DeleteRegistrationOutcomeCallable;
      typedef std::future<DeleteRegistrationAttachmentOutcome> DeleteRegistrationAttachmentOutcomeCallable;
      typedef std::future<DeleteRegistrationFieldValueOutcome> DeleteRegistrationFieldValueOutcomeCallable;
      typedef std::future<DeleteResourcePolicyOutcome> DeleteResourcePolicyOutcomeCallable;
      typedef std::future<DeleteTextMessageSpendLimitOverrideOutcome> DeleteTextMessageSpendLimitOverrideOutcomeCallable;
      typedef std::future<DeleteVerifiedDestinationNumberOutcome> DeleteVerifiedDestinationNumberOutcomeCallable;
      typedef std::future<DeleteVoiceMessageSpendLimitOverrideOutcome> DeleteVoiceMessageSpendLimitOverrideOutcomeCallable;
      typedef std::future<DescribeAccountAttributesOutcome> DescribeAccountAttributesOutcomeCallable;
      typedef std::future<DescribeAccountLimitsOutcome> DescribeAccountLimitsOutcomeCallable;
      typedef std::future<DescribeConfigurationSetsOutcome> DescribeConfigurationSetsOutcomeCallable;
      typedef std::future<DescribeKeywordsOutcome> DescribeKeywordsOutcomeCallable;
      typedef std::future<DescribeOptOutListsOutcome> DescribeOptOutListsOutcomeCallable;
      typedef std::future<DescribeOptedOutNumbersOutcome> DescribeOptedOutNumbersOutcomeCallable;
      typedef std::future<DescribePhoneNumbersOutcome> DescribePhoneNumbersOutcomeCallable;
      typedef std::future<DescribePoolsOutcome> DescribePoolsOutcomeCallable;
      typedef std::future<DescribeProtectConfigurationsOutcome> DescribeProtectConfigurationsOutcomeCallable;
      typedef std::future<DescribeRegistrationAttachmentsOutcome> DescribeRegistrationAttachmentsOutcomeCallable;
      typedef std::future<DescribeRegistrationFieldDefinitionsOutcome> DescribeRegistrationFieldDefinitionsOutcomeCallable;
      typedef std::future<DescribeRegistrationFieldValuesOutcome> DescribeRegistrationFieldValuesOutcomeCallable;
      typedef std::future<DescribeRegistrationSectionDefinitionsOutcome> DescribeRegistrationSectionDefinitionsOutcomeCallable;
      typedef std::future<DescribeRegistrationTypeDefinitionsOutcome> DescribeRegistrationTypeDefinitionsOutcomeCallable;
      typedef std::future<DescribeRegistrationVersionsOutcome> DescribeRegistrationVersionsOutcomeCallable;
      typedef std::future<DescribeRegistrationsOutcome> DescribeRegistrationsOutcomeCallable;
      typedef std::future<DescribeSenderIdsOutcome> DescribeSenderIdsOutcomeCallable;
      typedef std::future<DescribeSpendLimitsOutcome> DescribeSpendLimitsOutcomeCallable;
      typedef std::future<DescribeVerifiedDestinationNumbersOutcome> DescribeVerifiedDestinationNumbersOutcomeCallable;
      typedef std::future<DisassociateOriginationIdentityOutcome> DisassociateOriginationIdentityOutcomeCallable;
      typedef std::future<DisassociateProtectConfigurationOutcome> DisassociateProtectConfigurationOutcomeCallable;
      typedef std::future<DiscardRegistrationVersionOutcome> DiscardRegistrationVersionOutcomeCallable;
      typedef std::future<GetProtectConfigurationCountryRuleSetOutcome> GetProtectConfigurationCountryRuleSetOutcomeCallable;
      typedef std::future<GetResourcePolicyOutcome> GetResourcePolicyOutcomeCallable;
      typedef std::future<ListPoolOriginationIdentitiesOutcome> ListPoolOriginationIdentitiesOutcomeCallable;
      typedef std::future<ListProtectConfigurationRuleSetNumberOverridesOutcome> ListProtectConfigurationRuleSetNumberOverridesOutcomeCallable;
      typedef std::future<ListRegistrationAssociationsOutcome> ListRegistrationAssociationsOutcomeCallable;
      typedef std::future<ListTagsForResourceOutcome> ListTagsForResourceOutcomeCallable;
      typedef std::future<PutKeywordOutcome> PutKeywordOutcomeCallable;
      typedef std::future<PutMessageFeedbackOutcome> PutMessageFeedbackOutcomeCallable;
      typedef std::future<PutOptedOutNumberOutcome> PutOptedOutNumberOutcomeCallable;
      typedef std::future<PutProtectConfigurationRuleSetNumberOverrideOutcome> PutProtectConfigurationRuleSetNumberOverrideOutcomeCallable;
      typedef std::future<PutRegistrationFieldValueOutcome> PutRegistrationFieldValueOutcomeCallable;
      typedef std::future<PutResourcePolicyOutcome> PutResourcePolicyOutcomeCallable;
      typedef std::future<ReleasePhoneNumberOutcome> ReleasePhoneNumberOutcomeCallable;
      typedef std::future<ReleaseSenderIdOutcome> ReleaseSenderIdOutcomeCallable;
      typedef std::future<RequestPhoneNumberOutcome> RequestPhoneNumberOutcomeCallable;
      typedef std::future<RequestSenderIdOutcome> RequestSenderIdOutcomeCallable;
      typedef std::future<SendDestinationNumberVerificationCodeOutcome> SendDestinationNumberVerificationCodeOutcomeCallable;
      typedef std::future<SendMediaMessageOutcome> SendMediaMessageOutcomeCallable;
      typedef std::future<SendTextMessageOutcome> SendTextMessageOutcomeCallable;
      typedef std::future<SendVoiceMessageOutcome> SendVoiceMessageOutcomeCallable;
      typedef std::future<SetAccountDefaultProtectConfigurationOutcome> SetAccountDefaultProtectConfigurationOutcomeCallable;
      typedef std::future<SetDefaultMessageFeedbackEnabledOutcome> SetDefaultMessageFeedbackEnabledOutcomeCallable;
      typedef std::future<SetDefaultMessageTypeOutcome> SetDefaultMessageTypeOutcomeCallable;
      typedef std::future<SetDefaultSenderIdOutcome> SetDefaultSenderIdOutcomeCallable;
      typedef std::future<SetMediaMessageSpendLimitOverrideOutcome> SetMediaMessageSpendLimitOverrideOutcomeCallable;
      typedef std::future<SetTextMessageSpendLimitOverrideOutcome> SetTextMessageSpendLimitOverrideOutcomeCallable;
      typedef std::future<SetVoiceMessageSpendLimitOverrideOutcome> SetVoiceMessageSpendLimitOverrideOutcomeCallable;
      typedef std::future<SubmitRegistrationVersionOutcome> SubmitRegistrationVersionOutcomeCallable;
      typedef std::future<TagResourceOutcome> TagResourceOutcomeCallable;
      typedef std::future<UntagResourceOutcome> UntagResourceOutcomeCallable;
      typedef std::future<UpdateEventDestinationOutcome> UpdateEventDestinationOutcomeCallable;
      typedef std::future<UpdatePhoneNumberOutcome> UpdatePhoneNumberOutcomeCallable;
      typedef std::future<UpdatePoolOutcome> UpdatePoolOutcomeCallable;
      typedef std::future<UpdateProtectConfigurationOutcome> UpdateProtectConfigurationOutcomeCallable;
      typedef std::future<UpdateProtectConfigurationCountryRuleSetOutcome> UpdateProtectConfigurationCountryRuleSetOutcomeCallable;
      typedef std::future<UpdateSenderIdOutcome> UpdateSenderIdOutcomeCallable;
      typedef std::future<VerifyDestinationNumberOutcome> VerifyDestinationNumberOutcomeCallable;
      /* End of service model Outcome callable definitions */
    } // namespace Model

    class PinpointSMSVoiceV2Client;

    /* Service model async handlers definitions */
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::AssociateOriginationIdentityRequest&, const Model::AssociateOriginationIdentityOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssociateOriginationIdentityResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::AssociateProtectConfigurationRequest&, const Model::AssociateProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssociateProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateConfigurationSetRequest&, const Model::CreateConfigurationSetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateConfigurationSetResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateEventDestinationRequest&, const Model::CreateEventDestinationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateEventDestinationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateOptOutListRequest&, const Model::CreateOptOutListOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateOptOutListResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreatePoolRequest&, const Model::CreatePoolOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreatePoolResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateProtectConfigurationRequest&, const Model::CreateProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateRegistrationRequest&, const Model::CreateRegistrationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateRegistrationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateRegistrationAssociationRequest&, const Model::CreateRegistrationAssociationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateRegistrationAssociationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateRegistrationAttachmentRequest&, const Model::CreateRegistrationAttachmentOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateRegistrationAttachmentResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateRegistrationVersionRequest&, const Model::CreateRegistrationVersionOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateRegistrationVersionResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::CreateVerifiedDestinationNumberRequest&, const Model::CreateVerifiedDestinationNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateVerifiedDestinationNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteAccountDefaultProtectConfigurationRequest&, const Model::DeleteAccountDefaultProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteAccountDefaultProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteConfigurationSetRequest&, const Model::DeleteConfigurationSetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteConfigurationSetResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteDefaultMessageTypeRequest&, const Model::DeleteDefaultMessageTypeOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteDefaultMessageTypeResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteDefaultSenderIdRequest&, const Model::DeleteDefaultSenderIdOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteDefaultSenderIdResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteEventDestinationRequest&, const Model::DeleteEventDestinationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteEventDestinationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteKeywordRequest&, const Model::DeleteKeywordOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteKeywordResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteMediaMessageSpendLimitOverrideRequest&, const Model::DeleteMediaMessageSpendLimitOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteMediaMessageSpendLimitOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteOptOutListRequest&, const Model::DeleteOptOutListOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteOptOutListResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteOptedOutNumberRequest&, const Model::DeleteOptedOutNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteOptedOutNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeletePoolRequest&, const Model::DeletePoolOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeletePoolResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteProtectConfigurationRequest&, const Model::DeleteProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteProtectConfigurationRuleSetNumberOverrideRequest&, const Model::DeleteProtectConfigurationRuleSetNumberOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteProtectConfigurationRuleSetNumberOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteRegistrationRequest&, const Model::DeleteRegistrationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteRegistrationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteRegistrationAttachmentRequest&, const Model::DeleteRegistrationAttachmentOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteRegistrationAttachmentResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteRegistrationFieldValueRequest&, const Model::DeleteRegistrationFieldValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteRegistrationFieldValueResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteResourcePolicyRequest&, const Model::DeleteResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteResourcePolicyResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteTextMessageSpendLimitOverrideRequest&, const Model::DeleteTextMessageSpendLimitOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteTextMessageSpendLimitOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteVerifiedDestinationNumberRequest&, const Model::DeleteVerifiedDestinationNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteVerifiedDestinationNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DeleteVoiceMessageSpendLimitOverrideRequest&, const Model::DeleteVoiceMessageSpendLimitOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteVoiceMessageSpendLimitOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeAccountAttributesRequest&, const Model::DescribeAccountAttributesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAccountAttributesResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeAccountLimitsRequest&, const Model::DescribeAccountLimitsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAccountLimitsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeConfigurationSetsRequest&, const Model::DescribeConfigurationSetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeConfigurationSetsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeKeywordsRequest&, const Model::DescribeKeywordsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeKeywordsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeOptOutListsRequest&, const Model::DescribeOptOutListsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeOptOutListsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeOptedOutNumbersRequest&, const Model::DescribeOptedOutNumbersOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeOptedOutNumbersResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribePhoneNumbersRequest&, const Model::DescribePhoneNumbersOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribePhoneNumbersResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribePoolsRequest&, const Model::DescribePoolsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribePoolsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeProtectConfigurationsRequest&, const Model::DescribeProtectConfigurationsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeProtectConfigurationsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationAttachmentsRequest&, const Model::DescribeRegistrationAttachmentsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationAttachmentsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationFieldDefinitionsRequest&, const Model::DescribeRegistrationFieldDefinitionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationFieldDefinitionsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationFieldValuesRequest&, const Model::DescribeRegistrationFieldValuesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationFieldValuesResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationSectionDefinitionsRequest&, const Model::DescribeRegistrationSectionDefinitionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationSectionDefinitionsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationTypeDefinitionsRequest&, const Model::DescribeRegistrationTypeDefinitionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationTypeDefinitionsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationVersionsRequest&, const Model::DescribeRegistrationVersionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationVersionsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeRegistrationsRequest&, const Model::DescribeRegistrationsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeRegistrationsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeSenderIdsRequest&, const Model::DescribeSenderIdsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeSenderIdsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeSpendLimitsRequest&, const Model::DescribeSpendLimitsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeSpendLimitsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DescribeVerifiedDestinationNumbersRequest&, const Model::DescribeVerifiedDestinationNumbersOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeVerifiedDestinationNumbersResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DisassociateOriginationIdentityRequest&, const Model::DisassociateOriginationIdentityOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DisassociateOriginationIdentityResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DisassociateProtectConfigurationRequest&, const Model::DisassociateProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DisassociateProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::DiscardRegistrationVersionRequest&, const Model::DiscardRegistrationVersionOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DiscardRegistrationVersionResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::GetProtectConfigurationCountryRuleSetRequest&, const Model::GetProtectConfigurationCountryRuleSetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetProtectConfigurationCountryRuleSetResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::GetResourcePolicyRequest&, const Model::GetResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetResourcePolicyResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::ListPoolOriginationIdentitiesRequest&, const Model::ListPoolOriginationIdentitiesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListPoolOriginationIdentitiesResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::ListProtectConfigurationRuleSetNumberOverridesRequest&, const Model::ListProtectConfigurationRuleSetNumberOverridesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListProtectConfigurationRuleSetNumberOverridesResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::ListRegistrationAssociationsRequest&, const Model::ListRegistrationAssociationsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListRegistrationAssociationsResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::ListTagsForResourceRequest&, const Model::ListTagsForResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListTagsForResourceResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::PutKeywordRequest&, const Model::PutKeywordOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutKeywordResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::PutMessageFeedbackRequest&, const Model::PutMessageFeedbackOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutMessageFeedbackResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::PutOptedOutNumberRequest&, const Model::PutOptedOutNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutOptedOutNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::PutProtectConfigurationRuleSetNumberOverrideRequest&, const Model::PutProtectConfigurationRuleSetNumberOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutProtectConfigurationRuleSetNumberOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::PutRegistrationFieldValueRequest&, const Model::PutRegistrationFieldValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutRegistrationFieldValueResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::PutResourcePolicyRequest&, const Model::PutResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutResourcePolicyResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::ReleasePhoneNumberRequest&, const Model::ReleasePhoneNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ReleasePhoneNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::ReleaseSenderIdRequest&, const Model::ReleaseSenderIdOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ReleaseSenderIdResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::RequestPhoneNumberRequest&, const Model::RequestPhoneNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > RequestPhoneNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::RequestSenderIdRequest&, const Model::RequestSenderIdOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > RequestSenderIdResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SendDestinationNumberVerificationCodeRequest&, const Model::SendDestinationNumberVerificationCodeOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SendDestinationNumberVerificationCodeResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SendMediaMessageRequest&, const Model::SendMediaMessageOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SendMediaMessageResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SendTextMessageRequest&, const Model::SendTextMessageOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SendTextMessageResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SendVoiceMessageRequest&, const Model::SendVoiceMessageOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SendVoiceMessageResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetAccountDefaultProtectConfigurationRequest&, const Model::SetAccountDefaultProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetAccountDefaultProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetDefaultMessageFeedbackEnabledRequest&, const Model::SetDefaultMessageFeedbackEnabledOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetDefaultMessageFeedbackEnabledResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetDefaultMessageTypeRequest&, const Model::SetDefaultMessageTypeOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetDefaultMessageTypeResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetDefaultSenderIdRequest&, const Model::SetDefaultSenderIdOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetDefaultSenderIdResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetMediaMessageSpendLimitOverrideRequest&, const Model::SetMediaMessageSpendLimitOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetMediaMessageSpendLimitOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetTextMessageSpendLimitOverrideRequest&, const Model::SetTextMessageSpendLimitOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetTextMessageSpendLimitOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SetVoiceMessageSpendLimitOverrideRequest&, const Model::SetVoiceMessageSpendLimitOverrideOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SetVoiceMessageSpendLimitOverrideResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::SubmitRegistrationVersionRequest&, const Model::SubmitRegistrationVersionOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > SubmitRegistrationVersionResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::TagResourceRequest&, const Model::TagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > TagResourceResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UntagResourceRequest&, const Model::UntagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UntagResourceResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UpdateEventDestinationRequest&, const Model::UpdateEventDestinationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateEventDestinationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UpdatePhoneNumberRequest&, const Model::UpdatePhoneNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdatePhoneNumberResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UpdatePoolRequest&, const Model::UpdatePoolOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdatePoolResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UpdateProtectConfigurationRequest&, const Model::UpdateProtectConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateProtectConfigurationResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UpdateProtectConfigurationCountryRuleSetRequest&, const Model::UpdateProtectConfigurationCountryRuleSetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateProtectConfigurationCountryRuleSetResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::UpdateSenderIdRequest&, const Model::UpdateSenderIdOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateSenderIdResponseReceivedHandler;
    typedef std::function<void(const PinpointSMSVoiceV2Client*, const Model::VerifyDestinationNumberRequest&, const Model::VerifyDestinationNumberOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > VerifyDestinationNumberResponseReceivedHandler;
    /* End of service model async handlers definitions */
  } // namespace PinpointSMSVoiceV2
} // namespace Aws
