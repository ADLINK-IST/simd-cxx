#ifndef OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_
#define OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_

#include <dds/core/ref_traits.hpp>
#include <org/opensplice/core/ConditionImpl.hpp>
#include <dds/sub/status/DataStatus.hpp>
#include <dds/sub/cond/detail/Executor.hpp>

namespace dds { namespace sub { namespace cond { namespace detail {


template <typename T>
class ReadCondition : public org::opensplice::core::ConditionImpl {

public:
	ReadCondition(const dds::sub::DataReader<T>& dr, const dds::sub::status::DataState& status)
	: dr_(dr),
	  executor_(new TrivialExecutor()),
	  status_(status)
	{ }

	template <typename FUN>
	ReadCondition(const dds::sub::DataReader<T>& dr, const dds::sub::status::DataState& status, const FUN& functor)
	: dr_(dr),
	  executor_(new ParametrizedExecutor<FUN, dds::sub::DataReader<T> >(functor, dr)),
	  status_(status)
	  { }

	virtual void dispatch() { executor_->exec(); }

private:
	dds::sub::DataReader<T> dr_;
	dds::sub::cond::detail::Executor* executor_;
	dds::sub::status::DataState status_;

//public:
//    typedef typename dds::core::smart_ptr_traits< dds::sub::detail::DataReaderHolder<T> >::ref_type
//    DRHolder;
//
//public:
//    ReadCondition(const DRHolder& reader) : reader_(reader) { }
//
//    virtual ~ReadConditionImpl() { }
//
//public:
//    const dds::sub::detail::DataReaderHolder<T>* parent() const {
//        return reader_.get();
//    }
//
//public:
//    // TODO
//
//private:
//    DRHolder reader_;
//

};

} } } }

#endif /* OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_ */
