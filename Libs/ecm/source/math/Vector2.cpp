#include <ecm/math/Vector2.h>

namespace ecm::math
{
	constexpr inline Vector2::Vector2()
		: coord{ 0, 0 }
	{ }

	constexpr inline Vector2::Vector2(float32 _x, float32 _y)
		: coord{ _x, _y }
	{ }

	constexpr inline Vector2::Vector2(float32 _coord[2])
		: coord{ _coord[0], _coord[1] }
	{ }
} // namespace ecm::math
