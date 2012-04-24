#ifndef ORG_OPENSPLICE_CORE_POLICY_QOS_POLICY_COUNT_HPP_
#define ORG_OPENSPLICE_CORE_POLICY_QOS_POLICY_COUNT_HPP_

#include <dds/core/types.hpp>

namespace org { namespace opensplice { namespace core { namespace policy {

	class QosPolicyCountImpl {
	public:
	  // @TODO: Finish Implementation
	  QosPolicyCountImpl(dds::core::policy::QosPolicyId id, uint32_t count)
	    : policy_id_(id),
	      count_(count)
	  { }

	  QosPolicyCountImpl(const QosPolicyCountImpl& other)
	  : policy_id_(other.policy_id()),
	    count_(other.count())
	  { }

	public:
	  dds::core::policy::QosPolicyId policy_id() const {
	    return policy_id_;
	  }
	  void policy_id(dds::core::policy::QosPolicyId id) {
	    policy_id_ = id;
	  }

	  uint32_t count() const {
	    return count_;
	  }
	  void count(uint32_t c) {
	    count_ = c;
	  }

	private:
	  dds::core::policy::QosPolicyId policy_id_;
	  uint32_t count_;
	};

      } 
    } 
  } 
}

#endif /* ORG_OPENSPLICE_CORE_POLICY_QOS_POLICY_COUNT_HPP_ */
