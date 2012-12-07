#ifndef ORG_OPENSPLICE_SUB_GENERATION_COUNT_IMPL_HPP_
#define ORG_OPENSPLICE_SUB_GENERATION_COUNT_IMPL_HPP_

namespace org {
  namespace opensplice {
    namespace sub {
      class GenerationCountImpl;
    }
  }
}

class org::opensplice::sub::GenerationCountImpl {
public:
  GenerationCountImpl(int32_t d, int32_t nw) : d_(d), nw_(nw) { }

public:
  inline int32_t disposed() const {
    return d_;
  }

  inline int32_t no_writers() const {
    return nw_;
  }

private:
  int32_t d_, nw_;
};

#endif /* ORG_OPENSPLICE_SUB_GENERATION_COUNT_IMPL_HPP_ */
