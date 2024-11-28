/**
 * \file Vector3.h
 *
 * \brief This header defines a three dimensional vector and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR3_H_
#define _ECM_VECTOR3_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

#include <type_traits>

namespace ecm::math
{
	/**
	 * This structure represents a 3d vector template.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	struct Vector3_Base
	{
		typedef T value_type;
		typedef Vector3_Base<T> type;

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
			};
			T coord[3]{ 0 };
		};

		// Basic constructors

		/**
		 * Default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base();

		/**
		 * Copy constructor initializing from another vector.
		 *
		 * \param v The vector to copy from.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base(Vector3_Base<T> const& v);

		/**
		 * Constructor initializing with a scalar value.
		 * All components are set to the given scalar.
		 *
		 * \param scalar The value to initialize both x, y and z components.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base(T scalar);

		/**
		 * Constructor initializing width x, y and z coordinates.
		 *
		 * \param x The x coordinate.
		 * \param y The y coordinate.
		 * \param z The z coordinate.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base(T x, T y, T z);

		/**
		 * Constructor initializing with an array of three coordinates.
		 *
		 * \param coord The coordinates as array with three values.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base(const T coord[3]);

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
		explicit constexpr Vector3_Base(Vector3_Base<U> const& v);

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
		constexpr const T& operator[](const uint8 axis) const;
	};

	/**
	 * This structure represents a 3D vector with float32 elements.
	 *
	 * \since v1.0.0
	 */
	struct Vector3 : public Vector3_Base<float32>
	{
		using Vector3_Base<float32>::Vector3_Base;

		/**
		 * Constructor to initialize from a Vector3_Base<float32>.
		 *
		 * \param base The base vector to initialize from.
		 *
		 * \since v1.0.0
		 */
		Vector3(const Vector3_Base<float32>& base)
			: Vector3_Base{ base.x, base.y, base.z } {}
	};

	/**
	 * This structure represents a 3D vector with float32 elements, aligned to
	 * 16 bytes.
	 *
	 * \since v1.0.0
	 */
	__declspec(align(16)) struct Vector3A : public Vector3
	{
		using Vector3::Vector3;
	};

	/**
	 * This structure represents a 3D vector with int32 elements.
	 *
	 * \since v1.0.0
	 */
	struct Vector3i : public Vector3_Base<int32>
	{
		using Vector3_Base<int32>::Vector3_Base;

		/**
		 * Constructor to initialize from a Vector3_Base<int32>.
		 *
		 * \param base The base vector to initialize from.
		 *
		 * \since v1.0.0
		 */
		Vector3i(const Vector3_Base<int32>& base)
			: Vector3_Base{ base.x, base.y, base.z } {}
	};

	/**
	 * This structure represents a 3D vector with int32 elements, aligned to 16
	 * bytes.
	 *
	 * \since v1.0.0
	 */
	__declspec(align(16)) struct Vector3iA : public Vector3i
	{
		using Vector3i::Vector3i;
	};

	/**
	 * This operator checks if the two Vector3 are the same.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr bool operator==(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator checks if the two Vector3 are not the same.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr bool operator!=(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator creates an new Vector3 object, calculates the addition of
	 * two Vector3 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns A new Vector3 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator+(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator creates a new Vector3 object, calculates the subtracting of
	 * two Vector3 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns A new Vector3 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator-(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator creates an new Vector3 object, calculates the
	 * multiplication of two Vector3 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns A new Vector3 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator*(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator creates a new Vector3 object, calculates the division of
	 * two Vector3 objects left and right component by component and returns the
	 * newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns A new Vector3 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator/(
		const Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator adds the two Vector3 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator+=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator subtracts the two Vector3 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator-=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator multiplies the two Vector3 objects left and right together
	 * and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator*=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator devides the two Vector3 objects left and right together and
	 * returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param right Right Vector3 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator/=(
		Vector3_Base<_Ty>& left, const Vector3_Base<_Ty>& right);

	/**
	 * This operator creates an new Vector3 object, calculates the addition of a
	 * Vector3 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator+(
		const Vector3_Base<_Ty>& left, const _Ty& scalar);

	/**
	 * This operator creates a new Vector3 object, calculates the subtracting of a
	 * Vector3 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator-(
		const Vector3_Base<_Ty>& left, const _Ty& scalar);

	/**
	 * This operator creates an new Vector3 object, calculates the
	 * multiplication of a Vector3 object and a Float32 object, left and right
	 * component-wise and returns the newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator*(
		const Vector3_Base<_Ty>& left, const _Ty& scalar);

	/**
	 * This operator creates a new Vector3 object, calculates the division of a
	 * Vector3 object and a Float32 object, left and right component by
	 * component and returns the newly created object.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty> operator/(
		const Vector3_Base<_Ty>& left, const _Ty& scalar);

	/**
	 * This operator adds a Float32 object to a Vector3 object, left and right
	 * together and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator+=(
		Vector3_Base<_Ty>& left, _Ty& scalar);

	/**
	 * This operator subtracts a Float32 object from a Vector3 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator-=(
		Vector3_Base<_Ty>& left, _Ty& scalar);

	/**
	 * This operator multiplies a Float32 object with a Vector3 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator*=(
		Vector3_Base<_Ty>& left, _Ty& scalar);

	/**
	 * This operator devides a Float32 object with a Vector3 object, left and
	 * right together and returns the new value of left.
	 *
	 * \param left Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns After calculation reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename _Ty> constexpr Vector3_Base<_Ty>& operator/=(
		Vector3_Base<_Ty>& left, _Ty& scalar);
} // namespace ecm::math

#include "vector3.inl"

#endif // !_ECM_VECTOR3_H_
