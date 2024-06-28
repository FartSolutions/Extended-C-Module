#include "ecm/math/functions.hpp"

#include <cmath>

namespace ecm::math
{
	namespace
	{
		__forceinline float64 _sin_with_taylor(float64 x)
		{
			const int terms{ 20 };
			x = Fmod(x + PI, PI2) - PI;
			float64 result{ 0.0 };
			for (int32 n{ 0 }; n < terms; ++n) {
				result += (Pow(-1, n) * Pow(x, 2 * n + 1) / Fact(2 * n + 1));
			}
			return result;
		}

		__forceinline float64 _sin_with_polynomiable_approximation(float64 x)
		{
			x = Fmod(x + PI, PI2) - PI;
			const float128 x2 = x * x;
			return x * (1 - x2 / 6 * (1 - x2 / 20 * (1 - x2 / 42)));
		}

		__forceinline float64 _reduce_angle(float64 x)
		{
			x = Fmod(x, PI2);
			if (x > PI) {
				x -= 2 * PI;
			} else if (x < -PI) {
				x += PI2;
			}
			return x;
		}

		__forceinline float64 _sin_fast(float64 x)
		{
			x = _reduce_angle(x);
			float64 x2 = x * x;
			float64 result = x;
			float64 term = x;
			term *= -x2 / (2 * 3);
			result += term;
			term *= -x2 / (4 * 5);
			result += term;
			term *= -x2 / (6 * 7);
			result += term;
			term *= -x2 / (8 * 9);
			result += term;
			term *= -x2 / (10 * 11);
			result += term;
			return result;
		}

		__forceinline float64 _sin_internal(float64 x)
		{
			return _sin_fast(x);
		}
	} // anonymous namespace

	float64 Sin(float64 x)
	{
		return sin(x);
	}
	
	float32 Sin(float32 x)
	{
		return sinf(x);
	}

	float64 Cos(float64 x)
	{
		return cos(x);
	}

	float32 Cos(float32 x)
	{
		return cosf(x);
	}

	float64 Tan(float64 x)
	{
		return sin(x) / cos(x);
	}

	float32 Tan(float32 x)
	{
		return sinf(x) / cosf(x);
	}
} // namespace ecm::math
