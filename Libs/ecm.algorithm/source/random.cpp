#include <ecm/algorithm/random.h>

#include <ctime>

namespace ecm::algorithm
{
	linear_congruential::linear_congruential()
	{
		std::time_t timeStamp{ std::time(nullptr) };
		_seed = static_cast<uint64>(timeStamp);
		_first = 894367923236ul;
		_second = 19358791230ul;
		_mask = 0xffff'ffff'ffff'ffffui64;
	}

	linear_congruential::linear_congruential(
		uint64 seed, uint64 mask, uint64 a, uint64 b)
	{
		_seed = seed;
		_first = a;
		_second = b;
		_mask = mask;
	}

	void linear_congruential::set_seed(uint64 seed)
	{
		_seed = seed;
	}

	void linear_congruential::set_mask(uint64 mask)
	{
		_mask = mask;
	}

	void linear_congruential::set_nums(uint64 a, uint32 b)
	{
		_first = a;
		_second = b;
	}

	const uint64 linear_congruential::next()
	{
		
		return next(0xffff'ffff'ffff'ffff);
	}

	const uint64 linear_congruential::next(uint64 maxVal)
	{
		_seed = (_first * _seed + _second) % maxVal;
		return _seed & _mask;
	}

	const uint64 linear_congruential::next(uint64 minVal, uint64 maxVal)
	{
		if (maxVal <= minVal) return 0;
		uint64 range{ maxVal - minVal };
		uint64 res{ next(maxVal) };
		return res + minVal;
	}
} // namespace ecm::algorithm
