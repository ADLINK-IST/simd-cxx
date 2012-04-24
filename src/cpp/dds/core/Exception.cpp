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

#include <ostream>
#include <dds/core/Exception.hpp>


#define DEFINE_LE_EXCEPTION (EXP) \
EXP(const std::string& what) : std::logic_error(what) { }\
~EXP() { }

namespace dds { namespace core {

// --- Exception: ------------------------------------------------------------

Exception::Exception() { }

Exception::~Exception() throw() { }


// --- InvalidDataError: -----------------------------------------------------

dds::core::InvalidDataError::InvalidDataError(const std::string& msg)
: Exception(), std::logic_error(msg) {
    // implementation-defined
}


dds::core::InvalidDataError::~InvalidDataError() throw () {
    // implementation-defined
}


const char* InvalidDataError::what() const throw () {
    return std::logic_error::what();
}
    

// --- InvalidDowncastError: -------------------------------------------------

InvalidDowncastError::InvalidDowncastError(const std::string& msg)
    : std::runtime_error(msg) { }
InvalidDowncastError::~InvalidDowncastError() throw() { }

const char* InvalidDowncastError::what() const throw () {
    return std::runtime_error::what();
}


// --- UnsupportedError: -----------------------------------------------------

dds::core::UnsupportedError::UnsupportedError(const std::string& msg) :
        Exception(),
        std::logic_error(msg) {
    // implementation-defined
}

dds::core::UnsupportedError::UnsupportedError(const UnsupportedError& other) 
    : Exception(), 
    std::logic_error(other.what())
{} 


dds::core::UnsupportedError::~UnsupportedError() throw () {
    // implementation-defined
}


const char* dds::core::UnsupportedError::what() const throw () {
    return std::logic_error::what();
}

} }
