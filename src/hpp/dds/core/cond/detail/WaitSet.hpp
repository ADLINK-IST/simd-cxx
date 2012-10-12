#ifndef OMG_DDS_CORE_COND_DETAIL_WAITSET_HPP_
#define OMG_DDS_CORE_COND_DETAIL_WAITSET_HPP_

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

#include <vector>
#include <iostream>

#include <dds/core/Duration.hpp>
#include <dds/core/cond/Condition.hpp>


namespace dds { namespace core { namespace cond { namespace detail {

    class WaitSet {
    public:
        typedef std::vector<dds::core::cond::Condition> ConditionSeqType;

    public:
        WaitSet() { }
        ~WaitSet() { }
        void close();

    public:
        const ConditionSeqType wait(const dds::core::Duration& timeout) {
            std::cout << "wait(timeout)" << std::endl;
            return ConditionSeqType();
        }

        const ConditionSeqType wait() {
            std::cout << "wait()" << std::endl;
            return ConditionSeqType();
        }

        ConditionSeqType& wait(ConditionSeqType& triggered,
                               const dds::core::Duration& timeout) {
            std::cout << "wait(triggered, timeout)" << std::endl;
            return triggered;
        }

        ConditionSeqType& wait(ConditionSeqType& triggered) {
            std::cout << "wait(triggered)" << std::endl;
            return triggered;
        }

    public:
        void dispatch() {
            std::cout << "dispatch()" << std::endl;
        }

        void dispatch(const dds::core::Duration& timeout) {
            std::cout << "dispatch(timeout)" << std::endl;
        }

    public:
        WaitSet& attach_condition(const dds::core::cond::Condition& cond) {
            std::cout << "attach_condition(condition)" << std::endl;
            return *this;
        }
        
        bool detach_condition(const dds::core::cond::Condition& cond) {
            std::cout << "detach_condition(condition)" << std::endl;
            return false;
        }

        const ConditionSeqType conditions() {
            std::cout << "conditions()" << std::endl;
            return ConditionSeqType();
        }

        ConditionSeqType& conditions(ConditionSeqType& conds) const {
            std::cout << "conditions(conditions)" << std::endl;
            return conds;
        }
    };

} } } }
#endif /* OMG_DDS_CORE_DETAIL_WAITSET_HPP_ */
