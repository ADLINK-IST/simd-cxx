#ifndef OMG_TDDS_CORE_POLICY_CORE_POLICY_HPP_
#define OMG_TDDS_CORE_POLICY_CORE_POLICY_HPP_

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
#include <dds/core/LengthUnlimited.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/policy/PolicyKind.hpp>

//==============================================================================
// DDS Policy Classes
namespace dds { namespace core { namespace policy {

//==============================================================================
/**
 * The purpose of this QoS is to allow the application to attach additional
 * information to the created Entity objects such that when a remote application
 * discovers their existence it can access that information and use it for its
 * own purposes. One possible use of this QoS is to attach security credentials
 * or some other information that can be used by the remote application to
 * authenticate the source. In combination with operations such as
 * ignore_participant, ignore_publication, ignore_subscription,
 * and ignore_topic these QoS can assist an application to define and enforce
 * its own security policies. The use of this QoS is not limited to security,
 * rather it offers a simple, yet flexible extensibility mechanism.
 */
template <typename D>
class TUserData : public dds::core::Value<D> {
public:
	/**
	 * Create a <code>UserData</code> instance with an empty user data.
	 */
	TUserData() : dds::core::Value<D>() { }

	/**
	 * Create a <code>UserData</code> instance.
	 *
	 * @param seq the sequence of octet representing the user data
	 */
	explicit TUserData(const dds::core::ByteSeq& seq) : dds::core::Value<D>(seq) { }

    //@TODO Implement
	TUserData(const uint8_t* value_begin, const uint8_t* value_end);
    
    TUserData(const TUserData& other) 
        : dds::core::Value<D>(other.value()) 
    { }

public:
	/**
	 * Set the value for the user data.
	 *
	 * @param seq a sequence of bytes representing the user data.
	 */
	void value(const dds::core::ByteSeq& seq) {
		this->delegate().value(seq);
	}

	/**
	 * Set the value for the user data.
	 */
	template <typename OCTET_ITER>
	void value(OCTET_ITER begin, OCTET_ITER end);

	/**
	 * Get the user data.
	 *
	 * @return the sequence of bytes representing the user data
	 */
	const dds::core::ByteSeq value() const {
		return this->delegate().value();
	}

	/**
	 * Get the user data.
	 */
	dds::core::ByteSeq& value(dds::core::ByteSeq& dst) const;

	const uint8_t* begin() const;
	const uint8_t* end() const;
};

//==============================================================================

/**
 * The purpose of this QoS is to allow the application to attach additional
 * information to the created Publisher or Subscriber.
 * The value of the GROUP_DATA is available to the application on the
 * DataReader and DataWriter entities and is propagated by means of the
 * built-in topics. This QoS can be used by an application combination with
 * the DataReaderListener and DataWriterListener to implement matching policies
 * similar to those of the PARTITION QoS except the decision can be made based
 * on an application-defined policy.
 */
template <typename D>
class TGroupData : public dds::core::Value<D> {
public:
	/**
	 * Create a <code>GroupData<code> instance.
	 */
	TGroupData() : dds::core::Value<D>() { }

	/**
	 * Create a <code>GroupData<code> instance.
	 *
	 * @param seq the group data value
	 */
	explicit TGroupData(const dds::core::ByteSeq& seq) : dds::core::Value<D>(seq) { }

	TGroupData(const TGroupData& other) 
		: dds::core::Value<D>(other.value()) 
	{ }

	TGroupData(const uint8_t* value_begin, const uint8_t* value_end);

public:
	/**
	 * Set the value for this <code>GroupData</code>
	 *
	 * @param seq the group data value
	 */
	void value(const dds::core::ByteSeq& seq) {
		this->delegate().value(seq);
	}

	/**
	 * Set the value for this <code>GroupData</code>
	 */
	template <typename OCTET_ITER>
	void value(OCTET_ITER begin, OCTET_ITER end);

