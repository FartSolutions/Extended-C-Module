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
#include <DirectXMath.h>

namespace ecm::math
{
	constexpr float64 DEF_PI = 3.14159265358979323846;
	constexpr float64 DEF_2PI = 6.28318530717958647692;
	constexpr float64 DEF_1DIVPI = 0.31830988618379067153;
	constexpr float64 DEF_1DIV2PI = 0.15915494309189533576;
	constexpr float64 DEF_PIDIV2 = 1.57079632679489661923;
	constexpr float64 DEF_PIDIV4 = 0.78539816339744830961;

	// Basic functions

	/**
	 * This function calculates the absolute value of a given input.
	 *
	 * \param x Input value of type T.
	 *
	 * \returns The absolute value of the input x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Abs(T x) noexcept;

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
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Trunc(T x) noexcept;

	/**
	 * This function calculates the factorial of a given input.
	 *
	 * \param n Input value of type T.
	 *
	 * \returns The factorial of the input n.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Fact(T n) noexcept;

	/**
	 * This function calculates the power of a base raised to an exponent.
	 *
	 * \param base The base value of type B.
	 * \param exp The exponent value of type E.
	 *
	 * \returns The result of raising base to the power of exp.
	 *
	 * \since v1.0.0
	 */
	template<typename B, typename E>
	ECM_NODISCARD constexpr B ECM_CALL Pow(B base, E exp) noexcept;

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
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Fmod(T x, T y) noexcept;

	// Trigonometry functions

	template<typename T>
	ECM_NODISCARD constexpr float64 ECM_CALL DegToRad(T d) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr float64 ECM_CALL RadToDeg(T r) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Sin(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Asin(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Sinh(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Asinh(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Cos(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Acos(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Cosh(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Acosh(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Tan(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Atan(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Tanh(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Atanh(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log2(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log10(T x) noexcept;

	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log1p(T x) noexcept;
} // namespace ecm::math

#include "functions.inl"

#endif // !_ECM_FUNCTIONS_H_
