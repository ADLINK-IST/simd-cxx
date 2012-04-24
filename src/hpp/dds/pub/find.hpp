#ifndef OMG_DDS_PUB_FIND_HPP_
#define OMG_DDS_PUB_FIND_HPP_

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

#include <string>

#include <dds/pub/detail/find.hpp>


namespace dds { namespace pub {

template <typename WRITER, typename FwdIterator>
uint32_t
find(const dds::pub::Publisher& pub, const std::string& topic_name,
		FwdIterator begin, uint32_t max_size) {
    return ::dds::pub::detail::find<WRITER, FwdIterator>(pub,
                                                         topic_name,
                                                         begin,
                                                         max_size);
}

template <typename WRITER, typename BinIterator>
uint32_t
find(const dds::pub::Publisher& pub, const std::string& topic_name,
		BinIterator begin) {
    return ::dds::pub::detail::find<WRITER, BinIterator>(pub,
                                                         topic_name,
                                                         begin);
}


} }

#endif /* OMG_DDS_PUB_FIND_HPP_ */
