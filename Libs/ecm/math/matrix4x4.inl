#pragma once

#include "matrix4x4.hpp"
#include "functions.hpp"

#include <limits>

namespace ecm::math
{
	// Basic constructors

	template<typename T>
	constexpr Matrix4x4_Base<T>::Matrix4x4_Base()
		: rows{
			column_type(1, 0, 0, 0),
			column_type(0, 1, 0, 0),
			column_type(0, 0, 1, 0),
			column_type(0, 0, 0, 1) }
	{}

	template<typename T>
	constexpr Matrix4x4_Base<T>::Matrix4x4_Base(Matrix4x4_Base<T> const& m)
		: rows{
			column_type(m[0]),
			column_type(m[1]),
			column_type(m[2]),
			column_type(m[3]) }
	{}

	template<typename T>
	constexpr Matrix4x4_Base<T>::Matrix4x4_Base(T s)
		: rows{
			column_type(s, 0, 0, 0),
			column_type(0, s, 0, 0),
			column_type(0, 0, s, 0),
			column_type(0, 0, 0, s) }
	{}

	template<typename T>
	constexpr Matrix4x4_Base<T>::Matrix4x4_Base(
		T const& x0, T const& y0, T const& z0, T const& w0,
		T const& x1, T const& y1, T const& z1, T const& w1,
		T const& x2, T const& y2, T const& z2, T const& w2,
		T const& x3, T const& y3, T const& z3, T const& w3)
		: rows{
			column_type(x0, y0, z0, w0),
			column_type(x1, y1, z1, w1),
			column_type(x2, y2, z2, w2),
			column_type(x3, y3, z3, w3) }
	{}

	template<typename T>
	constexpr Matrix4x4_Base<T>::Matrix4x4_Base(
		column_type const& v0,
		column_type const& v1,
		column_type const& v2,
		column_type const& v3)
		: rows{
			column_type(v0),
			column_type(v1),
			column_type(v2),
			column_type(v3) }
	{}

	// Conversion constructors

