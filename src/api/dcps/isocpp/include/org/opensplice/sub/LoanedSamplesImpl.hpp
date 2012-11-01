#ifndef ORG_OPENSPLICE_SUB_LOANED_SAMPLES_HPP_
#define ORG_OPENSPLICE_SUB_LOANED_SAMPLES_HPP_

#include <org/opensplice/core/config.hpp>
#include <org/opensplice/sub/LoanedSequence.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <vector>
#include <dds/sub/Sample.hpp>

namespace org {
   namespace opensplice {
      namespace sub {
         template <typename T>
         class LoanedSamplesImpl;
      }
   }
}

template <typename T>
class org::opensplice::sub::LoanedSamplesImpl {
public:

   typedef std::vector< dds::sub::Sample<T> >                             LoanedDataContainer;
   typedef typename std::vector< dds::sub::Sample<T> >::                iterator iterator;
   typedef typename std::vector< dds::sub::Sample<T> >::const_iterator  const_iterator;

   typedef typename org::opensplice::topic::topic_data_reader<T>::type DR;

public:
   LoanedSamplesImpl() { }

   ~LoanedSamplesImpl() {  }

public:

   iterator mbegin() {
      return samples_.begin();
   }

   const_iterator begin() const {
      return samples_.begin();
   }

   const_iterator end() const {
      return samples_.end();
   }

   uint32_t length() const {
      return samples_.length();
   }

   void resize(int s) {
      samples_.resize(s);
   }

private:

   LoanedDataContainer samples_;
};

#endif /* ORG_OPENSPLICE_SUB_LOANED_SAMPLES_HPP_ */
