#ifndef OMG_DDS_CORE_WEAK_REFERENCE_HPP_
#define OMG_DDS_CORE_WEAK_REFERENCE_HPP_

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

#include <dds/core/Reference.hpp>

namespace dds { namespace core {
/**
 * The <code>WeakReference</code> class allow to maintain a
 * weak reference to a DDS reference type. Meaning that the existence
 * of a weak link will not prevent the garbage collection of the
 * reference type.
 */
template <typename T>
class WeakReference {
public:
	typedef T ReferenceType;

public:
	/**
	 * Creates a weak reference for the reference type passed as argument
	 *
	 */
	WeakReference(const T& t) : impl_(t.delegate()) { }

	~WeakReference() { }

	/**
	 * Checks whether the underlying reference has been collected.
	 *
	 * @returns true if the underlying reference has expired, false otherwise
	 */
	bool expired() {
		return impl_.expired();
	}

	/**
	 * Gives access to the underlying reference. If the reference has expired the
	 * returned object will be referencing to <code>null</code>
	 */
	T lock() {
		return T(impl_.lock());
	}

private:
	typename T::DELEGATE_WEAK_REF_T impl_;
};
}}

#endif /* OMG_DDS_CORE_WEAK_REFERENCE_HPP_ */
