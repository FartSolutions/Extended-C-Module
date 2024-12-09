#pragma once

#include "vector4.hpp"

#pragma warning(push)
#pragma warning(disable : 26495)

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

	// Unary arithmetic operators

	template<typename T>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator=(Vector4_Base<T> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator=(Vector4_Base<U> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		this->w = static_cast<T>(v.w);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		this->w += static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator+=(Vector4_Base<U> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		this->w += static_cast<T>(v.w);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		this->w -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator-=(Vector4_Base<U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		this->w -= static_cast<T>(v.w);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		this->w *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator*=(Vector4_Base<U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		this->w *= static_cast<T>(v.w);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		this->w /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator/=(Vector4_Base<U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		this->w /= static_cast<T>(v.w);
		return *this;
	}

	// Increment and decrement operators

	template<typename T>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		++this->w;
		return *this;
	}

	template<typename T>
	constexpr Vector4_Base<T>& Vector4_Base<T>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		--this->w;
		return *this;
	}

	template<typename T>
	constexpr Vector4_Base<T> Vector4_Base<T>::operator++(int)
	{
		Vector4_Base<T> result(*this);
		++*this;
		return result;
	}

	template<typename T>
	constexpr Vector4_Base<T> Vector4_Base<T>::operator--(int)
	{
		Vector4_Base<T> result(*this);
		--*this;
		return result;
	}

	// Boolean operators

	template<typename T>
	constexpr bool operator==(Vector4_Base<T> const& v1, Vector4_Base<T> const& v2)
	{
		if (v1.x == v2.x) {
			if (v1.y == v2.y) {
				if (v1.z == v2.z) {
					if (v1.w == v2.w) {
						return true;
					}
				}
			}
		}
		return false;
	}

	template<typename T>
	constexpr bool operator!=(Vector4_Base<T> const& v1, Vector4_Base<T> const& v2)
	{
		return !(v1 == v2);
	}

	constexpr Vector4_Base<bool> operator&&(Vector4_Base<bool> const& v1, Vector4_Base<bool> const& v2)
	{
		return Vector4_Base<bool>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z, v1.w && v2.w);
	}

	constexpr Vector4_Base<bool> operator||(Vector4_Base<bool> const& v1, Vector4_Base<bool> const& v2)
	{
		return Vector4_Base<bool>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z, v1.w || v2.w);
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Vector4_Base<T> operator+(Vector4_Base<T> const& v)
	{
		return v;
	}

	template<typename T>
	constexpr Vector4_Base<T> operator-(Vector4_Base<T> const& v)
	{
		return Vector4_Base<T>(-v.x, -v.y, -v.z, -v.w);
	}

	// Binary operators

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator+(Vector4_Base<T> const& v, U scalar)
	{
		return Vector4_Base<T>(
			static_cast<T>(v.x + scalar),
			static_cast<T>(v.y + scalar),
			static_cast<T>(v.z + scalar),
			static_cast<T>(v.w + scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator+(Vector4_Base<T> const& v1, Vector4_Base<U> const& v2)
	{
		return Vector4_Base<T>(
			static_cast<T>(v1.x + v2.x),
			static_cast<T>(v1.y + v2.y),
			static_cast<T>(v1.z + v2.z),
			static_cast<T>(v1.w + v2.w));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator-(Vector4_Base<T> const& v, U scalar)
	{
		return Vector4_Base<T>(
			static_cast<T>(v.x - scalar),
			static_cast<T>(v.y - scalar),
			static_cast<T>(v.z - scalar),
			static_cast<T>(v.w - scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator-(Vector4_Base<T> const& v1, Vector4_Base<U> const& v2)
	{
		return Vector4_Base<T>(
			static_cast<T>(v1.x - v2.x),
			static_cast<T>(v1.y - v2.y),
			static_cast<T>(v1.z - v2.z),
			static_cast<T>(v1.w - v2.w));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator*(Vector4_Base<T> const& v, U scalar)
	{
		return Vector4_Base<T>(
			static_cast<T>(v.x * scalar),
			static_cast<T>(v.y * scalar),
			static_cast<T>(v.z * scalar),
			static_cast<T>(v.w * scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator*(Vector4_Base<T> const& v1, Vector4_Base<U> const& v2)
	{
		return Vector4_Base<T>(
			static_cast<T>(v1.x * v2.x),
			static_cast<T>(v1.y * v2.y),
			static_cast<T>(v1.z * v2.z),
			static_cast<T>(v1.w * v2.w));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator/(Vector4_Base<T> const& v, U scalar)
	{
		return Vector4_Base<T>(
			static_cast<T>(v.x / scalar),
			static_cast<T>(v.y / scalar),
			static_cast<T>(v.z / scalar),
			static_cast<T>(v.w / scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector4_Base<T> operator/(Vector4_Base<T> const& v1, Vector4_Base<U> const& v2)
	{
		return Vector4_Base<T>(
			static_cast<T>(v1.x / v2.x),
			static_cast<T>(v1.y / v2.y),
			static_cast<T>(v1.z / v2.z),
			static_cast<T>(v1.w / v2.w));
	}
} // namespace ecm::math

#pragma warning(pop)
