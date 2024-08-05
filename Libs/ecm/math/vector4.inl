#pragma once

#include "vector4.hpp"

namespace ecm::math
{
	template<typename _Ty>
	constexpr Vector4_Base<_Ty>::Vector4_Base()
	{
		this->coord[AXIS_X] = 0;
		this->coord[AXIS_Y] = 0;
		this->coord[AXIS_Z] = 0;
		this->coord[AXIS_W] = 0;
	}

	template<typename _Ty>
	constexpr Vector4_Base<_Ty>::Vector4_Base(_Ty _x, _Ty _y, _Ty _z, _Ty _w)
	{
		this->coord[AXIS_X] = _x;
		this->coord[AXIS_Y] = _y;
		this->coord[AXIS_Z] = _z;
		this->coord[AXIS_W] = _w;
	}

	template<typename _Ty>
	constexpr Vector4_Base<_Ty>::Vector4_Base(_Ty _coord[4])
	{
		this->coord[AXIS_X] = _coord[AXIS_X];
		this->coord[AXIS_Y] = _coord[AXIS_Y];
		this->coord[AXIS_Z] = _coord[AXIS_Z];
		this->coord[AXIS_W] = _coord[AXIS_W];
	}

	template<typename _Ty>
	constexpr _Ty& Vector4_Base<_Ty>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}
	
	template<typename _Ty>
	constexpr const _Ty& Vector4_Base<_Ty>::operator[](const uint8 axis) const
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
