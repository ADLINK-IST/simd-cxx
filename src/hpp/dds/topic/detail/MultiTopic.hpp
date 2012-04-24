#ifndef OMG_DDS_TOPIC_DETAIL_MULTI_TOPIC_HPP_
#define OMG_DDS_TOPIC_DETAIL_MULTI_TOPIC_HPP_

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

#include <string>
#include <vector>

#include <dds/core/types.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/topic/detail/TopicDescription.hpp>
#include <dds/core/Query.hpp>

namespace dds { namespace topic { namespace detail {

#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT

template <typename T>
class MultiTopic  : public dds::topic::detail::TopicDescription<T>
{
public:
	MultiTopic(const dds::domain::DomainParticipant& dp,
			   const std::string& name,
			   const dds::core::Query& query)
    : dds::topic::detail::TopicDescription<T>(dp, name, topic_type_name<T>::value()),
      query_(query) { }

	virtual ~MultiTopic() { }

public:
    const dds::core::Query& query() { return query_; }

    void expression_parameters(const dds::core::StringSeq& params) {
		query_.parameters(params.begin(), params.end());
	}

private:
	std::string 		     subscription_expression_;
	std::vector<std::string> params_;
	dds::core::Query query_;
};

#endif  // OMG_DDS_MULTI_TOPIC_SUPPORT

} } }


#endif /* OMG_DDS_TOPIC_DETAIL_MULTI_TOPIC_HPP_ */
