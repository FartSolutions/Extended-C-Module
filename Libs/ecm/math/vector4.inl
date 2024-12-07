#pragma once

#include "vector4.hpp"

namespace ecm::math
{
	// Basic constructors

	template<typename T>
	constexpr Vector4_Base<T>::Vector4_Base()
		: x(0), y(0), z(0), w(0)
	{}

	template<typename T>
	constexpr Vector4_Base<T>::Vector4_Base(Vector4_Base<T> const& v)
		: x(v.x), y(v.y), z(v.z), w(v.w)
	{}

	template<typename T>
	constexpr Vector4_Base<T>::Vector4_Base(T scalar)
		: x(scalar), y(scalar), z(scalar), w(scalar)
	{}

	template<typename T>
	constexpr Vector4_Base<T>::Vector4_Base(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w)
	{}

	template<typename T>
	constexpr Vector4_Base<T>::Vector4_Base(const T coord[4])
		: x(coord[AXIS_X]), y(coord[AXIS_Y]), z(coord[AXIS_Z]), w(coord[AXIS_W])
	{}

	// Conversion constructors

	template<typename T>
	template<typename U>
	constexpr Vector4_Base<T>::Vector4_Base(Vector4_Base<U> const& v)
		: x(static_cast<T>(v.x)),
		  y(static_cast<T>(v.y)),
		  z(static_cast<T>(v.z)),
		  w(static_cast<T>(v.w))
	{}

	// Component access

	template<typename T>
	constexpr T& Vector4_Base<T>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}
	
	template<typename T>
	constexpr T const& Vector4_Base<T>::operator[](const uint8 axis) const
	{
		return this->coord[axis];
	}

	// ##########################################################################
	// External operators

	template<typename _Ty> constexpr bool operator==(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		if (left.x == right.x) {
			if (left.y == right.y) {
				if (left.z == right.z) {
					if (left.w == right.w) {
						return true;
					}
				}
			}
		}
		return false;
	}

	template<typename _Ty> constexpr bool operator!=(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		return !(left == right);
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator+(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x + right.x;
		vec.y = left.y + right.y;
		vec.z = left.z + right.z;
		vec.w = left.w + right.w;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator-(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x - right.x;
		vec.y = left.y - right.y;
		vec.z = left.z - right.z;
		vec.w = left.w - right.w;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator*(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x * right.x;
		vec.y = left.y * right.y;
		vec.z = left.z * right.z;
		vec.w = left.w * right.w;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator/(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x / right.x;
		vec.y = left.y / right.y;
		vec.z = left.z / right.z;
		vec.w = left.w / right.w;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator+=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		left = left + right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator-=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		left = left - right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator*=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		left = left * right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator/=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right)
	{
		left = left / right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator+(
		const Vector4_Base<_Ty>& left, const _Ty& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x + right;
		vec.y = left.y + right;
		vec.z = left.z + right;
		vec.w = left.w + right;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator-(
		const Vector4_Base<_Ty>& left, const _Ty& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x - right;
		vec.y = left.y - right;
		vec.z = left.z - right;
		vec.w = left.w - right;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator*(
		const Vector4_Base<_Ty>& left, const _Ty& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x * right;
		vec.y = left.y * right;
		vec.z = left.z * right;
		vec.w = left.w * right;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator/(
		const Vector4_Base<_Ty>& left, const _Ty& right)
	{
		Vector4_Base<_Ty> vec{};
		vec.x = left.x / right;
		vec.y = left.y / right;
		vec.z = left.z / right;
		vec.w = left.w / right;
		return vec;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator+=(
		Vector4_Base<_Ty>& left, const _Ty& right)
	{
		left = left + right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator-=(
		Vector4_Base<_Ty>& left, const _Ty& right)
	{
		left = left - right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator*=(
		Vector4_Base<_Ty>& left, const _Ty& right)
	{
		left = left * right;
		return left;
	}

	template<typename _Ty> constexpr Vector4_Base<_Ty> operator/=(
		Vector4_Base<_Ty>& left, const _Ty& right)
	{
		left = left / right;
		return left;
	}
} // namespace ecm::math
