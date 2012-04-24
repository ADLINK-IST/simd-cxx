#ifndef OMG_DDS_SUB_TQUERY_CONDITION_HPP_
#define OMG_DDS_SUB_TQUERY_CONDITION_HPP_

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

#include <dds/sub/cond/detail/QueryCondition.hpp>
#include <dds/sub/cond/ReadCondition.hpp>


#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

namespace dds { namespace sub { namespace cond {
	template <typename T, template <typename Q> class DELEGATE>
	class QueryCondition;
} } }

/**
 * ReadCondition objects are conditions specifically dedicated
 * to read operations and attached to one DataReader.
 * <br>
 * ReadCondition objects allow an application to specify the data samples
 * it is interested in (by specifying the desired sample states, view states,
 * and instance states). See the parameter definitions for DataReader's
 * read/take operations.) This allows the middleware to enable the condition
 * only when suitable information is available. They are to be used in
 * conjunction with a WaitSet as normal conditions. More than one
 * ReadCondition may be attached to the same DataReader.
 */
template <typename T, template <typename Q> class DELEGATE>
class dds::sub::cond::QueryCondition : public dds::sub::cond::ReadCondition< T, DELEGATE > {
public:
    OMG_DDS_REF_TYPE_T(QueryCondition, dds::sub::cond::ReadCondition, T, DELEGATE)

    // QueryCondition(const dds::sub::DataReader& reader, const dds::sub::status::DataStatus& status, const dds::core::Query& query) { }
    //: dds::sub::cond::ReadCondition<T, DELEGATE<T> >(new DELEGATE<T>(reader, status, query)) { }
    ~QueryCondition() { }

public:
    const dds::core::Query& query() {
    	return this->delegate()->query();
    }
    const dds::core::StringSeq query_parameters() const;

    void query_parameters(const dds::core::StringSeq& query_parameters);
};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT


#endif /* OMG_DDS_SUB_TQUERY_CONDITION_HPP_ */