	/**
	 * Get the value for this <code>GroupData</code>
	 *
	 * @return  the group data value
	 */
	const dds::core::ByteSeq value() const {
		return this->delegate().value();
	}

	/**
	 * Get the value for this <code>GroupData</code>
	 */
	dds::core::ByteSeq& value(dds::core::ByteSeq& dst) const;

	const uint8_t* begin() const;
	const uint8_t* end() const;
};

//==============================================================================

/**
 * The purpose of this QoS is to allow the application to attach additional
 * information to the created Topic such that when a remote application
 * discovers their existence it can examine the information and use it in
 * an application-defined way. In combination with the listeners on the
 * DataReader and DataWriter as well as by means of operations such as
 * ignore_topic, these QoS can assist an application to extend the provided QoS.
 */
template <typename D>
class TTopicData : public dds::core::Value<D> {
public:
	TTopicData() : dds::core::Value<D>() { }

	explicit TTopicData(const dds::core::ByteSeq& seq) : dds::core::Value<D>(seq) { }

	TTopicData(const TTopicData& other) : dds::core::Value<D>(other.value()) { }

	TTopicData(const uint8_t* value_begin, const uint8_t* value_end);

public:
	/**
	 * Set the value for the topic data.
	 *
	 * @param seq a sequence of bytes representing the topic data.
	 */
	void value(const dds::core::ByteSeq& seq) {
		this->delegate().value(seq);
	}

	/**
	 * Set the value for the topic data.
	 */
	template <typename OCTET_ITER>
	void value(OCTET_ITER begin, OCTET_ITER end);

	/**
	 * Get the topic data.
	 *
	 * @return the sequence of bytes representing the topic data
	 */
	const dds::core::ByteSeq value() const {
		return this->delegate().value();
	}

	/**
	 * Get the topic data.
	 */
	dds::core::ByteSeq& value(dds::core::ByteSeq& dst) const;

	const uint8_t* begin() const;
	const uint8_t* end() const;
};


//==============================================================================

/**
 * This policy controls the behavior of the Entity as a factory for other
 * entities. This policy concerns only DomainParticipant (as factory for
 * Publisher, Subscriber, and Topic), Publisher (as factory for DataWriter),
 * and Subscriber (as factory for DataReader). This policy is mutable.
 * A change in the policy affects only the entities created after the change;
 * not the previously created entities.
 * The setting of autoenable_created_entities to TRUE indicates that the
 * newly created object will be enabled by default.
 * A setting of FALSE indicates that the Entity will not be automatically
 * enabled. The application will need to enable it explicitly by means of the
 * enable operation (see Section 7.1.2.1.1.7, “enable”). The default setting
 * of autoenable_created_entities = TRUE means that, by default, it is not
 * necessary to explicitly call enable on newly created entities.
 */
template <typename D>
class TEntityFactory : public dds::core::Value<D> {
public:
	TEntityFactory() :dds::core::Value<D>(true) { }

	explicit TEntityFactory(bool the_auto_enable)
	: dds::core::Value<D>(the_auto_enable) { }

	TEntityFactory(const TEntityFactory& other)
		: dds::core::Value<D>(other.autoenable_created_entities()) 
	{ }

public:
	void autoenable_created_entities(bool on) {
		this->delegate().auto_enable(on);
	}
	bool autoenable_created_entities() const {
		return this->delegate().auto_enable();
	}

public:
	static TEntityFactory AutoEnable() {
		return TEntityFactory(true);
	}
	static TEntityFactory ManuallyEnable() {
		return TEntityFactory(false);
	}
};

//==============================================================================

/**
 * The purpose of this QoS is to allow the application to take advantage of
 * transports capable of sending messages with different priorities.
 * This policy is considered a hint. The policy depends on the ability of the
 * underlying transports to set a priority on the messages they send.
 * Any value within the range of a 32-bit signed integer may be chosen;
 * higher values indicate higher priority. However, any further interpretation
 * of this policy is specific to a particular transport and a particular
 * implementation of the Service. For example, a particular transport is
 * permitted to treat a range of priority values as equivalent to one another.
 * It is expected that during transport configuration the application would
 * provide a mapping between the values of the TRANSPORT_PRIORITY set on
 * DataWriter and the values meaningful to each transport. This mapping would
 * then be used by the infrastructure when propagating the data written by
 * the DataWriter.
 */
template <typename D>
class TTransportPriority : public dds::core::Value<D> {
public:
	explicit TTransportPriority(int32_t prio) : dds::core::Value<D>(prio) { }
	
