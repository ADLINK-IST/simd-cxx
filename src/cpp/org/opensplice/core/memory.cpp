#include <org/opensplice/core/memory.hpp>

void
org::opensplice::core::DPDeleter::operator()(DDS::DomainParticipant* dp)
{
  DDS::DomainParticipantFactory_var dpf = DDS::DomainParticipantFactory::get_instance();
  dpf->delete_participant(dp);
  DDS::release(dp);

  OMG_DDS_LOG("MM", "Deleted Participant at: " << std::hex << dp << std::dec);

}

org::opensplice::core::PubDeleter::PubDeleter(const org::opensplice::core::DDS_DP_REF& dp) : dp_(dp) { }

org::opensplice::core::PubDeleter::~PubDeleter()  { }

void
org::opensplice::core::PubDeleter::operator()(DDS::Publisher* p)
{
  dp_->delete_publisher(p);
  DDS::release(p);
  OMG_DDS_LOG("MM", "Deleted Publisher at: " << std::hex << p << std::dec);
}

org::opensplice::core::DWDeleter::DWDeleter(const DDS_PUB_REF& pub) : pub_(pub) { }

org::opensplice::core::DWDeleter::~DWDeleter() { }
void
org::opensplice::core::DWDeleter::operator()(DDS::DataWriter* w)
{
  pub_->delete_datawriter(w);
  DDS::release(w);
  OMG_DDS_LOG("MM", "Deleted DataWriter at: " << std::hex << w << std::dec);
}



org::opensplice::core::SubDeleter::SubDeleter(const DDS_DP_REF& dp) : dp_(dp) { }

org::opensplice::core::SubDeleter::~SubDeleter() { }

void
org::opensplice::core::SubDeleter::operator()(DDS::Subscriber* s)
{
  dp_->delete_subscriber(s);
  DDS::release(s);
  OMG_DDS_LOG("MM", "Deleted Subscriber at: " << std::hex << s << std::dec);
}


org::opensplice::core::DRDeleter::DRDeleter(const DDS_SUB_REF& sub) : sub_(sub) { }
org::opensplice::core::DRDeleter::~DRDeleter() { }
void
org::opensplice::core::DRDeleter::operator()(DDS::DataReader* r)
{
  sub_->delete_datareader(r);
  DDS::release(r);
  OMG_DDS_LOG("MM", "Deleted DataReader at: " << std::hex << r << std::dec);
}
