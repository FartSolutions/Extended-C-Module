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

	/**
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

	/**
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

	/**
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

	/**
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

	/**
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

	template<typename T>
	constexpr float64 DegToRad(T d);

	template<typename T>
	constexpr float64 RadToDeg(T r);

	template<typename T>
	constexpr T Sin(T x);

	template<typename T>
	constexpr T Asin(T x);

	template<typename T>
	constexpr T Sinh(T x);

	template<typename T>
	constexpr T Asinh(T x);

	template<typename T>
	constexpr T Cos(T x);

	template<typename T>
	constexpr T Acos(T x);

	template<typename T>
	constexpr T Cosh(T x);

	template<typename T>
	constexpr T Acosh(T x);

	template<typename T>
	constexpr T Tan(T x);

	template<typename T>
	constexpr T Atan(T x);

	template<typename T>
	constexpr T Tanh(T x);

	template<typename T>
	constexpr T Atanh(T x);

	template<typename T>
	constexpr T Log(T x);

	template<typename T>
	constexpr T Log2(T x);

	template<typename T>
	constexpr T Log10(T x);

	template<typename T>
	constexpr T Log1p(T x);
} // namespace ecm::math

#include "functions.inl"

#endif // !_ECM_FUNCTIONS_H_
