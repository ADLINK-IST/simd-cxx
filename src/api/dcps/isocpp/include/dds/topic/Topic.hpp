#ifndef OMG_DDS_TOPIC_TOPIC_HPP_
#define OMG_DDS_TOPIC_TOPIC_HPP_

#include <dds/topic/detail/Topic.hpp>
#include <dds/topic/TTopic.hpp>

namespace dds { namespace topic {
    template <typename T, template <typename Q> class DELEGATE = dds::topic::detail::Topic>
    class Topic;
} }

#endif /* OMG_DDS_TOPIC_TOPIC_HPP_ */