    TTransportPriority() : dds::core::Value<D>(0) { }

    TTransportPriority(const TTransportPriority& other) 
        : dds::core::Value<D>(other.value()) 
    { }

public:
	void value(int32_t prio) {
		this->delegate().value(prio);
	}
	int32_t value() const {
		return this->delegate().value();
	}
};

//==============================================================================

/**
 * The purpose of this QoS is to avoid delivering “stale” data to the
 * application. Each data sample written by the DataWriter has an associated
 * expiration time beyond which the data should not be delivered to any
 * application. Once the sample expires, the data will be removed from the
 * DataReader caches as well as from the transient and persistent
 * information caches. The expiration time of each sample is computed by
 * adding the duration specified by the LIFESPAN QoS to the source timestamp.
 * As described in Section 7.1.2.4.2.11, “write and Section 7.1.2.4.2.12,
 * write_w_timestamp the source timestamp is either automatically computed by
 * the Service each time the DataWriter write operation is called, or else
 * supplied by the application by means of the write_w_timestamp operation.
 *
 * This QoS relies on the sender and receiving applications having their clocks
 * sufficiently synchronized. If this is not the case and the Service can
 * detect it, the DataReader is allowed to use the reception timestamp instead
 * of the source timestamp in its computation of the expiration time.
 */
template <typename D>
class TLifespan : public dds::core::Value<D> {
public:
	explicit TLifespan(const dds::core::Duration& d) : dds::core::Value<D>(d) { }

    TLifespan() : dds::core::Value<D>(dds::core::Duration::infinite()) { }
   
    TLifespan(const TLifespan& other) 
        : dds::core::Value<D>(other.duration())
    { }
public:
	void duration(const dds::core::Duration& d) {
		this->delegate().duration(d);
	}
	
    const dds::core::Duration duration() const {
		return this->delegate().duration();
	}
};

//==============================================================================

/**
 * This policy is useful for cases where a Topic is expected to have each
 * instance updated periodically. On the publishing side this setting
 * establishes a contract that the application must meet. On the subscribing
 * side the setting establishes a minimum requirement for the remote publishers
 * that are expected to supply the data values. When the Service ‘matches’ a
 * DataWriter and a DataReader it checks whether the settings are compatible
 * (i.e., offered deadline period<= requested deadline period) if they are not,
 * the two entities are informed (via the listener or condition mechanism)
 * of the incompatibility of the QoS settings and communication will not occur.
 * Assuming that the reader and writer ends have compatible settings, the
 * fulfillment of this contract is monitored by the Service and the application
 * is informed of any violations by means of the proper listener or condition.
 * The value offered is considered compatible with the value requested if and
 * only if the inequality “offered deadline period <= requested deadline period”
 * evaluates to ‘TRUE.’ The setting of the DEADLINE policy must be set
 * consistently with that of the TIME_BASED_FILTER.
 * For these two policies to be consistent the settings must be such that
 * “deadline period>= minimum_separation.”
 */
template <typename D>
class TDeadline : public dds::core::Value<D> {
public:
	explicit TDeadline(const dds::core::Duration& d) : dds::core::Value<D>(d) { }

	TDeadline(const TDeadline& other) : dds::core::Value<D>(other.period()) { }
	
