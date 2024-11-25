/**
 * \file vector.h
 *
 * \brief This header defines a two dimensional vector and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR_H_
#define _ECM_VECTOR_H_

#include "vector2.hpp"

namespace ecm::math
{
	// Vector2 definitions

	/**
	 * A 2D point represented as a floating-point vector.
	 *
	 * This type alias is used to represent a point in a 2D space using
	 * single-precision floating-point numbers.
	 *
	 * \since v1.0.0
	 */
	using PointF = Vector2_Base<float32>;

	/**
	 * A 2D point represented as a integer vector.
	 *
	 * This type alias is used to represent a point in a 2D space using
	 * 32-bit integers.
	 *
	 * \since v1.0.0
	 */
	using PointI = Vector2_Base<int32>;

	/**
	 * A general-purpose 2D vector with single-precision floating-point
	 * components.
	 *
	 * This type alias is used for mathematical operations in a 2D space.
	 *
	 * \since v1.0.0
	 */
	using Vector2 = Vector2_Base<float32>;

	/**
	 * A general-purpose 2D vector with single-precision floating-point
	 * components and 16-byte alignment.
	 *
	 * This type alias is used for mathematical operations in a 2D space where
	 * SIMD alignment is required.
	 *
	 * \note Requires SIMD alignment for efficient vectorized operations.
	 *
	 * \since v1.0.0
	 */
	using Vector2A = ECM_ALIGN(16) Vector2;

	/**
	 * A general-purpose 2D vector with 32-bit integer components.
	 *
	 * This type alias is used for mathematical operations in a 2D space using
	 * integers.
	 *
	 * \since v1.0.0
	 */
	using Vector2i = Vector2_Base<int32>;

	/**
	 * A general-purpose 2D vector with 32-bit integer components and 16-byte
	 * alignment.
	 *
	 * This type alias is used for mathematical operations in a 2D space using
	 * integers, optimized for SIMD alignment.
	 *
	 * \note Requires SIMD alignment for efficient vectorized operations.
	 *
	 * \since v1.0.0
	 */
	using Vector2iA = ECM_ALIGN(16) Vector2i;

	/**
	 * A general-purpose 2D vector with unsigned 32-bit integer components.
	 *
	 * This type alias is used for mathematical operations in a 2D space using
	 * unsigned integers.
	 *
	 * \since v1.0.0
	 */
	using Vector2u = Vector2_Base<uint32>;

	/**
	 * A general-purpose 2D vector with unsigned 32-bit integer components and
	 * 16-byte alignment.
	 *
	 * This type alias is used for mathematical operations in a 2D space using
	 * unsigned integers, optimized for SIMD alignment.
	 *
	 * \note Requires SIMD alignment for efficient vectorized operations.
	 *
	 * \since v1.0.0
	 */
	using Vector2uA = ECM_ALIGN(16) Vector2u;
} // namespace ecm::math

#endif // !_ECM_VECTOR_H_