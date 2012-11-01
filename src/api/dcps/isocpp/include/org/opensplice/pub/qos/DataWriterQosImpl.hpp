#ifndef ORG_OPENSPLICE_PUB_QOS_DATA_WRITER_QOS_HPP_
#define ORG_OPENSPLICE_PUB_QOS_DATA_WRITER_QOS_HPP_

#include <dds/core/detail/conformance.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <org/opensplice/topic/qos/TopicQosImpl.hpp>

namespace org {
  namespace opensplice {
    namespace pub  {
      namespace qos {
    class DataWriterQosImpl;
      }
    }
  }
}

class org::opensplice::pub::qos::DataWriterQosImpl {
public:
    DataWriterQosImpl();

  DataWriterQosImpl(const org::opensplice::topic::qos::TopicQosImpl& tqos);

    DataWriterQosImpl(
            dds::core::policy::UserData                user_data,
            dds::core::policy::Durability              durability,

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
            dds::core::policy::DurabilityService       durability_service,
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

            dds::core::policy::Deadline                deadline,
            dds::core::policy::LatencyBudget           budget,
            dds::core::policy::Liveliness              liveliness,
            dds::core::policy::Reliability             reliability,
            dds::core::policy::DestinationOrder        order,
            dds::core::policy::History                 history,
            dds::core::policy::ResourceLimits          resources,
            dds::core::policy::TransportPriority       priority,
            dds::core::policy::Lifespan                lifespan,
            dds::core::policy::Ownership               ownership,

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
            dds::core::policy::OwnershipStrength       strength,
#endif  // OMG_DDS_OWNERSHIP_SUPPORT

            dds::core::policy::WriterDataLifecycle     lifecycle);

    ~DataWriterQosImpl();

    void policy(const dds::core::policy::UserData&          user_data);
    void policy(const dds::core::policy::Durability&        durability);

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    void policy(const dds::core::policy::DurabilityService& durability_service);
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    void policy(const dds::core::policy::Deadline&          deadline);
    void policy(const dds::core::policy::LatencyBudget&     budget);
    void policy(const dds::core::policy::Liveliness&        liveliness);
    void policy(const dds::core::policy::Reliability&       reliability);
    void policy(const dds::core::policy::DestinationOrder&  order);
    void policy(const dds::core::policy::History&           history);
    void policy(const dds::core::policy::ResourceLimits&    resources);
    void policy(const dds::core::policy::TransportPriority& priority);
    void policy(const dds::core::policy::Lifespan&          lifespan);
    void policy(const dds::core::policy::Ownership&         ownership);

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
    void policy(const dds::core::policy::OwnershipStrength& strength);
#endif  // OMG_DDS_OWNERSHIP_SUPPORT

    void policy(const dds::core::policy::WriterDataLifecycle&   lifecycle);

    template <typename POLICY> const POLICY& policy() const;
    template <typename POLICY> POLICY& policy();

private:
    dds::core::policy::UserData               user_data_;
    dds::core::policy::Durability              durability_;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    dds::core::policy::DurabilityService       durability_service_;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    dds::core::policy::Deadline                deadline_;
    dds::core::policy::LatencyBudget           budget_;
    dds::core::policy::Liveliness              liveliness_;
    dds::core::policy::Reliability             reliability_;
    dds::core::policy::DestinationOrder        order_;
    dds::core::policy::History                 history_;
    dds::core::policy::ResourceLimits          resources_;
    dds::core::policy::TransportPriority       priority_;
    dds::core::policy::Lifespan                lifespan_;
    dds::core::policy::Ownership               ownership_;

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
    dds::core::policy::OwnershipStrength       strength_;
#endif  // OMG_DDS_OWNERSHIP_SUPPORT

    dds::core::policy::WriterDataLifecycle     lifecycle_;


};

#endif /* ORG_OPENSPLICE_PUB_QOS_DATA_WRITER_QOS_HPP_ */