    TDeadline() : dds::core::Value<D>(dds::core::Duration::infinite()) { }

public:
	void period(const dds::core::Duration& d) {
		this->delegate().period(d);
	}
	const dds::core::Duration period() const {
		return this->delegate().period();
	}
};

//==============================================================================

template <typename D>
class TLatencyBudget : public dds::core::Value<D> {
public:
	explicit TLatencyBudget(const dds::core::Duration& d) : dds::core::Value<D>(d) { }

	TLatencyBudget() : dds::core::Value<D>(dds::core::Duration::zero()) { }

	TLatencyBudget(const TLatencyBudget& other) 
		: dds::core::Value<D>(other.duration())
	{ } 
public:
	void duration(const dds::core::Duration& d) {
		this->delegate().duration(d);
	}
	const dds::core::Duration duration() const {
		return this->delegate().duration();
	}
};

//==============================================================================
template <typename D>
class TTimeBasedFilter : public dds::core::Value<D> {
public:
	TTimeBasedFilter() : dds::core::Value<D>(dds::core::Duration::zero()) { }
	
    explicit TTimeBasedFilter(const dds::core::Duration& the_min_separation)
	: dds::core::Value<D>(the_min_separation) { }

    TTimeBasedFilter(const TTimeBasedFilter& other)
        : dds::core::Value<D>(other.minimum_separation())
    { }

public:
	void minimum_separation(const dds::core::Duration& ms) {
		this->delegate().min_separation(ms);
	}
	const dds::core::Duration minimum_separation() const {
		return this->delegate().min_separation();
	}
};


//==============================================================================
template <typename D>
class TPartition : public dds::core::Value<D> {
public:
	explicit TPartition(const std::string& partition) : dds::core::Value<D>() {
		this->delegate().name().push_back(partition);
	}
	explicit TPartition(const dds::core::StringSeq& partitions)
	: dds::core::Value<D>(partitions) { }

	TPartition() : dds::core::Value<D>() {
		this->delegate().name().push_back("");
	}

    TPartition(const TPartition& other) 
        : dds::core::Value<D>(other.name())
    { }

public:
	void name(const dds::core::StringSeq& partitions) {
		this->delegate().name() = partitions;
	}

	const dds::core::StringSeq name() const {
		return this->delegate().name();
	}

	dds::core::StringSeq& name(dds::core::StringSeq& dst) const;
};

//==============================================================================
#ifdef OMG_DDS_OWNERSHIP_SUPPORT

template <typename D>
class TOwnership : public dds::core::Value<D> {
public:
	explicit TOwnership(dds::core::policy::OwnershipKind::Type the_kind)
	: dds::core::Value<D>(the_kind) { }

	TOwnership(const TOwnership& other) : dds::core::Value<D>(other.kind()) { }

	TOwnership() : dds::core::Value<D>(dds::core::policy::OwnershipKind::SHARED) { }


public:
    void kind(dds::core::policy::OwnershipKind::Type the_kind) {
        this->delegate().kind(the_kind);
    }
    dds::core::policy::OwnershipKind::Type kind() const {
        return this->delegate().kind();
    }

public:
	static TOwnership Exclusive() {
		return TOwnership(dds::core::policy::OwnershipKind::EXCLUSIVE);
	}
	static TOwnership Shared() {
		return TOwnership(dds::core::policy::OwnershipKind::SHARED);
	}
};


//==============================================================================


template <typename D>
class TOwnershipStrength : public dds::core::Value<D> {
public:
	explicit TOwnershipStrength(int32_t s) : dds::core::Value<D>(s) { }
    
    TOwnershipStrength(const TOwnershipStrength& other) 
        : dds::core::Value<D>(other.value())
        { }

public:
	int32_t value() const { return this->delegate().strength(); }
	void value(int32_t s) { this->delegate().strength(s); }
};

#endif  // OMG_DDS_OWNERSHIP_SUPPORT


//==============================================================================

template <typename D>
class TWriterDataLifecycle : public dds::core::Value<D> {
public:
	TWriterDataLifecycle() :
		dds::core::Value<D>(true) { }

