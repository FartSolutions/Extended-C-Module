#include "ecm/math/functions.hpp"

namespace ecm::math
{
	namespace
	{
		__forceinline float64 _sin_with_taylor(float64 x)
		{
			const int terms{ 20 };
			x = Fmod(x + PI, PI2) - PI;
			float64 result{ 0.0l };
			/*const int terms{10};
			for (int32 i{ 0 }; i < terms; ++i) {
				int32 sign{ (i % 2 == 0) ? 1 : -1 };
				result += sign * Pow(x, 2 * i + 1) / Fact(2 * i + 1);
			}*/
			float64 term{ x };
			for (int32 i{ 0 }; i < terms; ++i) {
				result += term;
				term *= -x * x / ((2 * i + 2) * (2 * i + 3));
			}
			return result;
		}

		__forceinline float64 _sin_with_polynomiable_approximation(float64 x)
		{
			x = Fmod(x + PI, PI2) - PI;
			const float128 x2 = x * x;
			return x * (1 - x2 / 6 * (1 - x2 / 20 * (1 - x2 / 42)));
		}
	} // anonymous namespace

	float64 Sin(float64 x)
	{
		return _sin_with_polynomiable_approximation(x);
	}
	
	float64 SinT(float64 x)
	{
		return _sin_with_taylor(x);
	}

	float32 Sin(float32 x)
	{
		return static_cast<float32>(_sin_with_polynomiable_approximation(static_cast<float64>(x)));
	}
} // namespace ecm::math
