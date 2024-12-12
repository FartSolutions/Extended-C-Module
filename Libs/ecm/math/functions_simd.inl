#include "functions_simd.hpp"

namespace ecm::math
{
	constexpr __m128 Fma(__m128 a, __m128 b, __m128 c)
	{
		return _mm_fmadd_ps(a, b, c);
	}

	constexpr __m128 SplatX(__m128 v)
	{
		return _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
	}

	constexpr __m128 SplatY(__m128 v)
	{
		return _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
	}

	constexpr __m128 SplatZ(__m128 v)
	{
		return _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
	}

	constexpr __m128 SplatW(__m128 v)
	{
		return _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3));
	}
} // namespace ecm::math
