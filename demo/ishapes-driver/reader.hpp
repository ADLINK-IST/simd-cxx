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


      dds::sub::DataReader<T> dr(sub, topic, drqos);
      const uint32_t period = params.period;
      const uint32_t samples = params.samples;
      const uint32_t max_samples = 16;
      const uint32_t sleep_time = period * 1000;

      std::vector<ShapeType> data(max_samples);
      std::vector<dds::sub::SampleInfo> info(max_samples);

      dds::sub::qos::DataReaderQos qos = dr.qos();

      AnyTopic at = topic;
      Topic<ShapeType> xt = at.get<ShapeType>();

      Filter filter("x > 200 AND y > 100");
      ContentFilteredTopic<ShapeType> cft(topic, "CFCircle", filter);

      DataReader<ShapeType> cfdr(sub, cft);

      // Query
      Query q(dr, "x < 100 AND y < 100");


      // AnyDataReader
      AnyDataReader adr = q.data_reader();
      dds::sub::DataReader<ShapeType> xdr = adr.get<ShapeType>();

      // Conditions
      cond::ReadCondition rc(dr, params.data_state);
      cond::QueryCondition qc(q, params.data_state);

      dds::core::Entity e = dr;
      dds::core::cond::StatusCondition sc(dr);
      sc.enabled_statuses(StatusMask::data_available());

      Subscriber xsub = dr.subscriber();

      WaitSet ws;
      ws
         .attach_condition(sc)
         .attach_condition(rc)
         .attach_condition(qc);

      LoanedSamples<ShapeType> loaned_samples = dr.read();

      for (uint32_t i = 0; i < samples; ++i) {
         int32_t rs =
               dr.selector()
                  .filter_state(params.data_state)
                  .filter_content(q)
                  .read(data.begin(), info.begin(), max_samples);

         std::cout << "==== Read " << rs << " sample(s) ==== \n";
         std::for_each(data.begin(), data.begin() + rs, printShape);
         std::cout << std::endl;
         usleep(sleep_time);

         LoanedSamples<ShapeType> loaned_samples =
               dr.selector()
                        .filter_state(params.data_state)
                        .filter_content(q)
                        .read();

         std::cout << "==== Read Loaned Sample(s) ==== \n";
         std::for_each(loaned_samples.data().begin(), loaned_samples.data().end(), printShape);
         std::cout << std::endl;
         usleep(sleep_time);
         std::cout << "============================ \n";
      }
   }
};

#endif /* ORG_OPENSPLICE_DEMO_ISHAPES_READER_HPP_ */
