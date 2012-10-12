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

//#include <dds/sub/DataReader.hpp>
//#include <dds/sub/Query.hpp>
#include <dds/core/detail/conformance.hpp>
#include <dds/sub/cond/detail/QueryCondition.hpp>



#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

namespace dds { namespace sub { namespace cond {
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
class dds::sub::cond::QueryCondition : public dds::sub::cond::TReadCondition<detail::QueryCondition> {
public:
   typedef detail::QueryCondition DELEGATE;
public:
   // Random access iterators
   typedef DELEGATE::iterator iterator;
   typedef DELEGATE::const_iterator const_iterator;
public:
    // OMG_DDS_REF_TYPE(TQueryCondition, dds::sub::cond::TReadCondition, DELEGATE)

    QueryCondition(const dds::sub::Query& query,
                   const dds::sub::status::DataState& status)
    : TReadCondition<detail::QueryCondition>(new detail::QueryCondition(query, status)) { }

    ~QueryCondition() { }

public:

    void expression(const std::string& expr) {
       this->delegate()->expression(expr);
    }

    const std::string& expression() {
       return this->delegate()->expression();
    }

    /**
       * Provides the begin iterator to the parameter list.
       */
      const_iterator begin() const {
         return this->delegate()->begin();
      }

      /**
       * The end iterator to the parameter list.
       */
      const_iterator end() const {
         return this->delegate()->end();
      }

      /**
       * Provides the begin iterator to the parameter list.
       */
      iterator begin() {
         return this->delegate()->begin();
      }

      /**
       * The end iterator to the parameter list.
       */
      iterator end() {
         return this->delegate()->end();
      }

      template<typename FWIterator>
      void parameters(const FWIterator& begin, const FWIterator end) {
         this->delegate()->parameters(begin, end);
      }

      void add_parameter(const std::string& param) {
         this->delegate()->add_parameter(param);
      }

      uint32_t parameters_length() const {
         return this->delegate()->parameters_length();
      }
};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

#endif /* OMG_DDS_SUB_TQUERY_CONDITION_HPP_ */
