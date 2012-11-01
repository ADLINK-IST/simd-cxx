#ifndef ORG_OPENSPLICE_CORE_POLICY_POLICYCONVERTER_HPP_
#define ORG_OPENSPLICE_CORE_POLICY_POLICYCONVERTER_HPP_

#include <dds/core/types.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <org/opensplice/core/config.hpp>

namespace org {
   namespace opensplice {
      namespace core {
         namespace policy {

            // History Policy
            dds::core::policy::History
            convertPolicy(const DDS::HistoryQosPolicy& h);

            DDS::HistoryQosPolicy
            convertPolicy(const dds::core::policy::History& h);

            // Reliability Policy
            dds::core::policy::Reliability
            convertPolicy(const DDS::ReliabilityQosPolicy& from);

            DDS::ReliabilityQosPolicy
            convertPolicy(const dds::core::policy::Reliability& from);
         }
      }
   }
}


#endif /* ORG_OPENSPLICE_CORE_POLICY_POLICYCONVERTER_HPP_ */
