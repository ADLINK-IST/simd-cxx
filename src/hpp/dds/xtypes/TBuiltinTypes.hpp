#ifndef OMG_TDDS_XYPES_BUILTIN_TYPES_HPP_
#define OMG_TDDS_XYPES_BUILTIN_TYPES_HPP_


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

#include <dds/core/corefwd.hpp>
#include <dds/core/Value.hpp>
#include <tdds/xtypes/tdds_xtypes_fwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


// --- Keyed string: ---------------------------------------------------------

template <typename DELEGATE>
class tdds::type::builtin::KeyedString : public dds::core::Value<DELEGATE> {
public:
    KeyedString(const std::string& key, const std::string& value);

public:
    const std::string key() const;
    void key(const std::string& value);

    const std::string value() const;
    void value(const std::string& value);
};


// --- Keyed bytes: ----------------------------------------------------------

template <typename DELEGATE>
class tdds::type::builtin::KeyedBytes : public dds::core::Value<DELEGATE> {

public:
    template <typename RNDA_ITER>
    KeyedBytes(const std::string& key,
               RNDA_ITER value_begin,
               RNDA_ITER value_end);

public:
    const std::string key() const;
    void key(const std::string& value);

    uint8_t* value_begin();
    uint8_t* value_end();
};


#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)


#endif // !defined(OMG_TDDS_XYPES_BUILTIN_TYPES_HPP_)
