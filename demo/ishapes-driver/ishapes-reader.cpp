#include <dds/domain/DomainParticipant.hpp>
#include <dds/pub/Publisher.hpp>
#include <dds/topic/TopicTraits.hpp>
#include <dds/topic/Topic.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/sub/sub.hpp>

#include <org/opensplice/topic/TopicTraits.hpp>
#include "gen/ccpp_ishapes.h"

#include <algorithm>

REGISTER_TOPIC_TRAITS(org::opensplice::demo::ShapeType)
using namespace org::opensplice::demo;
using namespace dds::domain;
using namespace dds::pub;
using namespace dds::topic;
using namespace dds::pub;
using namespace dds::sub;

std::ostream& 
operator << (std::ostream& os, const ShapeType& s) {
  os << "("  << s.color.in() << "," 
     << s.x << ", " << s.y 
     << ", " << s.shapesize << ")";
  return os;
}

std::ostream& 
operator << (std::ostream& os, const dds::sub::SampleInfo& si) {
  os << "SampleInfo {"
     << "\n\tDataState = " << si.state()
     << "\n\tvalid_data = " << si.valid()
     << "\n\tsource_timestamp = " << " timestamp... "//si.timestamp()
     << "\n\tinstance_handle = " << si.instance_handle()
     << "\n\tpublication_handle = " << si.publication_handle()
     << "\n\trank = " << si.rank()
     << "}";

  return os;
}

void printShape(const ShapeType& s) {
  std::cout << s << std::endl;
}

int main(int argc, char* argv[]) {
  try {
    DomainParticipant dp(0);
    Topic<ShapeType> topic(dp, "Circle");
    Subscriber sub(dp);
    DataReader<ShapeType> dr(sub, topic);
      
    uint32_t sleepTime = 100000;

    while (true) {
      LoanedSamples<ShapeType> samples = 
	dr.selector()
	.filter_state(dds::sub::status::DataState::any_data())
	.read();
      std::cout << "--------------------------------------------" << std::endl;      
      std::for_each(samples.data().begin(), samples.data().end(), printShape);
      usleep(sleepTime);
    }
  } catch (const dds::core::Exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}


