#ifndef OMG_DDS_SUB_LOANED_SAMPLES_HPP_
#define OMG_DDS_SUB_LOANED_SAMPLES_HPP_

#include <org/opensplice/sub/LoanedSamplesImpl.hpp>
#include <org/opensplice/sub/LoanedSequence.hpp>
#include <dds/sub/TLoanedSamples.hpp>

namespace dds { namespace sub {
    template <typename T,
	      template <typename Q> class DELEGATE = org::opensplice::sub::LoanedSamplesImpl>
    class LoanedSamples;
  } 
}

#endif /* OMG_DDS_SUB_LOANED_SAMPLES_HPP_ */
