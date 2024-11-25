#pragma once

#include "vector2.hpp"

#pragma warning(push)
#pragma warning(disable : 26495)

namespace ecm::math
{
	// Basic constructors

	template<typename T>
	constexpr Vector2_Base<T>::Vector2_Base()
		: x(0), y(0)
	{}

	template<typename T>
	constexpr Vector2_Base<T>::Vector2_Base(Vector2_Base<T> const& v)
		: x(v.x), y(v.y)
	{}

	template<typename T>
	constexpr Vector2_Base<T>::Vector2_Base(T scalar)
		: x(scalar), y(scalar)
	{}

	template<typename T>
	constexpr Vector2_Base<T>::Vector2_Base(T x, T y)
		: x(x), y(y)
	{}

	template<typename T>
	constexpr Vector2_Base<T>::Vector2_Base(const T coord[2])
		: x(coord[AXIS_X]), y(coord[AXIS_Y])
	{}

	// Conversion constructors

	template<typename T>
	template<typename U>
	constexpr Vector2_Base<T>::Vector2_Base(Vector2_Base<U> const& v)
		: x(static_cast<T>(v.x)),
		  y(static_cast<T>(v.y))
	{}

	// Component access

	template<typename T>
	constexpr T& Vector2_Base<T>::operator[](const uint8 axis)
	{
		return this->coord[axis];
	}
	
	template<typename T>
	constexpr T const& Vector2_Base<T>::operator[](const uint8 axis) const
	{
		return this->coord[axis];
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator=(Vector2_Base<T> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator=(Vector2_Base<U> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator+=(Vector2_Base<U> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator-=(Vector2_Base<U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator*=(Vector2_Base<U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator/=(Vector2_Base<U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	// Increment and decrement operators

	template<typename T>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator++()
	{
		++this->x;
		++this->y;
		return *this;
	}

	template<typename T>
	constexpr Vector2_Base<T>& Vector2_Base<T>::operator--()
	{
		++this->x;
		++this->y;
		return *this;
	}

	template<typename T>
	constexpr Vector2_Base<T> Vector2_Base<T>::operator++(int)
	{
		Vector2_Base<T> result(*this);
		++*this;
		return result;
	}

	template<typename T>
	constexpr Vector2_Base<T> Vector2_Base<T>::operator--(int)
	{
		Vector2_Base<T> result(*this);
		--*this;
		return result;
	}

	// Boolean operators

	template<typename T>
	constexpr bool operator==(Vector2_Base<T> const& v1, Vector2_Base<T> const& v2)
	{
		if (v1.x == v2.x) {
			if (v1.y == v2.y) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	constexpr bool operator!=(Vector2_Base<T> const& v1, Vector2_Base<T> const& v2)
	{
		return !(v1 == v2);
	}

	constexpr Vector2_Base<bool> operator&&(Vector2_Base<bool> const& v1, Vector2_Base<bool> const& v2)
	{
		return Vector2_Base<bool>(v1.x && v2.x, v1.y && v2.y);
	}

	constexpr Vector2_Base<bool> operator||(Vector2_Base<bool> const& v1, Vector2_Base<bool> const& v2)
	{
		return Vector2_Base<bool>(v1.x || v2.x, v1.y || v2.y);
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Vector2_Base<T> operator+(Vector2_Base<T> const& v)
	{
		return v;
	}

	template<typename T>
	constexpr Vector2_Base<T> operator-(Vector2_Base<T> const& v)
	{
		return Vector2_Base<T>(-v.x, -v.y);
	}

	// Binary operators

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator+(Vector2_Base<T> const& v, U scalar)
	{
		return Vector2_Base<T>(
				static_cast<T>(v.x + scalar),
				static_cast<T>(v.y + scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator+(Vector2_Base<T> const& v1, Vector2_Base<U> const& v2)
	{
		return Vector2_Base<T>(
				static_cast<T>(v1.x + v2.x),
				static_cast<T>(v1.y + v2.y));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator-(Vector2_Base<T> const& v, U scalar)
	{
		return Vector2_Base<T>(
				static_cast<T>(v.x - scalar),
				static_cast<T>(v.y - scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator-(Vector2_Base<T> const& v1, Vector2_Base<U> const& v2)
	{
		return Vector2_Base<T>(
				static_cast<T>(v1.x - v2.x),
				static_cast<T>(v1.y - v2.y));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator*(Vector2_Base<T> const& v, U scalar)
	{
		return Vector2_Base<T>(
				static_cast<T>(v.x * scalar),
				static_cast<T>(v.y * scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator*(Vector2_Base<T> const& v1, Vector2_Base<U> const& v2)
	{
		return Vector2_Base<T>(
				static_cast<T>(v1.x * v2.x),
				static_cast<T>(v1.y * v2.y));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator/(Vector2_Base<T> const& v, U scalar)
	{
		return Vector2_Base<T>(
				static_cast<T>(v.x / scalar),
				static_cast<T>(v.y / scalar));
	}

	template<typename T, typename U, typename>
	constexpr Vector2_Base<T> operator/(Vector2_Base<T> const& v1, Vector2_Base<U> const& v2)
	{
		return Vector2_Base<T>(
				static_cast<T>(v1.x / v2.x),
				static_cast<T>(v1.y / v2.y));
	}
} // namespace ecm::math

#pragma warning(pop)
