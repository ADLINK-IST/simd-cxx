#ifndef OMG_TDDS_XTYPES_TYPE_OBJECT_HPP_
#define OMG_TDDS_XTYPES_TYPE_OBJECT_HPP_

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

#include <string>

#include <dds/core/corefwd.hpp>
#include <dds/core/Value.hpp>
#include <tdds/xtypes/tdds_xtypes_fwd.hpp>


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


// --- Annotation usage: -------------------------------------------------

/**
 * Literal value of an annotation member: either the default value in its
 * definition or the value applied in its usage.
 */
template <typename DELEGATE>
class tdds::type::typeobject::AnnotationMemberValue : public dds::core::Value<DELEGATE>
{
    
public:
    dds::type::TypeKind discriminator() const;
    void discriminator(dds::type::TypeKind d);
    
    bool as_bool() const;
    void as_bool(bool value);
    
    uint8_t as_byte() const;
    void as_byte(uint8_t value);
    
    int16_t as_int16() const;
    void as_int_16(int16_t value);
    
    uint16_t as_uint16() const;
    void as_uint_16(uint16_t value);
    
    int32_t as_int32() const;
    void as_int_32(int32_t value);
    
    uint32_t as_uint32() const;
    void as_uint32(uint32_t value);
    
    int32_t as_int64() const;
    void as_int64(int32_t value);
    
    uint64_t as_uint64() const;
    void as_uint64(uint64_t value);
    
    float as_float32() const;
    void as_float32(float value);
    
    double as_float64() const;
    void as_float64(double value);
    
    ldouble_t as_float128() const;
    void as_float128(ldouble_t value);
    
    char as_char() const;
    void as_char(char value);
    
    wchar_t as_wchar() const;
    void as_wchar(wchar_t value);
    
    int as_enum();
    void as_enum(int value);
    
    const std::string as_string();
    void as_string(const std::string& value);
    
    const std::wstring as_wstring();
    void as_wstring(const std::wstring& value);
};


/**
 * The assignment of a value to a member of an annotation.
 */
template <typename DELEGATE>
class tdds::type::typeobject::AnnotationUsageMember : public dds::core::Value<DELEGATE>
{
    
public:
    /**
     * Member of the annotation type
     */
    dds::type::MemberId member_id() const;
    void member_id(dds::type::MemberId id);
    
    /**
     * Value that member is set to
     */
    const dds::type::typeobject::AnnotationMemberValue value() const;
    void value(const dds::type::typeobject::AnnotationMemberValue& value);
};


/**
 * The application of an annotation to some type or type member
 */
template <typename DELEGATE>
class tdds::type::typeobject::AnnotationUsage : public dds::core::Value<DELEGATE>
{
    
public:
    dds::type::typeobject::TypeId type_id() const;
    void type_id(dds::type::typeobject::TypeId id);
    
    const dds::type::typeobject::AnnotationUsageMemberSeq member() const;
    dds::type::typeobject::AnnotationUsageMemberSeq& member(
        dds::type::typeobject::AnnotationUsageMemberSeq& dst);
    void member(const dds::type::typeobject::AnnotationUsageMemberSeq& src);
};


// --- Type base class: --------------------------------------------------

/**
 * Fundamental properties of any type definition
 */
template <typename DELEGATE>
class tdds::type::typeobject::TypeProperty : public dds::core::Value<DELEGATE>
{
    
public:
    const dds::type::typeobject::TypeFlag::Mask flag() const;
    void flag(const dds::type::typeobject::TypeFlag::Mask& mask);
    
    dds::type::typeobject::TypeId type_id() const;
    void type_id(dds::type::typeobject::TypeId id);
    
    const std::string name();
    void name(const std::string& name);
};


/**
 * Base type for all type definitions
 */
template <typename DELEGATE>
class tdds::type::typeobject::Type : public dds::core::Value<DELEGATE>
{
protected:
    Type(const DELEGATE& src);

public:
    virtual ~Type();
    
public:
    /**
     * Member IDs used in the Type base type
     */
    enum MemberId
    {
        PROPERTY_TYPE_MEMBER_ID   = 0,
        ANNOTATION_TYPE_MEMBER_ID = 1
    };
    
public:
    const dds::type::typeobject::TypeProperty property() const;
    void property(const dds::type::typeobject::TypeProperty& value);
    
    const dds::type::typeobject::AnnotationUsageSeq annotation() const;
    dds::type::typeobject::AnnotationUsageSeq& annotation(
        dds::type::typeobject::AnnotationUsageSeq& dst);
    void annotation(const dds::type::typeobject::AnnotationUsageSeq& value);
};


// --- Aggregations: -----------------------------------------------------

/**
 * Fundamental properties of any aggregation type member
 */
