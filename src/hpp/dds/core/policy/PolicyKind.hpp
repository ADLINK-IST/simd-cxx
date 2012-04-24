#ifndef OMG_DDS_CORE_POLICY_POLICYKIND_HPP_
#define OMG_DDS_CORE_POLICY_POLICYKIND_HPP_

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


namespace dds { namespace core { namespace policy {

namespace OwnershipKind {
enum Type {
	SHARED

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
	,
	EXCLUSIVE
#endif  // OMG_DDS_OWNERSHIP_SUPPORT
}; }



namespace DurabilityKind {
enum Type {
	VOLATILE,
	TRANSIENT_LOCAL

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
	,
	TRANSIENT,
	PERSISTENT
#endif  // #ifdef  OMG_DDS_PERSISTENCE_SUPPORT
}; }

namespace PresentationAccessScopeKind  {
enum Type {
	INSTANCE,
	TOPIC

#ifdef  OMG_DDS_OBJECT_MODEL_SUPPORT
	,
	GROUP
#endif  // OMG_DDS_OBJECT_MODEL_SUPPORT
}; }
namespace ReliabilityKind {
enum Type {
	BEST_EFFORT,
	RELIABLE
}; }

namespace DestinationOrderKind {
enum Type {
	BY_RECEPTION_TIMESTAMP,
	BY_SOURCE_TIMESTAMP
}; }

namespace HistoryKind {
enum Type {
	KEEP_LAST,
	KEEP_ALL
};}

namespace LivelinessKind {
enum Type {
	AUTOMATIC,
	MANUAL_BY_PARTICIPANT,
	MANUAL_BY_TOPIC
}; }

namespace TypeConsistencyEnforcementKind {
enum Type {
	EXACT_TYPE_TYPE_CONSISTENCY,
	EXACT_NAME_TYPE_CONSISTENCY,
	DECLARED_TYPE_CONSISTENCY,
	ASSIGNABLE_TYPE_CONSISTENCY
}; }

} } }
#endif /* OMG_DDS_CORE_POLICY_POLICYKIND_HPP_ */
