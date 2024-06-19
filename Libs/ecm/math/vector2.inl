#pragma once

#include "vector2.hpp"

namespace ecm::math
{
	template<typename _Ty>
	constexpr Vector2_Base<_Ty>::Vector2_Base()
	{
		this->coord[AXIS_X] = 0;
		this->coord[AXIS_Y] = 0;
	}

	template<typename _Ty>
	constexpr Vector2_Base<_Ty>::Vector2_Base(_Ty _x, _Ty _y)
	{
		this->coord[AXIS_X] = _x;
		this->coord[AXIS_Y] = _y;
	}

	template<typename _Ty>
	constexpr Vector2_Base<_Ty>::Vector2_Base(_Ty _coord[2])
	{
		this->coord[AXIS_X] = _coord[AXIS_X];
		this->coord[AXIS_Y] = _coord[AXIS_Y];
	}

	template<typename _Ty>
	constexpr _Ty& Vector2_Base<_Ty>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}
	
	template<typename _Ty>
	constexpr const _Ty& Vector2_Base<_Ty>::operator[](const uint8 axis) const
	{
		return this->coord[axis];
	}

	template<typename _Ty> constexpr bool operator==(
			const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		if (left.x == right.x) {
			if (left.y == right.y) {
				return true;
			}
		}
		return false;
	}

	template<typename _Ty> constexpr bool operator!=(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		return !(left == right);
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator+(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x + right.x;
		vec.y = left.y + right.y;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator-(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x - right.x;
		vec.y = left.y - right.y;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator*(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x * right.x;
		vec.y = left.y * right.y;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator/(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x / right.x;
		vec.y = left.y / right.y;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator+=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		left = left + right;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator-=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		left = left - right;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator*=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		left = left * right;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator/=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right)
	{
		left = left / right;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator+(
		const Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x + scalar;
		vec.y = left.y + scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator-(
		const Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x - scalar;
		vec.y = left.y - scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator*(
		const Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x * scalar;
		vec.y = left.y * scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator/(
		const Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		Vector2_Base<_Ty> vec{};
		vec.x = left.x / scalar;
		vec.y = left.y / scalar;
		return vec;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator+=(
		Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left + scalar;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator-=(
		Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left - scalar;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator*=(
		Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left * scalar;
		return left;
	}

	template<typename _Ty> constexpr Vector2_Base<_Ty> operator/=(
		Vector2_Base<_Ty>& left, const _Ty& scalar)
	{
		left = left / scalar;
		return left;
	}
} // namespace ecm::math
