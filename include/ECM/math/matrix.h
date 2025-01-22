/*
 * \file matrix4x4.h
 *
 * \brief This header defines diffrent 4x4 matrices.
 */

#pragma once
#ifndef _ECM_MATRIX_H_
#define _ECM_MATRIX_H_

#include <ECM/math/matrix4x4.h>

namespace ecm::math
{
	// Matrix4x4

	/**
	 * A 4x4 matrix of single-precision floating-point values (float32).
	 *
	 * This type alias provides a more convenient name for
	 * `Matrix4x4_Base<float32>`, making it easier to define and work with 4x4
	 * matrices of floats.
	 *
	 * \since v1.0.0
	 */
	using Matrix4x4 = Matrix4x4_Base<float32>;

	/**
	 * A 4x4 matrix of single-precision floating-point values (float32) aligned
	 * to a 16-byte boundary.
	 *
	 * Using `ECM_ALIGN(16)` ensures that the matrix data is aligned for optimal
	 * performance in SIMD operations or other vectorized instructions.
	 *
	 * \since v1.0.0
	 */
	using Matrix4x4A = ECM_ALIGN(16) Matrix4x4;

	/**
	 * A 4x4 matrix of 32-bit signed integers.
	 *
	 * This type alias provides a more convenient name for
	 * `Matrix4x4_Base<int32>`, making it easier to define and work with 4x4
	 * matrices of 32-bit integers.
	 *
	 * \since v1.0.0
	 */
	using Matrix4x4i = Matrix4x4_Base<int32>;

	/**
	 * A 4x4 matrix of 32-bit signed integers aligned to a 16-byte boundary.
	 *
	 * Using `ECM_ALIGN(16)` ensures that the matrix data is aligned for optimal
	 * performance in SIMD operations or other vectorized instructions.
	 *
	 * \since v1.0.0
	 */
	using Matrix4x4iA = ECM_ALIGN(16) Matrix4x4i;

	/**
	 * A 4x4 matrix of 32-bit unsigned integers.
	 *
	 * This type alias provides a more convenient name for
	 * `Matrix4x4_Base<uint32>`, making it easier to define and work with 4x4
	 * matrices of 32-bit unsigned integers.
	 *
	 * \since v1.0.0
	 */
	using Matrix4x4u = Matrix4x4_Base<uint32>;

	/**
	 * A 4x4 matrix of 32-bit unsigned integers aligned to a 16-byte boundary.
	 *
	 * Using `ECM_ALIGN(16)` ensures that the matrix data is aligned for optimal
	 * performance in SIMD operations or other vectorized instructions.
	 *
	 * \since v1.0.0
	 */
	using Matrix4x4uA = ECM_ALIGN(16) Matrix4x4u;
} // namespace ecm::math

#endif // !_ECM_MATRIX_H_
