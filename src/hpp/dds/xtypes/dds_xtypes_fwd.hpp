#ifndef OMG_DDS_XTYPES_FWD_HPP_
#define OMG_DDS_XTYPES_FWD_HPP_


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
#include <map>
#include <vector>
#include <dds/core/corefwd.hpp>
#include <dds/core/macros.hpp>
#include <tdds/xtypes/tdds_xtypes_fwd.hpp>
#include <dds/pub/pubfwd.hpp>
#include <dds/sub/subfwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

namespace dds { namespace type {

namespace builtin { namespace detail {
	class KeyedBytes;
	class KeyedString;
} }

namespace dynamic { namespace detail {
	class AnnotationDescription;
	class DynamicData;
	class DynamicDataFactory;
	class DynamicType;
	class DynamicTypeFactory;
	class DynamicTypeMember;
	class MemberDescriptor;
	class TypeDescriptor;
} }
namespace typeobject { namespace detail {
	class AliasType;
	class AnnotationMember;
	class AnnotationMemberValue;
	class AnnotationType;
	class AnnotationUsage;
	class AnnotationUsageMember;
	class ArrayType;
	class Bit;
	class BitSetType;
	class EnumeratedConstant;
	class EnumerationType;
	class MapType;
	class MemberProperty;
	class Module;
	class SequenceType;
	class StringType;
	class StructureMember;
	class StructureType;
	class TypeLibrary;
	class TypeLibraryElement;
	class TypeObject;
	class TypeProperty;
	class UnionMember;
	class UnionType;

} } } }


namespace dds {
    namespace type {
//        enum TypeKind;

        // --- Bound: --- //
        /** Bound of a collection type */
        typedef unsigned long Bound;

        typedef std::vector<Bound> BoundSeq;

        const Bound UNBOUNDED_COLLECTION = 0;

        // --- Member ID: --- //
        /** ID of a type member */
        typedef unsigned long MemberId;

        // --- Union case label sequence: --- //
        /** Case labels that apply to a member of a union type */
        typedef std::vector<int32_t> UnionCaseLabelSeq;

        // --- Built-in Types: --- //
        namespace builtin {
            // --- Bytes: --- //
            class BytesDataReader;
            class BytesDataWriter;

            // --- String: --- //
            typedef dds::sub::DataReader<std::string> StringDataReader;
            typedef dds::pub::DataWriter<std::string> StringDataWriter;

            // --- Keyed bytes: --- //
            typedef tdds::type::builtin::KeyedBytes<dds::type::builtin::detail::KeyedBytes>
            KeyedBytes;

            class OMG_DDS_API KeyedBytesDataReader;
            class OMG_DDS_API KeyedBytesDataWriter;

            // --- Keyed string: --- //
            typedef tdds::type::builtin::KeyedString<dds::type::builtin::detail::KeyedString>
            KeyedString;

            class OMG_DDS_API KeyedStringDataReader;
            class OMG_DDS_API KeyedStringDataWriter;
        }

        // --- Dynamic Language Binding: --- //
        namespace dynamic {
            // --- Annotation descriptor: --- //
            typedef tdds::type::dynamic::AnnotationDescriptor<dds::type::dynamic::detail::AnnotationDescription>
            AnnotationDescriptor;

            typedef std::vector<AnnotationDescriptor> AnnotationDescriptorSeq;

            // --- Dynamic data: --- //
            typedef tdds::type::dynamic::DynamicData<dds::type::dynamic::detail::DynamicData>
            DynamicData;

            // --- Dynamic data factory: --- //
            typedef tdds::type::dynamic::DynamicDataFactory<dds::type::dynamic::detail::DynamicDataFactory>
            DynamicDataFactory;

            // --- Dynamic type: --- //
            typedef tdds::type::dynamic::DynamicType<dds::type::dynamic::detail::DynamicType>
            DynamicType;

            // --- Dynamic type factory: --- //
            typedef tdds::type::dynamic::DynamicTypeFactory<dds::type::dynamic::detail::DynamicTypeFactory>
            DynamicTypeFactory;

            // --- Dynamic type member: --- //
            typedef tdds::type::dynamic::DynamicTypeMember<dds::type::dynamic::detail::DynamicTypeMember>
            DynamicTypeMember;

            typedef std::map<std::string, DynamicTypeMember>
            DynamicTypeMembersByName;

            typedef std::map<dds::type::MemberId, DynamicTypeMember>  
            DynamicTypeMembersById;

            // --- Include path sequence: --- //
            typedef std::vector<std::string> IncludePathSeq;
            
            // --- Member descriptor: --- //
            typedef tdds::type::dynamic::MemberDescriptor<dds::type::dynamic::detail::MemberDescriptor>
            MemberDescriptor;
            
            // --- Parameters: --- //
            typedef std::map<std::string, std::string> Parameters;

