#ifndef OMG_DDS_TOPIC_ANY_TOPIC_HPP_
#define OMG_DDS_TOPIC_ANY_TOPIC_HPP_

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

#include <dds/core/Exception.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/topic/detail/AnyTopic.hpp>
#include <dds/topic/TopicDescription.hpp>

namespace dds { namespace topic {

class AnyTopic {
public:
    template <typename T>
    inline AnyTopic(const dds::topic::Topic<T>& t)
    : holder_(new detail::THolder<T>(t)) { }

public:
     const dds::domain::DomainParticipant& domain_participant() const {
    	 return holder_->domain_participant();
     }

     const dds::core::status::InconsistentTopicStatus& inconsistent_topic_status() {
    	 return holder_->inconsistent_topic_status();
     }

       const dds::topic::qos::TopicQos& qos() const {
    	   return holder_->qos();
       }

       void qos(const dds::topic::qos::TopicQos& q) {
    	   holder_->qos(q);
       }

public:
    template <typename T>
    const Topic<T>& get() {
    	OMG_DDS_STATIC_ASSERT(::dds::topic::is_topic_type<T>::value == 1);
        detail::THolder<T>* h = dynamic_cast<detail::THolder<T>* >(holder_.get());
        if (h == 0) {
            throw dds::core::InvalidDowncastError("invalid type");
        }
        return h->get();
    }

public:
    inline const detail::THolderBase* operator->() const {
        return holder_.get();
    }

    detail::THolderBase* operator->() {
        return holder_.get();
    }

private:
    dds::core::smart_ptr_traits<detail::THolderBase>::ref_type holder_;
};

}}

#endif /* OMG_DDS_TOPIC_ANY_TOPIC_HPP_ */
