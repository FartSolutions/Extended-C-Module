#include <ecm/math/vector3.h>

namespace ecm::math
{
	constexpr Vector3::Vector3()
		: x{ 0.f }, y{ 0.f }, z{ 0.f }
	{ }

	constexpr Vector3::Vector3(float32 _x, float32 _y, float32 _z)
		: x{ _x }, y{ _y }, z{ _z }
	{ }

	constexpr Vector3::Vector3(float32 _coord[3])
		: x{ _coord[AXIS_X] }, y{ _coord[AXIS_Y] }, z{ _coord[AXIS_Z] }
	{ }

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
} // namespace ecm::math
