#ifndef ORG_OPENSPLICE_SUB_LOANED_SAMPLES_HPP_
#define ORG_OPENSPLICE_SUB_LOANED_SAMPLES_HPP_

#include <org/opensplice/core/config.hpp>
#include <org/opensplice/sub/LoanedSequence.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>

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
  typedef typename org::opensplice::topic::topic_data_reader<T>::type DR;   

public:
  LoanedSamplesImpl() 
    : raw_reader_(0),
      data_(),
      info_()
  { }

  ~LoanedSamplesImpl() { 
    if (raw_reader_ != 0) {
      raw_reader_->return_loan(data().sequence(), info().sequence());
    }
  }
   
public:
  void raw_reader(DR* dr) {
    raw_reader_ = dr;
  }
public:
  
  const LoanedSequence<T>& data() const {
    return data_;
  }
  const LoanedSequence<dds::sub::SampleInfo>& info() const {
    return info_;
  }

  LoanedSequence<T>& data() {
    return data_;
  }
  
  LoanedSequence<dds::sub::SampleInfo>& info() {
    return info_;
  }
  
  uint32_t length() const {
    return data_.length();
  }

private:
  DR* raw_reader_;
  LoanedSequence<T> data_;
  LoanedSequence<dds::sub::SampleInfo> info_;
};
#endif /* ORG_OPENSPLICE_SUB_LOANED_SAMPLES_HPP_ */
