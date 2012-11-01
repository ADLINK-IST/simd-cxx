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


namespace dds { namespace sub { namespace detail {

template <typename T>
class Sample {
public:
   Sample() { }

   Sample(const T& d, const SampleInfo& i)
   : data_(d), info_(i) { }

   Sample(const Sample& other) : data_(other.data()), info_(other.info_) { }

public:
    const T& data() const {
        return data_;
    }

    void data(const T& d) {
       data_ = d;
    }

    const SampleInfo& info() const {
        return info_;
    }
    void info(const SampleInfo& i) {
       info_ = i;
    }

private:
    T data_;
    SampleInfo info_;
};

} } }


#endif /* OMG_DDS_PUB_DETAIL_SAMPLE_HPP_ */
