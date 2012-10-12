#ifndef OMG_DDS_SUB_TDATA_READER_HPP_
#define OMG_DDS_SUB_TDATA_READER_HPP_

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
#include <dds/core/detail/conformance.hpp>
#include <dds/core/TEntity.hpp>
#include <dds/topic/ContentFilteredTopic.hpp>
#include <dds/topic/TopicInstance.hpp>
#include <dds/sub/LoanedSamples.hpp>
#include <dds/sub/DataReaderEventHandler.hpp>

namespace dds { namespace sub {
    template <typename T, template <typename Q> class DELEGATE>
    class DataReader;

    template <typename T>
    class DataReaderListener;
  } }
namespace dds { namespace sub {
   class Query;
} }

template <typename T, template <typename Q> class DELEGATE>
class dds::sub::DataReader : public dds::core::TEntity< DELEGATE<T> > {

public:
  typedef T                                        DataType;
  typedef ::dds::sub::DataReaderListener<T>        Listener;

public:
  ////////////////////////////////////////////////////////////////////////
  // Event Handler
  ///////////////////////////////////////////////////////////////////////
  template <typename DR>
  class EventHandler : public dds::sub::DataReaderEventHandler<T> {
  public:
    EventHandler(const DR& dr, 
		 dds::sub::DataReaderListener<T>* l)
      : dr_(dr),
	listener_(l)
    { }
  public:
    virtual void 
    on_requested_deadline_missed(const dds::core::status::RequestedDeadlineMissedStatus& status) 
    {
      if (listener_ != 0)
	listener_->on_requested_deadline_missed(dr_, status);
    }
    
    virtual void 
    on_requested_incompatible_qos(const dds::core::status::RequestedIncompatibleQosStatus& status) 
    {
      if (listener_ != 0)
	listener_->on_requested_incompatible_qos(dr_, status);
    }
      
    virtual void 
    on_sample_rejected(const dds::core::status::SampleRejectedStatus& status)
    {
      if (listener_ != 0)
	listener_->on_sample_rejected(dr_, status);
    }
      
    virtual void 
    on_liveliness_changed(const dds::core::status::LivelinessChangedStatus& status)
    {
      if (listener_ != 0)
	listener_->on_liveliness_changed(dr_, status);
    }
      
    virtual void 
    on_data_available() 
    {
      if (listener_ != 0)
	listener_->on_data_available(dr_);
    }
      
    virtual void 
    on_subscription_matched(const dds::core::status::SubscriptionMatchedStatus& status) 
    {
      if (listener_ != 0)
	listener_->on_subscription_matched(dr_, status);
    }
      
    virtual void 
    on_sample_lost(const dds::core::status::SampleLostStatus& status)
    {
      if (listener_ != 0)
	listener_->on_sample_lost(dr_, status);
    }

    DataReaderListener<T>* 
    listener() 
    {
      return listener_;
    }

    void listener(DataReaderListener<T>* l) {
      listener_ = l;
    }
    
    
  private:
    DR dr_;
    dds::sub::DataReaderListener<T>* listener_;
  };

  ////////////////////////////////////////////////////////////////////////
  // Selector API
  ///////////////////////////////////////////////////////////////////////
  class Selector {
  public:
    Selector(DataReader& dr)
    : impl_(dr.delegate().get()) {}

    Selector& instance(const dds::core::InstanceHandle& h) {
      impl_.instance(h);
      return *this;
    }

    Selector& next_instance(const dds::core::InstanceHandle& h) {
      impl_.next_instance(h);
      return *this;
    }

    Selector& filter_state(const dds::sub::status::DataState& s) {
      impl_.filter_state(s);
      return *this;
    }

    Selector& filter_content(const dds::sub::Query& query) {
      impl_.filter_content(query);
      return *this;
    }

    dds::sub::LoanedSamples<T>
    read()
    {
      return impl_.read();
    }

    dds::sub::LoanedSamples<T>
    take()
    {
      return impl_.take();
    }

    // --- Forward Iterators: --- //
    template <typename SamplesFWIterator, typename InfoFWIterator>
    uint32_t
    read(SamplesFWIterator sfit,
	 InfoFWIterator ifit,
	 uint32_t max_samples)
    {
      return impl_.read(sfit, ifit, max_samples);
    }

    template <typename SamplesFWIterator, typename InfoFWIterator>
    uint32_t
    take(SamplesFWIterator sfit,
	 InfoFWIterator ifit,
	 uint32_t max_samples)
    {
      return impl_.take(sfit, ifit, max_samples);
    }


    // --- Back-Inserting Iterators: --- //
    template <typename SamplesBIIterator, typename InfoBIIterator>
    uint32_t
    read(SamplesBIIterator sbit,
	 InfoBIIterator ibit)
    {
      return impl_.read(sbit, ibit);
    }


