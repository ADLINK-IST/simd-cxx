#ifndef ORG_OPENSPLICE_SUB_QOS_QOSCONVERTER_HPP_
#define ORG_OPENSPLICE_SUB_QOS_QOSCONVERTER_HPP_

#include <dds/core/types.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <org/opensplice/core/config.hpp>

namespace org {
   namespace opensplice {
      namespace sub {
         namespace qos {
            dds::sub::qos::DataReaderQos
            convertQos(const DDS::DataReaderQos& from);

            DDS::DataReaderQos
            convertQos(const dds::sub::qos::DataReaderQos& from);
         }
      }
   }
}

#endif /* ORG_OPENSPLICE_SUB_QOS_QOSCONVERTER_HPP_ */
