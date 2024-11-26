#pragma once

#include "vector3.hpp"

#pragma warning(push)
#pragma warning(disable : 26495)

namespace ecm::math
{
	// Basic constructors

	template<typename T>
	constexpr Vector3_Base<T>::Vector3_Base()
		: x(0), y(0), z(0)
	{}

	template<typename T>
	constexpr Vector3_Base<T>::Vector3_Base(Vector3_Base<T> const& v)
		: x(v.x), y(v.y), z(v.z)
	{}

	template<typename T>
	constexpr Vector3_Base<T>::Vector3_Base(T scalar)
		: x(scalar), y(scalar), z(scalar)
	{}

	template<typename T>
	constexpr Vector3_Base<T>::Vector3_Base(T x, T y, T z)
		: x(x), y(y), z(z)
	{}

	template<typename T>
	constexpr Vector3_Base<T>::Vector3_Base(const T coord[3])
		: x(coord[AXIS_X]), y(coord[AXIS_Y]), z(coord[AXIS_Z])
	{}

	template<typename T>
	constexpr T& Vector3_Base<T>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}
	
	template<typename T>
	constexpr const T& Vector3_Base<T>::operator[](const uint8 axis) const
	{
		return this->coord[axis];
	}

	template<typename _Ty> constexpr bool operator==(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		if (left.x == right.y) {
			if (left.y == right.y) {
				if (left.z == right.z) {
					return true;
				}
			}
		}
		return false;
	}

	template<typename _Ty> constexpr bool operator!=(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		return !(left == right);
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator+(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x + right.x;
		vec.y = left.y + right.y;
		vec.z = left.z + right.z;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator-(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x - right.x;
		vec.y = left.y - right.y;
		vec.z = left.z - right.z;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator*(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x * right.x;
		vec.y = left.y * right.y;
		vec.z = left.z * right.z;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator/(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x / right.x;
		vec.y = left.y / right.y;
		vec.z = left.z / right.z;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator+=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		left = left + right;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator-=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		left = left - right;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator*=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		left = left * right;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator/=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right)
	{
		left = left / right;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator+(
		const Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x + scalar;
		vec.y = left.y + scalar;
		vec.z = left.z + scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator-(
		const Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x - scalar;
		vec.y = left.y - scalar;
		vec.z = left.z - scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator*(
		const Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x * scalar;
		vec.y = left.y * scalar;
		vec.z = left.z * scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator/(
		const Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector3_Base<_Ty> vec{};
		vec.x = left.x / scalar;
		vec.y = left.y / scalar;
		vec.z = left.z / scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator+=(
		Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left + scalar;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator-=(
		Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left - scalar;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator*=(
		Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left * scalar;
		return left;
	}

	template<typename _Ty> constexpr Vector3_Base<_Ty> operator/=(
		Vector3_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left / scalar;
		return left;
	}
} // namespace ecm::math

#pragma warning(pop)