	explicit TWriterDataLifecycle(bool the_autodispose)
	: dds::core::Value<D>(the_autodispose) { }

    TWriterDataLifecycle(const TWriterDataLifecycle& other)
        : dds::core::Value<D>(other.autodispose_unregistered_instances())
    { }

public:
    bool autodispose_unregistered_instances() const {
        return this->delegate().autodispose();
    }
    void autodispose_unregistered_instances(bool b) {
        this->delegate().autodispose(b);
    }

public:
	static TWriterDataLifecycle AutoDisposeUnregisteredInstances() {
		return TWriterDataLifecycle(true);
	}
	static TWriterDataLifecycle ManuallyDisposeUnregisteredInstances() {
		return TWriterDataLifecycle(false);
	}
};

template <typename D>
class TReaderDataLifecycle : public dds::core::Value<D> {
public:
	TReaderDataLifecycle() :
		dds::core::Value<D>(dds::core::Duration::infinite(),
				dds::core::Duration::infinite())  { }

	TReaderDataLifecycle(const dds::core::Duration& the_nowriter_delay,
			const dds::core::Duration& the_disposed_samples_delay)
	: dds::core::Value<D>(the_nowriter_delay, the_disposed_samples_delay) { }

    TReaderDataLifecycle(const TReaderDataLifecycle& other) 
        : dds::core::Value<D>(other.autopurge_nowriter_samples_delay(), other.autopurge_disposed_samples_delay())
    { }
public:
	const dds::core::Duration autopurge_nowriter_samples_delay() const {
		return this->delegate().autopurge_nowriter_samples_delay();
	}

	void autopurge_nowriter_samples_delay(const dds::core::Duration& d) {
		this->delegate().autopurge_nowriter_samples_delay(d);
	}

	const dds::core::Duration autopurge_disposed_samples_delay() const {
		return this->delegate().autopurge_disposed_samples_delay();
	}

	void autopurge_disposed_samples_delay(const dds::core::Duration& d) {
		this->delegate().autopurge_disposed_samples_delay(d);
	}
public:
	static TReaderDataLifecycle NoAutoPurgeDisposedSamples() {
		return TReaderDataLifecycle();
	}
	static TReaderDataLifecycle AutoPurgeDisposedSamples(const dds::core::Duration& d) {
		return TReaderDataLifecycle(d);
	}
};

//==============================================================================
template <typename D>
class TDurability : public dds::core::Value<D> {
public:
	explicit TDurability(dds::core::policy::DurabilityKind::Type the_kind)
	: dds::core::Value<D>(the_kind) { }

	TDurability(const TDurability& other) : dds::core::Value<D>(other.kind()) { }

	TDurability() : dds::core::Value<D>(dds::core::policy::DurabilityKind::VOLATILE) { }

public:
	void kind(dds::core::policy::DurabilityKind::Type the_kind) {
		this->delegate().kind(the_kind);
	}

	dds::core::policy::DurabilityKind::Type  kind() const {
		return this->delegate().kind();
	}
public:
	static TDurability Volatile() {
		return TDurability(dds::core::policy::DurabilityKind::VOLATILE);
	}
	static TDurability TransientLocal() {
		return TDurability(dds::core::policy::DurabilityKind::TRANSIENT_LOCAL);
	}
	static TDurability Transient() {
		return TDurability(dds::core::policy::DurabilityKind::TRANSIENT);
	}
	static TDurability Persistent() {
		return TDurability(dds::core::policy::DurabilityKind::PERSISTENT);
	}
};
//==============================================================================
template <typename D>
class TPresentation : public dds::core::Value<D> {
public:
	TPresentation()
	:  dds::core::Value<D>(dds::core::policy::PresentationAccessScopeKind::INSTANCE,
			false,
			false) { }

	TPresentation(dds::core::policy::PresentationAccessScopeKind::Type the_access_scope,
			bool the_coherent_access,
			bool the_ordered_access)
	:  dds::core::Value<D>(the_access_scope,
			the_coherent_access,
			the_ordered_access)
			{ }

