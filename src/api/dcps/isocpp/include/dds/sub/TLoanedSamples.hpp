#ifndef OMG_DDS_SUB_TLOANED_SAMPLES_HPP_
#define OMG_DDS_SUB_TLOANED_SAMPLES_HPP_

#include <dds/core/ref_traits.hpp>
#include <dds/sub/Sample.hpp>

namespace dds { namespace sub {
    template <typename T,
               template <typename Q> class DELEGATE>
    class LoanedSamples;

  }
}

template <typename T,
      template <typename Q> class DELEGATE>
class dds::sub::LoanedSamples
{
public:
  typedef T                     DataType;
  typedef typename DELEGATE<T>::LoanedDataContainer   LoanedDataContainer;
  typedef typename DELEGATE<T>::iterator              iterator;
  typedef typename DELEGATE<T>::const_iterator        const_iterator;

  typedef typename dds::core::smart_ptr_traits< DELEGATE<T> >::ref_type DELEGATE_REF_T;

public:
  LoanedSamples()
    : delegate_(new DELEGATE<T>())
  { }

  /**
   * Implicitly return the loan.
   */
  ~LoanedSamples() {  }


public:
  const_iterator begin() const {
     return delegate()->begin();
  }

  const_iterator  end() const {
     return delegate()->end();
  }

  const DELEGATE_REF_T& delegate() const {
    return delegate_;
  }

  DELEGATE_REF_T& delegate() {
    return delegate_;
  }

  uint32_t length() const {
    return delegate_->length();
  }
private:
  DELEGATE_REF_T delegate_;
};

#endif /* OMG_DDS_SUB_TLOANED_SAMPLES_HPP_ */
