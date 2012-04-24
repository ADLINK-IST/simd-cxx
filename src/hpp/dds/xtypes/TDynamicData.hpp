#ifndef OMG_DDS_DYNAMIC_DATA_HPP_
#define OMG_DDS_DYNAMIC_DATA_HPP_

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

#include <iterator>

#include <dds/core/detail/conformance.hpp>
#include <dds/core/Value.hpp>
#include <tdds/xtypes/tdds_xtypes_fwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


template <typename DELEGATE>
class tdds::type::dynamic::DynamicData : public dds::core::Value<DELEGATE> {

public:
	class MemberDescriptorIterator : public std::iterator<std::forward_iterator_tag, dds::type::dynamic::MemberDescriptor>
	{
	public:
		MemberDescriptorIterator();
		MemberDescriptorIterator(const MemberDescriptorIterator& src);
		~MemberDescriptorIterator();

	public:
		MemberDescriptorIterator&
		operator=(const MemberDescriptorIterator& src);

		bool operator==(const MemberDescriptorIterator& other) const;
		bool operator!=(const MemberDescriptorIterator& other) const;

		MemberDescriptorIterator& operator++();       // prefix
		MemberDescriptorIterator  operator++(int);    // postfix

		dds::type::dynamic::MemberDescriptor& operator*();

		dds::type::dynamic::MemberDescriptor* operator->();

	};

	public:
	class ConstMemberDescriptorIterator : public std::iterator<std::forward_iterator_tag, const dds::type::dynamic::MemberDescriptor>
	{
	public:
		ConstMemberDescriptorIterator();
		ConstMemberDescriptorIterator(const ConstMemberDescriptorIterator& src);
		~ConstMemberDescriptorIterator();

	public:
		ConstMemberDescriptorIterator&
		operator=(const ConstMemberDescriptorIterator& src);

		bool operator==(const ConstMemberDescriptorIterator& other) const;
		bool operator!=(const ConstMemberDescriptorIterator& other) const;

		ConstMemberDescriptorIterator& operator++();       // prefix
		ConstMemberDescriptorIterator  operator++(int);    // postfix

		const dds::type::dynamic::MemberDescriptor& operator*();

		const dds::type::dynamic::MemberDescriptor* operator->();
	};

	public:
	const dds::type::dynamic::DynamicType& type() const;

	MemberDescriptorIterator begin();
	MemberDescriptorIterator end();

	ConstMemberDescriptorIterator begin() const;
	ConstMemberDescriptorIterator end() const;

	dds::type::MemberId member_id(const std::string& name) const;
	dds::type::MemberId member_idx(unsigned long index) const;

	void clear_all_values();
	void clear_nonkey_values();
	void clear_value(dds::type::MemberId id);

	const dds::type::dynamic::DynamicData&
	loan_value(dds::type::MemberId id) const;

	dds::type::dynamic::DynamicData& loan_value(dds::type::MemberId id);
	void return_loaned_value(const dds::type::dynamic::DynamicData& value);

	/**
	 * Implementations shall minimally provide specializations for all DDS
	 * primitive types, strings, wide strings, and DynamicData.
	 */
	template <typename T>
	T value(dds::type::MemberId id) const;

	/**
	 * Implementations shall minimally provide specializations for all DDS
	 * primitive types, strings, wide strings, and DynamicData.
	 */
	template <typename T>
	void value(dds::type::MemberId id, const T& value);

	/**
	 * Implementations shall minimally provide specializations of T for all
	 * DDS primitive types, strings, wide strings, and DynamicData.
	 *
	 * T_FWD_ITER is a forward iterator over elements of type T.
	 *
	 * As an input, element_count indicates the maximum number of elements of
	 * the collection to retrieve into the provided iterator. As an output,
	 * it indicates the number of elements in the collection, regardless of
	 * how many were retrieved. By comparing the input and output values of
	 * this argument, applications can detect overflow and underflow
	 * conditions.
	 */
	template <typename T, typename T_FWD_ITER>
	void values(T_FWD_ITER begin,
			dds::type::MemberId id,
			uint32_t& element_count = dds::core::LENGTH_UNLIMITED) const;

	/**
	 * Implementations shall minimally provide specializations of T for all
	 * DDS primitive types, strings, wide strings, and DynamicData.
	 *
	 * T_RNDA_ITER is a random-access iterator over elements of type T.
	 * However, implementations shall not modify the values within the range
	 * [begin, end).
	 */
	template <typename T, typename T_RNDA_ITER>
	void values(dds::type::MemberId id,
			T_RNDA_ITER begin,
			T_RNDA_ITER end);
};


#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


#endif // !defined(OMG_DDS_DYNAMIC_DATA_HPP_)
