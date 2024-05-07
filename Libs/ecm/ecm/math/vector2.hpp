/*
 * \file Vector2.h
 *
 * \brief This header defines a two dimensional vector and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR2_H_
#define _ECM_VECTOR2_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	/*
	 * This structure represents a 2d vector.
	 *
	 * \since v1.0.0
	 */
	struct ECM_API Vector2
	{
		enum Axis : uint8
		{
			AXIS_X = 0,
			AXIS_Y,
			AXIS_COUNT
		};
		union
		{
			struct
			{
				union
				{
					// X coordinate
					float32 x;
					// Value for width
					float32 width;
				};
				union
				{
					// Y coordinate
					float32 y;
					// Value for height
					float32 height;
				};
			};
			float32 coord[2]{ 0.f };
		};

		/*
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Vector2();

		/*
		 * This is a constructor.
		 *
		 * \param x the x coordinate or width.
		 * \param y the y coordinate or height.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Vector2(float32 x, float32 y);

		/*
		 * This is a constructor.
		 *
		 * \param coord the coordinates as array with two values.
		 *
		 * \since v1.0.0
		 */
		inline constexpr Vector2(float32 coord[2]);
	};

	__declspec(align(16)) struct Vector2A : public Vector2
	{
		using Vector2::Vector2;
	};

	/*
	 * This operator checks if the two Vector2 are the same.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr bool operator==(
		const Vector2& left, const Vector2& right);
	
	/*
	 * This operator checks if the two Vector2 are not the same.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr bool operator!=(
		const Vector2& left, const Vector2& right);

	/*
	 * This operator creates an new Vector2 object, calculates the addition of
	 * two Vector2 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns A new Vector2 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2 operator+(
		const Vector2& left, const Vector2& right);
	
	/*
	 * This operator creates a new Vector2 object, calculates the subtracting of
	 * two Vector2 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns A new Vector2 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2 operator-(
		const Vector2& left, const Vector2& right);
	
	/*
	 * This operator creates an new Vector2 object, calculates the
	 * multiplication of two Vector2 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns A new Vector2 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2 operator*(
		const Vector2& left, const Vector2& right);
	
	/*
	 * This operator creates a new Vector2 object, calculates the division of
	 * two Vector2 objects left and right component by component and returns the
	 * newly created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns A new Vector2 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2 operator/(
		const Vector2& left, const Vector2& right);

	/*
	 * This operator adds the two Vector2 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2& operator+=(
		Vector2& left, const Vector2& right);
	
	/*
	 * This operator subtracts the two Vector2 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2& operator-=(
		Vector2& left, const Vector2& right);
	
	/*
	 * This operator multiplies the two Vector2 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2& operator*=(
		Vector2& left, const Vector2& right);
	
	/*
	 * This operator devides the two Vector2 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param left right Vector2 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	inline constexpr Vector2& operator/=(
		Vector2& left, const Vector2& right);

	/*
	 * This structure represents a 2d position.
	 *
	 * \since v1.0.0
	 */
	using PointF = Vector2;
} // namespace ecm::math

#endif // !_ECM_VECTOR2_H_
