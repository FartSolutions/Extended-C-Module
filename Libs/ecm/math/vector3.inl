#pragma once

#include "vector3.hpp"

namespace ecm::math
{
	template<typename _Ty>
	constexpr Vector3_Base<_Ty>::Vector3_Base()
	{
		this->coord[AXIS_X] = 0;
		this->coord[AXIS_Y] = 0;
		this->coord[AXIS_Z] = 0;
	}

	template<typename _Ty>
	constexpr Vector3_Base<_Ty>::Vector3_Base(_Ty _x, _Ty _y, _Ty _z)
	{
		this->coord[AXIS_X] = _x;
		this->coord[AXIS_Y] = _y;
		this->coord[AXIS_Z] = _z;
	}

	template<typename _Ty>
	constexpr Vector3_Base<_Ty>::Vector3_Base(_Ty _coord[3])
	{
		this->coord[AXIS_X] = _coord[AXIS_X];
		this->coord[AXIS_Y] = _coord[AXIS_Y];
		this->coord[AXIS_Z] = _coord[AXIS_Z];
	}

	template<typename _Ty>
	constexpr _Ty& Vector3_Base<_Ty>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}
	
	template<typename _Ty>
	constexpr const _Ty& Vector3_Base<_Ty>::operator[](const uint8 axis) const
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
