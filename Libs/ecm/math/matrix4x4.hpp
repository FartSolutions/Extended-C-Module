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
#include "vector.hpp"

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
				// First row of matrix
				T m00, m01, m02, m03;
				// Second row of matrix
				T m10, m11, m12, m13;
				// Third row of matrix
				T m20, m21, m22, m23;
				// Fourth row of matrix
				T m30, m31, m32, m33;
			};
			// Matrix 2D array: 4x4 values
			T matrix[4][4];
			// Matrix 1D array: 16 values
			T elements[16]{ 0.f };
			// Matrix 1D array: 4 rows
			column_type rows[4];
		};

		// Basic constructors

		/*
		 * Default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Matrix4x4_Base();

		constexpr Matrix4x4_Base(Matrix4x4_Base<T> const& m);

		constexpr Matrix4x4_Base(T s);

		constexpr Matrix4x4_Base(
			T const& x0, T const& y0, T const& z0, T const& w0,
			T const& x1, T const& y1, T const& z1, T const& w1,
			T const& x2, T const& y2, T const& z2, T const& w2,
			T const& x3, T const& y3, T const& z3, T const& w3);

		constexpr Matrix4x4_Base(
			column_type const& v0,
			column_type const& v1,
			column_type const& v2,
			column_type const& v3);

		// Conversion constructors

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

		template<typename V1, typename V2, typename V3, typename V4>
		constexpr Matrix4x4_Base(
			Vector4_Base<V1> const& v1,
			Vector4_Base<V2> const& v2,
			Vector4_Base<V3> const& v3,
			Vector4_Base<V4> const& v4);

		template<typename U>
		explicit constexpr Matrix4x4_Base(Matrix4x4_Base<U> const& m);

		// Component accesses

		constexpr column_type& operator[](uint8 i) noexcept;

		constexpr column_type const& operator[](uint8 i) const noexcept;

		// Unary arithmetic operators

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator=(Matrix4x4_Base<U> const& m);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator+=(U scalar);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator+=(Matrix4x4_Base<U> const& m);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator-=(U scalar);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator-=(Matrix4x4_Base<U> const& m);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator*=(U scalar);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator*=(Matrix4x4_Base<U> const& m);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator/=(U scalar);

		template<typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
		constexpr Matrix4x4_Base<T>& operator/=(Matrix4x4_Base<U> const& m);

		// Increment and decrement operators

		constexpr Matrix4x4_Base<T>& operator++();

		constexpr Matrix4x4_Base<T>& operator--();

		constexpr Matrix4x4_Base<T> operator++(int);

		constexpr Matrix4x4_Base<T> operator--(int);
	};

	// Boolean operators

	template<typename T>
	constexpr bool operator==(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<T> const& m2);

	template<typename T>
	constexpr bool operator!=(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<T> const& m2);

	// Unary arithmetic operators

	template<typename T>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m);

	template<typename T>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m);

	// Binary operators

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m, U scalar);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator+(U scalar, Matrix4x4_Base<T> const& m);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m, U scalar);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator-(U scalar, Matrix4x4_Base<T> const& m);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator*(Matrix4x4_Base<T> const& m, U scalar);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator*(U scalar, Matrix4x4_Base<T> const& m);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::column_type operator*(Matrix4x4_Base<T> const& m, typename Matrix4x4_Base<U>::row_type const& v);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::row_type operator*(typename Matrix4x4_Base<U>::column_type const& v, Matrix4x4_Base<T> const& m);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator*(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator/(Matrix4x4_Base<T> const& m, U scalar);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator/(U scalar, Matrix4x4_Base<T> const& m);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::column_type operator/(Matrix4x4_Base<T> const& m, typename Matrix4x4_Base<U>::row_type const& v);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr typename Matrix4x4_Base<T>::row_type operator/(typename Matrix4x4_Base<U>::column_type const& v, Matrix4x4_Base<T> const& m);

	template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
	constexpr Matrix4x4_Base<T> operator/(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2);



	// TODO: Only temporary
	struct Matrix4x4 : public Matrix4x4_Base<float>
	{
		using Matrix4x4_Base<float>::Matrix4x4_Base;
	};

	// TODO: Only temporary
	__declspec(align(16)) struct Matrix4x4A : public Matrix4x4
	{
		using Matrix4x4::Matrix4x4;
	};

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 SetTranslation(float32 tx, float32 ty, float32 tz);

	/*
	 * This function sets a translation matrix with a given vector.
	 *
	 * \param t Vector3 containing translation values.
	 *
	 * \returns The translation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 * \sa Vector3
	 */
	ECM_INLINE Matrix4x4 SetTranslation(const Vector3& t);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 Translate(const Matrix4x4& mat, float32 tx, float32 ty, float32 tz);

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
	 * \sa Matrix4x4
	 * \sa Vector3
	 */
	ECM_INLINE Matrix4x4 Translate(const Matrix4x4& mat, const Vector3& t);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 SetScale(float32 sx, float32 sy, float32 sz);

	/*
	 * This function sets a scale matrix with a given vector.
	 *
	 * \param s Vector3 containing scale values.
	 *
	 * \returns The scale matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 * \sa Vector3
	 */
	ECM_INLINE Matrix4x4 SetScale(const Vector3& s);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 Scale(const Matrix4x4& mat, float32 sx, float32 sy, float32 sz);

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
	 * \sa Matrix4x4
	 * \sa Vector3
	 */
	ECM_INLINE Matrix4x4 Scale(const Matrix4x4& mat, const Vector3& s);

	/*
	 * This function sets a rotation matrix around the x-axis with a given angle.
	 *
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 SetRotationX(float32 angle);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 RotateX(const Matrix4x4& mat, float32 angle);

	/*
	 * This function sets a rotation matrix around the y-axis with a given angle.
	 *
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 SetRotationY(float32 angle);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 RotateY(const Matrix4x4& mat, float32 angle);

	/*
	 * This function sets a rotation matrix around the z-axis with a given angle.
	 *
	 * \param angle Angle in radians to rotate.
	 *
	 * \returns The rotation matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 SetRotationZ(float32 angle);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 RotateZ(const Matrix4x4& mat, float32 angle);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 SetRotation(float32 angle, float32 x, float32 y, float32 z);

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
	 * \sa Matrix4x4
	 * \sa Vector3
	 */
	ECM_INLINE Matrix4x4 SetRotation(float32 angle, const Vector3& r);

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
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 Rotate(const Matrix4x4& mat, float32 angle, float32 x, float32 y, float32 z);

	/*
	 * This function rotates a matrix around an arbitrary axis with given vector.
	 *
	 * \param mat The matrix to be rotated.
	 * \param angle Angle in radians to rotate.
	 * \param r Vector3 representing the axis of rotation.
	 *
	 * \returns The rotated matrix.
	 *
	 * \since v1.0.0
	 *
	 * \sa Matrix4x4
	 */
	ECM_INLINE Matrix4x4 Rotate(const Matrix4x4& mat, float32 angle, const Vector3& r);
} // namespace ecm::math

#include "matrix4x4.inl"

#endif // !_ECM_MATRIX4X4_H_