    TPresentation(const TPresentation& other) : 
        dds::core::Value<D>(other.access_scope(),
            other.coherent_access(),
            other.ordered_access()) 
    { }


public:
	void access_scope(dds::core::policy::PresentationAccessScopeKind::Type  as) {
		this->delegate().access_scope(as);
	}
	dds::core::policy::PresentationAccessScopeKind::Type  access_scope() const {
		return this->delegate().access_scope();
	}

	void coherent_access(bool on) {
		this->delegate().coherent_access(on);
	}
	bool coherent_access() const {
		return this->delegate().coherent_access();
	}

	void ordered_access(bool on) {
		this->delegate().ordered_access(on);
	}
	bool ordered_access() const {
		return this->delegate().ordered_access();
	}
public:
	static TPresentation GroupAccessScope(bool coherent = false, bool ordered = false) {
		return TPresentation(dds::core::policy::PresentationAccessScopeKind::GROUP,
				coherent,
				ordered);
	}
	static TPresentation InstanceAccessScope(bool coherent = false, bool ordered = false) {
		return TPresentation(dds::core::policy::PresentationAccessScopeKind::INSTANCE,
				coherent,
				ordered);
	}
	static TPresentation TopicAccessScope(bool coherent = false, bool ordered = false) {
		return TPresentation(dds::core::policy::PresentationAccessScopeKind::TOPIC,
				coherent,
				ordered);
	}
};

//==============================================================================

template <typename D>
class TReliability : public dds::core::Value<D> {
public:
	TReliability()
	:  dds::core::Value<D>(dds::core::policy::ReliabilityKind::BEST_EFFORT,
			dds::core::Duration::zero()) { }

	TReliability(dds::core::policy::ReliabilityKind::Type the_kind,
			const dds::core::Duration& the_max_blocking_time)
	:  dds::core::Value<D>(the_kind,
			the_max_blocking_time)
			{ }

    TReliability(const TReliability& other) 
        : dds::core::Value<D>(other.kind(), other.max_blocking_time())
    { }

public:

	void kind(dds::core::policy::ReliabilityKind::Type the_kind) {
		this->delegate().kind(the_kind);
	}
	dds::core::policy::ReliabilityKind::Type  kind() const {
		return this->delegate().kind();
	}

	void max_blocking_time(const dds::core::Duration& d) {
		this->delegate().max_blocking_time(d);
	}
	const dds::core::Duration max_blocking_time() const {
		return this->delegate().max_blocking_time();
	}
public:
	static TReliability Reliable(const dds::core::Duration& d = dds::core::Duration::infinite()) {
		return TReliability(dds::core::policy::ReliabilityKind::RELIABLE, d);
	}
	static TReliability BestEffort() {
		return TReliability(dds::core::policy::ReliabilityKind::BEST_EFFORT);
	}
};


//==============================================================================

template <typename D>
class TDestinationOrder : public dds::core::Value<D> {

public:
	explicit TDestinationOrder(dds::core::policy::DestinationOrderKind::Type the_kind)
	: dds::core::Value<D>(the_kind) { }

	TDestinationOrder(const TDestinationOrder& other) 
		: dds::core::Value<D>(other.kind())
	{ }

	TDestinationOrder() :
		dds::core::Value<D>(dds::core::policy::DestinationOrderKind::BY_SOURCE_TIMESTAMP) { }

public:
	void kind(dds::core::policy::DestinationOrderKind::Type the_kind) {
		this->delegate().kind(the_kind);
	}
	dds::core::policy::DestinationOrderKind::Type  kind() const {
		return this->delegate().kind();
	}
public:
	static TDestinationOrder SourceTimestamp() {
		return TDestinationOrder(dds::core::policy::DestinationOrderKind::BY_SOURCE_TIMESTAMP);
	}
	static TDestinationOrder ReceptionTimestamp() {
		return TDestinationOrder(dds::core::policy::DestinationOrderKind::BY_RECEPTION_TIMESTAMP);
	}
};

//==============================================================================
template <typename D>
class THistory : public dds::core::Value<D> {
public:
	THistory()
	:  dds::core::Value<D>(dds::core::policy::HistoryKind::KEEP_LAST, 1) { }


