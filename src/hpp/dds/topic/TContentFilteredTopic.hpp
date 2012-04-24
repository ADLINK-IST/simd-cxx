#ifndef OMG_DDS_T_TOPIC_CONTENT_FILTERED_TOPIC_HPP_
#define OMG_DDS_T_TOPIC_CONTENT_FILTERED_TOPIC_HPP_

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

#include <vector>

#include <dds/core/detail/conformance.hpp>
#include <dds/core/types.hpp>
#include <dds/topic/Topic.hpp>
#include <dds/core/Query.hpp>

namespace dds { namespace topic {

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

template <typename T, template <typename Q> class DELEGATE>
class ContentFilteredTopic : public TopicDescription <T, DELEGATE> {
public:
    OMG_DDS_REF_TYPE_T(ContentFilteredTopic, TopicDescription, T, DELEGATE)

public:
    ContentFilteredTopic(const std::string& name, const Topic<T>& topic, const dds::core::Query& query)
    : dds::topic::TopicDescription<T, DELEGATE>(new DELEGATE<T>(name, topic, query)) { }

    virtual ~ContentFilteredTopic() { }

public:
	public:
	const std::string& filter_expression() {
		return this->delegate()->filter_expression();
	}

    const dds::core::StringSeq expression_parameters() {
		return this->delegate()->expression_parameters();
	}

	void expression_parameters(const dds::core::StringSeq& params) {
		this->delegate()->parameters(params);
	}

    const dds::topic::Topic<T>& topic() {
		return this->delegate()->topic();
	}
};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

} }


#endif /* OMG_DDS_T_TOPIC_CONTENT_FILTERED_TOPIC_HPP_ */