    template <typename SamplesBIIterator, typename InfoBIIterator>
    uint32_t
    take(SamplesBIIterator sbit,
	 InfoBIIterator ibit)
    {
      return impl_.take(sbit, ibit);
    }

  private:
    typename DELEGATE<T>::Selector impl_;
  };

  class ManipulatorSelector {
  public:
    ManipulatorSelector(DataReader& dr) : impl_(dr.delegate().get()) { }

    bool read_mode() { return impl_.read_mode(); }

    void read_mode(bool b) { impl_.read_mode(b); }


    ManipulatorSelector& instance(const dds::core::InstanceHandle& h) {
      impl_.instance(h);
      return *this;
    }

    ManipulatorSelector& next_instance(const dds::core::InstanceHandle& h) {
      impl_.next_instance(h);
      return *this;
    }

    ManipulatorSelector& filter_state(const dds::sub::status::DataState& s) {
      impl_.filter_state(s);
      return *this;
    }


    ManipulatorSelector& filter_content(const dds::sub::Query& query) {
      impl_.filter_content(query);
      return *this;
    }

    ManipulatorSelector&
    operator >>(dds::sub::LoanedSamples<T>& samples) {
      impl_ >> samples;
      return *this;
    }

    ManipulatorSelector&
    operator >> (ManipulatorSelector& (manipulator)(ManipulatorSelector&)) {
      manipulator(*this);
      return *this;
    }

    template <typename Functor>
    ManipulatorSelector
    operator >> (Functor f) {
      f(*this);
      return *this;
    }
  private:
    typename DELEGATE<T>::ManipulatorSelector impl_;

  };

public:
  OMG_DDS_REF_TYPE(DataReader, dds::core::TEntity, DELEGATE<T>)

  public:
  DataReader(const dds::sub::Subscriber& sub,
	     const dds::topic::Topic<T>& topic) 
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic))
  { }

  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::Topic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos)
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic, qos)) { }

  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::Topic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos,
	     dds::sub::DataReaderListener<T>* listener,
	     const dds::core::status::StatusMask& mask)
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, 
							  topic, 
							  qos))
  { 
    
    EventHandler<DataReader>* h = new EventHandler<DataReader>(*this, 
							       listener);
    this->delegate()->event_handler(h, mask);
  }

#if 0
#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
  DataReader(const dds::sub::Subscriber& sub,
	     const dds::topic::ContentFilteredTopic<T>& topic)
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic))
  { }


  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::ContentFilteredTopic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos,
	     dds::sub::DataReaderListener<T>* listener,
	     const dds::core::status::StatusMask& mask)
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic, qos, new EventHandler<DataReader>(*this, listener), mask))
  { }
#endif /* OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT */
#endif // if 0
#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT
  DataReader(const dds::sub::Subscriber& sub,
	     const dds::topic::MultiTopic<T>& topic)
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic))
  { }


  DataReader(const dds::sub::Subscriber& sub,
	     const ::dds::topic::MultiTopic<T>& topic,
	     const dds::sub::qos::DataReaderQos& qos,
	     dds::sub::DataReaderListener<T>* listener = NULL,
	     const dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all())
    : ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic, qos, new EventHandler<DataReader>(*this, listener), mask))
  { }

#endif /* OMG_DDS_MULTI_TOPIC_SUPPORT */
public:
  ~DataReader() { }


public:
  // == ReadState Management

  /**
   * Returns the default read-state (if not changed, it is set to
   * ReaderState::any()).
   */
  const dds::sub::status::DataState& default_filter_state() {
    return this->delegate()->default_status_filter();
  }
  DataReader& default_filter_state(const dds::sub::status::DataState& status) {
    this->delegate()->default_status_filter(status);
    return *this;
  }
  //== Streaming read/take

  /**
   * Manipulators are defined externally to make it possible to control whether the
   * streaming operators reads or takes.
   * dr >> read >> loanedSamples;
   * dr >> take >> loanedSamples;
   *
   */
  DataReader& operator >>(dds::sub::LoanedSamples<T>& ls) {
    ls = this->read();
    return *this;
  }

  ManipulatorSelector
  operator >> (ManipulatorSelector& (manipulator)(ManipulatorSelector&)) {
    ManipulatorSelector selector(*this);
    manipulator(selector);
    return selector;
  }

  template <typename Functor>
  ManipulatorSelector
  operator >> (Functor f) {
    ManipulatorSelector selector(*this);
    f(selector);
    return selector;
  }
  ///////////////////////////////////////////////////////////////////////