	THistory(dds::core::policy::HistoryKind::Type the_kind, int32_t the_depth)
	: dds::core::Value<D>(the_kind, the_depth) { }

	THistory(const THistory& other) 
		: dds::core::Value<D>(other.kind(), other.depth())
	{ } 

public:
	dds::core::policy::HistoryKind::Type  kind() const {
		return this->delegate().kind();
	}
	void kind(dds::core::policy::HistoryKind::Type the_kind) {
		this->delegate().kind(the_kind);
	}

	int32_t depth() const {
		return this->delegate().depth();
	}
	void depth(int32_t the_depth) {
		this->delegate().depth(the_depth);
	}
public:
	static THistory KeepAll() {
		return THistory(dds::core::policy::HistoryKind::KEEP_ALL);
	}
	static THistory KeepLast(uint32_t depth) {
		return THistory(dds::core::policy::HistoryKind::KEEP_LAST, depth);
	}
};

//==============================================================================

template <typename D>
class TResourceLimits : public dds::core::Value<D> {
public:
	TResourceLimits()
	:  dds::core::Value<D>(dds::core::LENGTH_UNLIMITED,
			dds::core::LENGTH_UNLIMITED,
			dds::core::LENGTH_UNLIMITED) { }

	TResourceLimits(int32_t the_max_samples,
			int32_t the_max_instances,
			int32_t the_max_samples_per_instance)
	:  dds::core::Value<D>(the_max_samples,
			the_max_instances,
			the_max_samples_per_instance)
			{ }

    TResourceLimits(const TResourceLimits& other)
        : dds::core::Value<D>(other.max_samples(), other.max_instances(), other.max_samples_per_instance()) 
    { }

public:
	void max_samples(int32_t samples) {
		this->delegate().max_samples(samples);
	}
	int32_t max_samples() const {
		return this->delegate().max_samples();
	}

	void max_instances(int32_t the_max_instances) {
		this->delegate().max_instances(the_max_instances);
	}
	int32_t max_instances() const {
		return this->delegate().max_instances();
	}

	void max_samples_per_instance(int32_t the_max_samples_per_instance) {
		this->delegate().max_samples_per_instance(the_max_samples_per_instance);
	}
	int32_t max_samples_per_instance() const {
		return this->delegate().max_samples_per_instance();
	}
};



//==============================================================================

template <typename D>
class TLiveliness : public dds::core::Value<D> {
public:
	TLiveliness()
	:  dds::core::Value<D>(dds::core::policy::LivelinessKind::AUTOMATIC,
			dds::core::Duration::infinite()) { }

	TLiveliness(dds::core::policy::LivelinessKind::Type the_kind,
			const dds::core::Duration& the_lease_duration)
	:  dds::core::Value<D>(the_kind, the_lease_duration) { }

    TLiveliness(const TLiveliness& other)
        : dds::core::Value<D>(other.kind(), other.lease_duration())
    { }

public:
	void kind(dds::core::policy::LivelinessKind::Type the_kind) {
		this->delegate().kind(kind);
	}
	dds::core::policy::LivelinessKind::Type kind() const {
		return this->delegate().kind();
	}

