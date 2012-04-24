#ifndef OMG_DDS_TOPIC_ANY_TOPIC_DESCRIPTION_HPP_
#define OMG_DDS_TOPIC_ANY_TOPIC_DESCRIPTION_HPP_

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
#include <dds/topic/detail/AnyTopicDescription.hpp>


namespace dds { namespace topic {

class AnyTopicDescription {
public:
	template <typename T>
	inline AnyTopicDescription(const dds::topic::TopicDescription<T>& t)
	: holder_(new detail::TDHolder<T>(t)) { }

public:
	const dds::domain::DomainParticipant& domain_participant() const {
		return holder_->domain_participant();
	}

	const std::string& name() const {
		return holder_->name();
	}

	const std::string& type_name() const {
		return holder_->type_name();
	}

protected:
	inline AnyTopicDescription(detail::TDHolderBase* holder)
	: holder_(holder) { }

public:
	inline AnyTopicDescription& swap(AnyTopicDescription& rhs) {
		holder_.swap(rhs.holder_);
		return *this;
	}

	template <typename T>
	AnyTopicDescription& operator =(const dds::topic::Topic<T>& rhs) {
		holder_.reset(new detail::TDHolder<T>(rhs));
		return *this;
	}

	inline AnyTopicDescription& operator =(const AnyTopicDescription& rhs) {
		if (this != &rhs)
			holder_ = rhs.holder_;

		return *this;
	}

public:
	template <typename T>
	const dds::topic::TopicDescription<T>& get() {
		// OMG_DDS_STATIC_ASSERT(::dds::topic::is_topic_type<T>::value == 1);
		detail::TDHolder<T>* h = dynamic_cast<detail::TDHolder<T>* >(holder_.get() );
		if (h == 0) {
			throw dds::core::InvalidDowncastError("invalid type");
		}
		return h->get();
	}

public:
	const detail::TDHolderBase* operator->() const {
		return holder_.get();
	}

	detail::TDHolderBase* operator->() {
		return holder_.get();
	}

protected:
	dds::core::smart_ptr_traits<detail::TDHolderBase>::ref_type holder_;
};

}}

#endif /* OMG_DDS_TOPIC_ANY_TOPIC_DESCRIPTION_HPP_ */
