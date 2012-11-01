#ifndef OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_
#define OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_

#include <org/opensplice/sub/CoherentAccessImpl.hpp>
#include <dds/sub/TCoherentAccess.hpp>

namespace dds { namespace sub { namespace detail {
    typedef ::dds::sub::TCoherentAccess<org::opensplice::sub::CoherentAccessImpl> CoherentAccess;
} } }

#endif /* OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_ */
