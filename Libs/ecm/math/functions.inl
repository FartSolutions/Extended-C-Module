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
} // namespace ecm::math
