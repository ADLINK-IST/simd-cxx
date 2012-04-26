#include <org/opensplice/core/InstanceHandleImpl.hpp>

namespace org { namespace opensplice { namespace core {

      InstanceHandleImpl::InstanceHandleImpl() : handle_(-1) {
	// empty
      }

      InstanceHandleImpl::InstanceHandleImpl(DDS::InstanceHandle_t h) : handle_(h) { }
      
      InstanceHandleImpl::InstanceHandleImpl(const dds::core::null_type& src)
	: handle_(-1) { }

      InstanceHandleImpl::~InstanceHandleImpl() { }

      InstanceHandleImpl::InstanceHandleImpl(const InstanceHandleImpl& other) 
	: handle_(other.handle_)
      { }

      InstanceHandleImpl&
      InstanceHandleImpl::operator=(const dds::core::null_type& src) {
	handle_ = -1;
	return *this;
      }

      bool
      InstanceHandleImpl::is_nil() const {
	return (handle_ == -1);
      }
      
      bool
      InstanceHandleImpl::operator == (const InstanceHandleImpl& that) const {
	return (this->handle_ == that.handle_);
      }

    } } }
