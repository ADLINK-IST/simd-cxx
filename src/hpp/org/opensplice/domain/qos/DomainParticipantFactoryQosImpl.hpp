#ifndef ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_FACTORY_QOS_IMPL_HPP_
#define ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_FACTORY_QOS_IMPL_HPP_


#include <dds/core/policy/CorePolicy.hpp>


namespace org { namespace opensplice { namespace domain { namespace qos {
    class DomainParticipantFactoryQosImpl;
      }
    }
  }
}

class org::opensplice::domain::qos::DomainParticipantFactoryQosImpl {
public:
  DomainParticipantFactoryQosImpl();

public:
  const dds::core::policy::EntityFactory& entity_factory() const;
  dds::core::policy::EntityFactory& entity_factory();
  void entity_factory(const dds::core::policy::EntityFactory& policy);
};



#endif /* ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_FACTORY_QOS_IMPL_HPP_ */
