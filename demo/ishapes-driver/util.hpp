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

std::ostream& 
operator << (std::ostream& os, const org::opensplice::demo::ShapeType& s);

std::ostream& 
operator << (std::ostream& os, const dds::sub::SampleInfo& si);

void printShape(const org::opensplice::demo::ShapeType& s);

#endif /* ORG_OPENSPLICE_DEMO_ISHAPES_DRIVER_UTIL_HPP_ */

