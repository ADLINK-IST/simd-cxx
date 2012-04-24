#ifndef OMG_DDS_TYPE_OBJECT_HPP_
#define OMG_DDS_TYPE_OBJECT_HPP_

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

#include <bitset>

#include <dds/core/detail/conformance.hpp>
#include <dds/xtypes/dds_xtypes_fwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


// --- Shared meta-data: -------------------------------------------------

namespace dds {
    namespace type {
        enum TypeKind
        {
            NO_TYPE          =  0, // sentinel indicating "null" value
            
            BOOLEAN_TYPE     =  1,
            BYTE_TYPE        =  2,
            INT_16_TYPE      =  3,
            UINT_16_TYPE     =  4,
            INT_32_TYPE      =  5,
            UINT_32_TYPE     =  6,
            INT_64_TYPE      =  7,
            UINT_64_TYPE     =  8,
            FLOAT_32_TYPE    =  9,
            FLOAT_64_TYPE    = 10,
            FLOAT_128_TYPE   = 11,
            CHAR_8_TYPE      = 12,
            CHAR_32_TYPE     = 13,
            
            ENUMERATION_TYPE = 14,
            BITSET_TYPE      = 15,
            ALIAS_TYPE       = 16,
            
            ARRAY_TYPE       = 17,
            SEQUENCE_TYPE    = 18,
            STRING_TYPE      = 19,
            MAP_TYPE         = 20,
            
            UNION_TYPE       = 21,
            STRUCTURE_TYPE   = 22,
            ANNOTATION_TYPE  = 23
        };
        
        namespace typeobject {
            // --- Type ID --- //
            const TypeId NO_TYPE_ID         = NO_TYPE;
            const TypeId BOOLEAN_TYPE_ID    = BOOLEAN_TYPE;
            const TypeId BYTE_TYPE_ID       = BYTE_TYPE;
            const TypeId INT_16_TYPE_ID     = INT_16_TYPE;
            const TypeId UINT_16_TYPE_ID    = UINT_16_TYPE;
            const TypeId INT_32_TYPE_ID     = INT_32_TYPE;
            const TypeId UINT_32_TYPE_ID    = UINT_32_TYPE;
            const TypeId INT_64_TYPE_ID     = INT_64_TYPE;
            const TypeId UINT_64_TYPE_ID    = UINT_64_TYPE;
            const TypeId FLOAT_32_TYPE_ID   = FLOAT_32_TYPE;
            const TypeId FLOAT_64_TYPE_ID   = FLOAT_64_TYPE;
            const TypeId FLOAT_128_TYPE_ID  = FLOAT_128_TYPE;
            const TypeId CHAR_8_TYPE_ID     = CHAR_8_TYPE;
            const TypeId CHAR_32_TYPE_ID    = CHAR_32_TYPE;
            
            // --- Member ID --- //
            const MemberId MEMBER_ID_INVALID = 0x0FFFFFFF;
        }
    }
}


// --- Type base class: --------------------------------------------------

/**
 * Flags that apply to type definitions
 */
namespace dds {
    namespace type {
        namespace typeobject {
            namespace TypeFlag {
                enum Bits
                {
                    IS_FINAL    = (0x0001 << 0),    // | can't both
                    IS_MUTABLE  = (0x0001 << 1),    // | be '1'
                    IS_NESTED   = (0x0001 << 2)
                };
                
                typedef std::bitset<16> Mask;
            }
        }
    }
}


// --- Aggregations: -----------------------------------------------------

/**
 * Flags that apply to aggregation type members
 */
namespace dds {
    namespace type {
        namespace typeobject {
            namespace MemberFlag {
                enum Bits
                {
                    IS_KEY           = (0x0001 << 0),
                    IS_OPTIONAL      = (0x0001 << 1),
                    IS_SHAREABLE     = (0x0001 << 2),
                    /** Set if member is union default case */
                    IS_UNION_DEFAULT = (0x0001 << 3)
                };
                
                typedef std::bitset<16> Mask;
            }
        }
    }
}


#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


#endif // !defined(OMG_DDS_TYPE_OBJECT_HPP_)
