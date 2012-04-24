#ifndef DDS_CORE_DETAIL_QUERY_HPP_
#define DDS_CORE_DETAIL_QUERY_HPP_

#include <vector>
#include <iterator>

namespace dds { namespace core { namespace detail {
	class Query;
} } }

class dds::core::detail::Query {
public:
	typedef std::vector<std::string>::iterator iterator;
	typedef std::vector<std::string>::const_iterator const_iterator;

public:
	Query(const std::string& query_expression)
	: expression_(query_expression) { }


	template <typename FWIterator>
	Query(const std::string& query_expression,
		  const FWIterator& params_begin, const FWIterator& params_end)
	: expression_(query_expression)
	  {
		std::copy(params_begin, params_end, std::back_insert_iterator<std::vector<std::string> >(params_));
	  }


	const std::string& expression() {
		return expression_;
	}

	/**
	 * Provides the begin iterator to the parameter list.
	 */
	iterator begin() {
		return params_.begin();
	}

	/**
	 * The end iterator to the parameter list.
	 */
	iterator end() {
		return params_.end();
	}

	template <typename FWIterator>
	void parameters(const FWIterator& begin, const FWIterator end) {
		params_.erase(params_.begin(), params_.end());
		std::copy(begin, end, std::back_insert_iterator<std::vector<std::string> >(params_));
	}

	void add_parameter(const std::string& param) {
		params_.push_back(param);
	}

	uint32_t parameters_length() {
		return params_.size();
	}

private:
	std::string expression_;
	std::vector<std::string> params_;

};


#endif /* DDS_CORE_DETAIL_QUERY_HPP_ */
