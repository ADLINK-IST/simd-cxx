#ifndef ORG_OPENSPLICE_SUB_SUBSCRIBER_DELEGATE_HPP_
#define ORG_OPENSPLICE_SUB_SUBSCRIBER_DELEGATE_HPP_


#include <org/opensplice/core/EntityDelegate.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/core/status/State.hpp>
#include <dds/core/cond/StatusCondition.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>
#include <dds/domain/DomainParticipant.hpp>

namespace dds { namespace sub {
   class SubscriberListener;
} }

namespace org { namespace opensplice { namespace sub {

class SubscriberDelegate : public org::opensplice::core::EntityDelegate {
public:

public:
	SubscriberDelegate(
			const dds::domain::DomainParticipant& dp,
			const dds::sub::qos::SubscriberQos& the_qos,
			dds::sub::SubscriberListener* the_listener,
			const dds::core::status::StatusMask& event_mask);

	virtual ~SubscriberDelegate();

public:
	/**
	 * Returns a <code>StatusCondition</code> instance associated with
	 * this <code>Entity</code>.
	 */
	template <typename SELF>
	::dds::core::cond::StatusCondition<SELF>
	status_condition(const SELF& self) const {
		return ::dds::core::cond::StatusCondition<SELF>(
				new dds::core::cond::detail::StatusCondition<SELF>(self));
	}

public:
	/**
	 * This operation invokes the operation on_data_available on the
	 * DataReaderListener objects attached to contained DataReader
	 * entities with a DATA_AVAILABLE status that is considered changed
	 * as described in Section 7.1.4.2.2, Changes in Read Communication
	 * Statuses.
	 */
	void notify_datareaders();

	const dds::domain::DomainParticipant& parent() const;

	const dds::sub::qos::SubscriberQos qos() const;

	void qos(const dds::sub::qos::SubscriberQos& the_qos);

private:
   dds::domain::DomainParticipant dp_;
   dds::sub::qos::SubscriberQos qos_;
   dds::sub::SubscriberListener* listener_;
   dds::core::status::StatusMask mask_;

public:
   dds::core::smart_ptr_traits<DDS::Subscriber>::ref_type sub_;
   

};

} } }

#endif /* ORG_OPENSPLICE_SUB_SUBSCRIBER_DELEGATE_HPP_ */


