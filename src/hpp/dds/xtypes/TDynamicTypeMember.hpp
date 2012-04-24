#ifndef OMG_DDS_XTYPES_DYNAMIC_TYPE_MEMBER_HPP_
#define OMG_DDS_XTYPES_DYNAMIC_TYPE_MEMBER_HPP_


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
class tdds::type::dynamic::DynamicTypeMember : dds::core::Reference<DELEGATE>
{
	OMG_DDS_REF_TYPE(DynamicTypeMember, dds::core::Reference, DELEGATE)

public:
    dds::type::dynamic::MemberDescriptor descriptor() const;
    void descriptor(const dds::type::dynamic::MemberDescriptor& value);

    const dds::type::dynamic::AnnotationDescriptorSeq annotation() const;
    dds::type::dynamic::AnnotationDescriptorSeq&
    annotation(dds::type::dynamic::AnnotationDescriptorSeq& dst) const;

    void apply_annotation(
        const dds::type::dynamic::AnnotationDescriptor& descriptor);

    /**
     * Synonym for apply_annotation.
     */
    DynamicTypeMember& operator+=(
        const dds::type::dynamic::AnnotationDescriptor& descriptor);

    dds::type::MemberId id() const;

    const std::string name() const;

    /**
     * Test for "deep" equality: does the given type member have the same
     * state as this one?
     */
    bool equals(DynamicTypeMember other);

public:
    void close();
};


#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)


#endif // !defined(OMG_DDS_XTYPES_DYNAMIC_TYPE_MEMBER_HPP_)
