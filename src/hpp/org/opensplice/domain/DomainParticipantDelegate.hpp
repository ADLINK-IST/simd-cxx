#ifndef ORG_OPENSPLICE_DOMAIN_DOMAIN_PARTICIPANT_DELEGATE_HPP_
#define ORG_OPENSPLICE_DOMAIN_DOMAIN_PARTICIPANT_DELEGATE_HPP_


// DDS-PSM-Cxx Includes
#include <dds/core/ref_traits.hpp>
#include <dds/core/Time.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/core/status/State.hpp>
#include <dds/topic/qos/TopicQos.hpp>


// OpenSplice Includes
#include <org/opensplice/core/config.hpp>
#include <org/opensplice/core/EntityDelegate.hpp>


namespace dds {
    namespace domain {
        class DomainParticipantListener;
    }
}

namespace org { namespace opensplice { namespace domain {
	class DomainParticipantDelegate;
} } }

class org::opensplice::domain::DomainParticipantDelegate :
	public virtual  ::org::opensplice::core::EntityDelegate
{
public:
    explicit DomainParticipantDelegate(uint32_t id);

    DomainParticipantDelegate(uint32_t id,
                          const dds::domain::qos::DomainParticipantQos& qos,
                          dds::domain::DomainParticipantListener* listener,
                          const dds::core::status::StatusMask&);

    virtual ~DomainParticipantDelegate();

public:
    /*
    void listener(::dds::domain::DomainParticipantListener* listener,
                  const ::dds::core::status::StatusMask& event_mask);
*/
    dds::domain::DomainParticipantListener* listener() const;

public:
    const dds::domain::qos::DomainParticipantQos qos() const;

    void qos(const dds::domain::qos::DomainParticipantQos& qos);

    /**
     * Returns a <code>StatusCondition</code> instance associated with
     * this <code>Entity</code>.
     */
    /*
    template <typename SELF>
    ::dds::core::cond::StatusCondition<SELF>
    status_condition(const SELF& self) const {
        return ::dds::core::cond::StatusCondition<SELF>(
                new dds::core::cond::detail::StatusCondition<SELF>(self));
    }
*/
    uint32_t domain_id();

    void assert_liveliness();

    bool contains_entity(const ::dds::core::InstanceHandle& handle);

    dds::core::Time current_time();

    void close();

    const dds::topic::qos::TopicQos& default_topic_qos() const;
    void default_topic_qos(const dds::topic::qos::TopicQos& qos);
    
    const ::dds::pub::qos::PublisherQos& default_publisher_qos() const;
    void default_publisher_qos(const ::dds::pub::qos::PublisherQos& qos);
    
    const ::dds::sub::qos::SubscriberQos& default_subscriber_qos() const;
    void default_subscriber_qos(const ::dds::sub::qos::SubscriberQos& qos);
    
    const ::dds::domain::qos::DomainParticipantQos& default_domain_qos();
    void default_domain_qos(const ::dds::domain::qos::DomainParticipantQos& qos);

private:

    dds::domain::qos::DomainParticipantQos qos_;
    dds::topic::qos::TopicQos default_topic_qos_;
    dds::pub::qos::PublisherQos default_pub_qos_;
    dds::sub::qos::SubscriberQos default_sub_qos_;
    dds::domain::qos::DomainParticipantQos default_domain_qos_;

public:
    dds::core::smart_ptr_traits<DDS::DomainParticipant>::ref_type dp_;

};

#endif /* ORG_OPENSPLICE_DOMAIN_DOMAIN_PARTICIPANT_DELEGATE_HPP_ */
