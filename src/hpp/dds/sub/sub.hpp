#ifndef OMG_DDS_SUB_PACKAGE_INCLUDE_HPP_
#define OMG_DDS_SUB_PACKAGE_INCLUDE_HPP_

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

/////////////////////////////////////////////////////////////////////////////
// -- Status Includes
#include <dds/sub/status/DataStatus.hpp>


/////////////////////////////////////////////////////////////////////////////
// -- QoS Includes
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>

/////////////////////////////////////////////////////////////////////////////
// -- Sub Includes

#include <dds/sub/Rank.hpp>
#include <dds/sub/GenerationCount.hpp>



/*
 * Depends on:
 *  <dds/sub/GenerationCount.hpp>
 *  <dds/sub/Rank.hpp>
 */

#include <dds/sub/SampleInfo.hpp>

/*
 * Depends on:
 *   <dds/sub/status/ReaderState.hpp>
 *   <dds/sub/SampleInfo.hpp>
 */
#include <dds/sub/Sample.hpp>

/*
 * Depends on:
 *    <dds/sub/Sample.hpp>
 */
#include <dds/sub/LoanedSamples.hpp>


/* Depends on:
 *  <dds/sub/qos/SubscriberQos.hpp>
 *  <dds/sub/qos/DataReaderQos.hpp>
 */
#include <dds/sub/Subscriber.hpp>


/* Depends on:
 *    <dds/sub/Subscriber.hpp>
 */
#include <dds/sub/CoherentAccess.hpp>

/* Depends on:
 *  <dds/sub/Subscriber.hpp>
 */
#include <dds/sub/AnyDataReader.hpp>

#include <dds/sub/AnyDataReaderListener.hpp>

/* Depends on:
 * <dds/sub/AnyDataReaderListener.hpp>
 * <dds/sub/Subscriber.hpp>
 */
#include <dds/sub/SubscriberListener.hpp>

/* Depends on:
 *   <dds/sub/Subscriber.hpp>
 *   <dds/sub/status/DataStatus.hpp>
 *   <dds/sub/Sample.hpp>
 *   <dds/sub/LoanedSamples.hpp>
 */
#include <dds/sub/DataReader.hpp>
#include <dds/sub/DataReaderListener.hpp>

/////////////////////////////////////////////////////////////////////////////
// -- Condition Includes
/* Depends on:
 *   <dds/sub/DataReader.hpp>
 */
#include <dds/sub/cond/ReadCondition.hpp>

/* Depends on:
 *    <dds/sub/status/DataStatus.hpp>
 */
#include <dds/sub/cond/QueryCondition.hpp>

/* Depends on:
 *   <dds/sub/Subscriber.hpp>
 *   <dds/sub/status/ReaderState.hpp>
 */
#include <dds/sub/find.hpp>

#endif /* OMG_DDS_SUB_PACKAGE_INCLUDE_HPP_ */
