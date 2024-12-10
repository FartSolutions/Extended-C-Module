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
#include "vector3.hpp"

#include <type_traits>

namespace ecm::math
{
	/*
	 * This structure represents a 4x4 matrix template.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	struct Matrix4x4_Base
	{
		typedef T value_type;
		typedef Vector4_Base<T> column_type;
		typedef Vector4_Base<T> row_type;
		typedef Matrix4x4_Base<T> type;

		union
		{
			struct
			{
				// First row of the matrix
				T m00, m01, m02, m03;
				// Second row of the matrix
				T m10, m11, m12 the, m13;
				// Third row of matrix
				T m20, m21, m22, m23;
				// Fourth row of the matrix
				T m30, m31, m32, m33;
			};
			// Matrix represented as a 2D array (4x4).
			T matrix[4][4];
			// Matrix represented as a flat 1D array (16 elements).
			T elements[16]{ 0.f };
			// Matrix represented as rows as column vectors.
			column_type rows[4];
		};

		// Basic constructors

		/*
		 * Default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base();

		/*
		 * Copy constructor.
		 *
		 * \param m The matrix to copy.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base(Matrix4x4_Base<T> const& m);

		/*
		 * Scalar constructor.
		 * Initializes all components of the matrix with the given scalar value.
		 *
		 * \param s The scalar value to initialize the matrix.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base(T scalar);

		/**
		 * Component-wise constructor.
		 * Initializes the matrix with individual row elements.
		 *
		 * \param x0, y0, z0, w0 Components of the first row.
		 * \param x1, y1, z1, w1 Components of the second row.
		 * \param x2, y2, z2, w2 Components of the third row.
		 * \param x3, y3, z3, w3 Components of the fourth row.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base(
			T const& x0, T const& y0, T const& z0, T const& w0,
			T const& x1, T const& y1, T const& z1, T const& w1,
			T const& x2, T const& y2, T const& z2, T const& w2,
			T const& x3, T const& y3, T const& z3, T const& w3);

		/**
		 * Column vector constructor.
		 * Initializes the matrix with four column vectors.
		 *
		 * \param v0, v1, v2, v3 The column vectors to initialize the matrix.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base(
			column_type const& v0,
			column_type const& v1,
			column_type const& v2,
			column_type const& v3);

		// Conversion constructors

		/**
		 * Conversion constructor with individual row components of different
		 * types.
		 *
		 * \param x1, y1, z1, w1 Components of the first row.
		 * \param x2, y2, z2, w2 Components of the second row.
		 * \param x3, y3, z3, w3 Components of the third row.
		 * \param x4, y4, z4, w4 Components of the fourth row.
		 *
		 * \tparam X1, Y1, Z1, W1 Types of the components of the first row.
		 * \tparam X2, Y2, Z2, W2 Types of the components of the second row.
		 * \tparam X3, Y3, Z3, W3 Types of the components of the third row.
		 * \tparam X4, Y4, Z4, W4 Types of the components of the fourth row.
		 *
		 * \since v1.0.0
		 */
		template<
			typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2,
			typename X3, typename Y3, typename Z3, typename W3,
			typename X4, typename Y4, typename Z4, typename W4>
		constexpr Matrix4x4_Base(
			X1 const& x1, Y1 const& y1, Z1 const& z1, W1 const& w1,
			X2 const& x2, Y2 const& y2, Z2 const& z2, W2 const& w2,
			X3 const& x3, Y3 const& y3, Z3 const& z3, W3 const& w3,
			X4 const& x4, Y4 const& y4, Z4 const& z4, W4 const& w4);

		/**
		 * Conversion constructor with column vectors of different types.
		 *
		 * \param v1, v2, v3, v4 The column vectors to initialize the matrix.
		 *
		 * \tparam V1, V2, V3, V4 Types of the column vectors.
		 *
		 * \since v1.0.0
		 */
		template<typename V1, typename V2, typename V3, typename V4>
		constexpr Matrix4x4_Base(
			Vector4_Base<V1> const& v1,
			Vector4_Base<V2> const& v2,
			Vector4_Base<V3> const& v3,
			Vector4_Base<V4> const& v4);

