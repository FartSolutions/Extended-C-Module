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
		 * \param scalar The value to initialize all x, y and z components.
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

		// Unary arithmetic operators

		/**
		 * Assignment operator.
		 * Assigns the values of another vector to this one.
		 *
		 * \param v The vector to assign from.
		 *
		 * \returns A reference to this vector after assignment.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base<T>& operator=(Vector3_Base<T> const& v);

		/**
		 * Assignment operator for a vector with different component type.
		 * Assigns and casts the components from a vector of type U.
		 *
		 * \param v The vector to assign from.
		 *
		 * \tparam U The type of the source vector's component.
		 *
		 * \returns A reference to this vector after assignment.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator=(Vector3_Base<U> const& v);

		/**
		 * Adds a scalar to each component of the vector.
		 *
		 * \param scalar The scalar value to add.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this vector after addition.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator+=(U scalar);

		/**
		 * Adds another vector to this one component-wise.
		 *
		 * \param v The vector to add.
		 *
		 * \tparam U The type of the other vector's components, must be
		 *           arithmetic.
		 *
		 * \returns A reference to this vector after addition.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator+=(Vector3_Base<U> const& scalar);

		/**
		 * Subtracts a scalar from each component of the vector.
		 *
		 * \param scalar The scalar value to subtract.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this vector after subtraction
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator-=(U scalar);

		/**
		 * Subtracts another vector from this one component-wise.
		 *
		 * \param v The vector to subtract.
		 *
		 * \tparam U The type of the other vector's components, must be
		 *           arithmetic.
		 *
		 * \returns A reference to this vector after subtraction.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator-=(Vector3_Base<U> const& scalar);

		/**
		 * Multiplies each component of the vector by a scalar.
		 *
		 * \param scalar The scalar value to multiply by.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this vector after multiplication.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator*=(U scalar);

		/**
		 * Multiplies this vector component-wise by another vector.
		 *
		 * \param v The vector to multiply by.
		 *
		 * \tparam U The type of the other vector's components, must be
		 *           arithmetic.
		 *
		 * \returns A reference to this vector after multiplication.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator*=(Vector3_Base<U> const& scalar);

		/**
		 * Divides each component of the vector by a scalar.
		 *
		 * \param scalar The scalar value to divide by.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this vector after division.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator/=(U scalar);

		/**
		 * Divides this vector component-wise by another vector.
		 *
		 * \param v The vector to divide by.
		 *
		 * \tparam U The type of the other vector's components, must be
		 *           arithmetic.
		 *
		 * \returns A reference to this vector after division.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Vector3_Base<T>& operator/=(Vector3_Base<U> const& scalar);

		// Increment and decrement operators

		/**
		 * Prefix increment operator.
		 * Increments each component of the vector by 1.
		 *
		 * \returns A reference to this vector after the increment.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base<T>& operator++();

		/**
		 * Prefix decrement operator.
		 * Decrements each component of the vector by 1.
		 *
		 * \returns A reference to this vector after the decrement.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base<T>& operator--();

		/**
		 * Postfix increment operator.
		 * Increments each component of the vector by 1.
		 *
		 * \returns A copy of the vector before the increment.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base<T> operator++(int);

		/**
		 * Postfix decrement operator.
		 * Decrements each component of the vector by 1.
		 *
		 * \returns A copy of the vector before the decrement.
		 *
		 * \since v1.0.0
		 */
		constexpr Vector3_Base<T> operator--(int);
	};

	// Boolean operators

	/**
	 * This operator checks if the two Vector2 are the same.
	 *
	 * \param v1 Left Vector3 operand.
	 * \param v2 Right Vector3 operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T>
	constexpr bool operator==(Vector3_Base<T> const& v1, Vector3_Base<T> const& v2);

	/**
	 * This operator checks if the two Vector3 are not the same.
	 *
	 * \param v1 Left Vector3 operand.
	 * \param v2 Right Vector3 operand.
	 *
	 * \returns true if left is not same as right, or false.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T>
	constexpr bool operator!=(Vector3_Base<T> const& v1, Vector3_Base<T> const& v2);

	/**
	 * Logical AND operator for two boolean vectors.
	 *
	 * \param v1 The left operand.
	 * \param v2 The right operand.
	 *
	 * \returns A boolean vector where each component is the logical AND of the
	 *          corresponding components in the operands.
	 *
	 * \since v1.0.0
	 */
	constexpr Vector3_Base<bool> operator&&(Vector3_Base<bool> const& v1, Vector3_Base<bool> const& v2);

	/**
	 * Logical OR operator for two boolean vectors.
	 *
	 * \param v1 The left operand.
	 * \param v2 The right operand.
	 *
	 * \returns A boolean vector where each component is the logical OR of the
	 *          corresponding components in the operands.
	 *
	 * \since v1.0.0
	 */
	constexpr Vector3_Base<bool> operator||(Vector3_Base<bool> const& v1, Vector3_Base<bool> const& v2);

	// Unary arithmetic operators

	/**
	 * Unary plus operator.
	 * Returns the vector itself.
	 *
	 * \param v The vector to apply the operator to.
	 *
	 * \returns A copy of the input vector.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	constexpr Vector3_Base<T> operator+(Vector3_Base<T> const& v);

	/**
	 * Unary minus operator.
	 * Negates each component of the vector.
	 *
	 * \param v The vector to apply the operator to.
	 *
	 * \returns A new vector with each component negated.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	constexpr Vector3_Base<T> operator-(Vector3_Base<T> const& v);

	// Binary operators

	/**
	 * This operator creates an new Vector3 object, calculates the addition of a
	 * Vector3 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param v Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator+(Vector3_Base<T> const& v, U scalar);

	/**
	 * This operator creates an new Vector3 object, calculates the addition of
	 * two Vector3 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param v1 Left Vector3 operand.
	 * \param v2 Right Vector3 operand.
	 *
	 * \returns A new Vector3 object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator+(Vector3_Base<T> const& v1, Vector3_Base<U> const& v2);

	/**
	 * This operator creates a new Vector3 object, calculates the subtracting of
	 * a Vector3 object and a Float32 object, left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param v Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator-(Vector3_Base<T> const& v, U scalar);

	/**
	 * This operator creates a new Vector3 object, calculates the subtracting of
	 * two Vector3 objects left and right component-wise and returns the newly
	 * created object.
	 *
	 * \param v1 Left Vector3 operand.
	 * \param v2 Right Vector3 operand.
	 *
	 * \returns A new Vector3 object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator-(Vector3_Base<T> const& v1, Vector3_Base<U> const& v2);

	/**
	 * This operator creates an new Vector3 object, calculates the
	 * multiplication of a Vector3 object and a Float32 object, left and right
	 * component-wise and returns the newly created object.
	 *
	 * \param v Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator*(Vector3_Base<T> const& v, U scalar);

	/**
	 * This operator creates an new Vector3 object, calculates the
	 * multiplication of two Vector3 objects left and right component-wise and
	 * returns the newly created object.
	 *
	 * \param v1 Left Vector3 operand.
	 * \param v2 Right Vector3 operand.
	 *
	 * \returns A new Vector3 object, which is the multiplicate of left and
	 *          right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator*(Vector3_Base<T> const& v1, Vector3_Base<U> const& v2);

	/**
	 * This operator creates a new Vector3 object, calculates the division of a
	 * Vector3 object and a Float32 object, left and right component by
	 * component and returns the newly created object.
	 *
	 * \param v Left Vector3 operand.
	 * \param scalar Right Float32 operand.
	 *
	 * \returns A new Vector3 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator/(Vector3_Base<T> const& v, U scalar);

	/**
	 * This operator creates a new Vector3 object, calculates the division of
	 * two Vector3 objects left and right component by component and returns the
	 * newly created object.
	 *
	 * \param v1 Left Vector3 operand.
	 * \param v2 Right Vector3 operand.
	 *
	 * \returns A new Vector3 object calculated by divide left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Vector3_Base
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Vector3_Base<T> operator/(Vector3_Base<T> const& v1, Vector3_Base<U> const& v2);
} // namespace ecm::math

#include "vector3.inl"

#endif // !_ECM_VECTOR3_H_
