#ifndef OMG_DDS_SUB_DETAIL_QUERY_CONDITION_HPP_
#define OMG_DDS_SUB_DETAIL_QUERY_CONDITION_HPP_

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

#include <dds/sub/cond/detail/ReadCondition.hpp>


namespace dds { namespace sub { namespace cond { namespace detail {

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
 
template <typename T>
class QueryCondition : public ReadCondition<T> {
public:
    QueryCondition(const dds::sub::DataReader<T>& dr,
    			   const dds::sub::status::DataState& status,
    			   const dds::core::Query& query)
    : ReadCondition<T>(dr, status), query_(query) { }

    virtual ~QueryCondition() { }

    const dds::core::Query& query() {
    	return query_;
    }

public:
    // TODO

private:
    dds::core::Query query_;
};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

} } } }

#endif /* OMG_DDS_SUB_DETAIL_QUERY_CONDITION_HPP_ */