public:
  //== Loan Read/Take API ==================================================
  LoanedSamples<T> read() {
    return this->delegate()->read();
  }

  LoanedSamples<T> take() {
    return this->delegate()->take();
  }

  //== Copy Read/Take API ==================================================

  // --- Forward Iterators: --- //
  template <typename SamplesFWIterator, typename InfoFWIterator>
  uint32_t
  read(SamplesFWIterator sfit,
       InfoFWIterator ifit,
       uint32_t max_samples)
  {
    return this->delegate()->read(sfit, ifit, max_samples);
  }

  template <typename SamplesFWIterator, typename InfoFWIterator>
  uint32_t
  take(SamplesFWIterator sfit,
       InfoFWIterator ifit,
       uint32_t max_samples)
  {
    return this->delegate()->take(sfit, ifit, max_samples);
  }


  // --- Back-Inserting Iterators: --- //
  template <typename SamplesBIIterator, typename InfoBIIterator>
  uint32_t
  read(SamplesBIIterator sbit,
       InfoBIIterator ibit)
  {
    return this->delegate()->read(sbit, ibit);
  }


  template <typename SamplesBIIterator, typename InfoBIIterator>
  uint32_t
  take(SamplesBIIterator sbit,
       InfoBIIterator ibit)
  {
    return this->delegate()->take(sbit, ibit);
  }
public:
  //========================================================================
  //== DSL Method for dealing with instances, content and status filters.
  Selector selector() {
    Selector selector(*this);
    return selector;
  }

  //========================================================================
  //== Instance Management
public:
  /**
   * This operation can be used to retrieve the instance key that corresponds
   * to an instance_handle. The operation will only fill the fields that form
   * the key inside the key_holder instance.
   * This operation may raise a BadParameter exception if the InstanceHandle
   * does not correspond to an existing data-object known to the DataWriter.
   * If the implementation is not able to check invalid handles, then the
   * result in this situation is unspecified.
   */
  dds::topic::TopicInstance<T> key_value(const dds::core::InstanceHandle& h) {
    return this->delegate()->key_value(h);
  }

  /**
   * This operation can be used to retrieve the instance key that corresponds
   * to an instance_handle. The operation will only fill the fields that form
   * the key inside the key_holder instance.
   * This operation may raise a BadParameter exception if the InstanceHandle
   * does not correspond to an existing data-object known to the DataWriter.
   * If the implementation is not able to check invalid handles, then the
   * result in this situation is unspecified.
   */
  T& key_value(T& sample, const dds::core::InstanceHandle& h) {
    return this->delegate()->key_value(sample, h);
  }

  /**
   * This operation takes as a parameter an instance and returns a handle
   * that can be used in subsequent operations that accept an instance handle
   * as an argument. The instance parameter is only used for the purpose
   * of examining the fields that define the key. This operation does not
   * register the instance in question. If the instance has not been
   * previously registered, or if for any other reason the Service is unable
   * to provide an instance handle, the Service will return a TopicInstance
   * whose handle will be set to the HANDLE_NIL value.
   */
  const dds::core::InstanceHandle 
  lookup_instance(const T& key) const {
    return this->delegate()->lookup_instance(key);
  }

  //==========================================================================
  // -- Entity Navigation API
public:
  dds::topic::TopicDescription<DataType> topic_description() const {
     return this->delegate()->topic_description();
  }


  const dds::sub::Subscriber& subscriber() const {
     return this->delegate()->subscriber();
  }

  // -- Listener Getter/Setter
  void listener(Listener* the_listener,
		const dds::core::status::StatusMask& event_mask) 
  {
    
  }

  Listener* listener() const {
    return this->delegate()->listener();
  }

  // -- Qos Getter/Setter

  const dds::sub::qos::DataReaderQos
  qos() const {
    return this->delegate()->qos();
  }

  void qos(const dds::sub::qos::DataReaderQos& the_qos) {
    this->delegate()->qos(the_qos);
  }

  DataReader& operator << (const dds::sub::qos::DataReaderQos& the_qos) {
    this->delegate()->qos(the_qos);
    return *this;
  }

  DataReader& operator >> (dds::sub::qos::DataReaderQos& the_qos) {
    the_qos = this->delegate()->qos();
    return *this;
  }

  void
  wait_for_historical_data(const dds::core::Duration& timeout) {
    this->delegate()->wait_for_historical_data(timeout);
  }

  //========================================================================
  //== Status API
  const dds::core::status::LivelinessChangedStatus&
  liveliness_changed_status() const {
    return this->delegate()->liveliness_changed_status();
  }

  const dds::core::status::SampleRejectedStatus&
  sample_rejected_status() const {
    return this->delegate()->sample_rejected_status()();
  }

  const dds::core::status::SampleLostStatus&
  sample_lost_status() const {
    return this->delegate()->sample_lost_status();
  }

  const dds::core::status::RequestedDeadlineMissedStatus&
  requested_deadline_missed_status() {
    return this->delegate()->requested_deadline_missed_status();
  }

  const dds::core::status::RequestedIncompatibleQosStatus&
  requested_incompatible_qos_status() const {
    return this->delegate()->requested_incompatible_qos_status();
  }

  const dds::core::status::SubscriptionMatchedStatus&
  subscription_matched_status() const {
    return this->delegate()->subscription_matched_status();
  }
};


#endif /* OMG_DDS_SUB_TDATA_READER_HPP_ */
