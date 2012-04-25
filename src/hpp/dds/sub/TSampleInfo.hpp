#ifndef OMG_DDS_SUB_TSAMPLE_INFO_HPP_
#define OMG_DDS_SUB_TSAMPLE_INFO_HPP_

#include <dds/core/Time.hpp>
#include <dds/core/Value.hpp>
#include <dds/sub/GenerationCount.hpp>
#include <dds/sub/Rank.hpp>

namespace dds { 
  namespace sub {
    template <typename DELEGATE>
    class TSampleInfo;
  }
}

template <typename DELEGATE>
class dds::sub::TSampleInfo : dds::core::Value<DELEGATE> {

public:
  // Required for containers
  TSampleInfo() { }
          
public:
  const dds::core::Time timestamp() const {
    return this->delegate().timestamp();
  }
        
  const dds::sub::status::DataState state() const {
    return this->delegate().state();
  }
  dds::sub::GenerationCount generation_count() const {
    return this->delegate().generation_count();
  }
  dds::sub::Rank rank() const {
    return this->delegate().rank();
  }
        
  bool valid() const {
    return this->delegate().valid();
  }

  dds::core::InstanceHandle instance_handle() const {
    return this->delegate().instance_handle();
  }

  dds::core::InstanceHandle publication_handle() const {
    return this->delegate().publication_handle();
  }
};
    
#endif /* OMG_DDS_SUB_TSAMPLE_INFO_HPP_ */
