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
	/**
	 * This structure represents a 4d vector template.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	struct Vector4_Base
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
				_Ty x;
				// Y coordinate
				_Ty y;
				// Z coordinate
				_Ty z;
				// W coordinate
				_Ty w;
			};
			_Ty coord[4]{ 0 };
		};

		/**
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base();

		/**
		 * This is a constructor.
		 *
		 * \param x the x coordinate.
		 * \param y the y coordinate.
		 * \param z the z coordinate.
		 * \param w the w coordinate.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base(_Ty x, _Ty y, _Ty z, _Ty w);

		/**
		 * This is a constructor.
		 *
		 * \param coord the coordinates as array with four values.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base(_Ty coord[4]);

		/**
		 * Subscript operator to access vector elements by axes.
		 *
		 * \param axis The axes of the element to access.
		 *
		 * \returns The element at the given axes.
		 *
		 * \since v1.0.0
		 */
		constexpr _Ty& operator[](const uint8 axis);

		/**
		 * Subscript operator to access vector elements by axes.
		 *
		 * \param axis The axes of the element to access.
		 *
		 * \returns The element at the given axes.
		 *
		 * \since v1.0.0
		 */
		constexpr const _Ty& operator[](const uint8 axis) const;
	};

	/**
	 * This structure represents a 4D vector with float32 elements.
	 *
	 * \since v1.0.0
	 */
	struct Vector4 : public Vector4_Base<float32>
	{
		using Vector4_Base<float32>::Vector4_Base;

		/**
		 * Constructor to initialize from a Vector4_Base<float32>.
		 *
		 * \param base The base vector to initialize from.
		 *
		 * \since v1.0.0
		 */
		Vector4(const Vector4_Base<float32>& base)
			: Vector4_Base{ base.x, base.y, base.z, base.w } {}
	};

	/**
	 * This structure represents a 4D vector with float32 elements, aligned to
	 * 16 bytes.
	 *
	 * \since v1.0.0
	 */
	ECM_ALIGN(16) struct Vector4A : public Vector4
	{
		using Vector4::Vector4;
	};
	
	/**
	 * This structure represents a 4D vector with int32 elements.
	 *
	 * \since v1.0.0
	 */
	struct Vector4i : public Vector4_Base<int32>
	{
		using Vector4_Base<int32>::Vector4_Base;

		/**
		 * Constructor to initialize from a Vector4_Base<int32>.
		 *
		 * \param base The base vector to initialize from.
		 *
		 * \since v1.0.0
		 */
		Vector4i(const Vector4_Base<int32>& base)
			: Vector4_Base{ base.x, base.y, base.z, base.w } {}
	};

	/**
	 * This structure represents a 4D vector with int32 elements, aligned to
	 * 16 bytes.
	 *
	 * \since v1.0.0
	 */
	ECM_ALIGN(16) struct Vector4iA : public Vector4i
	{
		using Vector4i::Vector4i;
	};

	/**
	 * This operator checks if the two Vector4 are the same.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr bool operator==(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/**
	 * This operator checks if the two Vector4 are not the same.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr bool operator!=(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/**
	 * This operator creates an new Vector4 object, calculates the addition of
	 * two Vector4 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns A new Vector4 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator+(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator creates a new Vector4 object, calculates the subtracting of
	 * two Vector4 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns A new Vector4 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator-(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator creates an new Vector4 object, calculates the
	 * multiplication of two Vector4 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns A new Vector4 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator*(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator creates a new Vector4 object, calculates the division of
	 * two Vector4 objects left and right component by component and returns the
	 * newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns A new Vector4 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator/(
		const Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator adds the two Vector4 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator+=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator subtracts the two Vector4 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator-=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator multiplies the two Vector4 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator*=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator devides the two Vector4 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Vector4 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator/=(
		Vector4_Base<_Ty>& left, const Vector4_Base<_Ty>& right);

	/*
	 * This operator creates an new Vector4 object, calculates the addition of a
	 * Vector4 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns A new Vector4 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator+(
		const Vector4_Base<_Ty>& left, const _Ty& right);

	/*
	 * This operator creates a new Vector4 object, calculates the subtracting of a
	 * Vector4 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns A new Vector4 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator-(
		const Vector4_Base<_Ty>& left, const _Ty& right);

	/*
	 * This operator creates an new Vector4 object, calculates the
	 * multiplication of a Vector4 object and a Float32 object, left and right
	 * component-wise and returns the newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns A new Vector4 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator*(
		const Vector4_Base<_Ty>& left, const _Ty& right);

	/*
	 * This operator creates a new Vector4 object, calculates the division of a
	 * Vector4 object and a Float32 object, left and right component by
	 * component and returns the newly created object.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns A new Vector4 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty> operator/(
		const Vector4_Base<_Ty>& left, const _Ty& right);

	/*
	 * This operator adds a Float32 object to a Vector4 object, left and right
	 * together and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator+=(
		Vector4_Base<_Ty>& left, _Ty& right);

	/*
	 * This operator subtracts a Float32 object from a Vector4 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator-=(
		Vector4_Base<_Ty>& left, _Ty& right);

	/*
	 * This operator multiplies a Float32 object with a Vector4 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator*=(
		Vector4_Base<_Ty>& left, _Ty& right);

	/*
	 * This operator devides a Float32 object with a Vector4 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector4 operand.
	 * \param right Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector4
	 */
	template<typename _Ty> constexpr Vector4_Base<_Ty>& operator/=(
		Vector4_Base<_Ty>& left, _Ty& right);
} // namespace ecm::math

#include "vector4.inl"

#endif // !_ECM_VECTOR4_H_