template <typename DELEGATE>
class tdds::type::typeobject::MemberProperty : public dds::core::Value<DELEGATE>
{
    
public:
    const dds::type::typeobject::MemberFlag::Mask flag() const;
    void flag(const dds::type::typeobject::MemberFlag::Mask& value);
    
    dds::type::MemberId member_id() const;
    void member_id(dds::type::MemberId value);
    
    dds::type::typeobject::TypeId type_id() const;
    void type_id(dds::type::typeobject::TypeId value);
    
    const std::string name() const;
    void name(const std::string& value);
};


/**
 * Member of an aggregation type
 */
template <typename DELEGATE>
class tdds::type::typeobject::Member : public dds::core::Value<DELEGATE>
{
protected:
    Member(const DELEGATE& src);

public:
    virtual ~Member();

public:
    /**
     * Member IDs used in the Member base type
     */
    enum MemberId {
        PROPERTY_MEMBER_MEMBER_ID   = 0,
        ANNOTATION_MEMBER_MEMBER_ID = 1
    };
    
public:
    const dds::type::typeobject::MemberProperty property() const;
    void property(const dds::type::typeobject::MemberProperty& value);
    
    const dds::type::typeobject::AnnotationUsageSeq annotation();
    dds::type::typeobject::AnnotationUsageSeq& annotation(
        dds::type::typeobject::AnnotationUsageSeq& dst);
    void annotation(const dds::type::typeobject::AnnotationUsageSeq& value);
};


template <typename DELEGATE>
class tdds::type::typeobject::StructureMember : public Member<DELEGATE>
{
};


template <typename DELEGATE>
class tdds::type::typeobject::StructureType : public Type<DELEGATE>
{

public:
    /**
     * Member IDs used in the StructureType type
     */
    enum MemberId
    {
        BASE_TYPE_STRUCTURETYPE_MEMBER_ID = 100,
        MEMBER_STRUCTURETYPE_MEMBER_ID    = 101
    };

public:
    dds::type::typeobject::TypeId base_type() const;
    void base_type(dds::type::typeobject::TypeId value);

    const dds::type::typeobject::StructureMemberSeq member() const;
    dds::type::typeobject::StructureMemberSeq& member(
        dds::type::typeobject::StructureMemberSeq& dst) const;
    void member(const dds::type::typeobject::StructureMemberSeq& value);
};


/**
 * Member of a union type
 */
template <typename DELEGATE>
class tdds::type::typeobject::UnionMember : public Member<DELEGATE>
{

public:
    /**
     * Member IDs used in the UnionMember type
     */
    enum MemberId
    {
        LABEL_UNIONMEMBER_MEMBER_ID = 100
    };

public:
    const dds::type::UnionCaseLabelSeq label() const;

    dds::type::UnionCaseLabelSeq&
    label(dds::type::UnionCaseLabelSeq& dst) const;

    void label(const dds::type::UnionCaseLabelSeq& value);
};


template <typename DELEGATE>
class tdds::type::typeobject::UnionType : public Type<DELEGATE>
{

public:
    /**
     * Member IDs used in the UnionType type
     */
    enum MemberId
    {
        MEMBER_UNIONTYPE_MEMBER_ID = 100
    };

public:
    const dds::type::typeobject::UnionMemberSeq member() const;
    dds::type::typeobject::UnionMemberSeq& member(
        dds::type::typeobject::UnionMemberSeq& dst) const;
    void member(const dds::type::typeobject::UnionMemberSeq& value);
};


/**
 * Member of an annotation type
 */
template <typename DELEGATE>
class tdds::type::typeobject::AnnotationMember : public Member<DELEGATE>
{

public:
    /**
     * Member IDs used in the AnnotationMember type
     */
    enum MemberId
    {
        DEFAULT_VALUE_ANNOTATIONMEMBER_MEMBER_ID = 100
    };

public:
    const dds::type::typeobject::AnnotationMemberValue default_value() const;
    dds::type::typeobject::AnnotationMemberValue& default_value(
        dds::type::typeobject::AnnotationMemberValue& dst) const;
    void default_value(
        const dds::type::typeobject::AnnotationMemberValue& value);
};


template <typename DELEGATE>
class tdds::type::typeobject::AnnotationType : public Type<DELEGATE>
{

public:
    /**
     * Member IDs used in the AnnotationType type
     */
    enum MemberId
    {
        BASE_TYPE_ANNOTATIONTYPE_MEMBER_ID  = 100,
        MEMBER_ANNOTATIONTYPE_MEMBER_ID     = 101
    };

public:
    dds::type::typeobject::TypeId base_type() const;
    void base_type(dds::type::typeobject::TypeId value);

