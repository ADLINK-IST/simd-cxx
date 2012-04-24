#ifndef OMG_DDS_TOPIC_DETAIL_TOPIC_HPP_
#define OMG_DDS_TOPIC_DETAIL_TOPIC_HPP_

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

#include <dds/core/ref_traits.hpp>
#include <dds/topic/TopicTraits.hpp>
#include <dds/core/status/Status.hpp>
#include <dds/core/status/State.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <dds/topic/detail/TopicDescription.hpp>

#include <org/opensplice/core/config.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>

namespace dds { namespace topic {
    template <typename T>
    class TopicListener;
} }

namespace dds { namespace topic { namespace detail {
    template <typename T>
    class Topic;
} } }

template <typename T>
class dds::topic::detail::Topic : public dds::topic::detail::TopicDescription<T> {
public:

    Topic(const dds::domain::DomainParticipant& dp,
          const std::string& name,
          const std::string& type_name,
          const dds::topic::qos::TopicQos& qos,
          dds::topic::TopicListener<T>* listener,
          const dds::core::status::StatusMask& mask)
    : dds::topic::detail::TopicDescription<T>(dp, name, type_name),
      dp_(dp),
	  qos_(qos),
    listener_(listener),
    mask_(mask)
	  {
    	char* tn = ts_.get_type_name();
        ts_.register_type(dp->dp_.get(), tn);

        DDS::TopicQos tqos;
        dp->dp_->get_default_topic_qos(tqos);
        t_ = dp->dp_->create_topic(name.c_str(), tn, tqos, 0,
    			   DDS::ANY_STATUS);

        if (t_ == 0)
        	throw dds::core::PreconditionNotMetError("Unable to create Topic!");
	  }

    virtual ~Topic() {
    	dp_->dp_->delete_topic(t_);
    }

public:
    /**
     * Returns a <code>StatusCondition</code> instance associated with
     * this <code>Entity</code>.
     */
    template <typename SELF>
    ::dds::core::cond::StatusCondition<SELF>
    status_condition(const SELF& self) const {
        return ::dds::core::cond::StatusCondition<SELF>
            (new ::dds::core::cond::detail::StatusCondition<SELF>(self));
    }

public:
	const dds::topic::qos::TopicQos& qos() const {
		return qos_;
	}

	void qos(const dds::topic::qos::TopicQos& the_qos) {
		qos_ = the_qos;
	}

	const ::dds::core::status::InconsistentTopicStatus& inconsistent_topic_status() {
		return its_;
	}

private:
	dds::domain::DomainParticipant dp_;
	dds::topic::qos::TopicQos qos_;
    dds::topic::TopicListener<T>* listener_;
    const dds::core::status::StatusMask& mask_;
    ::dds::core::status::InconsistentTopicStatus its_;

    typename dds::topic::topic_type_support<T>::type ts_;

public:
    DDS::Topic* t_;

};

#endif /* OMG_DDS_TOPIC_DETAIL_TOPIC_HPP_ */
