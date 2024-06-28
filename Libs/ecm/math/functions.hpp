/*
 * \file functions.hpp
 *
 * \brief This header defines mathematic functionalities.
 */

#pragma once
#ifndef _ECM_FUNCTIONS_H_
#define _ECM_FUNCTIONS_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	constexpr float64 PI = 3.14159265358979323846;
	constexpr float64 PI2 = 6.28318530717958647692;

	/*
	 * This function calculates the absolute value of a given input.
	 *
	 * \param x Input value of type _Ty.
	 *
	 * \returns The absolute value of the input x.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	inline _Ty ECM_CALL Abs(_Ty const x) noexcept;

	/*
	 * This function truncates the decimal part of the number and returns the
	 * integer part.
	 *
	 * \param x The input value to be truncated.
	 *
	 * \returns The truncated integer part of the input value.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	inline _Ty ECM_CALL Trunc(_Ty const x) noexcept;

	/*
	 * This function calculates the factorial of a given input.
	 *
	 * \param n Input value of type _Ty.
	 *
	 * \returns The factorial of the input n.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	inline _Ty ECM_CALL Fact(_Ty const n) noexcept;

	/*
	 * This function calculates the power of a base raised to an exponent.
	 *
	 * \param base The base value of type _Ty_Base.
	 * \param exp The exponent value of type _Ty_Exp.
	 *
	 * \returns The result of raising base to the power of exp.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty_Base, typename _Ty_Exp>
	inline _Ty_Base ECM_CALL Pow(_Ty_Base const base,
		_Ty_Exp const exp) noexcept;

	/*
	 * Computes the floating-point remainder of the division operation x/y.
	 *
	 * \param x The dividend in the division operation.
	 * \param y The divisor in the division operation.
	 *
	 * \returns The reminder of the division operation x/y.
	 *          If the divisor y is less than 0, returns a QuietNaN.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	inline _Ty ECM_CALL Fmod(_Ty const x, _Ty const y) noexcept;

	extern ECM_MATH_API float64 ECM_CALL Sin(float64 x);

	extern ECM_MATH_API float32 ECM_CALL Sin(float32 x);
} // namespace ecm::math

#include "functions.inl"

#endif // !_ECM_FUNCTIONS_H_