    const dds::type::typeobject::AnnotationMemberSeq member() const;
    dds::type::typeobject::AnnotationMemberSeq& member(
        dds::type::typeobject::AnnotationMemberSeq& dst) const;
    void member(const dds::type::typeobject::AnnotationMemberSeq& value);
};


// --- Alias: ------------------------------------------------------------

template <typename DELEGATE>
class tdds::type::typeobject::AliasType : public Type<DELEGATE>
{

public:
    /**
     * Member IDs used in the AliasType type
     */
    enum MemberId
    {
        BASE_TYPE_ALIASTYPE_MEMBER_ID = 100
    };

public:
    dds::type::typeobject::TypeId base_type() const;
    void base_type(dds::type::typeobject::TypeId value);
};


// --- Collection type: ------------------------------------------------------

/**
 * Base type for collection types
 */
template <typename DELEGATE>
class tdds::type::typeobject::CollectionType : public Type<DELEGATE>
{
protected:
    CollectionType(const DELEGATE& src);

public:
    virtual ~CollectionType();

public:
    /**
     * Member IDs used in the CollectionType base type
     */
    enum MemberId
    {
        ELEMENT_TYPE_COLLECTIONTYPE_MEMBER_ID = 100
    };

public:
    dds::type::typeobject::TypeId element_type() const;
    void element_type(dds::type::typeobject::TypeId value);
};


template <typename DELEGATE>
class tdds::type::typeobject::ArrayType : public CollectionType<DELEGATE>
{

public:
    /**
     * Member IDs used in the ArrayType type
     */
    enum MemberId
    {
        BOUND_ARRAYTYPE_MEMBER_ID = 200
    };

public:
    const dds::type::BoundSeq bound() const;
    dds::type::BoundSeq& bound(
        dds::type::BoundSeq& dst) const;
    void bound(const dds::type::BoundSeq& value);
};


template <typename DELEGATE>
class tdds::type::typeobject::MapType : public CollectionType<DELEGATE>
{

public:
    /**
     * Member IDs used in the MapType type
     */
    enum MemberId
    {
        KEY_ELEMENT_TYPE_MAPTYPE_MEMBER_ID  = 200,
        BOUND_MAPTYPE_MEMBER_ID             = 201
    };

public:
    dds::type::typeobject::TypeId key_element_type() const;
    void key_element_type(dds::type::typeobject::TypeId value);

    dds::type::Bound bound() const;
    void bound(dds::type::Bound value);
};


template <typename DELEGATE>
class tdds::type::typeobject::SequenceType : public CollectionType<DELEGATE>
{

public:
    /**
     * Member IDs used in the SequenceType type
     */
    enum MemberId
    {
        BOUND_SEQUENCETYPE_MEMBER_ID = 200
    };

public:
    dds::type::Bound bound() const;
    void bound(dds::type::Bound value);
};


template <typename DELEGATE>
class tdds::type::typeobject::StringType : public CollectionType<DELEGATE>
{

public:
    /**
     * Member IDs used in the StringType type
     */
    enum MemberId
    {
        BOUND_STRINGTYPE_MEMBER_ID = 200
    };

public:
    dds::type::Bound bound() const;
    void bound(dds::type::Bound value);
};


// --- Bit set: --------------------------------------------------------------

/**
 * Bit in a bit set
 */
template <typename DELEGATE>
class tdds::type::typeobject::Bit : public dds::core::Value<DELEGATE>
{

public:
    int32_t index() const;
    void index(int32_t value);

    const std::string name() const;
    void name(const std::string& value);
};


template <typename DELEGATE>
class tdds::type::typeobject::BitSetType : public Type<DELEGATE>
{

public:
    /**
     * Member IDs used in the BitSetType type
     */
    enum MemberId
    {
        BIT_BOUND_BITSETTYPE_MEMBER_ID  = 100,
        BIT_BITSETTYPE_MEMBER_ID        = 101
    };

public:
    dds::type::Bound bit_bound() const;
    void bit_bound(dds::type::Bound value);

    const dds::type::typeobject::BitSeq bit() const;
    dds::type::typeobject::BitSeq&
    bit(dds::type::typeobject::BitSeq& dst) const;
    void bit(const dds::type::typeobject::BitSeq& value);
};


// --- Enumeration: ----------------------------------------------------------

/**
 * Constant in an enumeration type
 */
template <typename DELEGATE>
class tdds::type::typeobject::EnumeratedConstant : public dds::core::Value<DELEGATE>
{

public:
    int32_t value() const;
    void value(int32_t value);

    const std::string name() const;
    void name(const std::string& value);
};


/**
 * Enumeration type
 */
template <typename DELEGATE>
class tdds::type::typeobject::EnumerationType : public Type<DELEGATE>
{

public:
    /**
     * Member IDs used in the EnumerationType type
     */
    enum MemberId
    {
        BIT_BOUND_ENUMERATIONTYPE_MEMBER_ID = 100,
        CONSTANT_ENUMERATIONTYPE_MEMBER_ID  = 101
    };

public:
    dds::type::Bound bit_bound() const;
    void bit_bound(dds::type::Bound value);

