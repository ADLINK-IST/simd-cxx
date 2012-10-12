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

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

namespace dds {
   namespace sub {
      namespace cond {
         namespace detail {
            class QueryCondition;
         }
      }
   }
}

class dds::sub::cond::detail::QueryCondition: public ReadCondition {
public:
   typedef std::vector<std::string>::iterator iterator;
   typedef std::vector<std::string>::const_iterator const_iterator;
public:
   QueryCondition(
         const dds::sub::Query& query,
         const dds::sub::status::DataState& data_state)
         : ReadCondition(query.data_reader(), data_state),
           query_(query)
           { }

   virtual ~QueryCondition() { }

   void expression(const std::string& expr) {
      query_.expression(expr);
   }

   const std::string& expression() {
      return query_.expression();
   }


    /**
     * Provides the begin iterator to the parameter list.
     */
    iterator begin() {
       return query_.begin();
    }

    /**
     * The end iterator to the parameter list.
     */
    iterator end() {
       return query_.end();
    }

    const_iterator begin() const {
       return query_.begin();
    }

    /**
     * The end iterator to the parameter list.
     */
    const_iterator end() const {
       return query_.end();
    }

    template<typename FWIterator>
    void parameters(const FWIterator& begin, const FWIterator end) {
       query_.parameters(begin, end);
    }

    void add_parameter(const std::string& param) {
       query_.add_parameter(param);
    }

    uint32_t parameters_length() const {
       return query_.parameters_length();
    }

    const AnyDataReader& data_reader() {
       return query_.data_reader();
    }

private:
   dds::sub::Query query_;
};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

#endif /* OMG_DDS_SUB_DETAIL_QUERY_CONDITION_HPP_ */
