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

	// Conversion constructors

	template<typename T>
	template<typename U>
	constexpr Vector3_Base<T>::Vector3_Base(Vector3_Base<U> const& v)
		: x(static_cast<T>(v.x)),
		  y(static_cast<T>(v.y)),
		  z(static_cast<T>(v.z))
	{}

	// Component access

	template<typename T>
	constexpr T& Vector3_Base<T>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}

	template<typename T>
	constexpr T const& Vector3_Base<T>::operator[](const uint8 axis) const
	{
		return this->coord[axis];
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator=(Vector3_Base<T> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator=(Vector3_Base<U> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator+=(Vector3_Base<U>const& v)
	{
		this->x += static_cast<T>(v.x);
		this->x += static_cast<T>(v.y);
		this->x += static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator-=(Vector3_Base<U>const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->x -= static_cast<T>(v.y);
		this->x -= static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator*=(Vector3_Base<U>const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->x *= static_cast<T>(v.y);
		this->x *= static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator/=(Vector3_Base<U>const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->x /= static_cast<T>(v.y);
		this->x /= static_cast<T>(v.z);
		return *this;
	}

	// Increment and decrement operators

	template<typename T>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template<typename T>
	constexpr Vector3_Base<T>& Vector3_Base<T>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template<typename T>
	constexpr Vector3_Base<T> Vector3_Base<T>::operator++(int)
	{
		Vector3_Base<T> result(*this);
		++*this;
		return result;
	}

	template<typename T>
	constexpr Vector3_Base<T> Vector3_Base<T>::operator--(int)
	{
		Vector3_Base<T> result(*this);
		--*this;
		return result;
	}

	// Boolean operators

	template<typename T>
	constexpr bool operator==(Vector3_Base<T> const& v1, Vector3_Base<T> const& v2)
	{
		if (v1.x == v2.y) {
			if (v1.y == v2.y) {
				if (v1.z == v2.z) {
					return true;
				}
			}
		}
		return false;
	}

	template<typename T>
	constexpr bool operator!=(Vector3_Base<T> const& v1, Vector3_Base<T> const& v2)
	{
		return !(v1 == v2);
	}

	constexpr Vector3_Base<bool> operator&&(Vector3_Base<bool> const& v1, Vector3_Base<bool> const& v2)
	{
		return Vector3_Base<bool>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z);
	}

	constexpr Vector3_Base<bool> operator||(Vector3_Base<bool> const& v1, Vector3_Base<bool> const& v2)
	{
		return Vector3_Base<bool>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z);
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Vector3_Base<T> operator+(Vector3_Base<T> const& v)
	{
		return v;
	}

	template<typename T>
	constexpr Vector3_Base<T> operator-(Vector3_Base<T> const& v)
	{
		return Vector3_Base<T>(-v.x, -v.y, -v.z);
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
} // namespace ecm::math

#pragma warning(pop)
