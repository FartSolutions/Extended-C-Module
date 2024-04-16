#include <ecm/math/matrix4x4.h>

namespace ecm::math
{
	constexpr Matrix4x4::Matrix4x4()
		: m00{ 1.f }, m01{ 0.f }, m02{ 0.f }, m03{ 0.f },
		  m10{ 0.f }, m11{ 1.f }, m12{ 0.f }, m13{ 0.f },
		  m20{ 0.f }, m21{ 0.f }, m22{ 1.f }, m23{ 0.f },
		  m30{ 0.f }, m31{ 0.f }, m32{ 0.f }, m33{ 1.f }
	{ }

	constexpr Matrix4x4::Matrix4x4(float32 m)
		: m00{  m  }, m01{ 0.f }, m02{ 0.f }, m03{ 0.f },
		  m10{ 0.f }, m11{  m  }, m12{ 0.f }, m13{ 0.f },
		  m20{ 0.f }, m21{ 0.f }, m22{  m  }, m23{ 0.f },
		  m30{ 0.f }, m31{ 0.f }, m32{ 0.f }, m33{  m  }
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
} // namespace ecm::math
