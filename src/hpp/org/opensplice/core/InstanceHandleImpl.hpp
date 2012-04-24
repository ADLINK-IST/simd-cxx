#ifndef ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_
#define ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_

#include <dds/core/types.hpp>

namespace org { 
  namespace opensplice { 
    namespace core {
      class InstanceHandleImpl;
    } 
  }
}

class org::opensplice::core::InstanceHandleImpl {
public:
  InstanceHandleImpl();
  InstanceHandleImpl(const dds::core::null_type& src);    
    InstanceHandleImpl(const InstanceHandleImpl& other);    
  ~InstanceHandleImpl();
  
public:
  
  InstanceHandleImpl& operator=(const dds::core::null_type& src);
  bool is_nil() const;
  
private:
  int32_t handle_;
};

#endif /* ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_ */
