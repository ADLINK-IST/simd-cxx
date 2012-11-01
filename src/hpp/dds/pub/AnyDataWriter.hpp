#ifndef OMG_DDS_PUB_ANY_DATA_WRITER_HPP_
#define OMG_DDS_PUB_ANY_DATA_WRITER_HPP_

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

#include <dds/core/macros.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/core/Exception.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/pub/detail/AnyDataWriter.hpp>

namespace dds { namespace pub {
class AnyDataWriter;
} }

/**
 * This class provides an holder for representing a generic DDS
 * <code>DataWriter</code>.
 */
class dds::pub::AnyDataWriter {
public:
    template <typename T>
    AnyDataWriter(const dds::pub::DataWriter<T>& dw)
    :    holder_(new dds::pub::detail::DWHolder<T>(dw)) { }

public:
    const dds::pub::qos::DataWriterQos& qos() const {
        return holder_->qos();
    }

    void qos(const ::dds::pub::qos::DataWriterQos& q) {
        holder_->qos(q);
    }

    const std::string& topic_name() const {
        return holder_->topic_name();
    }

    const std::string& type_name() const {
        return holder_->type_name();
    }

    const dds::pub::Publisher& publisher() const {
        return holder_->publisher();
    }

    void wait_for_acknowledgments(const dds::core::Duration& timeout) {
        holder_->wait_for_acknowledgments(timeout);
    }

    void close() {
        holder_->close();
    }

    void retain(bool b) {
        holder_->retain(b);
    }

public:
    inline AnyDataWriter&
    swap(AnyDataWriter& rhs) {
        holder_.swap(rhs.holder_);
        return *this;
    }

    template <typename T> AnyDataWriter&
    operator =(const dds::pub::DataWriter<T>& rhs) {
        holder_.reset(new detail::DWHolder<T>(rhs));
        return *this;
    }

    template <typename T>
    AnyDataWriter& operator =(const AnyDataWriter& rhs) {
        holder_ = rhs.holder_;
        return *this;
    }

    inline AnyDataWriter& operator =(AnyDataWriter rhs) {
        rhs.swap(*this);
        return *this;
    }

public:
    template <typename T>
    const dds::pub::DataWriter<T>& get() {
        OMG_DDS_STATIC_ASSERT(::dds::topic::is_topic_type<T>::value == 1);
        detail::DWHolder<T>* h = dynamic_cast<detail::DWHolder<T>* >(holder_.get());
        if (h == 0) {
            throw ::dds::core::InvalidDowncastError("invalid type");
        }
        return h->get();
    }

public:
    /**
     * Direct access to methods available on the delegate. Notice that
     * this should only be used to access proprietary extensions.
     */
    const detail::DWHolderBase* operator->() const {
        return holder_.get();
    }

    /**
     * Direct access to methods available on the delegate. Notice that
     * this should only be used to access proprietary extensions.
     */
    detail::DWHolderBase* operator->() {
        return holder_.get();
    }


private:
    dds::core::smart_ptr_traits<detail::DWHolderBase>::ref_type holder_;
};

#endif /* OMG_DDS_PUB_ANY_DATA_WRITER_HPP_ */