		/**
		 * Conversion constructor from a matrix of a different type.
		 *
		 * \param m The matrix to convert from.
		 *
		 * \tparam U The type of the input matrix.
		 *
		 * \since v1.0.0
		 */
		template<typename U>
		explicit constexpr Matrix4x4_Base(Matrix4x4_Base<U> const& m);

		// Component accesses

		/**
		 * Access a column of the matrix.
		 *
		 * \param i The index of the column to access (0-3).
		 *
		 * \returns A reference to the column vector.
		 *
		 * \since v1.0.0
		 */
		constexpr column_type& operator[](uint8 i) noexcept;

		/**
		 * Access a column of the matrix (const version).
		 *
		 * \param i The index of the column to access (0-3).
		 *
		 * \returns A const reference to the column vector.
		 *
		 * \since v1.0.0
		 */
		constexpr column_type const& operator[](uint8 i) const noexcept;

		// Unary arithmetic operators

		/**
		 * Assignment operator.
		 * Assigns the values of another matrix to this one.
		 *
		 * \param m The matrix to assign from.
		 *
		 * \returns A reference to this matrix after assignment.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base<T>& operator=(Matrix4x4_Base<T> const& m);

		/**
		 * Assignment operator for a matrix of a different type.
		 * Converts and assigns the values of another matrix to this one.
		 *
		 * \param m The matrix to assign from.
		 *
		 * \tparam U The type of the input matrix.
		 *
		 * \returns A reference to this matrix after assignment.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator=(Matrix4x4_Base<U> const& m);

		/**
		 * Adds a scalar to each element of the matrix.
		 *
		 * \param scalar The scalar value to add.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this matrix after addition.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator+=(U scalar);

		/**
		 * Adds another matrix to this one element-wise.
		 *
		 * \param m The matrix to add.
		 *
		 * \tparam U The type of the other matrix's elements.
		 *
		 * \returns A reference to this matrix after addition.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator+=(Matrix4x4_Base<U> const& m);

		/**
		 * Subtracts a scalar from each element of the matrix.
		 *
		 * \param scalar The scalar value to subtract.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this matrix after subtraction.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator-=(U scalar);

		/**
		 * Subtracts another matrix from this one element-wise.
		 *
		 * \param m The matrix to subtract.
		 *
		 * \tparam U The type of the other matrix's elements.
		 *
		 * \returns A reference to this matrix after subtraction.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator-=(Matrix4x4_Base<U> const& m);

		/**
		 * Multiplies each element of the matrix by a scalar.
		 *
		 * \param scalar The scalar value to multiply by.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this matrix after multiplication.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator*=(U scalar);

		/**
		 * Multiplies this matrix element-wise by another matrix.
		 *
		 * \param m The matrix to multiply by.
		 *
		 * \tparam U The type of the other matrix's elements.
		 *
		 * \returns A reference to this matrix after multiplication.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator*=(Matrix4x4_Base<U> const& m);

		/**
		 * Divides each element of the matrix by a scalar.
		 *
		 * \param scalar The scalar value to divide by.
		 *
		 * \tparam U The type of the scalar, must be arithmetic.
		 *
		 * \returns A reference to this matrix after division.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator/=(U scalar);

		/**
		 * Divides this matrix element-wise by another matrix.
		 *
		 * \param m The matrix to divide by.
		 *
		 * \tparam U The type of the other matrix's elements.
		 *
		 * \returns A reference to this matrix after division.
		 *
		 * \since v1.0.0
		 */
		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator/=(Matrix4x4_Base<U> const& m);

		// Increment and decrement operators

