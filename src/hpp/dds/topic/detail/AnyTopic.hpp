#ifndef OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_
#define OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
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

#include <string>

#include <dds/core/status/Status.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <dds/topic/detail/AnyTopicDescription.hpp>

namespace dds { namespace topic { namespace detail {

class THolderBase : public virtual TDHolderBase {
public:
    virtual ~THolderBase() { }

    virtual const dds::domain::DomainParticipant& domain_participant() const = 0;

    virtual const dds::core::status::InconsistentTopicStatus& inconsistent_topic_status()  = 0;

    virtual const dds::topic::qos::TopicQos& qos() const = 0;

    virtual void qos(const dds::topic::qos::TopicQos& qos) = 0;
};

template <typename T>
class THolder : public THolderBase {
public:
    THolder(const dds::topic::Topic<T>& t)
    : topic_(t) { }
    virtual ~THolder() { }
public:

    virtual const dds::domain::DomainParticipant& domain_participant() const {
    	return topic_->domain_participant();
    }

    virtual const std::string& name() const {
    	return topic_->name();
    }

    virtual const std::string& type_name() const {
    	return topic_->type_name();
    }

    virtual const dds::core::status::InconsistentTopicStatus& inconsistent_topic_status() {
    	return topic_->inconsistent_topic_status();
    }

    virtual const dds::topic::qos::TopicQos& qos() const {
    	return topic_->qos();
    }

    virtual void qos(const dds::topic::qos::TopicQos& q) {
    	topic_->qos(q);
    }

    const dds::topic::Topic<T>& get() const { return topic_; }

private:
    dds::topic::Topic<T> topic_;
};
} } }

#endif /* OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_ */
