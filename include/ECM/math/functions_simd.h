/*
 * \file functions.hpp
 *
 * \brief This header defines SIMD functionalities.
 */

#pragma once
#ifndef _ECM_FUNCTIONS_SIMD_H_
#define _ECM_FUNCTIONS_SIMD_H_

#include <ECM/ECM_api.h>
#include <ECM/ECM_stdtypes.h>

#include <immintrin.h>

namespace ecm::math
{
	/**
	 * Performs a fused multiply-add operation on three 128-bit vectors.
	 *
	 * This function computes (a * b) + c on each corresponding element of the
	 * provided 128-bit vectors and returns the result as a 128-bit vector.
	 * It leverages hardware-accelerated fused multiply-add instructions for
	 * improved performance and reduced floating-point rounding errors,
	 * where supported by the underlying architecture.
	 *
	 * \param a The first 128-bit vector operand.
	 * \param b The second 128-bit vector operand.
	 * \param c The 128-bit vector to be added after multiplication.
	 *
	 * \returns A 128-bit vector containing the result of (a * b) + c.
	 *
	 * \since v1.0.0
	 */
	ECM_NODISCARD ECM_INLINE __m128 ECM_CALL Fma(__m128 a, __m128 b, __m128 c);

	/**
	 * Broadcasts the x-component (the first element) of the given 128-bit
	 * vector to all four elements of a resulting 128-bit vector.
	 *
	 * \param v The input 128-bit vector.
	 *
	 * \returns A 128-bit vector with all elements set to the x-component of \p
	 *          v.
	 *
	 * \since v1.0.0
	 */
	ECM_NODISCARD ECM_INLINE __m128 ECM_CALL SplatX(__m128 v);

	/**
	 * Broadcasts the y-component (the second element) of the given 128-bit
	 * vector to all four elements of a resulting 128-bit vector.
	 *
	 * \param v The input 128-bit vector.
	 *
	 * \returns A 128-bit vector with all elements set to the y-component of \p
	 *          v.
	 *
	 * \since v1.0.0
	 */
	ECM_NODISCARD ECM_INLINE __m128 ECM_CALL SplatY(__m128 v);

	/**
	 * Broadcasts the z-component (the third element) of the given 128-bit
	 * vector to all four elements of a resulting 128-bit vector.
	 *
	 * \param v The input 128-bit vector.
	 *
	 * \returns A 128-bit vector with all elements set to the z-component of \p
	 *          v.
	 *
	 * \since v1.0.0
	 */
	ECM_NODISCARD ECM_INLINE __m128 ECM_CALL SplatZ(__m128 v);

	/**
	 * Broadcasts the w-component (the fourth element) of the given 128-bit
	 * vector to all four elements of a resulting 128-bit vector.
	 *
	 * \param v The input 128-bit vector.
	 *
	 * \returns A 128-bit vector with all elements set to the w-component of \p
	 *          v.
	 *
	 * \since v1.0.0
	 */
	ECM_NODISCARD ECM_INLINE __m128 ECM_CALL SplatW(__m128 v);
} // namespace ecm::math

#endif // !_ECM_FUNCTIONS_SIMD_H_
