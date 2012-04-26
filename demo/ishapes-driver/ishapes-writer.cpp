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

int main(int argc, char* argv[]) {
  try {
    DomainParticipant dp(0);
    Topic<ShapeType> topic(dp, "Circle");
    Publisher pub(dp);      
    DataWriter<ShapeType> dw(pub, topic);
      
    const uint32_t N = 1000;
    uint32_t sleepTime = 300000;
    for (int i = 0; i < N; ++i) {
      ShapeType bc = {"RED", i, i, 60};
      ShapeType rc = {"BLUE", N-i, N-i, 60};
      dw.write(bc);
      dw << rc;
      std::cout << "." << std::flush;
      usleep(sleepTime);
    }

  } catch (const dds::core::Exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}



