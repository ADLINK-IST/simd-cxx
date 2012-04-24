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

#include <dds/core/Duration.hpp>


dds::core::Duration::Duration()
:  sec_(0),
   nsec_(0)
{ }

dds::core::Duration::Duration(int32_t s, uint32_t ns)
:  sec_(s),
   nsec_(ns)
{ }

dds::core::Duration::~Duration() {
    // implementation-defined
}

int32_t dds::core::Duration::sec() const {
   return sec_;
}

void dds::core::Duration::sec(int32_t s) {
   sec_ = s;
}

uint32_t dds::core::Duration::nanosec() const {
   return nsec_;
}

void dds::core::Duration::nanosec(uint32_t ns) {
   nsec_ = ns;
}

/*
void dds::core::Duration::reset(int32_t s, uint32_t ns) {
   sec_ = s;
   nsec_ = ns;
}
*/

bool
dds::core::Duration::operator >(const Duration& that) const {
  // TODO: Implement
  return false;
}

bool
dds::core::Duration::operator >=(const Duration& that) const {
  // TODO: Implement
  return false;
}

bool
dds::core::Duration::operator ==(const Duration& that) const {
  // TODO: Implement
  return false;
}
bool
dds::core::Duration::operator <=(const Duration& that) const {
  // TODO: Implement
  return false;
}
bool
dds::core::Duration::operator <(const Duration& that) const {
  // TODO: Implement
  return false;
}


const dds::core::Duration
dds::core::Duration::infinite() {
	static Duration d(0x7fffffff, 0x7fffffff);
	return d;
}

const dds::core::Duration
dds::core::Duration::zero() {
	static Duration d(0,0);
	return d;
}
