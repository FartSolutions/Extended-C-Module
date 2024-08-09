#pragma once

#include "matrix4x4.hpp"
#include "functions.hpp"

namespace ecm::math
{
	constexpr Matrix4x4::Matrix4x4()
		: m00{ 1.f }, m01{ 0.f }, m02{ 0.f }, m03{ 0.f },
		m10{ 0.f }, m11{ 1.f }, m12{ 0.f }, m13{ 0.f },
		m20{ 0.f }, m21{ 0.f }, m22{ 1.f }, m23{ 0.f },
		m30{ 0.f }, m31{ 0.f }, m32{ 0.f }, m33{ 1.f }
	{ }

	constexpr Matrix4x4::Matrix4x4(float32 m)
		: m00{ m }, m01{ 0.f }, m02{ 0.f }, m03{ 0.f },
		m10{ 0.f }, m11{ m }, m12{ 0.f }, m13{ 0.f },
		m20{ 0.f }, m21{ 0.f }, m22{ m }, m23{ 0.f },
		m30{ 0.f }, m31{ 0.f }, m32{ 0.f }, m33{ m }
	{ }

	constexpr Matrix4x4::Matrix4x4(
		float32 _m00, float32 _m01, float32 _m02, float32 _m03,
		float32 _m10, float32 _m11, float32 _m12, float32 _m13,
		float32 _m20, float32 _m21, float32 _m22, float32 _m23,
		float32 _m30, float32 _m31, float32 _m32, float32 _m33)
		: m00{ _m00 }, m01{ _m01 }, m02{ _m02 }, m03{ _m03 },
		m10{ _m10 }, m11{ _m11 }, m12{ _m12 }, m13{ _m13 },
		m20{ _m20 }, m21{ _m21 }, m22{ _m22 }, m23{ _m23 },
		m30{ _m30 }, m31{ _m31 }, m32{ _m32 }, m33{ _m33 }
	{ }

	constexpr Matrix4x4::Matrix4x4(float32 mat[4][4])
		: m00{ mat[0][0] }, m01{ mat[0][1] }, m02{ mat[0][2] }, m03{ mat[0][3] },
		m10{ mat[1][0] }, m11{ mat[1][1] }, m12{ mat[1][2] }, m13{ mat[1][3] },
		m20{ mat[2][0] }, m21{ mat[2][1] }, m22{ mat[2][2] }, m23{ mat[2][3] },
		m30{ mat[3][0] }, m31{ mat[3][1] }, m32{ mat[3][2] }, m33{ mat[3][3] }
	{ }

	constexpr Matrix4x4::Matrix4x4(float32 val[16])
		: m00{ val[0] }, m01{ val[1] }, m02{ val[2] }, m03{ val[3] },
		m10{ val[4] }, m11{ val[5] }, m12{ val[6] }, m13{ val[7] },
		m20{ val[8] }, m21{ val[9] }, m22{ val[10] }, m23{ val[11] },
		m30{ val[12] }, m31{ val[13] }, m32{ val[14] }, m33{ val[15] }
	{ }

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
		return Matrix4x4(
			left.m00 + right.m00,
			left.m01 + right.m01,
			left.m02 + right.m02,
			left.m03 + right.m03,
			left.m10 + right.m10,
			left.m11 + right.m11,
			left.m12 + right.m12,
			left.m13 + right.m13,
			left.m20 + right.m20,
			left.m21 + right.m21,
			left.m22 + right.m22,
			left.m23 + right.m23,
			left.m30 + right.m30,
			left.m31 + right.m31,
			left.m32 + right.m32,
			left.m33 + right.m33
		);
	}

	constexpr Matrix4x4 operator-(const Matrix4x4& left, const Matrix4x4& right)
	{
		return Matrix4x4(
			left.m00 - right.m00,
			left.m01 - right.m01,
			left.m02 - right.m02,
			left.m03 - right.m03,
			left.m10 - right.m10,
			left.m11 - right.m11,
			left.m12 - right.m12,
			left.m13 - right.m13,
			left.m20 - right.m20,
			left.m21 - right.m21,
			left.m22 - right.m22,
			left.m23 - right.m23,
			left.m30 - right.m30,
			left.m31 - right.m31,
			left.m32 - right.m32,
			left.m33 - right.m33
		);
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

	constexpr Matrix4x4& operator+=(Matrix4x4& left, const Matrix4x4& right)
	{
		left = left + right;
		return left;
	}

	constexpr Matrix4x4& operator-=(Matrix4x4& left, const Matrix4x4& right)
	{
		left = left - right;
		return left;
	}

	constexpr Matrix4x4& operator*=(Matrix4x4& left, const Matrix4x4& right)
	{
		left = left * right;
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
