/*
 * \file matrix4x4.h
 *
 * \brief This header defines a 4x4 matrix and functionalities.
 */

#pragma once
#ifndef _ECM_MATRIX4X4_H_
#define _ECM_MATRIX4X4_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	/*
	 * This structure represents a 4x4 matrix.
	 *
	 * \since v1.0.0
	 */
	struct ECM_API Matrix4x4
	{
		union
		{
			struct
			{
				// First row of matrix
				float32 m00, m01, m02, m03;
				// Second row of matrix
				float32 m10, m11, m12, m13;
				// Third row of matrix
				float32 m20, m21, m22, m23;
				// Fourth row of matrix
				float32 m30, m31, m32, m33;
			};
			// Matrix 2D array: 4x4 values
			float32 matrix[4][4];
			// Matrix 1D array: 16 values
			float32 elements[16]{ 0.f };
		};

		/*
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Matrix4x4();

		/*
		 * This is a constructor.
		 *
		 * \param m the value for initial identity.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Matrix4x4(float32 m);
		
		/*
		 * This is a constructor.
		 *
		 * \param m00 the value for [0][0].
		 * \param m01 the value for [0][1].
		 * \param m02 the value for [0][2].
		 * \param m03 the value for [0][3].
		 * \param m10 the value for [1][0].
		 * \param m11 the value for [1][1].
		 * \param m12 the value for [1][2].
		 * \param m13 the value for [1][3].
		 * \param m20 the value for [2][0].
		 * \param m21 the value for [2][1].
		 * \param m22 the value for [2][2].
		 * \param m23 the value for [2][3].
		 * \param m30 the value for [3][0].
		 * \param m31 the value for [3][1].
		 * \param m32 the value for [3][2].
		 * \param m33 the value for [3][3].
		 *
		 * \since v1.0.0
		 */
		inline constexpr Matrix4x4(
			float32 m00, float32 m01, float32 m02, float32 m03,
			float32 m10, float32 m11, float32 m12, float32 m13,
			float32 m20, float32 m21, float32 m22, float32 m23,
			float32 m30, float32 m31, float32 m32, float32 m33);

		/*
		 * This is a constructor.
		 *
		 * \param mat the matrix values as 2D array.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Matrix4x4(float32 mat[4][4]);

		/*
		 * This is a constructor.
		 *
		 * \param val the matrix values as 1D array.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Matrix4x4(float32 val[16]);
	};

	__declspec(align(16)) struct ECM_API Matrix4x4A : public Matrix4x4
	{
		using Matrix4x4::Matrix4x4;
	};

	/*
	 * This operator checks if the two Matrix4x4 are the same.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr bool operator==(
		const Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator checks if the two Matrix4x4 are not the same.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr bool operator!=(
		const Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator creates an new Matrix4x4 object, calculates the addition of
	 * two Matrix4x4 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns A new Matrix4x4 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr Matrix4x4 operator+(
		const Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator creates a new Matrix4x4 object, calculates the subtracting of
	 * two Matrix4x4 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns A new Matrix4x4 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr Matrix4x4 operator-(
		const Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator creates an new Matrix4x4 object, calculates the
	 * multiplication of two Matrix4x4 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns A new Matrix4x4 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr Matrix4x4 operator*(
		const Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator adds the two Matrix4x4 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr Matrix4x4& operator+=(
		Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator subtracts the two Matrix4x4 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr Matrix4x4& operator-=(
		Matrix4x4& left, const Matrix4x4& right);

	/*
	 * This operator multiplies the two Matrix4x4 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Matrix4x4 operand.
	 * \param left right Matrix4x4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	inline constexpr Matrix4x4& operator*=(
		Matrix4x4& left, const Matrix4x4& right);
} // namespace ecm::math

#endif // !_ECM_MATRIX4X4_H_
