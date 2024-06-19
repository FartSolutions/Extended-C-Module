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
	constexpr _Ty& Vector3_Base<_Ty>::operator[](const uint8 axis) const
	{
		return this->coord[axis];
	}

	constexpr bool operator==(const Vector3& left, const Vector3& right)
	{
		if (left.x == right.y)
		{
			if (left.y == right.y)
			{
				if (left.z == right.z)
				{
					return true;
				}
			}
		}
		return false;
	}

	constexpr bool operator!=(const Vector3& left, const Vector3& right)
	{
		return !(left == right);
	}

	constexpr Vector3 operator+(const Vector3& left, const Vector3& right)
	{
		Vector3 vec{};
		vec.x = left.x + right.x;
		vec.y = left.y + right.y;
		vec.z = left.z + right.z;
		return vec;
	}

	constexpr Vector3 operator-(const Vector3& left, const Vector3& right)
	{
		Vector3 vec{};
		vec.x = left.x - right.x;
		vec.y = left.y - right.y;
		vec.z = left.z - right.z;
		return vec;
	}

	constexpr Vector3 operator*(const Vector3& left, const Vector3& right)
	{
		Vector3 vec{};
		vec.x = left.x * right.x;
		vec.y = left.y * right.y;
		vec.z = left.z * right.z;
		return vec;
	}

	constexpr Vector3 operator/(const Vector3& left, const Vector3& right)
	{
		Vector3 vec{};
		vec.x = left.x / right.x;
		vec.y = left.y / right.y;
		vec.z = left.z / right.z;
		return vec;
	}

	constexpr Vector3& operator+=(Vector3& left, const Vector3& right)
	{
		left = left + right;
		return left;
	}

	constexpr Vector3& operator-=(Vector3& left, const Vector3& right)
	{
		left = left - right;
		return left;
	}

	constexpr Vector3& operator*=(Vector3& left, const Vector3& right)
	{
		left = left * right;
		return left;
	}

	constexpr Vector3& operator/=(Vector3& left, const Vector3& right)
	{
		left = left / right;
		return left;
	}

	constexpr Vector3 operator+(const Vector3& left, const float32& right)
	{
		Vector3 vec{};
		vec.x = left.x + right;
		vec.y = left.y + right;
		vec.z = left.z + right;
		return vec;
	}

	constexpr Vector3 operator-(const Vector3& left, const float32& right)
	{
		Vector3 vec{};
		vec.x = left.x - right;
		vec.y = left.y - right;
		vec.z = left.z - right;
		return vec;
	}

	constexpr Vector3 operator*(const Vector3& left, const float32& right)
	{
		Vector3 vec{};
		vec.x = left.x * right;
		vec.y = left.y * right;
		vec.z = left.z * right;
		return vec;
	}

	constexpr Vector3 operator/(const Vector3& left, const float32& right)
	{
		Vector3 vec{};
		vec.x = left.x / right;
		vec.y = left.y / right;
		vec.z = left.z / right;
		return vec;
	}

	constexpr Vector3 operator+=(Vector3& left, const float32& right)
	{
		left = left + right;
		return left;
	}

	constexpr Vector3 operator-=(Vector3& left, const float32& right)
	{
		left = left - right;
		return left;
	}

	constexpr Vector3 operator*=(Vector3& left, const float32& right)
	{
		left = left * right;
		return left;
	}

	constexpr Vector3 operator/=(Vector3& left, const float32& right)
	{
		left = left / right;
		return left;
	}
} // namespace ecm::math
