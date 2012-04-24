#ifndef OMG_DDS_SUB_DETAIL_EXECUTOR_HPP_
#define OMG_DDS_SUB_DETAIL_EXECUTOR_HPP_


namespace dds { namespace sub { namespace cond { namespace detail {
	class Executor {
	public:
		virtual ~Executor() { }

		virtual void exec() = 0;
	};

	class TrivialExecutor : public Executor {
	public:
		virtual ~TrivialExecutor() { }
		virtual void exec() { }
	};

	template <typename FUN, typename ARG>
	class ParametrizedExecutor : public Executor {
	public:
		ParametrizedExecutor(const FUN& fun, const ARG& arg) : fun_(fun), arg_(arg) { }
		virtual ~ParametrizedExecutor() { }
		virtual void exec() { fun_(arg_); }

	private:
		FUN fun_;
		ARG arg_;
	};
} } } }


#endif /* OMG_DDS_SUB_DETAIL_EXECUTOR_HPP_ */
