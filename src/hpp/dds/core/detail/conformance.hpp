#ifndef OMG_DDS_CORE_DETAIL_CONFORMANCE_HPP_
#define OMG_DDS_CORE_DETAIL_CONFORMANCE_HPP_


/* The following macros correspond to the compliance "profiles" of the DDS
 * specification. Implementations shall modify this header to indicate their
 * level of support:
 *      - An implementation fully implementing a given profile shall define
 *        the corresponding macro to "FULL".
 *      - An implementation partially supporting a given profile shall define
 *        the corresponding macro to "PARTIAL".
 *      - And implementation with no support for a given profile shall leave
 *        the corresponding macro undefined.
 *
 * DDS Minimum Profile support is required of all DDS implementations;
 * therefore no corresponding macro is provided.
 */
#define OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT                FULL
// #define OMG_DDS_MULTI_TOPIC_SUPPORT                         FULL
#define OMG_DDS_PERSISTENCE_SUPPORT                         FULL
#define OMG_DDS_OWNERSHIP_SUPPORT                           FULL
#define OMG_DDS_OBJECT_MODEL_SUPPORT                        FULL
// #define OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT   FULL

#define OMG_DDS_HAS_PRETTY_PRINT_COUT 1

#endif /* OMG_DDS_CORE_DETAIL_CONFORMANCE_HPP_ */
