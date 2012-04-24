#ifndef OMG_DDS_DYNAMIC_TYPE_HPP_
#define OMG_DDS_DYNAMIC_TYPE_HPP_


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
#include <dds/core/Value.hpp>
#include <tdds/xtypes/tdds_xtypes_fwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


template <typename DELEGATE>
class tdds::type::dynamic::DynamicType : public dds::core::Value<DELEGATE> {

public:
    const dds::type::dynamic::TypeDescriptor descriptor() const;
    void descriptor(const dds::type::dynamic::TypeDescriptor& value);

    const std::string name() const;

    dds::type::TypeKind kind() const;

    dds::type::dynamic::DynamicTypeMember
    member(const std::string& name) const;

    const dds::type::dynamic::DynamicTypeMembersByName
    all_members_by_name() const;

    dds::type::dynamic::DynamicTypeMembersByName&
    all_members_by_name(dds::type::dynamic::DynamicTypeMembersByName& dst);
    
    dds::type::dynamic::DynamicTypeMember
    member(dds::type::MemberId id);

    const dds::type::dynamic::DynamicTypeMembersById
    all_members_by_id() const;

    dds::type::dynamic::DynamicTypeMembersById&
    all_members_by_id(dds::type::dynamic::DynamicTypeMembersById& value)
    const;

    const dds::type::dynamic::AnnotationDescriptorSeq annotation() const;
    dds::type::dynamic::AnnotationDescriptorSeq&
    annotation(dds::type::dynamic::AnnotationDescriptorSeq& dst) const;
    
    void apply_annotation(
        const dds::type::dynamic::AnnotationDescriptor& descriptor);

    /**
     * Synonym for apply_annotation.
     */
    DynamicType& operator+=(
        const dds::type::dynamic::AnnotationDescriptor& descriptor);

    /**
     * @return  the new member
     */
    dds::type::dynamic::DynamicTypeMember
    add_member(const dds::type::dynamic::MemberDescriptor& descriptor);

    /**
     * Synonym for add_member.
     */
    DynamicType&
    operator+=(const dds::type::dynamic::MemberDescriptor& descriptor);
};


#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)


#endif // !defined(OMG_DDS_DYNAMIC_TYPE_HPP_)
