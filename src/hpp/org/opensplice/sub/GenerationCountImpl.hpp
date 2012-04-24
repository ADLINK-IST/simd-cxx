#ifndef ORG_OPENSPLICE_SUB_GENERATION_COUNT_IMPL_HPP_
#define ORG_OPENSPLICE_SUB_GENERATION_COUNT_IMPL_HPP_

namespace org {
  namespace opensplice { 
    namespace sub {
      class GenerationCount {
      public:
        inline int32_t disposed() const {
	  return 0;
        }
        
        inline int32_t no_writers() const {
	  return 0;
        }
      };
      
    } 
  }
}

#endif /* ORG_OPENSPLICE_SUB_GENERATION_COUNT_IMPL_HPP_ */

