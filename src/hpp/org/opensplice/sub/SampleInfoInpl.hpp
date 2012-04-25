#ifndef ORG_OPENSPLICE_SUB_SAMPLE_INFO_IMPL_HPP_
#define ORG_OPENSPLICE_SUB_SAMPLE_INFO_IMPL_HPP_

#include <org/opensplice/core/config.hpp>
#include <dds/sub/Rank.hpp>
#include <dds/sub/GenerationCount.hpp>

namespace org { 
  namespace opensplice {
    namespace sub {
      class SampleInfoImpl;
    }
  }
}

/**
 * This is a "brutal" implementation of the SampleInfo which is
 * intented to give encapsulation to an existing SampleInfo by simply
 * casting the DDS::SampleInfo into a an org::opensplice::sub::SampleInfo type.
 *
 * This is kind of ugly but very efficient!
 */
class org::opensplice::sub::SampleInfoImpl : private DDS::SampleInfo {
public:
  SampleInfoImpl() { }
public:
  
  inline const dds::core::Time 
  timestamp() const {
    return dds::core::Time(this->source_timestamp.sec, this->source_timestamp.nanosec);
  }
  
  inline const dds::sub::status::DataState 
  state() const {
    return dds::sub::status::DataState(dds::sub::status::SampleState(this->sample_state), 
				       dds::sub::status::ViewState(this->view_state),
				       dds::sub::status::InstanceState(this->instance_state));
  }
    
  inline dds::sub::GenerationCount 
  generation_count() const {    
    return dds::sub::GenerationCount(this->disposed_generation_count, 
			   this->no_writers_generation_count);
  }
  
  inline dds::sub::Rank 
  rank() const {
    return dds::sub::Rank(this->sample_rank, 
		this->generation_rank, 
		this->absolute_generation_rank);
  }
    
  inline bool 
  valid() const {
    return this->valid_data;
  }

  inline dds::core::InstanceHandle
  instance_handle() const {
    return dds::core::InstanceHandle(this->DDS::SampleInfo::instance_handle);
  }

  inline dds::core::InstanceHandle
  publication_handle() const {
    return dds::core::InstanceHandle(this->DDS::SampleInfo::publication_handle);
  }

};


#endif /* ORG_OPENSPLICE_SUB_SAMPLE_INFO_IMPL_HPP_ */
