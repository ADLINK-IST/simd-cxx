#ifndef ORG_OPENSPLICE_DEMO_ISHAPES_DRIVER_UTIL_HPP_
#define ORG_OPENSPLICE_DEMO_ISHAPES_DRIVER_UTIL_HPP_

#include <iostream>
// DDS Include
#include <dds/dds.hpp>

// Generated Files
#include "gen/ccpp_ishapes.h"

REGISTER_TOPIC_TRAITS(org::opensplice::demo::ShapeType)

using namespace org::opensplice::demo;
using namespace dds::domain;
using namespace dds::pub;
using namespace dds::topic;
using namespace dds::pub;
using namespace dds::sub;
using namespace dds::sub::status;
using namespace dds::core::status;

std::ostream&
operator <<(std::ostream& os, const org::opensplice::demo::ShapeType& s);

std::ostream&
operator <<(std::ostream& os, const dds::sub::SampleInfo& si);

namespace demo {
   namespace ishapes {
      struct Params;

      void printShape(const org::opensplice::demo::ShapeType& s);

      template<typename T>
      class Runner {
      public:
         virtual ~Runner() {
         }
         virtual void run(const dds::domain::DomainParticipant& dp,
               const dds::topic::Topic<T>& topic,
               const Params& params) = 0;
      };

      template<typename T>
      class IdleRunner: public Runner<T> {
      public:
         virtual ~IdleRunner() {
         }
      public:
         virtual void run(const dds::domain::DomainParticipant& dp,
               const dds::topic::Topic<T>& topic,
               const Params& params) {

         }
      };

      typedef boost::shared_ptr<demo::ishapes::Runner<ShapeType> > Runner_t;

      struct Params {
          std::string shape;
          uint32_t period;
          uint32_t samples;
       };
       struct Config {
          Params params;
          Runner_t runner;
       };

   }
} /** demo :: ishapes */


#endif /* ORG_OPENSPLICE_DEMO_ISHAPES_DRIVER_UTIL_HPP_ */

