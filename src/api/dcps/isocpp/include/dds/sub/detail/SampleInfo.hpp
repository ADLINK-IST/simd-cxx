#ifndef OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_
#define OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_

#include <org/opensplice/sub/SampleInfoInpl.hpp>
#include <dds/sub/TSampleInfo.hpp>

namespace dds { namespace sub { namespace detail {
      typedef dds::sub::TSampleInfo<org::opensplice::sub::SampleInfoImpl> SampleInfo;
} } }

#endif /* OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_ */
