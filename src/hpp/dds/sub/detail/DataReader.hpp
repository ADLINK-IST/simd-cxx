#ifndef OMG_DDS_SUB_DETAIL_DATA_READER_HPP_
#define OMG_DDS_SUB_DETAIL_DATA_READER_HPP_

#include <org/opensplice/core/config.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <org/opensplice/core/memory.hpp>


/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#include <dds/sub/LoanedSamples.hpp>

namespace dds {
  namespace sub {
    namespace functors {
      namespace detail {

	class ContentFilterManipulatorFunctor {
	public:

	  ContentFilterManipulatorFunctor(const dds::core::Query& q)
	    : query_(q) {
	  }

	  template <typename S>
	  void operator()(S& s) {
	    s.filter_content(query_);
	  }
	private:
	  dds::core::Query query_;
	};

	class StateFilterManipulatorFunctor {
	public:

	  StateFilterManipulatorFunctor(const dds::sub::status::DataState& s)
	    : state_(s) {
	  }

	  template <typename S>
	  void operator()(S& s) {
	    s.filter_state(state_);
	  }
	private:
	  dds::sub::status::DataState state_;
	};

	class InstanceManipulatorFunctor {
	public:

	  InstanceManipulatorFunctor(const dds::core::InstanceHandle& h)
	    : handle_(h) {
	  }

	  template <typename S>
	  void operator()(S& s) {
	    s.instance(handle_);
	  }
	private:
	  dds::core::InstanceHandle handle_;
	};

	class NextInstanceManipulatorFunctor {
	public:

	  NextInstanceManipulatorFunctor(const dds::core::InstanceHandle& h)
	    : handle_(h) {
	  }

	  template <typename S>
	  void operator()(S& s) {
	    s.next_instance(handle_);
	  }
	private:
	  dds::core::InstanceHandle handle_;

	};

      }
    }
  }
}


namespace dds {
  namespace sub {
    namespace detail {
      template <typename T>
      class DataReader;
    }
  }
}
using namespace org::opensplice::core;

template <typename T>
class dds::sub::detail::DataReader {
public:

  // -- SELECTORS --
  class Selector {
  public:
    Selector(DataReader<T>* dr)
      : dr_(dr),
	status_(dr_->default_status_filter()),
	next_instance_(false),
	handle_(dds::core::null),
	has_query_(false),
	query_("") {
    }

    Selector& instance(const dds::core::InstanceHandle& h) {
      next_instance_ = false;
      handle_ = h;
      return *this;
    }

    Selector& next_instance(const dds::core::InstanceHandle& h) {
      next_instance_ = true;
      handle_ = h;
      return *this;
    }

    Selector& filter_state(const dds::sub::status::DataState& s) {
      status_ = s;
      return *this;
    }

    Selector& filter_content(const dds::core::Query& query) {
      query_ = query;
      return *this;
    }

    dds::sub::LoanedSamples<T>
    read() {
      return dr_->read(*this);
    }

    dds::sub::LoanedSamples<T>
    take() {
      return dr_->take(*this);
    }

    // --- Forward Iterators: --- //

    template <typename SamplesFWIterator, typename InfoFWIterator>
    void
    read(SamplesFWIterator sfit,
	 InfoFWIterator ifit,
	 size_t max_samples) {
      dr_->read(sfit, ifit, max_samples, *this);
    }

    template <typename SamplesFWIterator, typename InfoFWIterator>
    void
    take(SamplesFWIterator sfit,
	 InfoFWIterator ifit,
	 size_t max_samples) {
      dr_->take(sfit, ifit, max_samples, *this);
    }


    // --- Back-Inserting Iterators: --- //

    template <typename SamplesBIIterator, typename InfoBIIterator>
    void
    read(SamplesBIIterator sbit,
	 InfoBIIterator ibit) {
      dr_->read(sbit, ibit, *this);
    }

    template <typename SamplesBIIterator, typename InfoBIIterator>
    void
    take(SamplesBIIterator sbit,
	 InfoBIIterator ibit) {
      dr_->take(sbit, ibit, *this);
    }
  private:
    DataReader<T>* dr_;
    dds::sub::status::DataState status_;
    bool next_instance_;
    dds::core::InstanceHandle handle_;
    bool has_query_;
    dds::core::Query query_;
  };

  // -- MANIPULATORS SELECTORS --

  class ManipulatorSelector : public Selector {
  public:

    ManipulatorSelector(DataReader<T>* dr) : Selector(dr), read_mode_(true) {
    }

    bool read_mode() {
      return read_mode_;
    }

    void read_mode(bool b) {
      read_mode_ = b;
    }

