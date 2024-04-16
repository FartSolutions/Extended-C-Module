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
} // namespace ecm::math
