#ifndef OMG_DDS_SUB_DETAIL_DATA_READER_HPP_
#define OMG_DDS_SUB_DETAIL_DATA_READER_HPP_

#include <org/opensplice/core/config.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <org/opensplice/core/memory.hpp>
#include <dds/sub/DataReaderEventHandler.hpp>

namespace dds {
   namespace sub {
      class Query;
   }
}
namespace dds {
   namespace sub {
      namespace functors {
         namespace detail {
            //////////////////////////////////////////////////////////////////////
            // Manipulators
            //////////////////////////////////////////////////////////////////////

            class ContentFilterManipulatorFunctor {
            public:
               ContentFilterManipulatorFunctor(const dds::sub::Query& q) :
                     query_(q) {
               }

               template<typename S>
               void operator()(S& s) {
                  s.filter_content(query_);
               }
            private:
               const dds::sub::Query& query_;
            };

            class StateFilterManipulatorFunctor {
            public:
               StateFilterManipulatorFunctor(
                     const dds::sub::status::DataState& s) :
                     state_(s) {
               }

               template<typename S>
               void operator()(S& s) {
                  s.filter_state(state_);
               }
            private:
               dds::sub::status::DataState state_;
            };

            class InstanceManipulatorFunctor {
            public:
               InstanceManipulatorFunctor(const dds::core::InstanceHandle& h) :
                     handle_(h) {
               }

               template<typename S>
               void operator()(S& s) {
                  s.instance(handle_);
               }
            private:
               dds::core::InstanceHandle handle_;
            };

            class NextInstanceManipulatorFunctor {
            public:
               NextInstanceManipulatorFunctor(
                     const dds::core::InstanceHandle& h) :
                     handle_(h) {
               }

               template<typename S>
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
         //////////////////////////////////////////////////////////////////////
         // Listener
         //////////////////////////////////////////////////////////////////////
         template<typename T>
         class DataReaderEventForwarder: public DDS::DataReaderListener {
         public:
            DataReaderEventForwarder(
                  dds::sub::DataReaderEventHandler<T>* handler) :
                  handler_(handler) {
            }
            virtual ~DataReaderEventForwarder() {
               delete handler_;
            }
         public:
            virtual void on_requested_deadline_missed(
                  DDS::DataReader_ptr reader,
                  const DDS::RequestedDeadlineMissedStatus& status) {
               OMG_DDS_LOG("EVT", "on_requested_deadline_missed");
               handler_->on_requested_deadline_missed(
                     dds::core::status::RequestedDeadlineMissedStatus());
            }
            virtual void on_requested_incompatible_qos(
                  DDS::DataReader_ptr reader,
                  const DDS::RequestedIncompatibleQosStatus& status) {
               OMG_DDS_LOG("EVT", "on_requested_incompatible_qos");
               handler_->on_requested_incompatible_qos(
                     dds::core::status::RequestedIncompatibleQosStatus());
            }
            virtual void on_sample_rejected(DDS::DataReader_ptr reader,
                  const DDS::SampleRejectedStatus& status) {
               OMG_DDS_LOG("EVT", "on_sample_rejected");
               handler_->on_sample_rejected(
                     dds::core::status::SampleRejectedStatus());
            }
            virtual void on_liveliness_changed(DDS::DataReader_ptr reader,
                  const DDS::LivelinessChangedStatus& status) {
               OMG_DDS_LOG("EVT", "on_liveliness_changed");
               handler_->on_liveliness_changed(
                     dds::core::status::LivelinessChangedStatus());
            }
            virtual void on_data_available(DDS::DataReader_ptr reader) {
               OMG_DDS_LOG("EVT", "on_data_available");
               handler_->on_data_available();
            }
            virtual void on_subscription_matched(DDS::DataReader_ptr reader,
                  const DDS::SubscriptionMatchedStatus& status) {
               OMG_DDS_LOG("EVT", "on_subscription_matched");
               handler_->on_subscription_matched(
                     dds::core::status::SubscriptionMatchedStatus());
            }
            virtual void on_sample_lost(DDS::DataReader_ptr reader,
                  const DDS::SampleLostStatus& status) {
               OMG_DDS_LOG("EVT", "on_sample_lost");
               handler_->on_sample_lost(dds::core::status::SampleLostStatus());
            }

            dds::sub::DataReaderEventHandler<T>* handler_;
         };

