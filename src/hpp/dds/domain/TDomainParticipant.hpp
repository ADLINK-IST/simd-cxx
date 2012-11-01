#ifndef OMG_TDDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_
#define OMG_TDDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_

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

#include <string>

#include <dds/core/detail/conformance.hpp>
#include <dds/core/types.hpp>
#include <dds/core/Time.hpp>
#include <dds/core/TEntity.hpp>
#include <dds/core/cond/StatusCondition.hpp>
#include <dds/domain/types.hpp>
#include <dds/domain/qos/DomainParticipantQos.hpp>

#include <dds/topic/qos/TopicQos.hpp>

#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>


namespace dds { namespace domain {

    template <typename DELEGATE>
    class TDomainParticipant;

    class DomainParticipantListener;
} }

/**
 * The <code>DomainParticipant</code> object plays several roles:
 * <ul>
 *   <li>
 *     It represents the participation of the application on a communication
 *     plane that isolates applications running on the same set of physical
 *     computers from each other. A domain establishes a virtual network
 *     linking all applications that share the same domainId and isolating
 *     them from applications running on different domains. In this way,
 *     several independent distributed applications can coexist in the same
 *     physical network without interfering, or even being aware of each
 *     other.
 *   </li>
 * </ul>
 */
template <typename DELEGATE>
class dds::domain::TDomainParticipant : public ::dds::core::TEntity<DELEGATE> {
public:
    typedef dds::domain::DomainParticipantListener Listener;

public:
    /**
     * Create a new <code>DomainParticipant</code> object.
     * The <code>DomainParticipant</code> signifies that the calling
     * application intends to join the Domain identified by the domain_id
     * argument.
     * The <code>DomainParticipant</code> will be created with
     * <code>DomainParticipantQos</code> passed as argument.
     *
     * @param id the id of the domain joined by the new
     *           <code>DomainParticipant</code>.
     *
     */
    TDomainParticipant(uint32_t did)
    : ::dds::core::TEntity<DELEGATE>(new DELEGATE(did)) { }

    /**
     * Create a new <code>DomainParticipant</code> object.
     * The <code>DomainParticipant</code> signifies that the calling
     * application intends to join the Domain identified by the domain_id
     * argument.
     * The <code>DomainParticipant</code> will be created with
     * <code>DomainParticipantQos</code> passed as argument.
     *
     * @param id the id of the domain joined by this <code>DomainParticipant</code>.
     * @param qos the QoS settings for this <code>DomainParticipant</code>
     */
    TDomainParticipant(uint32_t                                            id,
                       const dds::domain::qos::DomainParticipantQos&     qos,
                       dds::domain::DomainParticipantListener*           listener = NULL,
                       const dds::core::status::StatusMask&              mask = dds::core::status::StatusMask::all())
    : ::dds::core::TEntity<DELEGATE>(new DELEGATE(id,
                                                  qos,
                                                  listener,
                                                  mask)) { }

public:
    OMG_DDS_BASIC_REF_TYPE(TDomainParticipant, ::dds::core::TEntity, DELEGATE)

public:
    ~TDomainParticipant() {
        // OMG_DDS_LOG("MM", "~DomainParticipant()");
    }

public:

    /**
     * Register a listener with the <core>DomainParticipant</code>.
     * The notifications received by the listener depend on the
     * status mask with which it was registered.
     *
     * @param listener the listener
     * @param event_mask the mask defining the events for which the listener
     *  will be notified.
     */
    void listener(Listener* the_listener,
            const ::dds::core::status::StatusMask& event_mask) {
        this->delegate()->listener(the_listener, event_mask);
    }

    /**
     * Get the listener of this <code>DomainParticipant</code>
     */
    Listener* listener() const {
        return this->delegate()->listener();
    }


    /**
     * Return the <code>DomainParticipantQos</code> setting for this instance.
     *
     * @return the qos setting.
     */
    const dds::domain::qos::DomainParticipantQos&
    qos() const {
        return this->delegate()->qos();
    }

