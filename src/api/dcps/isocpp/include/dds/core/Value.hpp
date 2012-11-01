#ifndef OMG_DDS_CORE_VALUE_HPP_
#define OMG_DDS_CORE_VALUE_HPP_

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


namespace dds { namespace core {

/**
 * This class provides the basic behavior for Value types.
 */
template <typename D>
class Value {
protected:
    Value() { }
    Value(const Value& p) : d_(p.d_) { }

public:
    template <typename ARG>
    Value(const ARG& arg) : d_(arg) { }

    // -- We can't assume that the compiler supports variadic templates,
    // -- `yet. this code should be refactored to take advantage of compier that
    // -- do support variadic templates.
    template <typename ARG1, typename ARG2>
    Value(const ARG1& arg1, const ARG2& arg2) : d_(arg1, arg2) { }

    template <typename ARG1, typename ARG2, typename ARG3>
    Value(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3)
    : d_(arg1, arg2, arg3) { }

    template <typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    Value(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4)
    : d_(arg1, arg2, arg3, arg4) { }

    template <typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
    Value(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5)
    : d_(arg1, arg2, arg3, arg4, arg5) { }

    template <typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
    Value(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5, const ARG6& arg6)
    : d_(arg1, arg2, arg3, arg4, arg5, arg6) { }

public:
    ~Value() { }

public:
    Value& operator=(const Value& other) {
        if (this != &other) {
            d_ = other.d_;
        }
        return *this;
    }

    bool operator==(const Value& other) const {
        return (d_ == other.d_);
    }

    bool operator !=(const Value& other) const {
        return !(d_ == other.d_);
    }

public:
    const D* operator->() const { return &d_; }
    D* operator->() { return &d_; }

    const D& delegate() const { return d_; }
    D& delegate() { return d_;}

protected:
    D d_;
};

} } /* dds / core */

#endif /* OMG_DDS_CORE_VALUE_HPP_ */
