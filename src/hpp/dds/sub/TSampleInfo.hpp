#ifndef OMG_DDS_SUB_TSAMPLE_INFO_HPP_
#define OMG_DDS_SUB_TSAMPLE_INFO_HPP_

#include <dds/core/Time.hpp>
#include <dds/core/Value.hpp>
#include <dds/sub/GenerationCount.hpp>
#include <dds/sub/Rank.hpp>

namespace dds { namespace sub {

    template <typename DELEGATE>
    class TSampleInfo : dds::core::Value<DELEGATE> {
        
    public:
        TSampleInfo() { }
        
        template <typename ARG0>
        TSampleInfo(const ARG0& src) : dds::core::Value<DELEGATE>(src) { }
        
    public:
        const dds::core::Time timestamp() const {
            return this->delegate().timestamp();
        }
        
        const dds::sub::status::DataState state() const {
            return this->delegate().state();
        }
        const dds::sub::GenerationCount generation_count() const {
            return this->delegate().generation_count();
        }
        const dds::sub::Rank rank() const {
            return this->delegate().rank();
        }
        
        bool valid() const {
            return this->delegate().valid();
        }
    };
    
} }

#endif /* OMG_DDS_SUB_TSAMPLE_INFO_HPP_ */
