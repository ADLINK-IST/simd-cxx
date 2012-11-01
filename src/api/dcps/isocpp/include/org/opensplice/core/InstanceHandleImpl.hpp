#ifndef ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_
#define ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_

#include <dds/core/types.hpp>
#include <org/opensplice/core/config.hpp>

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
  InstanceHandleImpl(DDS::InstanceHandle_t handle);
  ~InstanceHandleImpl();
public:
  InstanceHandleImpl(const dds::core::null_type& src);
  InstanceHandleImpl(const InstanceHandleImpl& other);


public:
  bool operator == (const InstanceHandleImpl& that) const;

  InstanceHandleImpl& operator=(const dds::core::null_type& src);
  bool is_nil() const;

public:
  const DDS::InstanceHandle_t handle() const { return handle_; }

private:
  DDS::InstanceHandle_t handle_;
};

inline std::ostream&
operator << (std::ostream& os,
         const org::opensplice::core::InstanceHandleImpl& h) {
  os << h.handle();
  return os;
}
#endif /* ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_ */
