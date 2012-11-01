#ifndef OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_
#define OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_

#include <dds/sub/TGenerationCount.hpp>
#include <org/opensplice/sub/GenerationCountImpl.hpp>
namespace dds { namespace sub { namespace detail {
    typedef dds::sub::TGenerationCount< org::opensplice::sub::GenerationCountImpl > GenerationCount;
} } }

#endif /* OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_ */
