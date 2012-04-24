/*
 * Query.hpp
 *
 *  Created on: Jan 25, 2012
 *      Author: angelo
 */

#ifndef DDS_CORE_QUERY_HPP_
#define DDS_CORE_QUERY_HPP_

#include <dds/core/detail/Query.hpp>
#include <dds/core/TQuery.hpp>

namespace dds { namespace core {

typedef dds::core::TQuery<dds::core::detail::Query> Query;

} }


#endif /* DDS_CORE_QUERY_HPP_ */
