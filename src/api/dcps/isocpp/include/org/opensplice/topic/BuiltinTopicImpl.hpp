#ifndef ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_IMPL_HPP
#define ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_IMPL_HPP


#include <dds/core/detail/conformance.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <dds/topic/BuiltinTopicKey.hpp>

namespace org { namespace opensplice { namespace topic {
      class ParticipantBuiltinTopicDataImpl;
      class TopicBuiltinTopicDataImpl;
      class PublicationBuiltinTopicDataImpl;
      class SubscriptionBuiltinTopicDataImpl;
    }
  }
}

class org::opensplice::topic::ParticipantBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }

    const ::dds::core::policy::UserData& user_data() {
        return user_data_;
    }
protected:
    dds::topic::BuiltinTopicKey key_;
    ::dds::core::policy::UserData user_data_;
};

class org::opensplice::topic::TopicBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }
    const std::string&                  name() const {
        return name_;
    }
    const std::string&                  type_name() const {
        return type_name_;
    }
    const ::dds::core::policy::Durability&         durability() const {
        return durability_;
    }


#ifdef  OMG_DDS_PERSISTENCE_SUPPORT

    const ::dds::core::policy::DurabilityService&  durability_service() const {
        return durability_service_;
    }

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


    const ::dds::core::policy::Deadline&           deadline() const {
        return deadline_;
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return latency_budget_;
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return liveliness_;
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return reliability_;
    }
    const ::dds::core::policy::TransportPriority&  transport_priority() const {
        return transport_priority_;
    }
    const ::dds::core::policy::Lifespan&           lifespan() const {
        return lifespan_;
    }
    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return destination_order_;
    }
    const ::dds::core::policy::History&            history() const {
        return history_;
    }
    const ::dds::core::policy::ResourceLimits&     resource_limits() const {
        return resource_limits_;
    }
    const ::dds::core::policy::Ownership&          ownership() const {
        return ownership_;
    }
    const ::dds::core::policy::TopicData&          topic_data() const {
        return topic_data_;
    }

protected:
    dds::topic::BuiltinTopicKey  key_;
    std::string                  name_;
    std::string                  type_name_;
    ::dds::core::policy::Durability         durability_;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    ::dds::core::policy::DurabilityService  durability_service_;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    ::dds::core::policy::Deadline           deadline_;
    ::dds::core::policy::LatencyBudget      latency_budget_;
    ::dds::core::policy::Liveliness         liveliness_;
    ::dds::core::policy::Reliability        reliability_;
    ::dds::core::policy::TransportPriority  transport_priority_;
    ::dds::core::policy::Lifespan           lifespan_;
    ::dds::core::policy::DestinationOrder   destination_order_;
    ::dds::core::policy::History            history_;
    ::dds::core::policy::ResourceLimits     resource_limits_;
    ::dds::core::policy::Ownership          ownership_;
    ::dds::core::policy::TopicData          topic_data_;
};

//==============================================================================
//            PublicationBuiltinTopicDataImpl
//==============================================================================

class org::opensplice::topic::PublicationBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }

    const dds::topic::BuiltinTopicKey& participant_key() {
        return participant_key_;
    }

    const std::string&                  topic_name() const {
        return topic_name_;
    }
    const std::string&                  type_name() const {
        return type_name_;
    }
    const ::dds::core::policy::Durability&         durability() const {
        return durability_;
    }


#ifdef  OMG_DDS_PERSISTENCE_SUPPORT

    const ::dds::core::policy::DurabilityService&  durability_service() const {
        return durability_service_;
    }

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


    const ::dds::core::policy::Deadline&           deadline() const {
        return deadline_;
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return latency_budget_;
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return liveliness_;
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return reliability_;
    }
//    const dds::core::policy::TransportPriority&  transport_priority() const {
//        return transport_priority_;
//    }
    const ::dds::core::policy::Lifespan&           lifespan() const {
        return lifespan_;
    }
    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return destination_order_;
    }

    const ::dds::core::policy::Ownership&          ownership() const {
        return ownership_;
    }


