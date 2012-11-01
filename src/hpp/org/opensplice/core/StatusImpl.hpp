#ifndef ORG_OPENSPLICE_CORE_STATUS_STATUS_IMPL_HPP_
#define ORG_OPENSPLICE_CORE_STATUS_STATUS_IMPL_HPP_

namespace org {
  namespace opensplice {
    namespace core {

      class InconsistentTopicStatusImpl {
      public:
    InconsistentTopicStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }
      protected:
    int32_t total_count_;
    int32_t total_count_change_;
      };


      class SampleLostStatusImpl {
      public:
    SampleLostStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }
      protected:
    int32_t total_count_;
    int32_t total_count_change_;
      };

      class SampleRejectedStatusImpl  {
      public:
    SampleRejectedStatusImpl()
      : last_reason_(dds::core::status::SampleRejectedState::not_rejected()){ }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

    dds::core::status::SampleRejectedState last_reason() const {
      return last_reason_;
    }

    const dds::core::InstanceHandle last_instance_handle() const {
      return last_instance_handle_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
    dds::core::status::SampleRejectedState last_reason_;
    dds::core::InstanceHandle last_instance_handle_;
      };


      class LivelinessLostStatusImpl  {
      public:
    LivelinessLostStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
      };


      class LivelinessChangedStatusImpl  {
      public:
    LivelinessChangedStatusImpl() { }

      public:

    int32_t alive_count() const {
      return alive_count_;
    }

    int32_t not_alive_count() const {
      return not_alive_count_;
    }

    int32_t alive_count_change() const {
      return alive_count_;
    }

    int32_t not_alive_count_change() const {
      return not_alive_count_;
    }

      protected:
    int32_t alive_count_;
    int32_t not_alive_count_;
    int32_t alive_count_change_;
    int32_t not_alive_count_change_;
      };

      class OfferedDeadlineMissedStatusImpl {
      public:
    OfferedDeadlineMissedStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
      };

      class RequestedDeadlineMissedStatusImpl {
      public:
    RequestedDeadlineMissedStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

    const dds::core::InstanceHandle last_instance_handle() const {
      return last_instance_handle_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
    dds::core::InstanceHandle last_instance_handle_;
      };


      class OfferedIncompatibleQosStatusImpl {
      public:
    OfferedIncompatibleQosStatusImpl() { }

      public  :
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

    dds::core::policy::QosPolicyId last_policy_id() const {
      return last_policy_id_;
    }

    const dds::core::policy::QosPolicyCountSeq policies() const {
      return policies_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
    dds::core::policy::QosPolicyId last_policy_id_;
    dds::core::policy::QosPolicyCountSeq policies_;
      };

      class RequestedIncompatibleQosStatusImpl {
      public:
    RequestedIncompatibleQosStatusImpl() { }

      public  :
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

    dds::core::policy::QosPolicyId last_policy_id() const {
      return last_policy_id_;
    }

    const dds::core::policy::QosPolicyCountSeq policies() const {
      return policies_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
    dds::core::policy::QosPolicyId last_policy_id_;
    dds::core::policy::QosPolicyCountSeq policies_;

      };


      class PublicationMatchedStatusImpl {
      public:
    PublicationMatchedStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

    int32_t current_count() const {
      return current_count_;
    }

    int32_t current_count_change() const {
      return current_count_change_;
    }

    const dds::core::InstanceHandle last_subscription_handle() const {
      return last_subscription_handle_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
    int32_t current_count_;
    int32_t current_count_change_;
    dds::core::InstanceHandle last_subscription_handle_;
      };

      class SubscriptionMatchedStatusImpl {
      public:
    SubscriptionMatchedStatusImpl() { }

      public:
    int32_t total_count() const {
      return total_count_;
    }

    int32_t total_count_change() const {
      return total_count_change_;
    }

    int32_t current_count() const {
      return current_count_;
    }

    int32_t current_count_change() const {
      return current_count_change_;
    }

    const dds::core::InstanceHandle last_publication_handle() const {
      return last_publication_handle_;
    }

      protected:
    int32_t total_count_;
    int32_t total_count_change_;
    int32_t current_count_;
    int32_t current_count_change_;
    dds::core::InstanceHandle last_publication_handle_;

      };

    } } }  /* namespace org::opensplice::core */

#endif /* ORG_OPENSPLICE_CORE_STATUS_STATUS_IMPL_HPP_ */
