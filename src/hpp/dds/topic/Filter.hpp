/*
 * Filter.hpp
 *
 *  Created on: Oct 10, 2012
 *      Author: angelo
 */

#ifndef DDS_TOPIC_FILTER_HPP_
#define DDS_TOPIC_FILTER_HPP_

#include <dds/topic/TFilter.hpp>
#include <dds/topic/detail/Filter.hpp>

namespace dds {
   namespace topic {
      typedef TFilter<detail::Filter> Filter;
   }
}


#endif /* DDS_TOPIC_FILTER_HPP_ */
