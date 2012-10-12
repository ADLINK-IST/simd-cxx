#ifndef OMG_DDS_CORE_QOS_DETAIL_QOS_PROVIDER_HPP_
#define OMG_DDS_CORE_QOS_DETAIL_QOS_PROVIDER_HPP_


/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Inc.
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


namespace dds {
   namespace core {
      namespace qos {
         namespace detail {
            class QosProvider;
         }
      }
   }
}

class dds::core::qos::detail::QosProvider {
public:
   explicit QosProvider(const std::string& uri) { }

   explicit QosProvider(const std::string& uri, const std::string& id) { }

   dds::domain::qos::DomainParticipantQos
   participant_qos() {
      return dds::domain::qos::DomainParticipantQos();
   }

   dds::domain::qos::DomainParticipantQos
   participant_qos(const std::string& id) {
      return dds::domain::qos::DomainParticipantQos();
   }


   dds::topic::qos::TopicQos
   topic_qos() {
      return dds::topic::qos::TopicQos();
   }

   dds::topic::qos::TopicQos
   topic_qos(const std::string& id) {
      return dds::topic::qos::TopicQos();
   }


   dds::sub::qos::SubscriberQos
   subscriber_qos() {
      return dds::sub::qos::SubscriberQos();
   }

   dds::sub::qos::SubscriberQos
   subscriber_qos( const std::string& id) {
      return dds::sub::qos::SubscriberQos();
   }

   dds::sub::qos::DataReaderQos
   datareader_qos() {
      return dds::sub::qos::DataReaderQos();
   }

   dds::sub::qos::DataReaderQos
   datareader_qos( const std::string& id) {
      return dds::sub::qos::DataReaderQos();
   }

   dds::pub::qos::PublisherQos
   publisher_qos() {
      return dds::pub::qos::PublisherQos();
   }

   dds::pub::qos::PublisherQos
   publisher_qos( const std::string& id) {
      return dds::pub::qos::PublisherQos();
   }

   dds::pub::qos::DataWriterQos
   datawriter_qos() {
      return dds::pub::qos::DataWriterQos();
   }

   dds::pub::qos::DataWriterQos
   datawriter_qos( const std::string& id) {
      return dds::pub::qos::DataWriterQos();
   }
};

#endif /* OMG_DDS_CORE_QOS_DETAIL_QOS_PROVIDER_HPP_ */