    const dds::type::typeobject::EnumeratedConstantSeq constant() const;
    dds::type::typeobject::EnumeratedConstantSeq&
    constant(dds::type::typeobject::EnumeratedConstantSeq& dst) const;
    void constant(const dds::type::typeobject::EnumeratedConstantSeq& value);
};


// --- Module: -----------------------------------------------------------

template <typename DELEGATE>
class tdds::type::typeobject::Module : public dds::core::Value<DELEGATE>
{

public:
    const std::string name() const;
    void name(const std::string& value);

    const dds::type::typeobject::TypeLibrary& library() const;
    void library(const dds::type::typeobject::TypeLibrary& value);
};


// --- Type library: ---------------------------------------------------------

/**
 * Element that can appear in a type library or module: a type or module
 */
template <typename DELEGATE>
class tdds::type::typeobject::TypeLibraryElement : public dds::core::Value<DELEGATE>
{

public:
    /**
     * All of the kinds of definitions that can exist in a type library
     */
    enum Kind
    {
        ALIAS_TYPE_ELEMENT        = dds::type::ALIAS_TYPE,
        ANNOTATION_TYPE_ELEMENT   = dds::type::ANNOTATION_TYPE,
        ARRAY_TYPE_ELEMENT        = dds::type::ARRAY_TYPE,
        BITSET_TYPE_ELEMENT       = dds::type::BITSET_TYPE,
        ENUMERATION_TYPE_ELEMENT  = dds::type::ENUMERATION_TYPE,
        MAP_TYPE_ELEMENT          = dds::type::MAP_TYPE,
        SEQUENCE_TYPE_ELEMENT     = dds::type::SEQUENCE_TYPE,
        STRING_TYPE_ELEMENT       = dds::type::STRING_TYPE,
        STRUCTURE_TYPE_ELEMENT    = dds::type::STRUCTURE_TYPE,
        UNION_TYPE_ELEMENT        = dds::type::UNION_TYPE,
        
        MODULE_ELEMENT         // = auto-assigned value
    };
    
public:
    Kind discriminator() const;
    void discriminator(Kind d);

    const dds::type::typeobject::AliasType& alias_type() const;
    void alias_type(const dds::type::typeobject::AliasType& value);

    const dds::type::typeobject::AnnotationType& annotation_type() const;
    void annotation_type(const dds::type::typeobject::AnnotationType& value);

    const dds::type::typeobject::ArrayType& array_type() const;
    void array_type(const dds::type::typeobject::ArrayType& value);

    const dds::type::typeobject::BitSetType& bitset_type() const;
    void bitset_type(const dds::type::typeobject::BitSetType& value);

    const dds::type::typeobject::EnumerationType& enumeration_type() const;
    void
    enumeration_type(const dds::type::typeobject::EnumerationType& value);

    const dds::type::typeobject::MapType& map_type() const;
    void map_type(const dds::type::typeobject::MapType& value);

    const dds::type::typeobject::SequenceType& sequence_type() const;
    void sequence_type(const dds::type::typeobject::SequenceType& value);

    const dds::type::typeobject::StringType& string_type() const;
    void string_type(const dds::type::typeobject::StringType& value);

    const dds::type::typeobject::StructureType& structure_type() const;
    void structure_type(const dds::type::typeobject::StructureType& value);

    const dds::type::typeobject::UnionType& union_type() const;
    void union_type(const dds::type::typeobject::UnionType& value);

    const dds::type::typeobject::Module& mod() const;
    void mod(const dds::type::typeobject::Module& value);
};


template <typename DELEGATE>
class tdds::type::typeobject::TypeLibrary : public dds::core::Value<DELEGATE>
{
    
public:
    const dds::type::typeobject::TypeLibraryElementSeq element() const;
    dds::type::typeobject::TypeLibraryElementSeq&
    element(dds::type::typeobject::TypeLibraryElementSeq& dst) const;
    void element(const dds::type::typeobject::TypeLibraryElementSeq& value);
};


/**
 * Central type of this Type Representation: identifies a single type
 * within a library.
 */
template <typename DELEGATE>
class tdds::type::typeobject::TypeObject : public dds::core::Value<DELEGATE>
{

public:
    const dds::type::typeobject::TypeLibrary& library() const;
    void library(const dds::type::typeobject::TypeLibrary& value);

    dds::type::typeobject::TypeId the_type() const;
    void the_type(dds::type::typeobject::TypeId value);
};


#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT


#endif // !defined(OMG_TDDS_XTYPES_TYPE_OBJECT_HPP_)
