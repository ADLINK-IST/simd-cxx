#include <org/opensplice/sub/SubscriberDelegate.hpp>
#include <org/opensplice/core/memory.hpp>

namespace org {
   namespace opensplice {
      namespace sub {

         SubscriberDelegate::SubscriberDelegate(
               const dds::domain::DomainParticipant& dp,
               const dds::sub::qos::SubscriberQos& the_qos,
               dds::sub::SubscriberListener* the_listener,
               const dds::core::status::StatusMask& event_mask) :
               dp_(dp), qos_(the_qos), listener_(the_listener), mask_(
                     event_mask) {
            DDS::SubscriberQos sqos;
            dp->dp_->get_default_subscriber_qos(sqos);

            DDS::Subscriber* s = dp->dp_->create_subscriber(sqos, 0,
                  DDS::ANY_STATUS);

            if (s == 0) throw dds::core::PreconditionNotMetError(
                  "Exception, Unable create Subscriber!");

            sub_.reset(s, ::org::opensplice::core::SubDeleter(dp_->dp_));
         }

         SubscriberDelegate::~SubscriberDelegate() {
         }

         void SubscriberDelegate::notify_datareaders() {

         }

         const dds::domain::DomainParticipant&
         SubscriberDelegate::parent() const {
            return dp_;
         }

         const dds::sub::qos::SubscriberQos SubscriberDelegate::qos() const {
            return dds::sub::qos::SubscriberQos();
         }

         void SubscriberDelegate::qos(
               const dds::sub::qos::SubscriberQos& the_qos) {
            // implementation-defined
         }

         const dds::sub::qos::DataReaderQos
         SubscriberDelegate::default_datareader_qos() const {
            return default_dr_qos_;
         }

         void
         SubscriberDelegate::default_datareader_qos(const dds::sub::qos::DataReaderQos &qos) {

         }

      }
   }
}
