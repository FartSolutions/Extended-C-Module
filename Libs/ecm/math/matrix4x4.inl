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
		Matrix4x4_Base<T> Result(*this);
		++*this;
		return Result;
	}

	template<typename T>
	constexpr Matrix4x4_Base<T> Matrix4x4_Base<T>::operator--(int)
	{
		Matrix4x4_Base<T> Result(*this);
		--*this;
		return Result;
	}

	// ##########################################################################
	// Operators

	constexpr bool operator==(const Matrix4x4& left, const Matrix4x4& right)
	{
		if (left.m00 == right.m00
			&& left.m01 == right.m01
			&& left.m02 == right.m02
			&& left.m03 == right.m03)
		{
			if (left.m10 == right.m10
				&& left.m11 == right.m11
				&& left.m12 == right.m12
				&& left.m13 == right.m13)
			{
				if (left.m20 == right.m20
					&& left.m21 == right.m21
					&& left.m22 == right.m22
					&& left.m23 == right.m23)
				{
					if (left.m30 == right.m30
						&& left.m31 == right.m31
						&& left.m32 == right.m32
						&& left.m33 == right.m33)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	constexpr bool operator!=(const Matrix4x4& left, const Matrix4x4& right)
	{
		return !(left == right);
	}

	constexpr Matrix4x4 operator+(const Matrix4x4& left, const Matrix4x4& right)
	{
		Matrix4x4 result;
		for (int32 row{ 0 }; row < 4; ++row) {
			for (int32 col{ 0 }; col < 4; ++col) {
				result.matrix[row][col] =
					left.matrix[row][col] + right.matrix[row][col];
			}
		}
		return result;
	}

	constexpr Matrix4x4 operator-(const Matrix4x4& left, const Matrix4x4& right)
	{
		Matrix4x4 result;
		for (int32 row{ 0 }; row < 4; ++row) {
			for (int32 col{ 0 }; col < 4; ++col) {
				result.matrix[row][col] =
					left.matrix[row][col] - right.matrix[row][col];
			}
		}
		return result;
	}

	constexpr Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right)
	{
		Matrix4x4 result;
		for (int32 row{ 0 }; row < 4; ++row) {
			for (int32 col{ 0 }; col < 4; ++col) {
				result.matrix[row][col] =
					left.matrix[row][0] * right.matrix[0][col] +
					left.matrix[row][1] * right.matrix[1][col] +
					left.matrix[row][2] * right.matrix[2][col] +
					left.matrix[row][3] * right.matrix[3][col];
			}
		}
		return left;
	}

	// ##########################################################################
	// Translation Methods

	Matrix4x4 SetTranslation(float32 tx, float32 ty, float32 tz)
	{
		Matrix4x4 result(1.0f);
		result.m30 = tx;
		result.m31 = ty;
		result.m32 = tz;
		return result;
	}

	Matrix4x4 SetTranslation(const Vector3& t)
	{
		return SetTranslation(t.x, t.y, t.z);
	}

	Matrix4x4 Translate(const Matrix4x4& mat, float32 tx, float32 ty, float32 tz)
	{
		Matrix4x4 translation = SetTranslation(tx, ty, tz);
		return mat * translation;
	}

	Matrix4x4 Translate(const Matrix4x4& mat, const Vector3& t)
	{
		return Translate(mat, t.x, t.y, t.z);
	}

	Matrix4x4 SetScale(float32 sx, float32 sy, float32 sz)
	{
		Matrix4x4 result(1.0f);
		result.m00 = sx;
		result.m11 = sy;
		result.m22 = sz;
		return result;
	}

	Matrix4x4 SetScale(const Vector3& s)
	{
		return SetScale(s.x, s.y, s.z);
	}

	Matrix4x4 Scale(const Matrix4x4& mat, float32 sx, float32 sy, float32 sz)
	{
		Matrix4x4 scaling = SetScale(sx, sy, sz);
		return mat * scaling;
	}

	Matrix4x4 Scale(const Matrix4x4& mat, const Vector3& s)
	{
		return Scale(mat, s.x, s.y, s.z);
	}

	Matrix4x4 SetRotationX(float32 angle)
	{
		Matrix4x4 result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		result.m11 = c;
		result.m12 = -s;
		result.m21 = s;
		result.m22 = c;
		return result;
	}

	Matrix4x4 RotateX(const Matrix4x4& mat, float32 angle)
	{
		Matrix4x4 rotation = SetRotationX(angle);
		return mat * rotation;
	}

	Matrix4x4 SetRotationY(float32 angle)
	{
		Matrix4x4 result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		result.m00 = c;
		result.m02 = s;
		result.m20 = -s;
		result.m22 = c;
		return result;
	}

	Matrix4x4 RotateY(const Matrix4x4& mat, float32 angle)
	{
		Matrix4x4 rotation = SetRotationY(angle);
		return mat * rotation;
	}

	Matrix4x4 SetRotationZ(float32 angle)
	{
		Matrix4x4 result(1.0f);
		float32 c = Cos(angle);
		float32 s = Sin(angle);
		result.m00 = c;
		result.m01 = -s;
		result.m10 = s;
		result.m11 = c;
		return result;
	}

	Matrix4x4 RotateZ(const Matrix4x4& mat, float32 angle)
	{
		Matrix4x4 rotation = SetRotationZ(angle);
		return mat * rotation;
	}

	Matrix4x4 SetRotation(float32 angle, float32 x, float32 y, float32 z)
	{
		Matrix4x4 result(1.0f);
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

	Matrix4x4 SetRotation(float32 angle, const Vector3& r)
	{
		return SetRotation(angle, r.x, r.y, r.z);
	}

	Matrix4x4 Rotate(const Matrix4x4& mat, float32 angle, float32 x, float32 y, float32 z)
	{
		Matrix4x4 rotation = SetRotation(angle, x, y, z);
		return mat * rotation;
	}

	Matrix4x4 Rotate(const Matrix4x4& mat, float32 angle, const Vector3& r)
	{
		return Rotate(mat, angle, r.x, r.y, r.z);
	}
} // namespace ecm::math
