/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Inc.
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

#include <dds/core/Time.hpp>

dds::core::Time::Time()
:  sec_(0L),
   nsec_(0u)
{ }

dds::core::Time::Time(int64_t s, uint32_t ns)
:  sec_(s),
   nsec_(ns)
{ }

int64_t dds::core::Time::sec() const {
   return sec_;
}

void dds::core::Time::sec(int64_t s) {
   sec_ = s;
}

uint32_t dds::core::Time::nanosec() const {
   return nsec_;
}

void dds::core::Time::nanosec(uint32_t ns) {
   nsec_ = ns;
}



bool
dds::core::Time::operator >=(const Time& that) {
  // TODO: Implement
  return false;
}

bool
dds::core::Time::operator ==(const Time& that) {
  // TODO: Implement
  return false;
}
bool
dds::core::Time::operator <=(const Time& that) {
  // TODO: Implement
  return false;
}
bool
dds::core::Time::operator <(const Time& that) {
  // TODO: Implement
  return false;
}
