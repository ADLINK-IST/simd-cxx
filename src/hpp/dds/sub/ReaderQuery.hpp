#ifndef OMG_DDS_SUB_READER_QUERY_HPP_
#define OMG_DDS_SUB_READER_QUERY_HPP_

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

#include <dds/core/InstanceHandle.hpp>

namespace dds { namespace sub {

/**
 * A ReaderQuery encapsulates the various ways that an application can
 * search for data to read or take from a DataReader.
 */
template <typename T>
class ReaderQuery {
    // --- Type Aliases: --- //
public:
    typedef ::dds::sub::cond::ReadCondition<T> ReadCondition;

    // --- Default Construction & Destruction: --- //
public:
    ReaderQuery()
    : instance_(), read_or_take_next_(false),
      reader_state_(dds::sub::status::ReaderState::any()),
      condition_()
    { }

    ~ReaderQuery() { }

    // --- Copy: --- //
public:
    ReaderQuery(const ReaderQuery& src)
    : instance_(src.instance()),
      read_or_take_next_(src.read_or_take_next_),
      reader_state_(src.reader_state_),
      condition_(src.condition_)
    { }

    ReaderQuery& operator =(const ReaderQuery& src) {
        instance_ = src.instance();
        read_or_take_next_ = src.read_or_take_next_;
        reader_state_ = src.reader_state_;
        condition_ = src.condition_;
        return *this;
    }

    // --- Conversion: --- //
public:
    /**
     * Construct a query to read or take samples of all available instances
     * that have the given ReaderState.
     */
    /* implicit */ ReaderQuery(const ::dds::sub::status::ReaderState& src)
    : instance_(),
      read_or_take_next_(false),
      reader_state_(src),
      condition_()
    { }

    /**
     * Construct a query to read or take samples of all available instances,
     * the availability of which would cause the given ReadCondition or
     * QueryCondition to trigger.
     */
    /* implicit */ ReaderQuery(const ReadCondition& src)
    : instance_(),
      read_or_take_next_(false),
      reader_state_(src.reader_state()),
      condition_(src)
    { }

    /**
     * Construct a query to read or take samples of the identified instance
     * (or the "next" instance), regardless of ReaderState.
     *
     * @param read_or_take_next If this flag is set to false (the default),
     *                          the read or take will return samples of the
     *                          identified instance. If it is true, the read
     *                          or take will return samples of the "next"
     *                          instance in order. This behavior allows
     *                          applications to easily iterate over the
     *                          available data one instance at a time.
     */
    /* implicit */ ReaderQuery(const ::dds::core::InstanceHandle& src,
                               bool read_or_take_next = false)
    : instance_(src),
      read_or_take_next_(read_or_take_next),
      reader_state_(dds::sub::status::ReaderState::any()),
      condition_()
    { }

    /**
     * Construct a query to read or take samples of the identified instance
     * (or the "next" instance) and with the given ReaderState.
     *
     * @param read_or_take_next If this flag is set to false (the default),
     *                          the read or take will return samples of the
     *                          identified instance. If it is true, the read
     *                          or take will return samples of the "next"
     *                          instance in order. This behavior allows
     *                          applications to easily iterate over the
     *                          available data one instance at a time.
     */
    ReaderQuery(const ::dds::sub::status::ReaderState& state,
                const ::dds::core::InstanceHandle& handle,
                bool read_or_take_next = false)
    : instance_(handle),
      read_or_take_next_(read_or_take_next),
      reader_state_(state),
      condition_()
    { }

    /**
     * Construct a query to read or take samples of the identified instance,
     * the availability of which would cause the given ReadCondition or
     * QueryCondition to trigger.
     *
     * @param read_or_take_next If this flag is set to false (the default),
     *                          the read or take will return samples of the
     *                          identified instance. If it is true, the read
     *                          or take will return samples of the "next"
     *                          instance in order. This behavior allows
     *                          applications to easily iterate over the
     *                          available data one instance at a time.
     */
    ReaderQuery(const ReadCondition& cond,
                const ::dds::core::InstanceHandle& handle,
                bool read_or_take_next = false)
    : instance_(handle),
      read_or_take_next_(read_or_take_next),
      reader_state_(cond.reader_state()),
      condition_(cond)
    { }

    // --- Query Access: --- //
public:
    /**
     * If this method returns a non-nil handle, the application intends to
     * read or take only those samples pertaining to the given instance (or
     * the "next" instance). If it returns a nil handle, the application
     * intends to read or take samples pertaining to all available instances.
     */
    const dds::core::InstanceHandle instance() const {
        return instance_;
    }

    /**
     * If this flag is set to false, the read or take will return samples of
     * the identified instance. If it is true, the read or take will return
     * samples of the "next" instance in order. This behavior allows
     * applications to easily iterate over the available data one instance at
     * a time.
     */
    bool is_read_or_take_next() const {
        return read_or_take_next_;
    }

    /**
     * The application intends to read or take only those samples with the
     * given ReaderState.
     *
     * If this ReaderQuery was initialized with a ReadCondition or
     * QueryCondition, this method shall return the ReaderState associated
     * with that condition.
     */
    const dds::sub::status::ReaderState reader_state() const {
        return reader_state_;
    }

    /**
     * The application intends only to read or take those samples, the
     * availability of which would cause the given ReadCondition or
     * QueryCondition to trigger.
     */
    ReadCondition condition() const {
        return condition_;
    }

private:
    dds::core::InstanceHandle instance_;
    bool read_or_take_next_;
    dds::sub::status::ReaderState reader_state_;
    ReadCondition condition_;
};

} }

#endif /* OMG_DDS_SUB_READER_QUERY_HPP_ */