    void qos(const dds::domain::qos::DomainParticipantQos& the_qos) {
        this->delegate()->qos(the_qos);
    }

    /**
     * This operation retrieves the domain_id used to create the
     * <code>DomainParticipant</code>. The domain_id identifies the DDS domain
     * to which the <code>DomainParticipant</code> belongs.
     * As described in the introduction to Section 7.1.2.2.1,
     * DomainParticipant Class, on page 22 each DDS domain represents a
     * separate data communication plane isolated from other domains.
     *
     * @return the domain id
     */
    uint32_t domain_id() const {
        return this->delegate()->domain_id();
    }


    /**
     * This operation manually asserts the liveliness of the DataWriter.
     * This is used in combination with the LIVELINESS QoS policy
     * (see Section 7.1.3, Supported QoS, on page 96) to indicate to the
     * Service that the entity remains active.
     * This operation need only be used if the LIVELINESS setting is either
     * MANUAL_BY_PARTICIPANT or MANUAL_BY_TOPIC. Otherwise, it has no effect.
     *
     * <b>Note</b> Writing data via the write operation on a DataWriter
     * asserts liveliness on the DataWriter itself and its DomainParticipant.
     * Consequently the use of assert_liveliness is only needed if the
     * application is not writing data regularly.
     */
    void
    assert_liveliness() {
        this->delegate()->assert_liveliness();
    }


    /**
     * This operation checks whether or not the given a_handle represents
     * an Entity that was created from the DomainParticipant.
     * The containment applies recursively. That is, it applies both to
     * entities (TopicDescription, Publisher, or Subscriber) created directly
     * using the DomainParticipant as well as entities created using a
     * contained Publisher, or Subscriber as the factory, and so forth.
     *
     * @param handle the instance handle for which the containement
     *               relationship has to be checked.
     *
     * @return true if the handle belongs to an <code>Entity</code> belonging
     *              to this <code>DomainParticipant</code>
     */
    bool
    contains_entity(const ::dds::core::InstanceHandle& handle) {
        return this->delegate()->contains_entity();
    }

    /**
     * This operation returns the current value of the time that the service
     * uses to time-stamp data writes and to set the reception timestamp
     * for the data updates it receives.
     */
    dds::core::Time
    current_time() {
        return this->delegate()->current_time();
    }

public:
    // --- DomainParticipant QoS Defaults --- //
    static dds::domain::qos::DomainParticipantQos default_participant_qos() {
        return DELEGATE::default_participant_qos();
    }

    static void default_participant_qos(const ::dds::domain::qos::DomainParticipantQos& qos) {
        DELEGATE::default_participant_qos(qos);
    }

    // --- Publisher QoS Defaults --- //
    dds::pub::qos::PublisherQos default_publisher_qos() const {
        return this->delegate()->default_publisher_qos();
    }
    TDomainParticipant& default_publisher_qos(const ::dds::pub::qos::PublisherQos& qos) {
        this->delegate()->default_publisher_qos(qos);
        return *this;
    }

    // --- Subscriber QoS Defaults --- //
    dds::sub::qos::SubscriberQos default_subscriber_qos() const {
        return this->delegate()->default_subscriber_qos();
    }

    TDomainParticipant& default_subscriber_qos(const ::dds::sub::qos::SubscriberQos& qos) {
        this->delegate()->default_subscriber_qos(qos);
        return *this;
    }

    // --- Topic QoS Defaults --- //
    dds::topic::qos::TopicQos default_topic_qos() const {
        return this->delegate()->default_topic_qos();
    }

    TDomainParticipant& default_topic_qos(const dds::topic::qos::TopicQos& qos) {
        this->delegate()->default_topic_qos(qos);
        return *this;
    }

//=============================================================================
};


#endif /* OMG_TDDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_ */
