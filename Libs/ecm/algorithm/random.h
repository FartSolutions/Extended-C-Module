#pragma once
#ifndef _ECM_RANDOM_H_
#define _ECM_RANDOM_H_

#include <ecm/ecm_api.h>
#include <ecm/types/stdtypes.h>

namespace ecm::algorithm
{
	class ECM_ALG_API linear_congruential
	{
	private:
		uint64 _seed;
		uint64 _first;
		uint64 _second;
		uint64 _mask;
	public:
		linear_congruential();
		explicit linear_congruential(uint64 seed, uint64 mask,
			uint64 a = 76088478917859ul, uint64 b = 12891702389ul);

		void set_seed(uint64 seed);
		void set_mask(uint64 seed);
		void set_nums(uint64 a, uint32 b);

		const uint64 next();
		const uint64 next(uint64 maxVal);
		const uint64 next(uint64 minVal, uint64 maxVal);
	};
} // namespace ecm::algorithm

#endif // !_ECM_RANDOM_H_
