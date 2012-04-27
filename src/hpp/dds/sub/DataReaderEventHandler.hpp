#ifndef OMG_DDS_SUB_DATA_READER_EVENT_HANDLER_HPP_
#define OMG_DDS_SUB_DATA_READER_EVENT_HANDLER_HPP_

namespace dds {
  namespace sub {
    template <typename T>
    class DataReaderListener;

    template <typename T> 
    class DataReaderEventHandler {
    public:
      virtual ~DataReaderEventHandler() { }

    public:
      virtual void 
      on_requested_deadline_missed(const dds::core::status::RequestedDeadlineMissedStatus& status) = 0;
    
      virtual void 
      on_requested_incompatible_qos(const dds::core::status::RequestedIncompatibleQosStatus& status) = 0;
      
      virtual void 
      on_sample_rejected(const dds::core::status::SampleRejectedStatus& status) = 0;
      
      virtual void 
      on_liveliness_changed(const dds::core::status::LivelinessChangedStatus& status) = 0;
      
      virtual void 
      on_data_available() = 0;
      
      virtual void 
      on_subscription_matched(const dds::core::status::SubscriptionMatchedStatus& status) = 0;
      
      virtual void 
      on_sample_lost(const dds::core::status::SampleLostStatus& status) = 0;

      virtual DataReaderListener<T>* listener() = 0;
      virtual void listener(DataReaderListener<T>* l) = 0;
    };
  }
}
#endif /* OMG_DDS_SUB_DATA_READER_EVENT_HANDLER_HPP_ */
