/*
 * Query.hpp
 *
 *  Created on: Oct 10, 2012
 *      Author: angelo
 */

#ifndef DDS_SUB_DETAIL_QUERY_HPP_
#define DDS_SUB_DETAIL_QUERY_HPP_

#include <vector>
#include <iterator>

namespace dds {
   namespace sub {
      namespace detail {
         class Query;
      }
   }
}

class dds::sub::detail::Query {
public:
   typedef std::vector<std::string>::iterator iterator;
   typedef std::vector<std::string>::const_iterator const_iterator;

public:
   template<typename T>
   Query(const dds::sub::DataReader<T>& dr, const std::string& query_expression) :
         adr_(dr),
         expression_(query_expression)
         { }

   template<typename T, typename FWIterator>
   Query(const dds::sub::DataReader<T>& dr, const std::string& query_expression,
         const FWIterator& params_begin, const FWIterator& params_end)
         : adr_(dr),
           expression_(query_expression) {
      std::copy(params_begin, params_end,
            std::back_insert_iterator<std::vector<std::string> >(params_));
   }

   const std::string& expression() const {
      return expression_;
   }

   void expression(const std::string& expr) {
       expression_ = expr;
   }

   /**
    * Provides the begin iterator to the parameter list.
    */
   iterator begin() {
      return params_.begin();
   }

   /**
    * The end iterator to the parameter list.
    */
   iterator end() {
      return params_.end();
   }

   const_iterator begin() const {
      return params_.begin();
   }

   /**
    * The end iterator to the parameter list.
    */
   const_iterator end() const {
      return params_.end();
   }

   template<typename FWIterator>
   void parameters(const FWIterator& begin, const FWIterator end) {
      params_.erase(params_.begin(), params_.end());
      std::copy(begin, end,
            std::back_insert_iterator<std::vector<std::string> >(params_));
   }

   void add_parameter(const std::string& param) {
      params_.push_back(param);
   }

   uint32_t parameters_length() const {
      return params_.size();
   }

   const AnyDataReader& data_reader() const {
      return adr_;
   }

private:
   dds::sub::AnyDataReader adr_;
   std::string expression_;
   std::vector<std::string> params_;

};

#endif /* DDS_SUB_DETAIL_QUERY_HPP_ */
