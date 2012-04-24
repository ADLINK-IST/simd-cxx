#ifndef OMG_DDS_PUB_DETAIL_SAMPLE_HPP_
#define OMG_DDS_PUB_DETAIL_SAMPLE_HPP_

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

#include <dds/core/Exception.hpp>
#include <dds/core/Time.hpp>
#include <dds/sub/status/DataStatus.hpp>


namespace dds { namespace sub { namespace detail {

template <typename T>
class Sample {
public:
    const T& data() const {
        throw dds::core::InvalidDataError("sample has no valid data");
    }

    const SampleInfo& info() const {
        return info_;
    }
    
private:
    SampleInfo info_;
};

} } }


#endif /* OMG_DDS_PUB_DETAIL_SAMPLE_HPP_ */
