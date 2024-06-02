#pragma once

#include "functions.hpp"

namespace ecm::math
{
	constexpr uint64 Fact(int32 n)
	{
		uint64 res{ 1 };
		for (int32 i{ 1 }; i <= n; ++i)
		{
			res *= i;
		}
		return res;
	}

	constexpr float128 Pow(float128 base, int32 expo)
	{
		float128 res{ 1.0L };
		for (int32 i{ 0 }; i < Abs(expo); ++i) // TODO: Implement Abs
		{
			res *= base;
		}
		if (expo < 0)
		{
			return 1.0L / res;
		}
		return res;
	}
} // namespace ecm::math