	template<typename T>
	template<
		typename X1, typename Y1, typename Z1, typename W1,
		typename X2, typename Y2, typename Z2, typename W2,
		typename X3, typename Y3, typename Z3, typename W3,
		typename X4, typename Y4, typename Z4, typename W4>
	constexpr ecm::math::Matrix4x4_Base<T>::Matrix4x4_Base(
		X1 const& x1, Y1 const& y1, Z1 const& z1, W1 const& w1,
		X2 const& x2, Y2 const& y2, Z2 const& z2, W2 const& w2,
		X3 const& x3, Y3 const& y3, Z3 const& z3, W3 const& w3,
		X4 const& x4, Y4 const& y4, Z4 const& z4, W4 const& w4)
		: rows{
			column_type(x1, y1, z1, w1),
			column_type(x2, y2, z2, w2),
			column_type(x3, y3, z3, w3),
			column_type(x4, y4, z4, w4) }
	{
		static_assert(std::numeric_limits<X1>::is_iec559 || std::numeric_limits<X1>::is_integer, "Matrix4x4 constructor only takes float and integer types, 1st paramter type is invalid.");
		static_assert(std::numeric_limits<Y1>::is_iec559 || std::numeric_limits<Y1>::is_integer, "Matrix4x4 constructor only takes float and integer types, 2nd paramter type is invalid.");
		static_assert(std::numeric_limits<Z1>::is_iec559 || std::numeric_limits<Z1>::is_integer, "Matrix4x4 constructor only takes float and integer types, 3rd paramter type is invalid.");
		static_assert(std::numeric_limits<W1>::is_iec559 || std::numeric_limits<W1>::is_integer, "Matrix4x4 constructor only takes float and integer types, 4th paramter type is invalid.");

		static_assert(std::numeric_limits<X2>::is_iec559 || std::numeric_limits<X2>::is_integer, "Matrix4x4 constructor only takes float and integer types, 5th paramter type is invalid.");
		static_assert(std::numeric_limits<Y2>::is_iec559 || std::numeric_limits<Y2>::is_integer, "Matrix4x4 constructor only takes float and integer types, 6th paramter type is invalid.");
		static_assert(std::numeric_limits<Z2>::is_iec559 || std::numeric_limits<Z2>::is_integer, "Matrix4x4 constructor only takes float and integer types, 7th paramter type is invalid.");
		static_assert(std::numeric_limits<W2>::is_iec559 || std::numeric_limits<W2>::is_integer, "Matrix4x4 constructor only takes float and integer types, 8th paramter type is invalid.");

		static_assert(std::numeric_limits<X3>::is_iec559 || std::numeric_limits<X3>::is_integer, "Matrix4x4 constructor only takes float and integer types, 9th paramter type is invalid.");
		static_assert(std::numeric_limits<Y3>::is_iec559 || std::numeric_limits<Y3>::is_integer, "Matrix4x4 constructor only takes float and integer types, 10th paramter type is invalid.");
		static_assert(std::numeric_limits<Z3>::is_iec559 || std::numeric_limits<Z3>::is_integer, "Matrix4x4 constructor only takes float and integer types, 11th paramter type is invalid.");
		static_assert(std::numeric_limits<W3>::is_iec559 || std::numeric_limits<W3>::is_integer, "Matrix4x4 constructor only takes float and integer types, 12th paramter type is invalid.");

		static_assert(std::numeric_limits<X4>::is_iec559 || std::numeric_limits<X4>::is_integer, "Matrix4x4 constructor only takes float and integer types, 13th paramter type is invalid.");
		static_assert(std::numeric_limits<Y4>::is_iec559 || std::numeric_limits<Y4>::is_integer, "Matrix4x4 constructor only takes float and integer types, 14th paramter type is invalid.");
		static_assert(std::numeric_limits<Z4>::is_iec559 || std::numeric_limits<Z4>::is_integer, "Matrix4x4 constructor only takes float and integer types, 15th paramter type is invalid.");
		static_assert(std::numeric_limits<W4>::is_iec559 || std::numeric_limits<W4>::is_integer, "Matrix4x4 constructor only takes float and integer types, 16th paramter type is invalid.");
	}

	template<typename T>
	template<typename V1, typename V2, typename V3, typename V4>
	constexpr ecm::math::Matrix4x4_Base<T>::Matrix4x4_Base(
		Vector4_Base<V1> const& v1,
		Vector4_Base<V2> const& v2,
		Vector4_Base<V3> const& v3,
		Vector4_Base<V4> const& v4)
		: rows{
			column_type(v1),
			column_type(v2),
			column_type(v3),
			column_type(v4) }
	{
		static_assert(std::numeric_limits<V1>::is_iec559 || std::numeric_limits<V1>::is_integer, "Matrix4x4 constructor only takes float and integer types, 1st paramter type is invalid.");
		static_assert(std::numeric_limits<V2>::is_iec559 || std::numeric_limits<V2>::is_integer, "Matrix4x4 constructor only takes float and integer types, 2nd paramter type is invalid.");
		static_assert(std::numeric_limits<V3>::is_iec559 || std::numeric_limits<V3>::is_integer, "Matrix4x4 constructor only takes float and integer types, 3rd paramter type is invalid.");
		static_assert(std::numeric_limits<V4>::is_iec559 || std::numeric_limits<V4>::is_integer, "Matrix4x4 constructor only takes float and integer types, 4th paramter type is invalid.");
	}

	template<typename T>
	template<typename U>
	constexpr Matrix4x4_Base<T>::Matrix4x4_Base(Matrix4x4_Base<U> const& m)
		: rows{
			column_type(m[0]),
			column_type(m[1]),
			column_type(m[2]),
			column_type(m[3]) }
	{}

	// Component accesses

	template<typename T>
	constexpr typename Matrix4x4_Base<T>::column_type& Matrix4x4_Base<T>::operator[](uint8 i) noexcept
	{
		return this->rows[i];
	}

