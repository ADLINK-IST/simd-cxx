#ifndef OMG_DDS_TOPIC_DETAIL_TOPIC_FWD_HPP_
#define OMG_DDS_TOPIC_DETAIL_TOPIC_FWD_HPP_

#include <org/opensplice/topic/topicfwd.hpp>


namespace dds { namespace topic {

namespace detail {
    typedef org::opensplice::topic::BuiltinTopicKeyImpl
    BuiltinTopicKeyImpl;

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
    template <typename T>
    class ContentFilteredTopic;
#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
    template <typename T>
    class MultiTopic;
#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

    typedef org::opensplice::topic::ParticipantBuiltinTopicDataImpl
    ParticipantBuiltinTopicDataImpl;

    typedef org::opensplice::topic::PublicationBuiltinTopicDataImpl
    PublicationBuiltinTopicDataImpl;

    typedef org::opensplice::topic::SubscriptionBuiltinTopicDataImpl
    SubscriptionBuiltinTopicDataImpl;

    typedef org::opensplice::topic::TopicBuiltinTopicDataImpl
    TopicBuiltinTopicDataImpl;

    template <typename T>
    class Topic;
}   // namespace dds::topic::detail


namespace qos { namespace detail {
    typedef tdds::core::qos::EntityQos<org::opensplice::qos::TopicQosImpl> TopicQos;
} } // namespace dds::topic::qos::detail

} }

#endif /* OMG_DDS_TOPIC_DETAIL_TOPIC_FWD_HPP_ */