    ManipulatorSelector&
    operator >>(dds::sub::LoanedSamples<T>& samples) {
      if (read_mode_) samples = this->Selector::read();
      else samples = this->Selector::take();
      return *this;
    }
  private:
    bool read_mode_;
  };
public:
  typedef typename org::opensplice::topic::topic_data_reader<T>::type DR;   
  typedef typename org::opensplice::topic::topic_data_seq<T>::type TSeq;

public:
  ////////////////////////////////////////////////////////////////////////////
  // -- CTORS

  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::Topic<T>& topic)
    : sub_(sub),
      topic_(topic) 
  {
    std::cout << "Topic: " << topic_->t_ << std::endl;
    std::cout << "Sub: " << sub_->sub_ << std::endl;
    DDS::DataReaderQos drqos = *(DDS::DomainParticipantFactory::datareader_qos_default());
    DDS::DataReader* r =
      sub_->sub_->create_datareader(topic_->t_, 
				    drqos, 
				    0, 
				    DDS::ANY_STATUS);
    
    if (r == 0)
      throw dds::core::PreconditionNotMetError("Unable to create DataReader!");

    raw_reader_ = DR::_narrow(r); 
    DDS_DR_REF tmp = 
      DDS_DR_REF(raw_reader_, org::opensplice::core::DRDeleter(sub_->sub_));
    reader_ = tmp;
  }

  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::Topic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos,
	     dds::sub::DataReaderListener<T>* listener,
	     const dds::core::status::StatusMask& mask) 
    : sub_(sub),
      topic_(topic),
      qos_(qos),
      listener_(listener),
      mask_(mask)
  {
    std::cout << "Topic: " << topic_->t_ << std::endl;
    DDS::DataReaderQos drqos = *(DDS::DomainParticipantFactory::datareader_qos_default());
    DDS::DataReader* r =
      sub_->sub_->create_datareader(topic_->t_, 
				    drqos,
				    0, 
				    DDS::ANY_STATUS);
    
    if (r == 0)
      throw dds::core::PreconditionNotMetError("Unable to create DataReader!");

    raw_reader_ = DR::_narrow(r); 
    DDS_DR_REF tmp = 
      DDS_DR_REF(raw_reader_, org::opensplice::core::DRDeleter(sub_->sub_));
    reader_ = tmp;

  }

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::ContentFilteredTopic<T>& topic) {
  }

  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::ContentFilteredTopic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos,
	     dds::sub::DataReaderListener<T>* listener,
	     const dds::core::status::StatusMask& mask) {
  }
#endif /* OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT */

#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT

  DataReader(const dds::sub::Subscriber& pub,
	     const ::dds::topic::MultiTopic<T>& topic) {
  }

  DataReader(const dds::sub::Subscriber& pub,
	     const ::dds::topic::MultiTopic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos,
	     dds::sub::DataReaderListener<T>* listener,
	     const dds::core::status::StatusMask& mask) {
  }
#endif /* OMG_DDS_MULTI_TOPIC_SUPPORT */
public:

  /**
   * Returns a <code>StatusCondition</code> instance associated with
   * this <code>Entity</code>.
   */
  template <typename SELF>
  ::dds::core::cond::StatusCondition<SELF>
  status_condition(const SELF& self) const {
    return ::dds::core::cond::StatusCondition<SELF > (
						      new dds::core::cond::detail::StatusCondition<SELF > (self));
  }

public:

  const dds::sub::status::DataState& default_status_filter() {
    return status_filter_;
  }

  DataReader& default_status_filter(const dds::sub::status::DataState& status) {
    status_filter_ = status;
    return *this;
  }

