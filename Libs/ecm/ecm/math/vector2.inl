#include "vector2.hpp"

namespace ecm::math
{
	constexpr Vector2::Vector2()
		: coord{ 0, 0 }
	{ }

	constexpr Vector2::Vector2(float32 _x, float32 _y)
		: coord{ _x, _y }
	{ }

	constexpr Vector2::Vector2(float32 _coord[2])
		: coord{ _coord[0], _coord[1] }
	{ }

	constexpr bool operator==(const Vector2& left, const Vector2& right)
	{
		if (left.x == right.x)
		{
			if (left.y == right.y)
			{
				return true;
			}
		}
		return false;
	}

	constexpr bool operator!=(const Vector2& left, const Vector2& right)
	{
		return !(left == right);
	}

	constexpr Vector2 operator+(const Vector2& left, const Vector2& right)
	{
		Vector2 vec{};
		vec.x = left.x + right.x;
		vec.y = left.y + right.y;
		return vec;
	}

	constexpr Vector2 operator-(const Vector2& left, const Vector2& right)
	{
		Vector2 vec{};
		vec.x = left.x - right.x;
		vec.y = left.y - right.y;
		return vec;
	}

	constexpr Vector2 operator*(const Vector2& left, const Vector2& right)
	{
		Vector2 vec{};
		vec.x = left.x * right.x;
		vec.y = left.y * right.y;
		return vec;
	}

	constexpr Vector2 operator/(const Vector2& left, const Vector2& right)
	{
		Vector2 vec{};
		vec.x = left.x / right.x;
		vec.y = left.y / right.y;
		return vec;
	}

	constexpr Vector2& operator+=(Vector2& left, const Vector2& right)
	{
		left = left + right;
		return left;
	}

	constexpr Vector2& operator-=(Vector2& left, const Vector2& right)
	{
		left = left - right;
		return left;
	}

	constexpr Vector2& operator*=(Vector2& left, const Vector2& right)
	{
		left = left * right;
		return left;
	}

	constexpr Vector2& operator/=(Vector2& left, const Vector2& right)
	{
		left = left / right;
		return left;
	}
} // namespace ecm::math
