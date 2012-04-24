#ifndef OMG_DDS_DYNAMIC_TYPE_FACTORY_HPP_
#define OMG_DDS_DYNAMIC_TYPE_FACTORY_HPP_


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
#include <dds/core/Reference.hpp>
#include <tdds/xtypes/tdds_xtypes_fwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


template <typename DELEGATE>
class tdds::type::dynamic::DynamicTypeFactory : dds::core::Reference<DELEGATE>
{
	OMG_DDS_REF_TYPE(DynamicTypeFactory, dds::core::Reference, DELEGATE)

public:
    static DynamicTypeFactory get_instance();

public:
    void close();

public:
    dds::type::dynamic::DynamicType
    primitive_type(dds::type::TypeKind kind) const;

    dds::type::dynamic::DynamicType
    type(const dds::type::dynamic::TypeDescriptor& descriptor);

    dds::type::dynamic::DynamicType
    string_type(dds::type::Bound bound);

    dds::type::dynamic::DynamicType
    wstring_type(dds::type::Bound bound);

    dds::type::dynamic::DynamicType
    sequence_type(
        const dds::type::dynamic::DynamicType& element_type,
        dds::type::Bound bound);

    dds::type::dynamic::DynamicType array_type(
        const dds::type::dynamic::DynamicType& element_type,
        const dds::type::BoundSeq& bound);

    dds::type::dynamic::DynamicType map_type(
        const dds::type::dynamic::DynamicType& key_element_type,
        const dds::type::dynamic::DynamicType& element_type,
        dds::type::Bound bound);

    dds::type::dynamic::DynamicType
    bitset_type(dds::type::Bound bound);

public:
    dds::type::dynamic::DynamicType load_type_from_url(
        const std::string& document_url,
        const std::string& type_name,
        const dds::type::dynamic::IncludePathSeq& include_paths);

    dds::type::dynamic::DynamicType load_type_from_document(
        const std::string& document,
        const std::string& type_name,
        const dds::type::dynamic::IncludePathSeq& include_paths);
};


#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)


#endif // !defined(OMG_DDS_DYNAMIC_TYPE_FACTORY_HPP_)