	void lease_duration(const dds::core::Duration& the_lease_duration){
		this->delegate().lease_duration(the_lease_duration);
	}
	const dds::core::Duration lease_duration() const {
		return this->delegate().lease_duration();
	}
public:
	static TLiveliness Automatic() {
		return TLiveliness(dds::core::policy::LivelinessKind::AUTOMATIC, dds::core::Duration::infinite());
	}
	static TLiveliness ManualByParticipant(const dds::core::Duration& lease = dds::core::Duration::infinite()) {
		return TLiveliness(dds::core::policy::LivelinessKind::MANUAL_BY_PARTICIPANT, lease);
	}
	static TLiveliness ManualByTopic(const dds::core::Duration& lease = dds::core::Duration::infinite()) {
		return TLiveliness(dds::core::policy::LivelinessKind::MANUAL_BY_TOPIC, lease);
	}
};

 
//==============================================================================

#ifdef OMG_DDS_PERSISTENCE_SUPPORT

template <typename D>
class TDurabilityService : public dds::core::Value<D> {
public:
	TDurabilityService() :
		dds::core::Value<D>() { }

	TDurabilityService(
			const dds::core::Duration& the_service_cleanup_delay,
			dds::core::policy::HistoryKind::Type the_history_kind,
			int32_t the_history_depth,
			int32_t the_max_samples,
			int32_t the_max_instances,
			int32_t the_max_samples_per_instance)
	: dds::core::Value<D>(the_service_cleanup_delay,
			the_history_kind,
			the_history_depth,
			the_max_samples,
			the_max_instances,
			the_max_samples_per_instance) { }

	TDurabilityService(const TDurabilityService& other) 
		: dds::core::Value<D>(other.service_cleanup_delay(),
			other.history_kind(), other.history_depth(),
			other.max_samples(), other.max_instances(), other.max_samples_per_instance()) 
	{ }
			

public:
	void service_cleanup_delay(const dds::core::Duration& d)  {
		this->delegate().service_cleanup_delay(d);
	}
	const dds::core::Duration service_cleanup_delay() const {
		return this->delegate().service_cleanup_delay();
	}

	void history_kind(dds::core::policy::HistoryKind::Type the_kind) {
		this->delegate().history_kind(the_kind);
	}
	dds::core::policy::HistoryKind::Type history_kind() const {
		return this->delegate().history_kind();
	}

	void history_depth(int32_t the_depth) {
		this->delegate().history_depth(the_depth);
	}
	int32_t history_depth() const {
		return this->delegate().history_depth();
	}

	void max_samples(int32_t the_max_samples) {
		this->delegate().max_samples(the_max_samples);
	}
	int32_t max_samples() const {
		return this->delegate().max_samples();
	}

	void max_instances(int32_t the_max_instances) {
		this->delegate().the_max_instances(the_max_instances);
	}
	int32_t max_instances() const {
		return this->delegate().max_instances();
	}

	void max_samples_per_instance(int32_t the_max_samples_per_instance) {
		this->delegate().the_max_instances(
				the_max_samples_per_instance);
	}
	int32_t max_samples_per_instance() const {
		return this->delegate().max_samples_per_instance();
	}
};

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


//============================================================================

//============================================================================

#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

template <typename D>
class TDataRepresentation : public dds::core::Value<D> {

public:
    explicit TDataRepresentation(
        const dds::core::policy::DataRepresentationIdSeq& value);

    TDataRepresentation(const TDataRepresentation& other)
        : dds::core::Value<D>(other.value())
    { }
public:
    void value(const dds::core::policy::DataRepresentationIdSeq& value);

    const dds::core::policy::DataRepresentationIdSeq value() const;

    dds::core::policy::DataRepresentationIdSeq&
    value(dds::core::policy::DataRepresentationIdSeq& dst) const;
};

#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)


//============================================================================

#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

template <typename D>
class TTypeConsistencyEnforcement : public dds::core::Value<D> {
public:
    explicit TTypeConsistencyEnforcement(dds::core::policy::TypeConsistencyEnforcementKind::Type kind);

public:
    void kind(dds::core::policy::TypeConsistencyEnforcementKind::Type  value);
    dds::core::policy::TypeConsistencyEnforcementKind::Type  kind() const;
};

#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)


//==============================================================================


} } } 

#endif /* OMG_TDDS_CORE_POLICY_CORE_POLICY_HPP_ */

