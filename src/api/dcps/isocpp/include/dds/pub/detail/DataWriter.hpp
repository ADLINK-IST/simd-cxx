#ifndef OMG_DDS_PUB_DETAIL_DATA_WRITER_HPP_
#define OMG_DDS_PUB_DETAIL_DATA_WRITER_HPP_

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

#include <dds/topic/Topic.hpp>
#include <org/opensplice/core/EntityDelegate.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <org/opensplice/core/memory.hpp>


namespace dds { namespace pub {

    template <typename T>
    class DataWriterListener;

    namespace detail {
      template <typename T>
      class DataWriter;
    }
  } }
using namespace org::opensplice::core;

template <typename T>
class dds::pub::detail::DataWriter : public  org::opensplice::core::EntityDelegate  {
public:
  typedef typename org::opensplice::topic::topic_data_writer<T>::type DW;

public:
  DataWriter(const ::dds::pub::Publisher& pub,
         const dds::topic::Topic<T>& topic,
         const ::dds::pub::qos::DataWriterQos& qos,
         DataWriterListener<T>* listener,
         const dds::core::status::StatusMask& mask)
    :   pub_(pub),
    topic_(topic),
    qos_(qos),
    listener_(listener),
    mask_(mask)
  {
    DDS::DataWriterQos dwqos;
    pub_->pub_->get_default_datawriter_qos(dwqos);
    DDS::DataWriter* w =
      pub_->pub_->create_datawriter(topic_->t_,
                    dwqos,
                    0,
                    DDS::ANY_STATUS);
    if (w == 0)
      throw dds::core::PreconditionNotMetError("Unable to create DataWriter!");

    raw_writer_ = DW::_narrow(w);
    DDS_DW_REF tmp = DDS_DW_REF(raw_writer_, org::opensplice::core::DWDeleter(pub_->pub_));
    writer_ = tmp;
  }


  virtual ~DataWriter() { }


public:
  void write(const T& sample) {
    raw_writer_->write(sample, DDS::HANDLE_NIL);
  }

  void write(const T& sample, const dds::core::Time& timestamp) {
    std::cout << ">> write(s, ts) >> " << sample << std::endl;
  }

  void write(const T& sample, const ::dds::core::InstanceHandle& instance) {
    std::cout << "write(s+i) >>" << sample << std::endl;
  }

  void write(const T& sample,
         const ::dds::core::InstanceHandle& instance,
         const dds::core::Time& timestamp) {
    std::cout << "write(s+i, ts) >>" << sample << std::endl;
  }

  void write(const dds::topic::TopicInstance<T>& i) {
    std::cout << ">> write(ti)" << std::endl;
  }

  void write(const dds::topic::TopicInstance<T>& i,
         const dds::core::Time& timestamp) {
    std::cout << ">> write(ti, ts)" << std::endl;
  }

  const ::dds::core::InstanceHandle register_instance(const T& key) {
    return dds::topic::TopicInstance<T>(0);
  }


  const ::dds::pub::qos::DataWriterQos& qos() const {
    return qos_;
  }

  void qos(const ::dds::pub::qos::DataWriterQos& the_qos) {
    qos_ = the_qos;
  }

  const dds::topic::Topic<T>& topic() const {
    return topic_;
  }

  const dds::pub::Publisher& publisher() const {
     return pub_;
  }

  bool wait_for_acknowledgments(const ::dds::core::Duration& timeout) {
    return true;
  }

private:
  ::dds::pub::Publisher             pub_;
  dds::topic::Topic<T>            topic_;
  ::dds::pub::qos::DataWriterQos    qos_;
  DataWriterListener<T>*            listener_;
  dds::core::status::StatusMask     mask_;

  DDS_DW_REF writer_;
  DW* raw_writer_;

};




#endif /* OMG_DDS_PUB_DETAIL_DATA_WRITER_HPP_ */
