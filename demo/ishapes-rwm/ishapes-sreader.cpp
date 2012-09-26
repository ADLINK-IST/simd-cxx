// Std C++ Include
#include <algorithm>

// Utils 
#include "util.hpp"

int main(int argc, char* argv[]) {
  try {
    DomainParticipant dp(0);
    Topic<ShapeType> topic(dp, "Circle");
    Subscriber sub(dp);
    DataReader<ShapeType> dr(sub, topic);
      
    uint32_t sleepTime = 100000;

    while (true) {
      // If you can use C++11 then the "auto" keywork and "lambda"
      // function can make this code even nicer.
      std::cout << "--------------------------------------------" << std::endl;
      LoanedSamples<ShapeType> samples;
      dr >> filter_state(DataState::any_data()) >> take >> samples;
      std::for_each(samples.data().begin(), samples.data().end(), demo::ishapes::printShape);
      usleep(sleepTime);
    }
  } catch (const dds::core::Exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}


