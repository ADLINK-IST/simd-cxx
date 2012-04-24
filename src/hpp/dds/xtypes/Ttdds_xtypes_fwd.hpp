#ifndef OMG_TDDS_XTYPES_XTYPES_FWD_HPP_
#define OMG_TDDS_XTYPES_XTYPES_FWD_HPP_

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

#include <dds/core/detail/conformance.hpp>
#include <dds/core/macros.hpp>

#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

namespace tdds {
    namespace type {
        // --- Built-in Types: --- //
        namespace builtin {
            // --- Keyed bytes: --- //
            template <typename DELEGATE>
            class OMG_DDS_API KeyedBytes;

            // --- Keyed string: --- //
            template <typename DELEGATE>
            class OMG_DDS_API KeyedString;
        }

        // --- Dynamic Language Binding: --- //
        namespace dynamic {
            // --- Annotation descriptor: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AnnotationDescriptor;

            // --- Dynamic data: --- //
            template <typename DELEGATE>
            class OMG_DDS_API DynamicData;

            // --- Dynamic data factory: --- //
            template <typename DELEGATE>
            class OMG_DDS_API DynamicDataFactory;
            
            // --- Dynamic type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API DynamicType;

            // --- Dynamic type factory: --- //
            template <typename DELEGATE>
            class OMG_DDS_API DynamicTypeFactory;
            
            // --- Dynamic type factory: --- //
            template <typename DELEGATE>
            class OMG_DDS_API DynamicTypeMember;

            // --- Member descriptor: --- //
            template <typename DELEGATE>
            class OMG_DDS_API MemberDescriptor;
            
            // --- Type descriptor: --- //
            template <typename DELEGATE>
            class OMG_DDS_API TypeDescriptor;
        }

        // --- Type Object Type Representation: --- //
        namespace typeobject {
            // --- Alias type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AliasType;

            // --- Annotation member value: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AnnotationMember;

            // --- Annotation member value: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AnnotationMemberValue;

            // --- Annotation type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AnnotationType;

            // --- Annotation usage: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AnnotationUsage;

            // --- Annotation usage member: --- //
            template <typename DELEGATE>
            class OMG_DDS_API AnnotationUsageMember;

            // --- Array type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API ArrayType;

            // --- Bit: --- //
            template <typename DELEGATE>
            class OMG_DDS_API Bit;

            // --- Bit set type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API BitSetType;

            // --- Collection type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API CollectionType;

            // --- Enumerated constant: --- //
            template <typename DELEGATE>
            class OMG_DDS_API EnumeratedConstant;

            // --- Enumeration type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API EnumerationType;

            // --- Map type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API MapType;

            // --- Member: --- //
            template <typename DELEGATE>
            class OMG_DDS_API Member;
            
            // --- Member property: --- //
            template <typename DELEGATE>
            class OMG_DDS_API MemberProperty;

            // --- Module: --- //
            template <typename DELEGATE>
            class OMG_DDS_API Module;

            // --- Sequence type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API SequenceType;

            // --- String type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API StringType;

            // --- Structure member: --- //
            template <typename DELEGATE>
            class OMG_DDS_API StructureMember;

            // --- Structure type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API StructureType;

            // --- Type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API Type;

            // --- Type library: --- //
            template <typename DELEGATE>
            class OMG_DDS_API TypeLibrary;

            // --- Type library element: --- //
            template <typename DELEGATE>
            class OMG_DDS_API TypeLibraryElement;

            // --- Type object: --- //
            template <typename DELEGATE>
            class OMG_DDS_API TypeObject;

            // --- Type property: --- //
            template <typename DELEGATE>
            class OMG_DDS_API TypeProperty;

            // --- Union member: --- //
            template <typename DELEGATE>
            class OMG_DDS_API UnionMember;
            
            // --- Union type: --- //
            template <typename DELEGATE>
            class OMG_DDS_API UnionType;
        }
    }
}

#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


#endif // !defined(OMG_TDDS_XTYPES_XTYPES_FWD_HPP_)
