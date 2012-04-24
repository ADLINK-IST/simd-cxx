/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Inc.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dds/core/Exception.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <org/opensplice/domain/DomainParticipantDelegate.hpp>
#include <org/opensplice/core/memory.hpp>



org::opensplice::domain::DomainParticipantDelegate::DomainParticipantDelegate(uint32_t id)
{
	DDS::DomainParticipantFactory_var dpf =
			DDS::DomainParticipantFactory::get_instance();

	if(dpf.in() == 0)
		throw dds::core::PreconditionNotMetError("Unable to resolve the DomainParticipant Factory!");

	DDS::DomainParticipant* dp =
			dpf->create_participant(0,
					PARTICIPANT_QOS_DEFAULT,
					0,
					DDS::ANY_STATUS);

	if(dp == 0)
		throw dds::core::PreconditionNotMetError("Failed to create DomainParticipant");

	dp_.reset(dp, org::opensplice::core::DPDeleter());
}


org::opensplice::domain::DomainParticipantDelegate::DomainParticipantDelegate
(uint32_t id,
		const dds::domain::qos::DomainParticipantQos& qos,
		dds::domain::DomainParticipantListener* listener,
		const dds::core::status::StatusMask&)
{
	throw dds::core::PreconditionNotMetError("Method not supported");
}

org::opensplice::domain::DomainParticipantDelegate::~DomainParticipantDelegate() {
	OMG_DDS_LOG("MM", "~DomainParticipantImpl()");
}

/*
void org::opensplice::domain::DomainParticipantDelegate::listener(
        dds::domain::DomainParticipantListener* the_listener,
        const dds::core::status::StatusMask& event_mask) {
}
 */

dds::domain::DomainParticipantListener*
org::opensplice::domain::DomainParticipantDelegate::listener() const {
	return NULL;
}

uint32_t
org::opensplice::domain::DomainParticipantDelegate::domain_id() {
	return dp_->get_domain_id();
}

void
org::opensplice::domain::DomainParticipantDelegate::assert_liveliness() { }

bool
org::opensplice::domain::DomainParticipantDelegate::contains_entity(const dds::core::InstanceHandle& handle) {
	return false;
}

dds::core::Time
org::opensplice::domain::DomainParticipantDelegate::current_time() {
	return dds::core::Time();
}

const dds::domain::qos::DomainParticipantQos
org::opensplice::domain::DomainParticipantDelegate::qos() const {
	return this->qos_;
}


void
org::opensplice::domain::DomainParticipantDelegate::qos(const dds::domain::qos::DomainParticipantQos& the_qos) {

}

void
org::opensplice::domain::DomainParticipantDelegate::close() { }

const dds::topic::qos::TopicQos& 
org::opensplice::domain::DomainParticipantDelegate::default_topic_qos() const {
	return default_topic_qos_;
}

void 
org::opensplice::domain::DomainParticipantDelegate::default_topic_qos(const dds::topic::qos::TopicQos& qos) {
	default_topic_qos_ = qos;
}

const ::dds::pub::qos::PublisherQos&
org::opensplice::domain::DomainParticipantDelegate::default_publisher_qos() const {
	return default_pub_qos_;
}

void 
org::opensplice::domain::DomainParticipantDelegate::default_publisher_qos(const ::dds::pub::qos::PublisherQos& qos)
{
	default_pub_qos_ = qos;
}

const ::dds::sub::qos::SubscriberQos& 
org::opensplice::domain::DomainParticipantDelegate::default_subscriber_qos() const {
	return default_sub_qos_;
}

void 
org::opensplice::domain::DomainParticipantDelegate::default_subscriber_qos(const ::dds::sub::qos::SubscriberQos& qos)
{
	default_sub_qos_ = qos;
}

const ::dds::domain::qos::DomainParticipantQos& 
org::opensplice::domain::DomainParticipantDelegate::default_domain_qos() {
	return default_domain_qos_;
}
void 
org::opensplice::domain::DomainParticipantDelegate::default_domain_qos(const ::dds::domain::qos::DomainParticipantQos& qos)
{
	default_domain_qos_ = qos;
}


/*
namespace idds { namespace domain {

template <>
dds::core::cond::StatusCondition<dds::domain::DomainParticipant>
DomainParticipantImpl::status_condition<dds::domain::DomainParticipant>(const dds::domain::DomainParticipant& self) const {
    return dds::core::cond::StatusCondition<dds::domain::DomainParticipant>(
        new dds::core::cond::detail::StatusCondition<dds::domain::DomainParticipant>(self));
}

} }
 */
