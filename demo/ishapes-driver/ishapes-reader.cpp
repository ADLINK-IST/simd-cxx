#include <dds/domain/DomainParticipant.hpp>
#include <dds/pub/Publisher.hpp>
#include <dds/topic/TopicTraits.hpp>
#include <dds/topic/Topic.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/sub/sub.hpp>

#include <org/opensplice/topic/TopicTraits.hpp>
#include "gen/ccpp_ishapes.h"

REGISTER_TOPIC_TRAITS(org::opensplice::demo::ShapeType)
using namespace org::opensplice::demo;
using namespace dds::domain;
using namespace dds::pub;
using namespace dds::topic;
using namespace dds::pub;
using namespace dds::sub;

std::ostream& 
operator << (std::ostream& os, const ShapeType& s) {
  os << "(" // << s.color << "," 
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


int main(int argc, char* argv[]) {
  try {
    DomainParticipant dp(0);
    Topic<ShapeType> topic(dp, "Circle");
    Subscriber sub(dp);
    DataReader<ShapeType> dr(sub, topic);
      
    uint32_t max_size = 10;
    std::vector<ShapeType> data(max_size);
    std::vector<dds::sub::SampleInfo> info(max_size);
    uint32_t sleepTime = 500000;

    while (true) {
      uint32_t len = dr.read(data.begin(), info.begin(), max_size);
      std::cout << "--------------------------------------------" << std::endl;
      for (uint32_t i = 0; i < len; ++i)
	std::cout << data[i] << "\n"
		  << info[i] << std::endl;

      usleep(sleepTime);
    }
  } catch (const dds::core::Exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}


