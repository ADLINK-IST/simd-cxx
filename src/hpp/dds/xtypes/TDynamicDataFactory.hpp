#ifndef OMG_DDS_DYNAMIC_DATA_FACTORY_HPP_
#define OMG_DDS_DYNAMIC_DATA_FACTORY_HPP_


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
#include <dds/core/Reference.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


template <typename DELEGATE>
class tdds::type::dynamic::DynamicDataFactory : dds::core::Reference<DELEGATE>
{
	OMG_DDS_REF_TYPE(DynamicDataFactory, dds::core::Reference, DELEGATE)

public:
    static DynamicDataFactory get_instance();

public:
    void close();
    // TODO: Why no type-param?
    dds::type::dynamic::DynamicData create_data();
};


#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

    
#endif // !defined(OMG_DDS_DYNAMIC_DATA_FACTORY_HPP_)
