#ifndef OMG_DDS_SUB_DETAIL_RANK_HPP
#define OMG_DDS_SUB_DETAIL_RANK_HPP

#include <dds/sub/TRank.hpp>
#include <org/opensplice/sub/RankImpl.hpp>

namespace dds { namespace sub { namespace detail {
    typedef dds::sub::TRank< org::opensplice::sub::RankImpl > Rank;
} } }

#endif /* OMG_DDS_SUB_DETAIL_RANK_HPP */
