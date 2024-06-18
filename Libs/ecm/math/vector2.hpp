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
	 * This structure represents a 2d vector template.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	struct Vector2_Base
	{
		/*
		 * Enum representing the axes of the vector.
		 *
		 * \since v1.0.0
		 */
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
					_Ty x;
					// Value for width
					_Ty width;
				};
				union
				{
					// Y coordinate
					_Ty y;
					// Value for height
					_Ty height;
				};
			};
			_Ty coord[2]{ 0 };
		};

		/*
		 * Default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector2_Base();

		/*
		 * Constructor initializing with x and y coordinates.
		 *
		 * \param x the x coordinate or width.
		 * \param y the y coordinate or height.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector2_Base(_Ty x, _Ty y);

		/*
		 * Constructor initializing with an array of two coordinates.
		 *
		 * \param coord the coordinates as array with two values.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector2_Base(_Ty coord[2]);

		/*
		 * Subscript operator to access vector elements by axes.
		 *
		 * \param axis The axes of the element to access.
		 *
		 * \returns The element at the given axes.
		 *
		 * \since v1.0.0
		 */
		constexpr _Ty operator[](const uint8 axis) const;
	};

	/*
	 * This structure represents a 2D vector with float32 elements.
	 *
	 * \since v1.0.0
	 */
	struct Vector2 : public Vector2_Base<float32>
	{
		using Vector2_Base<float32>::Vector2_Base;

		/*
		 * Constructor to initialize from a Vector2_Base<float32>.
		 *
		 * \param base The base vector to initialize from.
		 *
		 * \since v1.0.0
		 */
		Vector2(const Vector2_Base<float32>& base)
			: Vector2_Base{ base.x, base.y } {}
	};

	/*
	 * This structure represents a 2D vector with float32 elements, aligned to
	 * 16 bytes.
	 *
	 * \since v1.0.0
	 */
	__declspec(align(16)) struct Vector2A : public Vector2
	{
		using Vector2::Vector2;
	};

	/*
	 * This structure represents a 2D point with float32 elements.
	 *
	 * \since v1.0.0
	 */
	struct PointF : public Vector2
	{
		using Vector2::Vector2;
	};
	
	/*
	 * This structure represents a 2D vector with int32 elements.
	 *
	 * \since v1.0.0
	 */
	struct Vector2i : public Vector2_Base<int32>
	{
		using Vector2_Base<int32>::Vector2_Base;

		/*
		 * Constructor to initialize from a Vector2_Base<int32>
		 *
		 * \param base The base vector to initialize from.
		 *
		 * \since v1.0.0
		 */
		Vector2i(const Vector2_Base<int32>& base)
			: Vector2_Base{ base.x, base.y } {}
	};

	/*
	 * This structure represents a 2D vector with int32 elements, aligned to 16
	 * bytes.
	 *
	 * \since v1.0.0
	 */
	__declspec(align(16)) struct Vector2iA : public Vector2i
	{
		using Vector2i::Vector2i;
	};

	/*
	 * This structure represents a 2D point with int32 elements.
	 *
	 * \since v1.0.0
	 */
	struct PointI : public Vector2i
	{
		using Vector2i::Vector2i;
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
	template<typename _Ty> constexpr bool operator==(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr bool operator!=(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);

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
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator+(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator-(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator*(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator/(
		const Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);

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
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator+=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator-=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator*=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);
	
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
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator/=(
		Vector2_Base<_Ty>& left, const Vector2_Base<_Ty>& right);

	/*
	 * This operator creates an new Vector2 object, calculates the addition of a
	 * Vector2 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector2 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator+(
		const Vector2_Base<_Ty>& left, const _Ty& scalar);

	/*
	 * This operator creates a new Vector2 object, calculates the subtracting of a
	 * Vector2 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector2 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator-(
		const Vector2_Base<_Ty>& left, const _Ty& scalar);

	/*
	 * This operator creates an new Vector2 object, calculates the
	 * multiplication of a Vector2 object and a Float32 object, left and right
	 * component-wise and returns the newly created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector2 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator*(
		const Vector2_Base<_Ty>& left, const _Ty& scalar);

	/*
	 * This operator creates a new Vector2 object, calculates the division of a
	 * Vector2 object and a Float32 object, left and right component by
	 * component and returns the newly created object.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector2 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty> operator/(
		const Vector2_Base<_Ty>& left, const _Ty& scalar);

	/*
	 * This operator adds a Float32 object to a Vector2 object, left and right
	 * together and returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator+=(
		Vector2_Base<_Ty>& left, _Ty& scalar);

	/*
	 * This operator subtracts a Float32 object from a Vector2 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator-=(
		Vector2_Base<_Ty>& left, _Ty& scalar);

	/*
	 * This operator multiplies a Float32 object with a Vector2 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator*=(
		Vector2_Base<_Ty>& left, _Ty& scalar);

	/*
	 * This operator devides a Float32 object with a Vector2 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector2 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector2
	 */
	template<typename _Ty> constexpr Vector2_Base<_Ty>& operator/=(
		Vector2_Base<_Ty>& left, _Ty& scalar);
} // namespace ecm::math

#include "vector2.inl"

#endif // !_ECM_VECTOR2_H_
