//
//  EnumClass.h
//  ArticleEnumClass
//
//  Created by Gabriel Aubut-Lussier on 16-02-16.
//  Copyright © 2016 Gabriel Aubut-Lussier. All rights reserved.
//

#ifndef EnumClass_h
#define EnumClass_h

#include <type_traits>

// Credits to Anthony Williams for inspiring me with this opt-in mecanism
// https://www.justsoftwaresolutions.co.uk/cplusplus/using-enum-classes-as-bitfields.html
template<typename T>
struct enable_enum_class_bitfield
{
	static constexpr bool value = false;
};

#define enableEnumClassBitfield(T) template<> \
struct enable_enum_class_bitfield<T> \
{ \
static constexpr bool value = true; \
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T>::type
operator&(T lhs, T rhs)
{
	typedef typename std::underlying_type<T>::type integer_type;
	return static_cast<T>(static_cast<integer_type>(lhs) & static_cast<integer_type>(rhs));
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T>::type
operator|(T lhs, T rhs)
{
	typedef typename std::underlying_type<T>::type integer_type;
	return static_cast<T>(static_cast<integer_type>(lhs) | static_cast<integer_type>(rhs));
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T>::type
operator^(T lhs, T rhs)
{
	typedef typename std::underlying_type<T>::type integer_type;
	return static_cast<T>(static_cast<integer_type>(lhs) ^ static_cast<integer_type>(rhs));
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T>::type
operator~(T t)
{
	typedef typename std::underlying_type<T>::type integer_type;
	return static_cast<T>(~ static_cast<integer_type>(t));
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T&>::type
operator&=(T& lhs, T rhs)
{
	typedef typename std::underlying_type<T>::type integer_type;
	lhs = static_cast<T>(static_cast<integer_type>(lhs) & static_cast<integer_type>(rhs));
	return lhs;
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T&>::type
operator|=(T& lhs, T rhs)
{
	typedef typename std::underlying_type<T>::type integer_type;
	lhs = static_cast<T>(static_cast<integer_type>(lhs) | static_cast<integer_type>(rhs));
	return lhs;
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value && enable_enum_class_bitfield<T>::value, T&>::type
operator^=(T& lhs, T rhs)
{
	typedef typename std::underlying_type<T>::type integer_type;
	lhs = static_cast<T>(static_cast<integer_type>(lhs) ^ static_cast<integer_type>(rhs));
	return lhs;
}

#endif /* EnumClass_h */
