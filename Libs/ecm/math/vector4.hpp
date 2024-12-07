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

#include <type_traits>

namespace ecm::math
{
	/**
	 * This structure represents a 4d vector template.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	struct Vector4_Base
	{
		typedef T value_type;
		typedef Vector4_Base<T> type;

		/**
		 * Enum representing the axes of the vector.
		 *
		 * \since v1.0.0
		 */
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
				T x;
				// Y coordinate
				T y;
				// Z coordinate
				T z;
				// W coordinate
				T w;
			};
			T coord[4]{ 0 };
		};

		// Basic constructors

		/**
		 * Default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base();

		/**
		 * Copy constructor initializing from another vector.
		 *
		 * \param v The vector to copy from.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base(Vector4_Base<T> const& v);

		/**
		 * Constructor initializing with a scalar value.
		 * All components are set to the given scalar.
		 *
		 * \param scalar The value to initialize all x, y, z and w components.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base(T scalar);

		/**
		 * Constructor initializing with x, y, z and w coordinates.
		 *
		 * \param x The x coordinate.
		 * \param y The y coordinate.
		 * \param z The z coordinate.
		 * \param w The w coordinate.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base(T x, T y, T z, T w);

		/**
		 * Constructor initializing with an array of two coordinates.
		 *
		 * \param coord The coordinates as array with two values.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector4_Base(const T coord[4]);

		// Conversion constructors

		/**
		 * Conversion constructor initializing from a vector with a different
		 * type. Components are cast to the template type T.
		 *
		 * \param v The vector with components of type U to initialize from.
		 *
		 * \tparam U The type of the source vector's components.
		 *
		 * \since v1.0.0
		 */
		template<typename U>
		explicit constexpr Vector4_Base(Vector4_Base<U> const& v);

		// Component access

		/**
		 * Subscript operator to access vector elements by axes.
		 *
		 * \param axis The axes of the element to access.
		 *
		 * \returns The element at the given axes.
		 *
		 * \since v1.0.0
		 */
		constexpr T& operator[](const uint8 axis);

		/**
		 * Subscript operator to access vector elements by axes.
		 *
		 * \param axis The axes of the element to access.
		 *
		 * \returns The element at the given axes.
		 *
		 * \since v1.0.0
		 */
		constexpr T const& operator[](const uint8 axis) const;
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
