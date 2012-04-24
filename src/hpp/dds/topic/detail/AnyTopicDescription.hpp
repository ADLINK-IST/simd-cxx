#ifndef OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_DESCRIPTION_HPP_
#define OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_DESCRIPTION_HPP_

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

#include <dds/domain/DomainParticipant.hpp>


namespace dds { namespace topic { namespace detail {
class TDHolderBase {
public:
    virtual ~TDHolderBase() { }

    virtual const dds::domain::DomainParticipant& domain_participant() const = 0;

    virtual const std::string& name() const = 0;

    virtual const std::string& type_name() const = 0;
};

template <typename T>
class TDHolder : public virtual TDHolderBase {
public:
    TDHolder(const dds::topic::TopicDescription<T>& t) : td_(t) { }
    virtual ~TDHolder() { }
public:
    virtual const dds::domain::DomainParticipant& domain_participant() const {
    	return td_.domain_participant();
    }

    virtual const std::string& name() const {
    	return td_.name();
    }

    virtual const std::string& type_name() const {
    	return td_.type_name();
    }

    const dds::topic::TopicDescription<T>& get() const { return td_; }

protected:
    dds::topic::TopicDescription<T> td_;
};
} } }

#endif /* OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_DESCRIPTION_HPP_ */
