#ifndef OMG_DDS_DESCRIPTOR_HPP_
#define OMG_DDS_DESCRIPTOR_HPP_


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


template <typename DELEGATE>
class tdds::type::dynamic::AnnotationDescriptor : public dds::core::Value<DELEGATE>
{

public:
    dds::type::dynamic::DynamicType type() const;
    void type(const dds::type::dynamic::DynamicType& value);

    const std::string value(const std::string& key);

    const dds::type::dynamic::Parameters all_values() const;

    dds::type::dynamic::Parameters&
    all_values(dds::type::dynamic::Parameters& dst) const;

    void value(const std::string& key, const std::string& value);

    bool is_consistent() const;
};


template <typename DELEGATE>
class tdds::type::dynamic::MemberDescriptor : public dds::core::Value<DELEGATE>
{

public:
    const std::string name() const;
    void name(const std::string& value);

    dds::type::MemberId id() const;
    void id(dds::type::MemberId value);

    dds::type::dynamic::DynamicType type() const;
    void type(const dds::type::dynamic::DynamicType& value);

    const std::string default_value() const;
    void default_value(const std::string& value);

    uint32_t index() const;
    void index(uint32_t value);

    const dds::type::UnionCaseLabelSeq label() const;

    dds::type::UnionCaseLabelSeq&
    label(dds::type::UnionCaseLabelSeq& dst) const;

    void label(const dds::type::UnionCaseLabelSeq& value);

    bool default_label();
    void default_label(bool value);

    bool is_consistent();
};


template <typename DELEGATE>
class tdds::type::dynamic::TypeDescriptor : public dds::core::Value<DELEGATE>
{

public:
    dds::type::TypeKind kind() const;
    void kind(dds::type::TypeKind value);

    const std::string name() const;
    void name(const std::string& value);

    dds::type::dynamic::DynamicType base_type() const;
    void base_type(const dds::type::dynamic::DynamicType& value);

    dds::type::dynamic::DynamicType discriminator_type() const;
    void discriminator_type(const dds::type::dynamic::DynamicType& value);

    const dds::type::BoundSeq bound() const;
    dds::type::BoundSeq& bound(dds::type::BoundSeq& dst) const;
    void bound(const dds::type::BoundSeq& value);

    dds::type::dynamic::DynamicType element_type() const;
    void element_type(const dds::type::dynamic::DynamicType& value);

    dds::type::dynamic::DynamicType key_element_type() const;
    void key_element_type(const dds::type::dynamic::DynamicType& value);

    bool is_consistent() const;
};


#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


#endif // !defined(OMG_DDS_DESCRIPTOR_HPP_)
