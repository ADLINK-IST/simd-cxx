#include <org/opensplice/core/policy/PolicyConverter.hpp>

/////////////////////////////////////////////////////////////////////////////
dds::core::policy::History
org::opensplice::core::policy::convertPolicy(const DDS::HistoryQosPolicy& from)
{
   if (from.kind == DDS::KEEP_ALL_HISTORY_QOS)
      return dds::core::policy::History::KeepAll();

   return dds::core::policy::History::KeepLast(from.depth);
}

DDS::HistoryQosPolicy
org::opensplice::core::policy::convertPolicy(const dds::core::policy::History& from)
{
   DDS::HistoryQosPolicy to;
   if (from.kind() == dds::core::policy::HistoryKind::KEEP_ALL) {
      to.kind = DDS::KEEP_ALL_HISTORY_QOS;
   }
   else {
      to.kind = DDS::KEEP_LAST_HISTORY_QOS;
      to.depth = from.depth();
   }
   return to;
}

///////////////////////////////////////////////////////////////////////////////

dds::core::policy::Reliability
org::opensplice::core::policy::convertPolicy(const DDS::ReliabilityQosPolicy& from)
{
   if (from.kind == DDS::BEST_EFFORT_RELIABILITY_QOS)
      return dds::core::policy::Reliability::BestEffort();

   dds::core::Duration d(from.max_blocking_time.sec, from.max_blocking_time.nanosec);
   return dds::core::policy::Reliability::Reliable(d);
}

DDS::ReliabilityQosPolicy
org::opensplice::core::policy::convertPolicy(const dds::core::policy::Reliability& from)
{
   DDS::ReliabilityQosPolicy to;
   if (from.kind() == dds::core::policy::ReliabilityKind::BEST_EFFORT) {
      to.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
   }
   else {
      to.kind = DDS::RELIABLE_RELIABILITY_QOS;
      to.synchronous = false;
      DDS::Duration_t d = {
            from.max_blocking_time().sec(),
            from.max_blocking_time().nanosec()
      };
      to.max_blocking_time = d;
   }
   return to;
}

///////////////////////////////////////////////////////////////////////////////
