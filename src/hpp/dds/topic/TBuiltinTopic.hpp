#ifndef OMG_TDDS_TOPIC_BUILT_IN_TOPIC_HPP_
#define OMG_TDDS_TOPIC_BUILT_IN_TOPIC_HPP_

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
#include <dds/core/Value.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <dds/topic/BuiltinTopicKey.hpp>

namespace dds { namespace topic {
    template <typename D>
    class TParticipantBuiltinTopicData;

    template <typename D>
    class TTopicBuiltinTopicData;
    
    template <typename D>
    class TPublicationBuiltinTopicData;
    
    template <typename D>
    class TSubscriptionBuiltinTopicData;
} }
    
template <typename D>
class dds::topic::TParticipantBuiltinTopicData : public ::dds::core::Value<D> {
public:
    const dds::topic::BuiltinTopicKey& key() const {
        return this->delegate()->key();
    }

    const ::dds::core::policy::UserData& user_data() const {
        return this->delegate()->user_data();
    }
};

template <typename D>
class dds::topic::TTopicBuiltinTopicData : public ::dds::core::Value<D>  {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return this->delegate()->key();
    }
    const std::string&                  name() const {
        return this->delegate()->name();
    }
    const std::string&                  type_name() const {
        return this->delegate()->type_name();
    }
    const ::dds::core::policy::Durability&         durability() const {
        return this->delegate()->durability();
    }


#ifdef OMG_DDS_PERSISTENCE_SUPPORT

    const ::dds::core::policy::DurabilityService&  durability_service() const {
        return this->delegate()->durability_service();
    }

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


    const ::dds::core::policy::Deadline&           deadline() const {
        return this->delegate()->delegate();
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return this->delegate()->latency_budget();
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return this->delegate()->liveliness();
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return this->delegate()->reliability();
    }
    const ::dds::core::policy::TransportPriority&  transport_priority() const {
        return this->delegate()->transport_priority();
    }
    const ::dds::core::policy::Lifespan&           lifespan() const {
        return this->delegate()->lifespan();
    }
    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return this->delegate()->destination_order();
    }
    const ::dds::core::policy::History&            history() const {
        return this->delegate()->history();
    }
    const ::dds::core::policy::ResourceLimits&     resource_limits() const {
        return this->delegate()->resource_limits();
    }
    const ::dds::core::policy::Ownership&          ownership() const {
        return this->delegate()->ownership();
    }
    const ::dds::core::policy::TopicData&          topic_data() const {
        return this->delegate()->topic_data();
    }
};

template <typename D>
class dds::topic::TPublicationBuiltinTopicData  : public ::dds::core::Value<D> {
public:
    const dds::topic::BuiltinTopicKey& key() const  {
        return this->delegate()->key();
    }
    const dds::topic::BuiltinTopicKey& participant_key()  const {
        return this->delegate()->key();
    }
    const std::string&                  topic_name() const {
        return this->delegate()->topic_name();
    }
    const std::string&                  type_name() const {
        return this->delegate()->type_name();
    }
    const ::dds::core::policy::Durability&         durability() const {
        return this->delegate()->durability();
    }


#ifdef OMG_DDS_PERSISTENCE_SUPPORT

    const ::dds::core::policy::DurabilityService&  durability_service() const {
        return this->delegate()->durability_service();
    }

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


    const ::dds::core::policy::Deadline&           deadline() const {
        return this->delegate()->delegate();
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return this->delegate()->latency_budget();
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return this->delegate()->liveliness();
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return this->delegate()->reliability();
    }
    const ::dds::core::policy::Lifespan&           lifespan() const {
        return this->delegate()->lifespan();
    }

    const ::dds::core::policy::UserData&           user_data() const {
        return this->delegate()->user_data();
    }
    const ::dds::core::policy::Ownership&          ownership() const {
        return this->delegate()->ownership();
    }


#ifdef OMG_DDS_OWNERSHIP_SUPPORT

    const ::dds::core::policy::OwnershipStrength&  ownership_strength() const {
        return this->delegate()->ownership_strength();
    }

#endif  // OMG_DDS_OWNERSHIP_SUPPORT


    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return this->delegate()->destination_order();
    }

    const ::dds::core::policy::Presentation&       presentation() const {
        return this->delegate()->presentation();
    }

    const ::dds::core::policy::Partition&          partition() const {
        return this->delegate()->partition();
    }

    const ::dds::core::policy::TopicData&          topic_data() const {
        return this->delegate()->topic_data();
    }

    const ::dds::core::policy::GroupData&          group_data() const {
        return this->delegate()->group_data();
    }

};

template <typename D>
class dds::topic::TSubscriptionBuiltinTopicData  : public ::dds::core::Value<D> {
public:
    const dds::topic::BuiltinTopicKey& key() const {
        return this->delegate()->key();
    }
    const dds::topic::BuiltinTopicKey& participant_key() const {
        return this->delegate()->key();
    }
    const std::string&                  topic_name() const {
        return this->delegate()->topic_name();
    }
    const std::string&                  type_name() const {
        return this->delegate()->type_name();
    }
    const ::dds::core::policy::Durability&         durability() const {
        return this->delegate()->durability();
    }
    const ::dds::core::policy::Deadline&           deadline() const {
        return this->delegate()->deadline();
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return this->delegate()->latency_budget();
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return this->delegate()->liveliness();
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return this->delegate()->reliability();
    }
    const ::dds::core::policy::Ownership&          ownership() const {
        return this->delegate()->ownership();
    }
    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return this->delegate()->destination_order();
    }
    const ::dds::core::policy::UserData&           user_data() const {
        return this->delegate()->user_data();
    }
    const ::dds::core::policy::TimeBasedFilter&    time_based_filter() const {
        return this->delegate()->time_based_filter();
    }

    const ::dds::core::policy::Presentation&       presentation() const {
        return this->delegate()->presentation();
    }
    const ::dds::core::policy::Partition&          partition() const {
        return this->delegate()->partition();
    }


    const ::dds::core::policy::TopicData&          topic_data() const {
        return this->delegate()->topic_data();
    }

    const ::dds::core::policy::GroupData&          group_data() const {
        return this->delegate()->group_data();
    }

};
 
#endif /* OMG_TDDS_TOPIC_BUILT_IN_TOPIC_HPP_ */