public:

  dds::sub::LoanedSamples<T> take() {
    std::cout << "DataReader::take : LoanedSamples<T>" << std::endl;
    return dds::sub::LoanedSamples<T > ();
  }

  dds::sub::LoanedSamples<T> read() {
    std::cout << "DataReader::read : LoanedSamples<T>" << std::endl;
    return dds::sub::LoanedSamples<T > ();
  }

  // --- Forward Iterators: --- //

  template <typename SamplesFWIterator, typename InfoFWIterator>
  uint32_t
  read(SamplesFWIterator data_begin,
       InfoFWIterator info_begin,
       size_t max_samples) 
  {
    TSeq data;
    DDS::SampleInfoSeq info;
    uint32_t size;
    raw_reader_->read(data, info, max_samples, 
		  DDS::NOT_READ_SAMPLE_STATE, 
		  DDS::ANY_VIEW_STATE,
		  DDS::ALIVE_INSTANCE_STATE);

    size = data.length();
    for (uint32_t i = 0; i < size; ++i) {
      *data_begin = data[i];
      *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
      ++data_begin;
      ++info_begin;
    }
    raw_reader_->return_loan(data, info);
    return size;
  }

  template <typename SamplesFWIterator, typename InfoFWIterator>
  uint32_t
  take(SamplesFWIterator data_begin,
       InfoFWIterator info_begin,
       size_t max_samples) 
  {
    TSeq data;
    DDS::SampleInfoSeq info;
    uint32_t size;
    raw_reader_->take(data, info, max_samples, 
		  DDS::NOT_READ_SAMPLE_STATE, 
		  DDS::ANY_VIEW_STATE,
		  DDS::ALIVE_INSTANCE_STATE);

    size = data.length();
    for (uint32_t i = 0; i < size; ++i) {
      *data_begin = data[i];
      *info_begin = info[i];
      ++data_begin;
      ++info_begin;
    }
    return_loan(data, info);
    return size;
  }

  // --- Back-Inserting Iterators: --- //
  template <typename SamplesBIIterator, typename InfoBIIterator>
  uint32_t
  read(SamplesBIIterator data_begin,
       InfoBIIterator info_begin) 
  {
    TSeq data;
    DDS::SampleInfoSeq info;
    uint32_t size;
    raw_reader_->read(data, info, DDS::LENGTH_UNLIMITED, 
		  DDS::NOT_READ_SAMPLE_STATE, 
		  DDS::ANY_VIEW_STATE,
		  DDS::ALIVE_INSTANCE_STATE);

    size = data.length();
    for (uint32_t i = 0; i < size; ++i) {
      *data_begin = data[i];
      *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
      ++data_begin;
      ++info_begin;
    }
    return_loan(data, info);
    return size;
  }

  template <typename SamplesBIIterator, typename InfoBIIterator>
  uint32_t
  take(SamplesBIIterator data_begin,
       InfoBIIterator info_begin) 
  {
    TSeq data;
    DDS::SampleInfoSeq info;
    uint32_t size;
    raw_reader_->take(data, info, DDS::LENGTH_UNLIMITED, 
		  DDS::NOT_READ_SAMPLE_STATE, 
		  DDS::ANY_VIEW_STATE,
		  DDS::ALIVE_INSTANCE_STATE);

    size = data.length();
    for (uint32_t i = 0; i < size; ++i) {
      *data_begin = data[i];
      *info_begin = info[i];
      ++data_begin;
      ++info_begin;
    }
    return_loan(data, info);
    return size;
  }

  //========================================================================
  //== Status API

  const dds::core::status::LivelinessChangedStatus&
  liveliness_changed_status() const {
    return liveliness_status_;
  }

  const dds::core::status::SampleRejectedStatus&
  sample_rejected_status() const {
    return sample_rejected_status_;
  }

  const dds::core::status::SampleLostStatus&
  sample_lost_status() const {
    return sample_lost_status_;
  }

  const dds::core::status::RequestedDeadlineMissedStatus&
  requested_deadline_missed_status() {
    return deadline_missed_status_;

  }

  const dds::core::status::RequestedIncompatibleQosStatus&
  requested_incompatible_qos_status() const {
    return incompatible_qos_status_;
  }

  const dds::core::status::SubscriptionMatchedStatus&
  subscription_matched_status() const {
    return subscription_matched_status_;
  }

private:
  // ==============================================================
  // == Selector Read/Take API

  dds::sub::LoanedSamples<T> take(const Selector& cmd) {
    std::cout << "DataReader::Selector::read" << std::endl;
    return dds::sub::LoanedSamples<T > ();
  }

  dds::sub::LoanedSamples<T> read(const Selector& cmd) {
    std::cout << "DataReader::Selector::read" << std::endl;
    return dds::sub::LoanedSamples<T > ();
  }

  // --- Forward Iterators: --- //

  template <typename SamplesFWIterator, typename InfoFWIterator>
  void
  read(SamplesFWIterator sfit,
       InfoFWIterator ifit,
       size_t max_samples, const Selector& cmd) {
    std::cout << "DataReader::Selector::read" << std::endl;
  }

  template <typename SamplesFWIterator, typename InfoFWIterator>
  void
  take(SamplesFWIterator sfit,
       InfoFWIterator ifit,
       size_t max_samples, const Selector& cmd) {
    std::cout << "DataReader::Selector::read" << std::endl;
  }


  // --- Back-Inserting Iterators: --- //

  template <typename SamplesBIIterator, typename InfoBIIterator>
  void
  read(SamplesBIIterator sbit,
       InfoBIIterator ibit, const Selector& cmd) {
    std::cout << "DataReader::Selector::read" << std::endl;
  }

  template <typename SamplesBIIterator, typename InfoBIIterator>
  void
  take(SamplesBIIterator sbit,
       InfoBIIterator ibit, const Selector& cmd) {
    std::cout << "DataReader::Selector::read" << std::endl;
  }

private:
  dds::sub::Subscriber sub_;
  dds::topic::Topic<T> topic_;
  DDS_DR_REF reader_;
  DR* raw_reader_;
  dds::sub::qos::DataReaderQos qos_;
  dds::sub::DataReaderListener<T>* listener_;
  dds::core::status::StatusMask mask_;
  dds::sub::status::DataState status_filter_;
  dds::core::status::LivelinessChangedStatus liveliness_status_;
  dds::core::status::SampleRejectedStatus sample_rejected_status_;
  dds::core::status::SampleLostStatus sample_lost_status_;
  dds::core::status::RequestedDeadlineMissedStatus deadline_missed_status_;
  dds::core::status::RequestedIncompatibleQosStatus incompatible_qos_status_;
  dds::core::status::SubscriptionMatchedStatus subscription_matched_status_;
};



#endif /* OMG_TDDS_SUB_DETAIL_DATA_READER_HPP_ */