         template<typename T>
         class DataReader;
      }
   }
}
using namespace org::opensplice::core;

//////////////////////////////////////////////////////////////////////////////
// DataReader
//////////////////////////////////////////////////////////////////////////////
template<typename T>
class dds::sub::detail::DataReader : public org::opensplice::core::EntityDelegate {
public:

   // -- SELECTORS --
   class Selector {
   public:
      Selector(DataReader<T>* dr) :
            dr_(dr), status_(dr_->default_status_filter()), next_instance_(
                  false), handle_(dds::core::null), has_query_(false), query_(
                  "") {
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

      template<typename QUERY>
      Selector& filter_content(const QUERY& query) {
         query_ = query.expression();
         // TODO: Get also params
         return *this;
      }

      dds::sub::LoanedSamples<T> read() {
         return dr_->read(*this);
      }

      dds::sub::LoanedSamples<T> take() {
         return dr_->take(*this);
      }

      // --- Forward Iterators: --- //

      template<typename SamplesFWIterator, typename InfoFWIterator>
      uint32_t read(SamplesFWIterator sfit, InfoFWIterator ifit,
            uint32_t max_samples) {
         return dr_->read(sfit, ifit, max_samples, *this);
      }

      template<typename SamplesFWIterator, typename InfoFWIterator>
      uint32_t take(SamplesFWIterator sfit, InfoFWIterator ifit,
            uint32_t max_samples) {
         return dr_->take(sfit, ifit, max_samples, *this);
      }

      // --- Back-Inserting Iterators: --- //

      template<typename SamplesBIIterator, typename InfoBIIterator>
      uint32_t read(SamplesBIIterator sbit, InfoBIIterator ibit) {
         return dr_->read(sbit, ibit, *this);
      }

      template<typename SamplesBIIterator, typename InfoBIIterator>
      uint32_t take(SamplesBIIterator sbit, InfoBIIterator ibit) {
         return dr_->take(sbit, ibit, *this);
      }

   private:
      friend class DataReader;
      DataReader<T>* dr_;
      dds::sub::status::DataState status_;
      bool next_instance_;
      dds::core::InstanceHandle handle_;
      bool has_query_;
      std::string query_;
      std::vector<std::string> query_params_;
   };

   // -- MANIPULATORS SELECTORS --

   class ManipulatorSelector: public Selector {
   public:

      ManipulatorSelector(DataReader<T>* dr) :
            Selector(dr), read_mode_(true) {
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
         const ::dds::topic::Topic<T>& topic) :
         sub_(sub), topic_(topic), event_forwarder_(0) {
      DDS::DataReaderQos drqos =
            *(DDS::DomainParticipantFactory::datareader_qos_default());
      DDS::DataReader* r = sub_->sub_->create_datareader(topic_->t_, drqos, 0,
            DDS::ANY_STATUS);

      if (r == 0) throw dds::core::PreconditionNotMetError(
            "Unable to create DataReader!");

      raw_reader_ = DR::_narrow(r);
      DDS_DR_REF tmp = DDS_DR_REF(raw_reader_,
            org::opensplice::core::DRDeleter(sub_->sub_));
      reader_ = tmp;
   }

   DataReader(const dds::sub::Subscriber& sub,
         const ::dds::topic::Topic<T>& topic,
         const dds::sub::qos::DataReaderQos& qos) :
         sub_(sub), topic_(topic), raw_reader_(0), qos_(qos), event_forwarder_(
               0) {
      DDS::DataReaderQos drqos =
            *(DDS::DomainParticipantFactory::datareader_qos_default());
      DDS::DataReader* r = sub_->sub_->create_datareader(topic_->t_, drqos,
            event_forwarder_, DDS::ANY_STATUS);

      if (r == 0) {
         throw dds::core::PreconditionNotMetError(
               "Unable to create DataReader!");
      }

      raw_reader_ = DR::_narrow(r);
      DDS_DR_REF tmp = DDS_DR_REF(raw_reader_,
            org::opensplice::core::DRDeleter(sub_->sub_));
      reader_ = tmp;

   }

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

   DataReader(const dds::sub::Subscriber& sub,
         const ::dds::topic::ContentFilteredTopic<T>& topic) :
         raw_reader_(0), event_forwarder_(0) {
   }

   DataReader(const dds::sub::Subscriber& sub,
         const ::dds::topic::ContentFilteredTopic<T>& topic,
         const dds::sub::qos::DataReaderQos& qos,
         dds::sub::DataReaderEventHandler<T>* handler,
         const dds::core::status::StatusMask& mask) :
         raw_reader_(0), event_forwarder_(0) {
   }
#endif /* OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT */

#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT

