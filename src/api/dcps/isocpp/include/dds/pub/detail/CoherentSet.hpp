#ifndef OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_
#define OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_

#include <dds/pub/TCoherentSet.hpp>
#include <org/opensplice/pub/CoherentSetImpl.hpp>

namespace dds { namespace pub { namespace detail {
    typedef dds::pub::TCoherentSet<org::opensplice::pub::CoherentSetImpl> CoherentSet;
} } }

#endif /*  OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_ */
