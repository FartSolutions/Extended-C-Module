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
} // namespace ecm::math
