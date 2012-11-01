#include <org/opensplice/domain/qos/DomainParticipantQosImpl.hpp>

namespace org { namespace opensplice { namespace domain { namespace qos {

    template<>
    const ::dds::core::policy::UserData&
    DomainParticipantQosImpl::policy<dds::core::policy::UserData> () const {
      return user_data_;
    }

    template<>
    const ::dds::core::policy::EntityFactory&
    DomainParticipantQosImpl::policy<dds::core::policy::EntityFactory> () const {
      return entity_factory_;
    }

    void
    DomainParticipantQosImpl::policy(const dds::core::policy::UserData& ud) {
      user_data_ = ud;
    }

    void
    DomainParticipantQosImpl::policy(const dds::core::policy::EntityFactory& efp) {
      entity_factory_ = efp;
    }

      }
    }
  }
}