   DataReader(const dds::sub::Subscriber& pub,
         const ::dds::topic::MultiTopic<T>& topic) {
   }

   DataReader(const dds::sub::Subscriber& pub,
         const ::dds::topic::MultiTopic<T>& topic,
         const dds::sub::qos::DataReaderQos& qos,
         dds::sub::DataReaderEventHandler<T>* handler,
         const dds::core::status::StatusMask& mask) {
   }
#endif /* OMG_DDS_MULTI_TOPIC_SUPPORT */

public:
   // -- Dtor
   ~DataReader() {
      if (event_forwarder_ != 0) {
         raw_reader_->set_listener(0, DDS::STATUS_MASK_NONE);
         delete event_forwarder_;
      }
   }
public:
   void event_handler(dds::sub::DataReaderEventHandler<T>* handler,
         const dds::core::status::StatusMask& mask) {
      if (event_forwarder_ == 0) event_forwarder_ =
            new DataReaderEventForwarder<T>(handler);
      else event_forwarder_->handler_ = handler;
      raw_reader_->set_listener(event_forwarder_, mask.to_ulong());
   }

public:

   const dds::sub::status::DataState& default_status_filter() {
      return status_filter_;
   }

   DataReader& default_status_filter(
         const dds::sub::status::DataState& status) {
      status_filter_ = status;
      return *this;
   }

public:
   // -- Read/Take API
   dds::sub::LoanedSamples<T> take() {
      LoanedSamples<T> ls;
      ls.delegate()->raw_reader(raw_reader_);
      raw_reader_->take(ls.delegate()->data().sequence(),
            ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
            DDS::NOT_READ_SAMPLE_STATE, DDS::ANY_VIEW_STATE,
            DDS::ALIVE_INSTANCE_STATE);
      return ls;
   }

   dds::sub::LoanedSamples<T> read() {
      LoanedSamples<T> ls;
      ls.delegate()->raw_reader(raw_reader_);
      raw_reader_->read(ls.delegate()->data().sequence(),
            ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
            DDS::NOT_READ_SAMPLE_STATE, DDS::ANY_VIEW_STATE,
            DDS::ALIVE_INSTANCE_STATE);
      return ls;
   }

   // --- Forward Iterators: --- //

   template<typename SamplesFWIterator, typename InfoFWIterator>
   uint32_t read(SamplesFWIterator data_begin, InfoFWIterator info_begin,
         uint32_t max_samples) {
      TSeq data;
      DDS::SampleInfoSeq info;
      raw_reader_->read(data, info, max_samples, DDS::NOT_READ_SAMPLE_STATE,
            DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE);

      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);
      return size;
   }

   template<typename SamplesFWIterator, typename InfoFWIterator>
   uint32_t take(SamplesFWIterator data_begin, InfoFWIterator info_begin,
         uint32_t max_samples) {
      TSeq data;
      DDS::SampleInfoSeq info;
      raw_reader_->take(data, info, max_samples, DDS::NOT_READ_SAMPLE_STATE,
            DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE);

      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);
      return size;
   }

   // --- Back-Inserting Iterators: --- //
   template<typename SamplesBIIterator, typename InfoBIIterator>
   uint32_t read(SamplesBIIterator data_begin, InfoBIIterator info_begin) {
      TSeq data;
      DDS::SampleInfoSeq info;
      raw_reader_->read(data, info, DDS::LENGTH_UNLIMITED,
            DDS::NOT_READ_SAMPLE_STATE, DDS::ANY_VIEW_STATE,
            DDS::ALIVE_INSTANCE_STATE);

      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);
      return size;
   }

   template<typename SamplesBIIterator, typename InfoBIIterator>
   uint32_t take(SamplesBIIterator data_begin, InfoBIIterator info_begin) {
      TSeq data;
      DDS::SampleInfoSeq info;
      raw_reader_->take(data, info, DDS::LENGTH_UNLIMITED,
            DDS::NOT_READ_SAMPLE_STATE, DDS::ANY_VIEW_STATE,
            DDS::ALIVE_INSTANCE_STATE);

      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);
      return size;
   }
   //========================================================================
   //== Instance Management
   dds::topic::TopicInstance<T> key_value(const dds::core::InstanceHandle& h) {
      T key_holder;
      raw_reader_->get_key_value(key_holder, h.delegate().handle());
      return dds::topic::TopicInstance<T>(key_holder, h);
   }

