#include <sstream>

#include <dds/core/Exception.hpp>
#include <dds/core/InstanceHandle.hpp>

#include <org/opensplice/core/EntityDelegate.hpp>


volatile unsigned int org::opensplice::core::EntityDelegate::entityID_ = 0;

org::opensplice::core::EntityDelegate::EntityDelegate()
: enabled_(true)
{ }

org::opensplice::core::EntityDelegate::~EntityDelegate()
{ }

void
org::opensplice::core::EntityDelegate::enable() {
   // implementation-defined
}

const dds::core::status::StatusMask
org::opensplice::core::EntityDelegate::status_changes() {
    throw dds::core::UnsupportedError("not implemented");
}

const dds::core::InstanceHandle
org::opensplice::core::EntityDelegate::instance_handle() const {
   return dds::core::InstanceHandle(dds::core::null);
}



void
org::opensplice::core::EntityDelegate::close() {  }

void
org::opensplice::core::EntityDelegate::retain() {  }
