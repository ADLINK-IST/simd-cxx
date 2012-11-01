#ifndef ORG_OPENSPLICE_PUB_SUSPENDED_PUBBLICATIONS_IMPL_HPP_
#define ORG_OPENSPLICE_PUB_SUSPENDED_PUBBLICATIONS_IMPL_HPP_

#include <iostream>

#include <org/opensplice/pub/pubfwd.hpp>


namespace org {
  namespace opensplice {
    namespace pub {
      class SuspendedPublicationImpl;
    }
  }
}

class org::opensplice::pub::SuspendedPublicationImpl {
public:
  SuspendedPublicationImpl(const dds::pub::Publisher& t) : t_(t), ended_(false) {
    std::cout << "=== suspend publication" << std::endl;
  }
  void end() {
    if (!ended_) {
      std::cout << "=== resume publication" << std::endl;
      ended_ = true;
    }
  }
  ~SuspendedPublicationImpl() {
    if (!ended_) {
      this->end();
    }
  }

private:
  dds::pub::Publisher t_;
  bool ended_;
};

#endif /* ORG_OPENSPLICE_PUB_SUSPENDED_PUBBLICATIONS_IMPL_HPP_ */
