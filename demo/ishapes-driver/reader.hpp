#ifndef ORG_OPENSPLICE_DEMO_ISHAPES_READER_HPP_
#define ORG_OPENSPLICE_DEMO_ISHAPES_READER_HPP_

#include "util.hpp"
#include <unistd.h>
#include <vector>
#include <algorithm>

namespace demo {
   namespace ishapes {
      template<typename T>
      class Reader;
   }
}
/**
 * This class shows a sample use of the (forward) iterator-based read API.
 * Beware that a back-inserting iterator API also exist.
 *
 */
template<typename T>
class demo::ishapes::Reader: public demo::ishapes::Runner<T> {
public:
   virtual ~Reader() {
   }

public:
   virtual void run(const dds::domain::DomainParticipant& dp,
         const dds::topic::Topic<T>& topic, const Params& params)
   {
      dds::sub::Subscriber sub(dp);
      dds::sub::qos::DataReaderQos drqos =
            sub.default_datareader_qos()
            << dds::core::policy::History::KeepLast(params.history_depth);


      dds::sub::DataReader<T> dr(dp, topic, drqos);
      const uint32_t period = params.period;
      const uint32_t samples = params.samples;
      const uint32_t max_samples = 16;
      const uint32_t sleep_time = period * 1000;

      std::vector<ShapeType> data(max_samples);
      std::vector<dds::sub::SampleInfo> info(max_samples);

      for (uint32_t i = 0; i < samples; ++i) {
         int32_t rs =
               dr.selector()
                  .filter_state(params.data_state)
                  .read(data.begin(), info.begin(), max_samples);

         std::cout << "==== Read " << rs << " sample(s) ==== \n";
         std::for_each(data.begin(), data.begin() + rs, printShape);
         std::cout << std::endl;
         usleep(sleep_time); // period is in ms
      }
   }
};

#endif /* ORG_OPENSPLICE_DEMO_ISHAPES_READER_HPP_ */