		/**
		 * Prefix increment operator.
		 * Increments each element of the matrix by 1.
		 *
		 * \returns A reference to this matrix after increment.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base<T>& operator++();

		/**
		 * Prefix decrement operator.
		 * Decrements each element of the matrix by 1.
		 *
		 * \returns A reference to this matrix after decrement.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base<T>& operator--();

		/**
		 * Postfix increment operator.
		 * Increments each element of the matrix by 1.
		 *
		 * \returns A copy of the matrix before the increment.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base<T> operator++(int);

		/**
		 * Postfix decrement operator.
		 * Decrements each element of the matrix by 1.
		 *
		 * \returns A copy of the matrix before the decrement.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base<T> operator--(int);
	};

	// Boolean operators

	/**
	 * Equality operator.
	 * Checks if two matrices are element-wise equal.
	 *
	 * \param m1 The first matrix to compare.
	 * \param m2 The second matrix to compare.
	 *
	 * \returns true if all elements are equal, false otherwise.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	constexpr bool operator==(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<T> const& m2);

	/**
	 * Inequality operator.
	 * Checks if two matrices are not element-wise equal.
	 *
	 * \param m1 The first matrix to compare.
	 * \param m2 The second matrix to compare.
	 *
	 * \returns true if at least one element is not equal, false otherwise.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	constexpr bool operator!=(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<T> const& m2);

	// Unary arithmetic operators

	/**
	 * Unary plus operator.
	 * Returns the matrix itself.
	 *
	 * \param m The matrix to apply the operator to.
	 *
	 * \returns A copy of the input matrix.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m);

	/**
	 * Unary minus operator.
	 * Negates each element of the matrix.
	 *
	 * \param m The matrix to apply the operator to.
	 *
	 * \returns A new matrix with all elements negated.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m);

	// Binary operators

	/**
	 * Adds a scalar to each element of the matrix.
	 *
	 * \param m The matrix to add to.
	 * \param scalar The scalar value to add.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the addition.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m, U scalar);

	/**
	 * Adds a scalar to each element of the matrix (commutative).
	 *
	 * \param scalar The scalar value to add.
	 * \param m The matrix to add to.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the addition.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator+(U scalar, Matrix4x4_Base<T> const& m);

	/**
	 * Adds two matrices element-wise.
	 *
	 * \param m1 The first matrix to add.
	 * \param m2 The second matrix to add.
	 *
	 * \tparam U The type of the second matrix's elements.
	 *
	 * \returns A new matrix with the result of the addition.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);

	/**
	 * Subtracts a scalar from each element of the matrix.
	 *
	 * \param m The matrix to subtract from.
	 * \param scalar The scalar value to subtract.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the subtraction.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m, U scalar);

	/**
	 * Subtracts a scalar from each element of the matrix (commutative).
	 *
	 * \param scalar The scalar value to subtract.
	 * \param m The matrix to subtract from.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the subtraction.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator-(U scalar, Matrix4x4_Base<T> const& m);

	/**
	 * Subtracts two matrices element-wise.
	 *
	 * \param m1 The first matrix to subtract from.
	 * \param m2 The second matrix to subtract.
	 *
	 * \tparam U The type of the second matrix's elements.
	 *
	 * \returns A new matrix with the result of the subtraction.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);

	/**
	 * Multiplies each element of the matrix by a scalar.
	 *
	 * \param m The matrix to multiply.
	 * \param scalar The scalar value to multiply by.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the multiplication.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator*(Matrix4x4_Base<T> const& m, U scalar);

	/**
	 * Multiplies each element of the matrix by a scalar (commutative).
	 *
	 * \param scalar The scalar value to multiply by.
	 * \param m The matrix to multiply.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the multiplication.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator*(U scalar, Matrix4x4_Base<T> const& m);

	/**
	 * Multiplies a matrix by a row vector.
	 * This operator performs a matrix-vector multiplication.
	 *
	 * \param m The matrix to multiply.
	 * \param v The row vector to multiply by.
	 *
	 * \tparam U The type of the vector's elements.
	 *
	 * \returns A column vector with the result of the multiplication.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::column_type operator*(Matrix4x4_Base<T> const& m, typename Matrix4x4_Base<U>::row_type const& v);

	/**
	 * Multiplies a column vector by a matrix.
	 *
	 * This operator performs a vector-matrix multiplication.
	 *
	 * \param v The column vector to multiply.
	 * \param m The matrix to multiply by.
	 *
	 * \tparam U The type of the vector's elements.
	 *
	 * \returns A row vector with the result of the multiplication.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::row_type operator*(typename Matrix4x4_Base<U>::column_type const& v, Matrix4x4_Base<T> const& m);

	/**
	 * Multiplies two matrices.
	 * This operator performs a standard matrix multiplication.
	 *
	 * \param m1 The first matrix operand.
	 * \param m2 The second matrix operand.
	 *
	 * \tparam U The type of the second matrix's elements.
	 *
	 * \returns A new matrix with the result of the multiplication.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator*(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);

	/**
	 * Divides each element of the matrix by a scalar.
	 *
	 * \param m The matrix to divide.
	 * \param scalar The scalar value to divide by.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the division.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator/(Matrix4x4_Base<T> const& m, U scalar);

	/**
	 * Divides a scalar by each element of the matrix.
	 *
	 * \param scalar The scalar value to divide by.
	 * \param m The matrix to divide.
	 *
	 * \tparam U The type of the scalar, must be arithmetic.
	 *
	 * \returns A new matrix with the result of the division.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator/(U scalar, Matrix4x4_Base<T> const& m);

	/**
	 * Divides a matrix by a row vector.
	 * This operator performs an element-wise division of each column of the
	 * matrix by the corresponding components of the row vector.
	 *
	 * \param m The matrix to divide.
	 * \param v The row vector to divide by.
	 *
	 * \tparam T The type of the matrix's elements.
	 * \tparam U The type of the vector's elements, must be arithmetic.
	 *
	 * \returns A column vector where each component is the result of the
	 *          division of the corresponding matrix column by the vector
	 *          component.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::column_type operator/(Matrix4x4_Base<T> const& m, typename Matrix4x4_Base<U>::row_type const& v);

	/**
	 * Divides a column vector by a matrix.
	 * This operator performs an element-wise division of each component of the
	 * column vector by the corresponding rows of the matrix.
	 *
	 * \param v The column vector to divide.
	 * \param m The matrix to divide by.
	 *
	 * \tparam T The type of the matrix's elements.
	 * \tparam U The type of the vector's elements, must be arithmetic.
	 *
	 * \returns A row vector where each component is the result of the division
	 *          of the vector component by the corresponding row of the matrix.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::row_type operator/(typename Matrix4x4_Base<U>::column_type const& v, Matrix4x4_Base<T> const& m);

	/**
	 * Divides two matrices element-wise.
	 *
	 * \param m1 The first matrix to divide.
	 * \param m2 The second matrix to divide by.
	 *
	 * \tparam U The type of the second matrix's elements.
	 *
	 * \returns A new matrix with the result of the division.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator/(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);



	/*
	 * This function sets a translation matrix with given translation values.
	 *
	 * \param tx Translation along the x-axis.
	 * \param ty Translation along the y-axis.
	 * \param tz Translation along the z-axis.
	 *
	 * \returns The translation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetTranslation(float32 tx, float32 ty, float32 tz);

	/*
	 * This function sets a translation matrix with a given vector.
	 *
	 * \param t Vector3 containing translation values.
	 *
	 * \returns The translation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 * \sa Vector3
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetTranslation(const Vector3_Base<T>& t);

	/*
	 * This function translates a matrix with given translation values.
	 *
	 * \param mat The matrix to be translated.
	 * \param tx Translation along the x-axis.
	 * \param ty Translation along the y-axis.
	 * \param tz Translation along the z-axis.
	 *
	 * \returns The translated matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> Translate(const Matrix4x4_Base<T>& mat, float32 tx, float32 ty, float32 tz);

	/*
	 * This function translates a matrix with a given vector.
	 *
	 * \param mat The matrix to be translated.
	 * \param t Vector3 containing translation values.
	 *
	 * \returns The translated matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 * \sa Vector3
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> Translate(const Matrix4x4_Base<T>& mat, const Vector3_Base<T>& t);

	/*
	 * This function sets a scale matrix with given scale values.
	 *
	 * \param sx Scale along the x-axis.
	 * \param sy Scale along the y-axis.
	 * \param sz Scale along the z-axis.
	 *
	 * \returns The scale matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetScale(float32 sx, float32 sy, float32 sz);

	/*
	 * This function sets a scale matrix with a given vector.
	 *
	 * \param s Vector3 containing scale values.
	 *
	 * \returns The scale matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 * \sa Vector3
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetScale(const Vector3_Base<T>& s);

	/*
	 * This function scales a matrix with given scale values.
	 *
	 * \param mat The matrix to be scaled.
	 * \param sx Scale along the x-axis.
	 * \param sy Scale along the y-axis.
	 * \param sz Scale along the z-axis.
	 *
	 * \returns The scaled matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> Scale(const Matrix4x4_Base<T>& mat, float32 sx, float32 sy, float32 sz);

	/*
	 * This function scales a matrix with a given vector.
	 *
	 * \param mat The matrix to be scaled.
	 * \param s Vector3 containing scale values.
	 *
	 * \returns The scaled matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 * \sa Vector3
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> Scale(const Matrix4x4_Base<T>& mat, const Vector3_Base<T>& s);

	/*
	 * This function sets a rotation matrix around the x-axis with a given
	 * angle.
	 *
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetRotationX(float32 angle);

	/*
	 * This function rotates a matrix around the x-axis with a given angle.
	 *
	 * \param mat The matrix to be rotated.
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> RotateX(const Matrix4x4_Base<T>& mat, float32 angle);

	/*
	 * This function sets a rotation matrix around the y-axis with a given
	 * angle.
	 *
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetRotationY(float32 angle);

	/*
	 * This function rotates a matrix around the y-axis with a given angle.
	 *
	 * \param mat The matrix to be rotated.
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> RotateY(const Matrix4x4_Base<T>& mat, float32 angle);

	/*
	 * This function sets a rotation matrix around the z-axis with a given
	 * angle.
	 *
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetRotationZ(float32 angle);

	/*
	 * This function rotates a matrix around the z-axis with a given angle.
	 *
	 * \param mat The matrix to be rotated.
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> RotateZ(const Matrix4x4_Base<T>& mat, float32 angle);

	/*
	 * This function sets a rotation matrix around an arbitrary axis with a
	 * given angle.
	 *
	 * \param angle Angle in radians to rotate.
	 * \param x X component of the axis.
	 * \param y Y component of the axis.
	 * \param z Z component of the axis.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetRotation(float32 angle, float32 x, float32 y, float32 z);

	/*
	 * This function sets a rotation matrix around an arbitrary axis with a
	 * given angle and vector.
	 *
	 * \param angle Angle in radians to rotate.
	 * \param r Vector3 representing the axis of rotation.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 * \sa Vector3
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> SetRotation(float32 angle, const Vector3_Base<T>& r);

	/*
	 * This function rotates a matrix around an arbitrary axis with given axis
	 * components.
	 *
	 * \param mat The matrix to be rotated.
	 * \param angle Angle in radians to rotate.
	 * \param x X component of the axis.
	 * \param y Y component of the axis.
	 * \param z Z component of the axis.
	 *
	 * \returns The rotated matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> Rotate(const Matrix4x4_Base<T>& mat, float32 angle, float32 x, float32 y, float32 z);

	/*
	 * This function rotates a matrix around an arbitrary axis with given
	 * vector.
	 *
	 * \param mat The matrix to be rotated.
	 * \param angle Angle in radians to rotate.
	 * \param r Vector3 representing the axis of rotation.
	 *
	 * \returns The rotated matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4_Base
	 */
	template<typename T>
	ECM_INLINE Matrix4x4_Base<T> Rotate(const Matrix4x4_Base<T>& mat, float32 angle, const Vector3_Base<T>& r);
} // namespace ecm::math

#include "matrix4x4.inl"

#endif // !_ECM_MATRIX4X4_H_
