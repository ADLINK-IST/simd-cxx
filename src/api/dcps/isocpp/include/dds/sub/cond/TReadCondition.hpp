#ifndef OMG_DDS_SUB_TCOND_READ_CONDITION_HPP_
#define OMG_DDS_SUB_TCOND_READ_CONDITION_HPP_


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

#include <dds/core/cond/TCondition.hpp>

namespace dds { namespace sub { namespace cond {
   template <typename DELEGATE>
    class TReadCondition;
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
template <typename DELEGATE>
class dds::sub::cond::TReadCondition : public dds::core::cond::TCondition<DELEGATE> {
public:
   OMG_DDS_REF_TYPE(TReadCondition, dds::core::cond::TCondition, DELEGATE)

public:
    template <typename T>
    TReadCondition(const dds::sub::DataReader<T>& dr, const dds::sub::status::DataState& status)
    : dds::core::cond::TCondition<DELEGATE>(new DELEGATE(dr, status)) { }

    template <typename T, typename FUN>
    TReadCondition(const dds::sub::DataReader<T>& dr, const dds::sub::status::DataState& status, const FUN& functor)
        : dds::core::cond::TCondition<DELEGATE>(new DELEGATE(dr, status, functor)) { }

    ~TReadCondition() { }

public:
    /**
     * This operation returns the set of sample-states that are taken into
     * account to determine the trigger_value of the ReadCondition. These are
     * the sample-states specified when the ReadCondition was created.
     */
    const dds::sub::status::DataState state_filter() const {
        return this->delegate()->state_filter();
    }

    const AnyDataReader& data_reader() const {
       return this->delegate()->data_reader();
    }

};


#endif /* OMG_DDS_SUB_TCOND_READ_CONDITION_HPP_ */