            // --- Type descriptor: --- //
            typedef tdds::type::dynamic::TypeDescriptor<dds::type::dynamic::detail::TypeDescriptor>
            TypeDescriptor;
        }

        // --- Type Object Type Representation: --- //
        namespace typeobject {
            // --- Alias type: --- //
            typedef tdds::type::typeobject::AliasType<dds::type::typeobject::detail::AliasType>
            AliasType;

            // --- Annotation member: --- //
            typedef tdds::type::typeobject::AnnotationMember<dds::type::typeobject::detail::AnnotationMember>
            AnnotationMember;

            typedef std::vector<AnnotationMember> AnnotationMemberSeq;

            // --- Annotation member value: --- //
            typedef tdds::type::typeobject::AnnotationMemberValue<dds::type::typeobject::detail::AnnotationMemberValue>
            AnnotationMemberValue;

            // --- Annotation type: --- //
            typedef tdds::type::typeobject::AnnotationType<dds::type::typeobject::detail::AnnotationType>
            AnnotationType;
            
            // --- Annotation usage: --- //
            typedef tdds::type::typeobject::AnnotationUsage<dds::type::typeobject::detail::AnnotationUsage>
            AnnotationUsage;

            typedef std::vector<AnnotationUsage> AnnotationUsageSeq;

            // --- Annotation usage member: --- //
            typedef tdds::type::typeobject::AnnotationUsageMember<dds::type::typeobject::detail::AnnotationUsageMember>
            AnnotationUsageMember;

            typedef std::vector<AnnotationUsageMember> AnnotationUsageMemberSeq;

            // --- Array type: --- //
            typedef tdds::type::typeobject::ArrayType<dds::type::typeobject::detail::ArrayType>
            ArrayType;

            // --- Bit: --- //
            typedef tdds::type::typeobject::Bit<dds::type::typeobject::detail::Bit> Bit;

            typedef std::vector<Bit> BitSeq;

            // --- Bit set type: --- //
            typedef tdds::type::typeobject::BitSetType<dds::type::typeobject::detail::BitSetType>
            BitSetType;

            // --- Enumerated constant: --- //
            typedef tdds::type::typeobject::EnumeratedConstant<dds::type::typeobject::detail::EnumeratedConstant>
            EnumeratedConstant;

            typedef std::vector<EnumeratedConstant> EnumeratedConstantSeq;

            // --- Enumeration type: --- //
            typedef tdds::type::typeobject::EnumerationType< dds::type::typeobject::detail::EnumerationType>
            EnumerationType;
            
            // --- Map type: --- //
            typedef tdds::type::typeobject::MapType<dds::type::typeobject::detail::MapType>
            MapType;

            // --- Member property: --- //
            typedef tdds::type::typeobject::MemberProperty<dds::type::typeobject::detail::MemberProperty>
            MemberProperty;

            // --- Module: --- //
            typedef tdds::type::typeobject::Module<dds::type::typeobject::detail::Module>
            Module;

            // --- Sequence type: --- //
            typedef tdds::type::typeobject::SequenceType<dds::type::typeobject::detail::SequenceType>
            SequenceType;

            // --- String type: --- //
            typedef tdds::type::typeobject::StringType<dds::type::typeobject::detail::StringType>
            StringType;

            // --- Structure member: --- //
            typedef tdds::type::typeobject::StructureMember<dds::type::typeobject::detail::StructureMember>
            StructureMember;

            typedef std::vector<StructureMember> StructureMemberSeq;

            // --- Structure type: --- //
            typedef tdds::type::typeobject::StructureType<dds::type::typeobject::detail::StructureType>
            StructureType;

            // --- Type ID --- //
            typedef long TypeId;

            // --- Type library: --- //
            typedef tdds::type::typeobject::TypeLibrary<dds::type::typeobject::detail::TypeLibrary>
            TypeLibrary;

            // --- Type library element: --- //
            typedef tdds::type::typeobject::TypeLibraryElement<dds::type::typeobject::detail::TypeLibraryElement>
            TypeLibraryElement;

            typedef std::vector<TypeLibraryElement> TypeLibraryElementSeq;

            // --- Type library: --- //
            typedef tdds::type::typeobject::TypeObject<dds::type::typeobject::detail::TypeObject>
            TypeObject;

            // --- Type property: --- //
            typedef tdds::type::typeobject::TypeProperty<dds::type::typeobject::detail::TypeProperty>
            TypeProperty;

            // --- Union member: --- //
            typedef tdds::type::typeobject::UnionMember<dds::type::typeobject::detail::UnionMember>
            UnionMember;
            
            typedef std::vector<UnionMember> UnionMemberSeq;

            // --- Union type: --- //
            typedef tdds::type::typeobject::UnionType<dds::type::typeobject::detail::UnionType>
            UnionType;

        }
    }
}

#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


#endif // !defined(OMG_DDS_XTYPES_FWD_HPP_)