   const dds::core::InstanceHandle lookup_instance(const T& key) const {
      DDS::InstanceHandle_t h = raw_reader_->lookup_instance(key);
      if (h == DDS::HANDLE_NIL) return dds::core::InstanceHandle::nil();
      return dds::core::InstanceHandle(h);
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

   //========================================================================
   // -- Entity Navigation
   dds::topic::TopicDescription<T> topic_description() const {
      return this->topic_;
   }
   const dds::sub::Subscriber& subscriber() const {
      return sub_;
   }

   //========================================================================
   // -- QoS
public:
   const dds::sub::qos::DataReaderQos qos() const {
      return qos_;
   }

   void qos(const dds::sub::qos::DataReaderQos& qos) {
      qos_ = qos;
   }

   // ==============================================================
   // == Resource Management
   void close() {
      // TODO: Properly implement close by releasing the DR resources.
      // as well as keeping track of its status.
      // Notice that a trivial implementation  close () (like this) is
      // also compliant with the spec since resources will be collected
      // once the DR reference count drops to zero.
   }
private:
   // ==============================================================
   // == Selector Read/Take API

   dds::sub::LoanedSamples<T> take(const Selector& cmd) {
      dds::sub::LoanedSamples<T> ls;
      if (cmd.has_query_ == false && cmd.handle_.is_nil()) {
         ls.delegate()->raw_reader(raw_reader_);
         raw_reader_->take(ls.delegate()->data().sequence(),
               ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
               cmd.status_.sample_state().to_ulong(),
               cmd.status_.view_state().to_ulong(),
               cmd.status_.instance_state().to_ulong());
      }
      else if (cmd.has_query_ == false && cmd.handle_ != dds::core::null) {
         ls.delegate()->raw_reader(raw_reader_);
         if (cmd.next_instance_ == false) {
            raw_reader_->read_instance(ls.delegate()->data().sequence(),
                  ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
         else {
            raw_reader_->read_next_instance(ls.delegate()->data().sequence(),
                  ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
      }
      else {
         OMG_DDS_LOG("WARNING", "Queries are not supported yet!");
      }

      return ls;
   }

   dds::sub::LoanedSamples<T> read(const Selector& cmd) {
      dds::sub::LoanedSamples<T> ls;
      if (cmd.has_query_ == false && cmd.handle_.is_nil()) {
         ls.delegate()->raw_reader(raw_reader_);
         raw_reader_->read(ls.delegate()->data().sequence(),
               ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
               cmd.status_.sample_state().to_ulong(),
               cmd.status_.view_state().to_ulong(),
               cmd.status_.instance_state().to_ulong());
      }
      else if (cmd.has_query_ == false && cmd.handle_ != dds::core::null) {
         ls.delegate()->raw_reader(raw_reader_);
         if (cmd.next_instance_ == false) {
            raw_reader_->read_instance(ls.delegate()->data().sequence(),
                  ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
         else {
            raw_reader_->read_next_instance(ls.delegate()->data().sequence(),
                  ls.delegate()->info().sequence(), DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());

         }
      }
      else {
         OMG_DDS_LOG("WARNING", "Queries are not supported yet!");
      }

      return ls;
   }

   // --- Forward Iterators: --- //

   template<typename SamplesFWIterator, typename InfoFWIterator>
   uint32_t read(SamplesFWIterator data_begin, InfoFWIterator info_begin,
         uint32_t max_samples, const Selector& cmd) {
      TSeq data;
      DDS::SampleInfoSeq info;

      if (cmd.has_query_ == false && cmd.handle_.is_nil()) {
         raw_reader_->read(data, info, max_samples,
               cmd.status_.sample_state().to_ulong(),
               cmd.status_.view_state().to_ulong(),
               cmd.status_.instance_state().to_ulong());
      }
      else if (cmd.has_query_ == false && cmd.handle_ != dds::core::null) {
         if (cmd.next_instance_ == false) {
            raw_reader_->read_instance(data, info, max_samples,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
         else {
            raw_reader_->read_next_instance(data, info, DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());

         }
      }
      else {
         OMG_DDS_LOG("WARNING", "Queries are not supported yet!");
      }
      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);

      return size;
   }

   template<typename SamplesFWIterator, typename InfoFWIterator>
   uint32_t take(SamplesFWIterator data_begin, InfoFWIterator info_begin,
         uint32_t max_samples, const Selector& cmd) {
      TSeq data;
      DDS::SampleInfoSeq info;

      if (cmd.has_query_ == false && cmd.handle_.is_nil()) {
         raw_reader_->take(data, info, max_samples,
               cmd.status_.sample_state().to_ulong(),
               cmd.status_.view_state().to_ulong(),
               cmd.status_.instance_state().to_ulong());
      }
      else if (cmd.has_query_ == false && cmd.handle_ != dds::core::null) {
         if (cmd.next_instance_ == false) {
            raw_reader_->take_instance(data, info, max_samples,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
         else {
            raw_reader_->take_next_instance(data, info, DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());

         }
      }
      else {
         OMG_DDS_LOG("WARNING", "Queries are not supported yet!");
      }
      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);

      return size;
   }

   // --- Back-Inserting Iterators: --- //

   template<typename SamplesBIIterator, typename InfoBIIterator>
   uint32_t read(SamplesBIIterator data_begin, InfoBIIterator info_begin,
         const Selector& cmd) {
      TSeq data;
      DDS::SampleInfoSeq info;

      if (cmd.has_query_ == false && cmd.handle_.is_nil()) {
         raw_reader_->read(data, info, DDS::LENGTH_UNLIMITED,
               cmd.status_.sample_state().to_ulong(),
               cmd.status_.view_state().to_ulong(),
               cmd.status_.instance_state().to_ulong());
      }
      else if (cmd.has_query_ == false && cmd.handle_ != dds::core::null) {
         if (cmd.next_instance_ == false) {
            raw_reader_->read_instance(data, info, DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
         else {
            raw_reader_->read_next_instance(data, info, DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());

         }
      }
      else {
         OMG_DDS_LOG("WARNING", "Queries are not supported yet!");
      }

      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);

      return size;
   }

   template<typename SamplesBIIterator, typename InfoBIIterator>
   uint32_t take(SamplesBIIterator data_begin, InfoBIIterator info_begin,
         const Selector& cmd) {
      TSeq data;
      DDS::SampleInfoSeq info;
      if (cmd.has_query_ == false && cmd.handle_.is_nil()) {
         raw_reader_->take(data, info, DDS::LENGTH_UNLIMITED,
               cmd.status_.sample_state().to_ulong(),
               cmd.status_.view_state().to_ulong(),
               cmd.status_.instance_state().to_ulong());
      }
      else if (cmd.has_query_ == false && cmd.handle_ != dds::core::null) {
         if (cmd.next_instance_ == false) {
            raw_reader_->take_instance(data, info, DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());
         }
         else {
            raw_reader_->take_next_instance(data, info, DDS::LENGTH_UNLIMITED,
                  cmd.handle_.delegate().handle(),
                  cmd.status_.sample_state().to_ulong(),
                  cmd.status_.view_state().to_ulong(),
                  cmd.status_.instance_state().to_ulong());

         }
      }
      else {
         OMG_DDS_LOG("WARNING", "Queries are not supported yet!");
      }

      uint32_t size = data.length();
      for (uint32_t i = 0; i < size; ++i) {
         *data_begin = data[i];
         *info_begin = *(reinterpret_cast<dds::sub::SampleInfo*>(&info[i]));
         ++data_begin;
         ++info_begin;
      }
      if (size != 0) raw_reader_->return_loan(data, info);

      return size;
   }

private:
   dds::sub::Subscriber sub_;
   dds::topic::Topic<T> topic_;
   DDS_DR_REF reader_;
   DR* raw_reader_;
   dds::sub::qos::DataReaderQos qos_;
   dds::core::status::StatusMask mask_;
   dds::sub::status::DataState status_filter_;
   dds::core::status::LivelinessChangedStatus liveliness_status_;
   dds::core::status::SampleRejectedStatus sample_rejected_status_;
   dds::core::status::SampleLostStatus sample_lost_status_;
   dds::core::status::RequestedDeadlineMissedStatus deadline_missed_status_;
   dds::core::status::RequestedIncompatibleQosStatus incompatible_qos_status_;
   dds::core::status::SubscriptionMatchedStatus subscription_matched_status_;
   DataReaderEventForwarder<T>* event_forwarder_;
};

#endif /* OMG_TDDS_SUB_DETAIL_DATA_READER_HPP_ */
