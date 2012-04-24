#ifndef OMG_DDS_SUB_READ_CONDITION_HPP_
#define OMG_DDS_SUB_READ_CONDITION_HPP_

#include <dds/sub/cond/TReadCondition.hpp>
#include <dds/sub/cond/detail/ReadCondition.hpp>

namespace dds { namespace sub { namespace cond {
	template <typename T, template <typename Q> class DELEGATE = dds::sub::cond::detail::ReadCondition >
	class ReadCondition;
} } }
#endif /* OMG_DDS_SUB_READ_CONDITION_HPP_ */
