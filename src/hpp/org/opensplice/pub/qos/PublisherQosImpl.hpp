#ifndef ORG_OPENSPLICE_PUB_QOS_PUBLISHER_QOS_IMPL_HPP_
#define ORG_OPENSPLICE_PUB_QOS_PUBLISHER_QOS_IMPL_HPP_

#include <dds/core/policy/CorePolicy.hpp>

namespace org {
  namespace opensplice {
    namespace pub {
      namespace qos {
    class PublisherQosImpl;
      }
    }
  }
}

class org::opensplice::pub::qos::PublisherQosImpl {
public:
    PublisherQosImpl();

    PublisherQosImpl(const PublisherQosImpl& other);

    PublisherQosImpl(const dds::core::policy::Presentation& presentation,
                     const dds::core::policy::Partition& partition,
                     const dds::core::policy::GroupData& gdata,
                     const dds::core::policy::EntityFactory& factory_policy);

    template <typename POLICY>
    const POLICY& policy() const;

    template <typename POLICY>
    POLICY& policy();

public:
    void policy(const dds::core::policy::Presentation& presentation);
    void policy(const dds::core::policy::Partition& partition);
    void policy(const dds::core::policy::GroupData& gdata);
    void policy(const dds::core::policy::EntityFactory& factory_policy);

private:
    dds::core::policy::Presentation          presentation_;
    dds::core::policy::Partition             partition_;
    dds::core::policy::GroupData             gdata_;
    dds::core::policy::EntityFactory   factory_policy_;
};

#endif /* ORG_OPENSPLICE_PUB_QOS_PUBLISHER_QOS_IMPL_HPP_ */
