#ifndef OMG_DDS_SUB_DATA_STATUS_HPP_
#define OMG_DDS_SUB_DATA_STATUS_HPP_

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

#include <bitset>

#include <dds/core/types.hpp>


namespace dds { namespace sub { namespace status {


class SampleState : public std::bitset<OMG_DDS_STATE_BIT_COUNT> {
public:
    typedef std::bitset<OMG_DDS_STATE_BIT_COUNT> MaskType;

public:
    SampleState() : MaskType() { }
    SampleState(const SampleState& src) : MaskType(src) { }
    SampleState(const MaskType& src) : MaskType(src) { }

public:
    inline static const SampleState read() {
        return SampleState(0x0001 << 0u);
    }

    inline static const SampleState not_read() {
        return SampleState(0x0001 << 1u);
    }

    inline static const SampleState any() {
        return SampleState(~0u);
    }

private:
    SampleState(uint32_t i) : MaskType(i) { }
};


class ViewState : public std::bitset<OMG_DDS_STATE_BIT_COUNT> {
public:
    typedef std::bitset<OMG_DDS_STATE_BIT_COUNT> MaskType;

public:
    ViewState() : MaskType() { }
    ViewState(const ViewState& src) : MaskType(src) { }
    ViewState(const MaskType& src) : MaskType(src) { }

public:
    inline static const ViewState new_view() {
        return ViewState(0x0001 << 0u);
    }

    inline static const ViewState not_new_view() {
        return ViewState(0x0001 << 1u);
    }

    inline static const ViewState any() {
        return ViewState(~0u);
    }
private:
    ViewState(uint32_t m) : MaskType(m) { }

};


class InstanceState : public std::bitset<OMG_DDS_STATE_BIT_COUNT> {
public:
    typedef std::bitset<OMG_DDS_STATE_BIT_COUNT> MaskType;

public:
    InstanceState() : MaskType() { }
    InstanceState(const InstanceState& src) : MaskType(src) { }
    InstanceState(const MaskType& src) : MaskType(src) { }

public:
    inline static const InstanceState alive() {
        return InstanceState(0x0001 << 0u);
    }

    inline static const InstanceState not_alive_disposed() {
        return InstanceState(0x0001 << 1u);
    }

    inline static const InstanceState not_alive_no_writers() {
        return InstanceState(0x0001 << 2u);
    }

    inline static const InstanceState not_alive_mask() {
        return not_alive_disposed() | not_alive_no_writers();
    }

    inline static const InstanceState any() {
        return InstanceState(~0u);
    }
private:
    InstanceState(uint32_t m) : MaskType(m) { }

};

class DataState {
public:
	DataState()
	: ss_(dds::sub::status::SampleState::any()),
	  vs_(dds::sub::status::ViewState::any()),
	  is_(dds::sub::status::InstanceState::any())
	{ }

	/* implicit */ DataState(const dds::sub::status::SampleState& ss)
	: ss_(ss),
      vs_(dds::sub::status::ViewState::any()),
      is_(dds::sub::status::InstanceState::any())
	{ }

	/* implicit */ DataState(const dds::sub::status::ViewState& vs)
	: ss_(dds::sub::status::SampleState::any()),
      vs_(vs),
      is_(dds::sub::status::InstanceState::any())
	{ }
    
	/* implicit */ DataState(const dds::sub::status::InstanceState& is)
	: ss_(dds::sub::status::SampleState::any()),
      vs_(dds::sub::status::ViewState::any()),
      is_(is)
	{ }
    
	DataState(const dds::sub::status::SampleState& ss,
			const dds::sub::status::ViewState& vs,
			const dds::sub::status::InstanceState& is)
	: ss_(ss), vs_(vs), is_(is)
	{ }

	DataState& operator << (const dds::sub::status::SampleState& ss) {
		ss_ = ss;
		return *this;
	}
	DataState& operator << (const dds::sub::status::InstanceState& is) {
		is_ = is;
		return *this;
	}
	DataState& operator << (const dds::sub::status::ViewState& vs) {
		vs_ = vs;
		return *this;
	}

	const DataState& operator >> (dds::sub::status::SampleState& ss) const {
		ss = ss_;
		return *this;
	}

	const DataState& operator >> (dds::sub::status::InstanceState& is) const {
		is = is_;
		return *this;
	}

	const DataState& operator >> (dds::sub::status::ViewState& vs) const {
		vs = vs_;
		return *this;
	}

	const dds::sub::status::SampleState& sample_state() const {
		return ss_;
	}

	const void sample_state(const dds::sub::status::SampleState& ss) {
		*this << ss;
	}

	const dds::sub::status::InstanceState& instance_state() const{
		return is_;
	}
	void instance_state(const dds::sub::status::InstanceState& is) {
		*this << is;
	}

	const dds::sub::status::ViewState& view_state() const {
		return vs_;
	}
	void view_state(const dds::sub::status::ViewState& vs) {
		*this << vs;
	}

	static DataState any() {
		return DataState(dds::sub::status::SampleState::any(),
				dds::sub::status::ViewState::any(),
				dds::sub::status::InstanceState::any());
	}

	static DataState new_data() {
		return DataState(dds::sub::status::SampleState::not_read(),
				dds::sub::status::ViewState::any(),
				dds::sub::status::InstanceState::alive());
	}

	static DataState any_data() {
			return DataState(dds::sub::status::SampleState::any(),
					dds::sub::status::ViewState::any(),
					dds::sub::status::InstanceState::alive());
		}

	static DataState new_instance() {
		return DataState(dds::sub::status::SampleState::any(),
				dds::sub::status::ViewState::new_view(),
				dds::sub::status::InstanceState::alive());
	}
private:
	dds::sub::status::SampleState ss_;
	dds::sub::status::ViewState vs_;
	dds::sub::status::InstanceState is_;

};

} } }


#endif /* OMG_DDS_SUB_DATA_STATUS_HPP_ */
