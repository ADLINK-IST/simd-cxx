#ifndef OMG_DDS_SUB_DATA_READER_HPP_
#define OMG_DDS_SUB_DATA_READER_HPP_

#include <dds/sub/TDataReader.hpp>
#include <dds/sub/detail/DataReader.hpp>


namespace dds { namespace sub {
	template <typename T, template <typename Q> class DELEGATE = dds::sub::detail::DataReader>
	class DataReader;

} }

// = Manipulators
namespace dds { namespace sub { namespace functors {

	typedef dds::sub::functors::detail::ContentFilterManipulatorFunctor ContentFilterManipulatorFunctor;
	typedef dds::sub::functors::detail::StateFilterManipulatorFunctor 	StateFilterManipulatorFunctor;
	typedef dds::sub::functors::detail::InstanceManipulatorFunctor 		InstanceManipulatorFunctor;
	typedef dds::sub::functors::detail::NextInstanceManipulatorFunctor 	NextInstanceManipulatorFunctor;

} } }

namespace dds { namespace sub {

template <typename SELECTOR>
SELECTOR& read(SELECTOR& selector) {
	selector.read_mode(true);
	return selector;
}

template <typename SELECTOR>
SELECTOR& take(SELECTOR& selector) {
	selector.read_mode(false);
	return selector;
}

dds::sub::functors::ContentFilterManipulatorFunctor
filter_content(const dds::core::Query& query) {
	return dds::sub::functors::ContentFilterManipulatorFunctor(query);
}

dds::sub::functors::StateFilterManipulatorFunctor
filter_state(const dds::sub::status::DataState& s) {
	return dds::sub::functors::StateFilterManipulatorFunctor(s);
}

dds::sub::functors::InstanceManipulatorFunctor
instance(const dds::core::InstanceHandle& h) {
	return dds::sub::functors::InstanceManipulatorFunctor(h);
}

dds::sub::functors::NextInstanceManipulatorFunctor
next_instance(const dds::core::InstanceHandle& h) {
	return dds::sub::functors::NextInstanceManipulatorFunctor(h);
}

} }


#endif /* OMG_DDS_SUB_DATA_READER_HPP_ */
