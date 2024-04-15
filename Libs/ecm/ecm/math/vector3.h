/*
  Extended Cpp Module
  Copyright (C) 2024, Alexander Burkhardt <alexander@fürth.org>

  All rights reserved.

  Use of this source code (the "Software"), except for compilation as part of a
  binary compiled library and its use in conjunction with the binary compiled
  library, without the prior written permission of the copyright owner is
  strictly prohibited. Permission is granted to use the header files of this
  software and to link against the binary compiled library, provided that the
  following conditions are met:

  1. redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
  2. redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

  THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
  OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO
  EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING OUT OF THE USE OF THE SOFTWARE OR ANY OTHER DEALINGS IN THE SOFTWARE.
*/

/*
 * \file Vector3.h
 *
 * \brief This header defines a three dimensional vector and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR3_H_
#define _ECM_VECTOR3_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	/*
	 * This structure represents a 3d vector.
	 *
	 * \since v1.0.0
	 */
	struct ECM_API Vector3
	{
		enum Axis : uint8
		{
			AXIS_X = 0,
			AXIS_Y,
			AXIS_Z,
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
			};
			float32 coord[3]{ 0.f };
		};

		/*
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3();

		/*
		 * This is a constructor.
		 *
		 * \param x the x coordinate.
		 * \param y the y coordinate.
		 * \param z the z coordinate.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3(float32 x, float32 y, float32 z);

		/*
		 * This is a constructor.
		 *
		 * \param coord the coordinates as array with three values.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3(float32 coord[3]);
	};

	/*
	 * This operator checks if the two Vector3 are the same.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr bool operator==(
		const Vector3& left, const Vector3& right);

	/*
	 * This operator checks if the two Vector3 are not the same.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr bool operator!=(
		const Vector3& left, const Vector3& right);

	/*
	 * This operator creates an new Vector3 object, calculates the addition of
	 * two Vector3 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns A new Vector3 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3 operator+(
		const Vector3& left, const Vector3& right);

	/*
	 * This operator creates a new Vector3 object, calculates the subtracting of
	 * two Vector3 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns A new Vector3 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3 operator-(
		const Vector3& left, const Vector3& right);

	/*
	 * This operator creates an new Vector3 object, calculates the
	 * multiplication of two Vector3 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns A new Vector3 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3 operator*(
		const Vector3& left, const Vector3& right);

	/*
	 * This operator creates a new Vector3 object, calculates the division of
	 * two Vector3 objects left and right component by component and returns the
	 * newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns A new Vector3 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3 operator/(
		const Vector3& left, const Vector3& right);

	/*
	 * This operator adds the two Vector3 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3& operator+=(
		Vector3& left, const Vector3& right);

	/*
	 * This operator subtracts the two Vector3 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3& operator-=(
		Vector3& left, const Vector3& right);

	/*
	 * This operator multiplies the two Vector3 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3& operator*=(
		Vector3& left, const Vector3& right);

	/*
	 * This operator devides the two Vector3 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param left right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3
	 */
	extern ECM_API constexpr Vector3& operator/=(
		Vector3& left, const Vector3& right);
} // namespace ecm::math

#endif // !_ECM_VECTOR3_H_