	template<typename T>
	constexpr typename Matrix4x4_Base<T>::column_type const& Matrix4x4_Base<T>::operator[](uint8 i) const noexcept
	{
		return this->rows[i];
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator=(Matrix4x4_Base<T> const& m)
	{
		memcpy(&this->rows, &m.rows, 16 * sizeof(value_type));
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator=(Matrix4x4_Base<U> const& m)
	{
		memcpy(&this->rows, &m.rows, 16 * sizeof(value_type));
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator+=(U scalar)
	{
		this->rows[0] += scalar;
		this->rows[1] += scalar;
		this->rows[2] += scalar;
		this->rows[3] += scalar;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator+=(Matrix4x4_Base<U> const& m)
	{
		this->rows[0] += m[0];
		this->rows[1] += m[1];
		this->rows[2] += m[2];
		this->rows[3] += m[3];
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator-=(U scalar)
	{
		this->rows[0] -= scalar;
		this->rows[1] -= scalar;
		this->rows[2] -= scalar;
		this->rows[3] -= scalar;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator-=(Matrix4x4_Base<U> const& m)
	{
		this->rows[0] -= m[0];
		this->rows[1] -= m[1];
		this->rows[2] -= m[2];
		this->rows[3] -= m[3];
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator*=(U scalar)
	{
		this->rows[0] *= scalar;
		this->rows[1] *= scalar;
		this->rows[2] *= scalar;
		this->rows[3] *= scalar;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator*=(Matrix4x4_Base<U> const& m)
	{
		// TODO: Use this code: return (*this = *this * m);
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator/=(U scalar)
	{
		this->rows[0] /= scalar;
		this->rows[1] /= scalar;
		this->rows[2] /= scalar;
		this->rows[3] /= scalar;
		return *this;
	}

	template<typename T>
	template<typename U, typename>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator/=(Matrix4x4_Base<U> const& m)
	{
		// TODO: Use this code: return (*this *= inverse(m));
		return *this;
	}

	// Increment and decrement operators

	template<typename T>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator++()
	{
		++this->rows[0];
		++this->rows[1];
		++this->rows[2];
		++this->rows[3];
		return *this;
	}

	template<typename T>
	constexpr Matrix4x4_Base<T>& Matrix4x4_Base<T>::operator--()
	{
		--this->rows[0];
		--this->rows[1];
		--this->rows[2];
		--this->rows[3];
		return *this;
	}

	template<typename T>
	constexpr Matrix4x4_Base<T> Matrix4x4_Base<T>::operator++(int)
	{
		Matrix4x4_Base<T> result(*this);
		++*this;
		return result;
	}

	template<typename T>
	constexpr Matrix4x4_Base<T> Matrix4x4_Base<T>::operator--(int)
	{
		Matrix4x4_Base<T> result(*this);
		--*this;
		return result;
	}

	// Boolean operators

	template<typename T>
	constexpr bool operator==(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<T> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template<typename T>
	constexpr bool operator!=(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<T> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}

	// Unary arithmetic operators

	template<typename T>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m)
	{
		return m;
	}

	template<typename T>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m)
	{
		return Matrix4x4_Base<T>(-m[0], -m[1], -m[2], -m[3]);
	}

	// Binary operators

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m, U scalar)
	{
		return Matrix4x4_Base<T>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator+(U scalar, Matrix4x4_Base<T> const& m)
	{
		return Matrix4x4_Base<T>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator+(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2)
	{
		return Matrix4x4_Base<T>(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m, U scalar)
	{
		return Matrix4x4_Base<T>(
			m[0] - scalar,
			m[1] - scalar,
			m[2] - scalar,
			m[3] - scalar);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator-(U scalar, Matrix4x4_Base<T> const& m)
	{
		return Matrix4x4_Base<T>(
			m[0] - scalar,
			m[1] - scalar,
			m[2] - scalar,
			m[3] - scalar);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator-(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2)
	{
		return Matrix4x4_Base<T>(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator*(Matrix4x4_Base<T> const& m, U scalar)
	{
		return Matrix4x4_Base<T>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator*(U scalar, Matrix4x4_Base<T> const& m)
	{
		return Matrix4x4_Base<T>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, typename U, typename>
	constexpr typename Matrix4x4_Base<T>::column_type operator*(Matrix4x4_Base<T> const& m, typename Matrix4x4_Base<U>::row_type const& v)
	{
		typename Matrix4x4_Base<T>::column_type const mov0(v[0]);
		typename Matrix4x4_Base<T>::column_type const mov1(v[1]);
		typename Matrix4x4_Base<T>::column_type const mov2(v[2]);
		typename Matrix4x4_Base<T>::column_type const mov3(v[3]);
		typename Matrix4x4_Base<T>::column_type const mul0 = m[0] * mov0;
		typename Matrix4x4_Base<T>::column_type const mul1 = m[1] * mov1;
		typename Matrix4x4_Base<T>::column_type const mul2 = m[2] * mov2;
		typename Matrix4x4_Base<T>::column_type const mul3 = m[3] * mov3;
		typename Matrix4x4_Base<T>::column_type const add0 = mul0 + mul1;
		typename Matrix4x4_Base<T>::column_type const add1 = mul2 + mul3;
		return add0 + add1;
	}

	template<typename T, typename U, typename>
	constexpr typename Matrix4x4_Base<T>::row_type operator*(typename Matrix4x4_Base<U>::column_type const& v, Matrix4x4_Base<T> const& m)
	{
		return typename Matrix4x4_Base<T>::row_type(
			// TODO: Use dot function.
			/*
			Dot(m[0], v),
			Dot(m[1], v),
			Dot(m[2], v),
			Dot(m[3], v)
			*/);
	}

	namespace detail
	{
		template<typename T>
		struct is_aligned
		{
			static constexpr bool value = alignof(T) >= 16;
		};

		template<typename T>
		constexpr bool is_aligned_v = is_aligned<T>::value;
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator*(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2)
	{
		if constexpr (detail::is_aligned_v<typename Matrix4x4_Base<T>::type>)
		{
			typename Matrix4x4_Base<T>::column_type const sourceA0 = m1[0];
			typename Matrix4x4_Base<T>::column_type const sourceA1 = m1[1];
			typename Matrix4x4_Base<T>::column_type const sourceA2 = m1[2];
			typename Matrix4x4_Base<T>::column_type const sourceA3 = m1[3];
			typename Matrix4x4_Base<U>::column_type const sourceB0 = m2[0];
			typename Matrix4x4_Base<U>::column_type const sourceB1 = m2[1];
			typename Matrix4x4_Base<U>::column_type const sourceB2 = m2[2];
			typename Matrix4x4_Base<U>::column_type const sourceB3 = m2[3];

			Matrix4x4_Base<T> result;
			// TODO: Implement this:
			// result[0] = Fma(srca3, SplatW(srcb0), Fma(srca2, SplatZ(srcb0), Fma(srca1, SplatY(srcb0), srca0 * SplatX(srcb0))));
			// result[1] = Fma(srca3, SplatW(srcb1), Fma(srca2, SplatZ(srcb1), Fma(srca1, SplatY(srcb1), srca0 * SplatX(srcb1))));
			// result[2] = Fma(srca3, SplatW(srcb2), Fma(srca2, SplatZ(srcb2), Fma(srca1, SplatY(srcb2), srca0 * SplatX(srcb2))));
			// result[3] = Fma(srca3, SplatW(srcb3), Fma(srca2, SplatZ(srcb3), Fma(srca1, SplatY(srcb3), srca0 * SplatX(srcb3))));
			return result;
		}
		else
		{
			typename Matrix4x4_Base<T>::column_type const& sourceA0 = m1[0];
			typename Matrix4x4_Base<T>::column_type const& sourceA1 = m1[1];
			typename Matrix4x4_Base<T>::column_type const& sourceA2 = m1[2];
			typename Matrix4x4_Base<T>::column_type const& sourceA3 = m1[3];
			typename Matrix4x4_Base<U>::column_type const& sourceB0 = m2[0];
			typename Matrix4x4_Base<U>::column_type const& sourceB1 = m2[1];
			typename Matrix4x4_Base<U>::column_type const& sourceB2 = m2[2];
			typename Matrix4x4_Base<U>::column_type const& sourceB3 = m2[3];

			Matrix4x4_Base<T> result;
			typename Matrix4x4_Base<T>::column_type temp;

			temp =  sourceA0 * sourceB0.x;
			temp += sourceA1 * sourceB0.y;
			temp += sourceA2 * sourceB0.z;
			temp += sourceA3 * sourceB0.w;
			result[0] = temp;

			temp =  sourceA0 * sourceB1.x;
			temp += sourceA1 * sourceB1.y;
			temp += sourceA2 * sourceB1.z;
			temp += sourceA3 * sourceB1.w;
			result[1] = temp;

			temp =  sourceA0 * sourceB2.x;
			temp += sourceA1 * sourceB2.y;
			temp += sourceA2 * sourceB2.z;
			temp += sourceA3 * sourceB2.w;
			result[2] = temp;

			temp =  sourceA0 * sourceB3.x;
			temp += sourceA1 * sourceB3.y;
			temp += sourceA2 * sourceB3.z;
			temp += sourceA3 * sourceB3.w;
			result[3] = temp;

			return result;
		}
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator/(Matrix4x4_Base<T> const& m, U scalar)
	{
		return Matrix4x4_Base<T>(
			m[0] / scalar,
			m[1] / scalar,
			m[2] / scalar,
			m[3] / scalar);
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator/(U scalar, Matrix4x4_Base<T> const& m)
	{
		return Matrix4x4_Base<T>(
			scalar / m[0],
			scalar / m[1],
			scalar / m[2],
			scalar / m[3]);
	}

	template<typename T, typename U, typename>
	constexpr typename Matrix4x4_Base<T>::column_type operator/(Matrix4x4_Base<T> const& m, typename Matrix4x4_Base<U>::row_type const& v)
	{
		typename Matrix4x4_Base<T>::column_type temp(1);
		// TODO: Implement this: return inverse(m) * v;
		return temp;
	}

	template<typename T, typename U, typename>
	constexpr typename Matrix4x4_Base<T>::row_type operator/(typename Matrix4x4_Base<U>::column_type const& v, Matrix4x4_Base<T> const& m)
	{
		typename Matrix4x4_Base<T>::row_type temp(1);
		// TODO: Implement this: return v * inverse(m);
		return temp;
	}

	template<typename T, typename U, typename>
	constexpr Matrix4x4_Base<T> operator/(Matrix4x4_Base<T> const& m1, Matrix4x4_Base<U> const& m2)
	{
		Matrix4x4_Base<T> m1_copy(m1);
		return m1_copy /= m2;
	}

	// ##########################################################################
	// Translation Methodsy

	template<typename T>
	Matrix4x4_Base<T> SetTranslation(float32 tx, float32 ty, float32 tz)
	{
		Matrix4x4_Base<T> result(1.0f);
		result.m30 = tx;
		result.m31 = ty;
		result.m32 = tz;
		return result;
	}

	template<typename T>
	Matrix4x4_Base<T> SetTranslation(const Vector3_Base<T>& t)
	{
		return SetTranslation(t.x, t.y, t.z);
	}

	template<typename T>
	Matrix4x4_Base<T> Translate(const Matrix4x4_Base<T>& mat, float32 tx, float32 ty, float32 tz)
	{
		Matrix4x4_Base<T> translation = SetTranslation<T>(tx, ty, tz);
		return mat * translation;
	}

	template<typename T>
	Matrix4x4_Base<T> Translate(const Matrix4x4_Base<T>& mat, const Vector3_Base<T>& t)
	{
		return Translate(mat, t.x, t.y, t.z);
	}

	template<typename T>
	Matrix4x4_Base<T> SetScale(float32 sx, float32 sy, float32 sz)
	{
		Matrix4x4_Base<T> result(1.0f);
		result.m00 = sx;
		result.m11 = sy;
		result.m22 = sz;
		return result;
	}

	template<typename T>
	Matrix4x4_Base<T> SetScale(const Vector3_Base<T>& s)
	{
		return SetScale(s.x, s.y, s.z);
	}

	template<typename T>
	Matrix4x4_Base<T> Scale(const Matrix4x4_Base<T>& mat, float32 sx, float32 sy, float32 sz)
	{
		Matrix4x4_Base<T> scaling = SetScale<T>(sx, sy, sz);
		return mat * scaling;
	}

	template<typename T>
	Matrix4x4_Base<T> Scale(const Matrix4x4_Base<T>& mat, const Vector3_Base<T>& s)
	{
		return Scale(mat, s.x, s.y, s.z);
	}

	template<typename T>
	Matrix4x4_Base<T> SetRotationX(float32 angle)
	{
		Matrix4x4_Base<T> result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		result.m11 = c;
		result.m12 = -s;
		result.m21 = s;
		result.m22 = c;
		return result;
	}

	template<typename T>
	Matrix4x4_Base<T> RotateX(const Matrix4x4_Base<T>& mat, float32 angle)
	{
		Matrix4x4_Base<T> rotation = SetRotationX<T>(angle);
		return mat * rotation;
	}

	template<typename T>
	Matrix4x4_Base<T> SetRotationY(float32 angle)
	{
		Matrix4x4_Base<T> result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		result.m00 = c;
		result.m02 = s;
		result.m20 = -s;
		result.m22 = c;
		return result;
	}

	template<typename T>
	Matrix4x4_Base<T> RotateY(const Matrix4x4_Base<T>& mat, float32 angle)
	{
		Matrix4x4_Base<T> rotation = SetRotationY<T>(angle);
		return mat * rotation;
	}

	template<typename T>
	Matrix4x4_Base<T> SetRotationZ(float32 angle)
	{
		Matrix4x4_Base<T> result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		result.m00 = c;
		result.m01 = -s;
		result.m10 = s;
		result.m11 = c;
		return result;
	}

	template<typename T>
	Matrix4x4_Base<T> RotateZ(const Matrix4x4_Base<T>& mat, float32 angle)
	{
		Matrix4x4_Base<T> rotation = SetRotationZ<T>(angle);
		return mat * rotation;
	}

	template<typename T>
	Matrix4x4_Base<T> SetRotation(float32 angle, float32 x, float32 y, float32 z)
	{
		Matrix4x4_Base<T> result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		float32 t = 1 - c;

		result.m00 = t * x * x + c;
		result.m01 = t * x * y - z * s;
		result.m02 = t * x * z + y * s;
		result.m03 = 0;

		result.m10 = t * x * y + z * s;
		result.m11 = t * y * y + c;
		result.m12 = t * y * z - x * s;
		result.m13 = 0;

		result.m20 = t * x * z - y * s;
		result.m21 = t * y * z + x * s;
		result.m22 = t * z * z + c;
		result.m23 = 0;

		result.m30 = 0;
		result.m31 = 0;
		result.m32 = 0;
		result.m33 = 1;

		return result;
	}

	template<typename T>
	Matrix4x4_Base<T> SetRotation(float32 angle, const Vector3_Base<T>& r)
	{
		return SetRotation<T>(angle, r.x, r.y, r.z);
	}

	template<typename T>
	Matrix4x4_Base<T> Rotate(const Matrix4x4_Base<T>& mat, float32 angle, float32 x, float32 y, float32 z)
	{
		Matrix4x4_Base<T> rotation = SetRotation<T>(angle, x, y, z);
		return mat * rotation;
	}

	template<typename T>
	Matrix4x4_Base<T> Rotate(const Matrix4x4_Base<T>& mat, float32 angle, const Vector3_Base<T>& r)
	{
		return Rotate<T>(mat, angle, r.x, r.y, r.z);
	}
} // namespace ecm::math
