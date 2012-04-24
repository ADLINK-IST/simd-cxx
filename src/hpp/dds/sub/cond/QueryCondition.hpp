#ifndef OMG_DDS_SUB_QUERY_CONDITION_HPP_
#define OMG_DDS_SUB_QUERY_CONDITION_HPP_

#include <dds/sub/cond/TQueryCondition.hpp>
#include <dds/sub/cond/detail/QueryCondition.hpp>

namespace dds { namespace sub { namespace cond {

	template <typename T, template <typename Q> class DELEGATE = dds::sub::cond::detail::QueryCondition>
	class QueryCondition;

} } }
#endif /* OMG_DDS_SUB_QUERY_CONDITION_HPP_ */
