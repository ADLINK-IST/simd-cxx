#ifndef ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_
#define ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_

#include <dds/core/policy/CorePolicy.hpp>

namespace org { namespace opensplice  { namespace domain {  namespace qos {
    class DomainParticipantQosImpl;
      }
    }
  }
}

class org::opensplice::domain::qos::DomainParticipantQosImpl {
public:
  DomainParticipantQosImpl() { }

  DomainParticipantQosImpl(const ::dds::core::policy::UserData& user_data,
               const ::dds::core::policy::EntityFactory& entity_factory)
    :  user_data_(user_data),
       entity_factory_(entity_factory)
  { }

  template <typename POLICY>
  const POLICY& policy() const;

  template <typename POLICY>
  POLICY& policy();


  void policy(const ::dds::core::policy::UserData& ud);
  void policy(const ::dds::core::policy::EntityFactory& efp);

private:
    ::dds::core::policy::UserData user_data_;
    ::dds::core::policy::EntityFactory entity_factory_;
};


#endif /* ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_ */
