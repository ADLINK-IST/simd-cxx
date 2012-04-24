#ifndef OMG_DDS_SUB_ANY_DATA_READER_HPP_
#define OMG_DDS_SUB_ANY_DATA_READER_HPP_

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
#include <dds/core/ref_traits.hpp>
#include <dds/sub/detail/AnyDataReader.hpp>


namespace dds { namespace sub {
class AnyDataReader {
public:
    template <typename T>
    AnyDataReader(const dds::sub::DataReader<T>& dr)
    : holder_ (new detail::DRHolder<T>(dr)) { }

    inline const detail::DRHolderBase* operator->() const {
        return holder_.get();
    }

    inline detail::DRHolderBase* operator->() {
        return holder_.get();
    }


public:
    inline AnyDataReader& swap(AnyDataReader& rhs) {
        holder_.swap(holder_);
        return *this;
    }

    template <typename T>
    AnyDataReader& operator =(const DataReader<T>& rhs) {
        holder_.reset(new detail::DRHolder<T>(rhs));
        return *this;
    }

    inline AnyDataReader& operator =(AnyDataReader rhs) {
    	if (this != &rhs)
    		holder_ = rhs.holder_;

        return *this;
    }

public:
    template <typename T>
    const dds::sub::DataReader<T>& get() {
    	OMG_DDS_STATIC_ASSERT(::dds::topic::is_topic_type<T>::value == 1);
        detail::DRHolder<T>* h = dynamic_cast<detail::DRHolder<T>* >(holder_.get());
        if (h == 0) {
            throw dds::core::InvalidDowncastError("invalid type");
        }
        return h->get();
    }
private:
    dds::core::smart_ptr_traits<detail::DRHolderBase>::ref_type holder_;
};

}}

#endif /* OMG_DDS_SUB_ANY_DATA_READER_HPP_ */