#ifdef  OMG_DDS_OWNERSHIP_SUPPORT

    const ::dds::core::policy::OwnershipStrength&  ownership_strength() const {
        return ownership_strength_;
    }

#endif  // OMG_DDS_OWNERSHIP_SUPPORT


    const ::dds::core::policy::Partition&          partition() const {
        return partition_;
    }
    const ::dds::core::policy::Presentation&       presentation() const {
        return presentation_;
    }

    const ::dds::core::policy::TopicData&          topic_data() const {
        return topic_data_;
    }

    const ::dds::core::policy::UserData&           user_data() const {
        return user_data_;
    }

    const ::dds::core::policy::GroupData&          group_data() const {
        return group_data_;
    }

public:
    dds::topic::BuiltinTopicKey  key_;
    dds::topic::BuiltinTopicKey  participant_key_;
    std::string                  topic_name_;
    std::string                  type_name_;
    ::dds::core::policy::Durability         durability_;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    ::dds::core::policy::DurabilityService  durability_service_;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    ::dds::core::policy::Deadline           deadline_;
    ::dds::core::policy::LatencyBudget      latency_budget_;
    ::dds::core::policy::Liveliness         liveliness_;
    ::dds::core::policy::Reliability        reliability_;
    ::dds::core::policy::Lifespan           lifespan_;
    ::dds::core::policy::UserData            user_data_;
    ::dds::core::policy::Ownership          ownership_;

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
    ::dds::core::policy::OwnershipStrength  ownership_strength_;
#endif  // OMG_DDS_OWNERSHIP_SUPPORT

    ::dds::core::policy::DestinationOrder   destination_order_;
    ::dds::core::policy::Presentation       presentation_;
    ::dds::core::policy::Partition          partition_;
    ::dds::core::policy::TopicData           topic_data_;
    ::dds::core::policy::GroupData          group_data_;
};

//==============================================================================
//            SubscriptionBuiltinTopicDataImpl
//==============================================================================

class org::opensplice::topic::SubscriptionBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }

    const dds::topic::BuiltinTopicKey& participant_key() {
        return participant_key_;
    }

    const std::string&                  topic_name() const {
        return topic_name_;
    }
    const std::string&                  type_name() const {
        return type_name_;
    }
    const ::dds::core::policy::Durability&         durability() const {
        return durability_;
    }


    const ::dds::core::policy::Deadline&           deadline() const {
        return deadline_;
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return latency_budget_;
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return liveliness_;
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return reliability_;
    }


    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return destination_order_;
    }

    const ::dds::core::policy::TimeBasedFilter& time_based_filter() {
        return time_based_filter_;
    }

    const ::dds::core::policy::Ownership&          ownership() const {
        return ownership_;
    }
    const ::dds::core::policy::TopicData&          topic_data() const {
        return topic_data_;
    }

    const ::dds::core::policy::Partition&          partition() const {
        return partition_;
    }
    const ::dds::core::policy::Presentation&       presentation() const {
        return presentation_;
    }

    const ::dds::core::policy::UserData&           user_data() const {
        return user_data_;
    }

    const ::dds::core::policy::GroupData&          group_data() const {
        return group_data_;
    }

public:
    dds::topic::BuiltinTopicKey  key_;
    dds::topic::BuiltinTopicKey  participant_key_;
    std::string                  topic_name_;
    std::string                  type_name_;
    ::dds::core::policy::Durability         durability_;
    ::dds::core::policy::Deadline           deadline_;
    ::dds::core::policy::LatencyBudget      latency_budget_;
    ::dds::core::policy::Liveliness         liveliness_;
    ::dds::core::policy::Reliability        reliability_;
    ::dds::core::policy::Ownership          ownership_;
    ::dds::core::policy::DestinationOrder   destination_order_;
    ::dds::core::policy::UserData           user_data_;
    ::dds::core::policy::TimeBasedFilter    time_based_filter_;
    ::dds::core::policy::Presentation       presentation_;
    ::dds::core::policy::Partition          partition_;
    ::dds::core::policy::TopicData          topic_data_;
    ::dds::core::policy::GroupData         group_data_;
};
#endif /* ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_IMPL_HPP */
