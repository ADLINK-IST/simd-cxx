#ifndef OMG_DDS_SUB_TRANK_HPP_
#define OMG_DDS_SUB_TRANK_HPP_

#include <dds/core/Value.hpp>

namespace dds  { namespace sub {
    template <typename DELEGATE>
    class TRank;
  } }


template <typename DELEGATE>
class dds::sub::TRank : public dds::core::Value<DELEGATE> {
public:
  TRank() { }
    
  TRank(int32_t s, int32_t a, int32_t ag) 
    : dds::core::Value<DELEGATE>(s, a, ag) { }
    
  int32_t absolute_generation() const {
    return this->delegate().absolute_generation();
  }
    
  inline int32_t generation() const {
    return this->delegate().generation();
  }
    
  inline int32_t sample() const {    
    return this->delegate()->sample();
  }
};

#endif /* OMG_DDS_SUB_TRANK_HPP_ */
