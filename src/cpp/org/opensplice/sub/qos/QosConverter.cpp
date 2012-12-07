#include <org/opensplice/sub/qos/QosConverter.hpp>
#include <org/opensplice/core/policy/PolicyConverter.hpp>

using namespace org::opensplice::core::policy;

dds::sub::qos::DataReaderQos
org::opensplice::sub::qos::convertQos(const DDS::DataReaderQos& from)
{
   dds::sub::qos::DataReaderQos to;
   to = to << convertPolicy(from.history) << convertPolicy(from.reliability);
   return to;
}

DDS::DataReaderQos
org::opensplice::sub::qos::convertQos(const dds::sub::qos::DataReaderQos& from)
{
   DDS::DataReaderQos to;
   DDS::HistoryQosPolicy h = convertPolicy(from.policy<dds::core::policy::History>());
   DDS::ReliabilityQosPolicy r = convertPolicy(from.policy<dds::core::policy::Reliability>());
   to.history.kind = h.kind;
   to.history.depth = h.depth;

   to.reliability.kind = r.kind;
   to.reliability.max_blocking_time = r.max_blocking_time;
   to.reliability.synchronous = r.synchronous;

   return to;
}
