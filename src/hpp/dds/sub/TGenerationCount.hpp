#ifndef OMG_DDS_SUB_T_GENERATION_COUNT_HPP_
#define OMG_DDS_SUB_T_GENERATION_COUNT_HPP_

#include <dds/core/Value.hpp>

namespace dds { namespace sub {
    template <typename DELEGATE>
    class TGenerationCount;
} }

template <typename DELEGATE>
class dds::sub::TGenerationCount : public dds::core::Value<DELEGATE> {
public:
    TGenerationCount() { }
    
    template <typename ARG0>
    TGenerationCount(const ARG0& arg)
    : dds::core::Value<DELEGATE>(arg) { }
    
public:
    int32_t disposed() const {
        return this->delegate().disposed();
    }
    
    inline int32_t no_writers() const {
        return this->delegate().no_writers();
    }

};

#endif /*  OMG_DDS_SUB_T_GENERATION_COUNT_HPP_ */
