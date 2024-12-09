#pragma once
#ifndef _ECM_MATRIX_H_
#define _ECM_MATRIX_H_

#include "matrix4x4.hpp"

namespace ecm::math
{
	// Matrix4x4

	using Matrix4x4 = Matrix4x4_Base<float32>;

	using Matrix4x4A = ECM_ALIGN(16) Matrix4x4;

	using Matrix4x4i = Matrix4x4_Base<int32>;

	using Matrix4x4iA = ECM_ALIGN(16) Matrix4x4i;

	using Matrix4x4u = Matrix4x4_Base<uint32>;

	using Matrix4x4uA = ECM_ALIGN(16) Matrix4x4u;
} // namespace ecm::math

#endif // !_ECM_MATRIX_H_
