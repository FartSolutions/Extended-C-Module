#include <ecm/math/vector4.h>

namespace ecm::math
{
	constexpr Vector4::Vector4()
		: x{ 0.f }, y{ 0.f }, z{ 0.f }, w{ 0.f }
	{ }

	constexpr Vector4::Vector4(float32 _x, float32 _y, float32 _z, float32 _w)
		: x{ _x }, y{ _y }, z{ _z }, w{ _w }
	{ }

	constexpr Vector4::Vector4(float32 _coord[4])
		: x{ _coord[AXIS_X] }, y{ _coord[AXIS_Y] },
		  z{ _coord[AXIS_Z] }, w{ _coord[AXIS_W] }
	{ }

	constexpr bool operator==(const Vector4& left, const Vector4& right)
	{
		if (left.x == right.x)
		{
			if (left.y == right.y)
			{
				if (left.z == right.z)
				{
					if (left.w == right.w)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	constexpr bool operator!=(const Vector4& left, const Vector4& right)
	{
		return !(left == right);
	}

	constexpr Vector4 operator+(const Vector4& left, const Vector4& right)
	{
		Vector4 vec{};
		vec.x = left.x + right.x;
		vec.y = left.y + right.y;
		vec.z = left.z + right.z;
		vec.w = left.w + right.w;
		return vec;
	}

	constexpr Vector4 operator-(const Vector4& left, const Vector4& right)
	{
		Vector4 vec{};
		vec.x = left.x - right.x;
		vec.y = left.y - right.y;
		vec.z = left.z - right.z;
		vec.w = left.w - right.w;
		return vec;
	}

	constexpr Vector4 operator*(const Vector4& left, const Vector4& right)
	{
		Vector4 vec{};
		vec.x = left.x * right.x;
		vec.y = left.y * right.y;
		vec.z = left.z * right.z;
		vec.w = left.w * right.w;
		return vec;
	}

	constexpr Vector4 operator/(const Vector4& left, const Vector4& right)
	{
		Vector4 vec{};
		vec.x = left.x / right.x;
		vec.y = left.y / right.y;
		vec.z = left.z / right.z;
		vec.w = left.w / right.w;
		return vec;
	}

	constexpr Vector4& operator+=(Vector4& left, const Vector4& right)
	{
		left = left + right;
		return left;
	}

	constexpr Vector4& operator-=(Vector4& left, const Vector4& right)
	{
		left = left - right;
		return left;
	}

	constexpr Vector4& operator*=(Vector4& left, const Vector4& right)
	{
		left = left * right;
		return left;
	}

	constexpr Vector4& operator/=(Vector4& left, const Vector4& right)
	{
		left = left / right;
		return left;
	}
} // namespace ecm::math
