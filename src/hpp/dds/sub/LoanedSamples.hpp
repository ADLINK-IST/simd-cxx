#ifndef OMG_DDS_SUB_LOANED_SAMPLES_HPP_
#define OMG_DDS_SUB_LOANED_SAMPLES_HPP_

#include <dds/sub/detail/LoanedSamples.hpp>
#include <dds/sub/TLoanedSamples.hpp>

namespace dds { namespace sub {
	template <typename T,
			  template <typename Q> class DELEGATE = dds::sub::detail::LoanedSamples>
	class LoanedSamples;
} }

#endif /* OMG_DDS_SUB_LOANED_SAMPLES_HPP_ */
