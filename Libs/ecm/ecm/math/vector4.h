/*
 * \file Vector4.h
 *
 * \brief This header defines a four dimensional vector and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR4_H_
#define _ECM_VECTOR4_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	/*
	 * This structure represents a 4d vector.
	 *
	 * \since v1.0.0
	 */
	struct ECM_API Vector4
	{
		enum Axis : uint8
		{
			AXIS_X = 0,
			AXIS_Y,
			AXIS_Z,
			AXIS_W,
			AXIS_COUNT
		};
		union
		{
			struct
			{
				// X coordinate
				float32 x;
				// Y coordinate
				float32 y;
				// Z coordinate
				float32 z;
				// W coordinate
				float32 w;
			};
			float32 coord[4]{ 0.f };
		};

		/*
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4();

		/*
		 * This is a constructor.
		 *
		 * \param x the x coordinate.
		 * \param y the y coordinate.
		 * \param z the z coordinate.
		 * \param w the w coordinate.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4(float32 x, float32 y, float32 z, float32 w);

		/*
		 * This is a constructor.
		 *
		 * \param coord the coordinates as array with four values.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4(float32 coord[4]);
	};

	/*
	 * This operator checks if the two Vector4 are the same.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr bool operator==(
		const Vector4& left, const Vector4& right);

	/*
	 * This operator checks if the two Vector4 are not the same.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr bool operator!=(
		const Vector4& left, const Vector4& right);

	/*
	 * This operator creates an new Vector4 object, calculates the addition of
	 * two Vector4 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns A new Vector4 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4 operator+(
		const Vector4& left, const Vector4& right);

	/*
	 * This operator creates a new Vector4 object, calculates the subtracting of
	 * two Vector4 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns A new Vector4 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4 operator-(
		const Vector4& left, const Vector4& right);

	/*
	 * This operator creates an new Vector4 object, calculates the
	 * multiplication of two Vector4 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns A new Vector4 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4 operator*(
		const Vector4& left, const Vector4& right);

	/*
	 * This operator creates a new Vector4 object, calculates the division of
	 * two Vector4 objects left and right component by component and returns the
	 * newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns A new Vector4 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4 operator/(
		const Vector4& left, const Vector4& right);

	/*
	 * This operator adds the two Vector4 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4& operator+=(
		Vector4& left, const Vector4& right);

	/*
	 * This operator subtracts the two Vector4 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4& operator-=(
		Vector4& left, const Vector4& right);

	/*
	 * This operator multiplies the two Vector4 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4& operator*=(
		Vector4& left, const Vector4& right);

	/*
	 * This operator devides the two Vector4 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param left right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	extern ECM_API constexpr Vector4& operator/=(
		Vector4& left, const Vector4& right);
} // namespace ecm::math

#endif // !_ECM_VECTOR4_H_
