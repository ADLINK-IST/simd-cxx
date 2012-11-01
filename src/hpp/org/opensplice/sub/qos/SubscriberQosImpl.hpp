#ifndef ORG_OPENSPLICE_SUB_QOS_SUBSCRIBER_QOS_IMPL_HPP_
#define ORG_OPENSPLICE_SUB_QOS_SUBSCRIBER_QOS_IMPL_HPP_

#include <dds/core/policy/CorePolicy.hpp>


namespace org { namespace opensplice { namespace sub { namespace qos {

    class SubscriberQosImpl {
    public:
       void policy(const dds::core::policy::Partition& partition) {
          partition_ = partition;
       }
    private:
       dds::core::policy::Partition             partition_;
    };

      }
    }
  }
}

#endif /* ORG_OPENSPLICE_SUB_QOS_SUBSCRIBER_QOS_IMPL_HPP_ */
