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
	template<typename U>
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
} // namespace ecm::math

#pragma warning(pop)
