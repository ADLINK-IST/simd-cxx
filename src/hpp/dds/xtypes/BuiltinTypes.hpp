#ifndef OMG_DDS_XTYPES_BUILTIN_TYPES_HPP_
#define OMG_DDS_XTYPES_BUILTIN_TYPES_HPP_


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

#include <dds/core/detail/conformance.hpp>
#include <dds/xtypes/dds_xtypes_fwd.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/sub/DataReader.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


// --- Keyed string: ---------------------------------------------------------

class dds::type::builtin::KeyedStringDataWriter :
    public dds::pub::DataWriter<KeyedString>
{

public:
    using dds::pub::DataWriter<KeyedString>::register_instance;
    dds::core::InstanceHandle register_instance(const std::string& key);
    dds::core::InstanceHandle
    register_instance(const std::string& key,
                      const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedString>::unregister_instance;
    void unregister_instance(const std::string& key);
    void unregister_instance(const std::string& key,
                             const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedString>::write;
    void write(const std::string& key,
               const std::string& str);
    void write(const std::string& key,
               const std::string& str,
               const dds::core::InstanceHandle& handle);
    void write(const std::string& key,
               const std::string& str,
               const dds::core::InstanceHandle& handle,
               const dds::core::Time& source_timestamp);

    void dispose(const std::string& key);
    void dispose(const std::string& key,
                 const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedString>::key_value;
    const std::string key_value(const dds::core::InstanceHandle& handle);
    
    using dds::pub::DataWriter<KeyedString>::lookup_instance;
    const dds::core::InstanceHandle lookup_instance(const std::string& key);
};


class dds::type::builtin::KeyedStringDataReader :
    public dds::sub::DataReader<KeyedString>
{

};


// --- Bytes: ----------------------------------------------------------------

class dds::type::builtin::BytesDataWriter :
    public dds::pub::DataWriter<dds::core::ByteSeq>
{

public:
    using dds::pub::DataWriter<dds::core::ByteSeq>::write;
    template <typename RNDA_ITER>
    void write(RNDA_ITER begin,
               RNDA_ITER end);
    template <typename RNDA_ITER>
    void write(RNDA_ITER begin,
               RNDA_ITER end,
               const dds::core::InstanceHandle& handle);
    template <typename RNDA_ITER>
    void write(RNDA_ITER begin,
               RNDA_ITER end,
               const dds::core::InstanceHandle& handle,
               const dds::core::Time& source_timestamp);
};


class dds::type::builtin::BytesDataReader :
    public dds::sub::DataReader<dds::core::ByteSeq>
{ };


// --- Keyed bytes: ----------------------------------------------------------

class dds::type::builtin::KeyedBytesDataWriter :
    public dds::pub::DataWriter<KeyedBytes>
{

public:
    using dds::pub::DataWriter<KeyedBytes>::register_instance;
    const dds::core::InstanceHandle register_instance(const std::string& key);
    const dds::core::InstanceHandle
    register_instance(const std::string& key,
                      const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedBytes>::unregister_instance;
    void unregister_instance(const std::string& key);
    void unregister_instance(const std::string& key,
                             const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedBytes>::write;
    template <typename RNDA_ITER>
    void write(const std::string& key,
               RNDA_ITER value_begin,
               RNDA_ITER value_end);
    template <typename RNDA_ITER>
    void write(const std::string& key,
               RNDA_ITER value_begin,
               RNDA_ITER value_end,
               const dds::core::InstanceHandle& handle);
    template <typename RNDA_ITER>
    void write(const std::string& key,
               RNDA_ITER value_begin,
               RNDA_ITER value_end,
               const dds::core::InstanceHandle& handle,
               const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedBytes>::dispose_instance;
    void dispose(const std::string& key);
    void dispose(const std::string& key,
                 const dds::core::Time& source_timestamp);

    using dds::pub::DataWriter<KeyedBytes>::key_value;
    const std::string key_value(const dds::core::InstanceHandle& handle);

    using dds::pub::DataWriter<KeyedBytes>::lookup_instance;
    const dds::core::InstanceHandle lookup_instance(const std::string& key);
};


class dds::type::builtin::KeyedBytesDataReader :
    public dds::sub::DataReader<KeyedBytes>
{ };


#endif  // defined(OMG_DDS_XTYPES_BUILTIN_TYPES_HPP_)


#endif // !defined(OMG_DDS_BUILTIN_TYPES_HPP_)
