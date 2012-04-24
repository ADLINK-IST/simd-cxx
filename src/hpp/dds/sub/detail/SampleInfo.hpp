#ifndef OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_
#define OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_

namespace dds { namespace sub { namespace detail {

class SampleInfo {
public:
    inline const dds::core::Time timestamp() const {
        return dds::core::Time();
    }
    
    inline const dds::sub::status::DataState state() const {
        return dds::sub::status::DataState::any();
    }
    
    inline const GenerationCount generation_count() const {
        return GenerationCount();
    }
    
    inline const Rank rank() const {
        return Rank();
    }
    
    inline bool valid() const {
        return false;
    }
};
    
} } }

#endif /* OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_ */

