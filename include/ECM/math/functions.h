/*
 * \file functions.hpp
 *
 * \brief This header defines mathematic functionalities.
 */

#pragma once
#ifndef _ECM_FUNCTIONS_H_
#define _ECM_FUNCTIONS_H_

#include <ECM/ECM_api.h>
#include <ECM/ECM_stdtypes.h>

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
	 * Computes the absolute value of the given number.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The absolute value of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Abs(T x) noexcept;

	/**
	 * Truncates the given number by removing the fractional part.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The truncated value of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Trunc(T x) noexcept;

	/**
	 * Calculates the factorial of a non-negative integer.
	 *
	 * \param n The non-negative integer input.
	 *
	 * \tparam T The type of the input value (generally integral).
	 *
	 * \returns The factorial of \p n.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Fact(T n) noexcept;

	/**
	 * Raises a base to the power of an exponent.
	 *
	 * \param base The base value.
	 * \param exp The exponent value.
	 *
	 * \tparam B The type of the base value.
	 * \tparam E The type of the exponent value (generally integral).
	 *
	 * \returns The value of \p base raised to the power \p exp.
	 *
	 * \since v1.0.0
	 */
	template<typename B, typename E>
	ECM_NODISCARD constexpr B ECM_CALL Pow(B base, E exp) noexcept;

	/**
	 * Computes the remainder of division.
	 *
	 * \param x The dividend.
	 * \param y The divisor.
	 *
	 * \tparam T The type of the dividend.
	 * \tparam U The type of the divisor.
	 *
	 * \returns The floating-point remainder of \p x / \p y.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U>
	ECM_NODISCARD constexpr T ECM_CALL Fmod(T x, U y) noexcept;

	/**
	 * Computes the cube root of the given number.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The cube root of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Cbrt(T x) noexcept;

	/**
	 * Computes the square root of the given number.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The square root of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Sqrt(T x) noexcept;

	/**
	 * Computes the smallest integer value not less than \p x.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The ceiling of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Ceil(T x) noexcept;

	/**
	 * Computes the largest integer value not greater than \p x.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The floor of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Floor(T x) noexcept;

	/**
	 * Computes the exponential function e^x.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The exponential of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Exp(T x) noexcept;

	/**
	 * Decomposes \p x into a normalized fraction and an integral power of two.
	 *
	 * \param x The input value.
	 * \param e A pointer to an integer to store the exponent.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The fraction part, with magnitude in [0.5, 1.0).
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Frexp(T x, int32* e) noexcept;

	/**
	 * Multiplies \p x by 2 raised to the power \p n.
	 *
	 * \param x The input value.
	 * \param n The integer exponent.
	 *
	 * \tparam T The type of the input value.
	 * \tparam U The type of the exponent (generally integral).
	 *
	 * \returns The result of \p x * 2^n.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U>
	ECM_NODISCARD constexpr T ECM_CALL Ldexp(T x, U n) noexcept;

	/**
	 * Computes the length of the hypotenuse of a right-angled triangle,
	 * given the lengths of the two other sides.
	 *
	 * \param x The length of one side.
	 * \param y The length of the other side.
	 *
	 * \tparam T The type of the first input value.
	 * \tparam U The type of the second input value.
	 *
	 * \returns The length of the hypotenuse.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U>
	ECM_NODISCARD constexpr T ECM_CALL Hypot(T x, U y) noexcept;

	/**
	 * Returns the minimum of two values.
	 *
	 * \param x The first value.
	 * \param y The second value.
	 *
	 * \tparam T The type of the input values.
	 *
	 * \returns The smaller of \p x and \p y.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Min(T x, T y) noexcept;

	/**
	 * Returns the maximum of two values.
	 *
	 * \param x The first value.
	 * \param y The second value.
	 *
	 * \tparam T The type of the input values.
	 *
	 * \returns The larger of \p x and \p y.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Max(T x, T y) noexcept;

	/**
	 * Linearly interpolates between two values based on a parameter \p t.
	 *
	 * This function computes the interpolation between \p x and \p y using the
	 * formula:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 *
	 * \param x The start value.
	 * \param y The end value.
	 * \param t The interpolation factor, typically in the range \[0, 1\].
	 *
	 * \tparam T The type of the input values.
	 *
	 * \returns The result of the linear interpolation between \p x and \p y at
	 * \p t.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Lerp(T x, T y, T t) noexcept;

	/**
	 * Clamps a value \p v within the inclusive range defined by \p min and \p max.
	 *
	 * If \p v is less than \p min, \p min is returned. If \p v is greater than
	 * \p max, \p max is returned. Otherwise, \p v itself is returned.
	 *
	 * \param v The input value to clamp.
	 * \param min The minimum bound.
	 * \param max The maximum bound.
	 *
	 * \tparam T The type of the input values.
	 *
	 * \returns \p v clamped to the range \[\p min, \p max\].
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Clamp(T v, T min, T max) noexcept;

	// Trigonometry functions

	/**
	 * Converts degrees to radians.
	 *
	 * \param d The angle in degrees.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The angle \p d converted to radians.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr float64 ECM_CALL DegToRad(T d) noexcept;

	/**
	 * Converts radians to degrees.
	 *
	 * \param r The angle in radians.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The angle \p r converted to degrees.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr float64 ECM_CALL RadToDeg(T r) noexcept;

	/**
	 * Computes the sine of a given angle (in radians).
	 *
	 * \param x The angle in radians.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The sine of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Sin(T x) noexcept;

	/**
	 * Computes the arcsine of a given value.
	 *
	 * \param x The input value, typically in the range [-1, 1].
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The arcsine of \p x, in radians.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Asin(T x) noexcept;

	/**
	 * Computes the hyperbolic sine of a given value.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The hyperbolic sine of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Sinh(T x) noexcept;

	/**
	 * Computes the inverse hyperbolic sine of a given value.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The inverse hyperbolic sine of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Asinh(T x) noexcept;

	/**
	 * Computes the cosine of a given angle (in radians).
	 *
	 * \param x The angle in radians.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The cosine of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Cos(T x) noexcept;

	/**
	 * Computes the arccosine of a given value.
	 *
	 * \param x The input value, typically in the range [-1, 1].
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The arccosine of \p x, in radians.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Acos(T x) noexcept;

	/**
	 * Computes the hyperbolic cosine of a given value.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The hyperbolic cosine of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Cosh(T x) noexcept;

	/**
	 * Computes the inverse hyperbolic cosine of a given value.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The inverse hyperbolic cosine of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Acosh(T x) noexcept;

	/**
	 * Computes the tangent of a given angle (in radians).
	 *
	 * \param x The angle in radians.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The tangent of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Tan(T x) noexcept;

	/**
	 * Computes the arctangent of a given value.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The arctangent of \p x, in radians.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Atan(T x) noexcept;

	/**
	 * Computes the hyperbolic tangent of a given value.
	 *
	 * \param x The input value.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The hyperbolic tangent of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Tanh(T x) noexcept;

	/**
	 * Computes the inverse hyperbolic tangent of a given value.
	 *
	 * \param x The input value, typically in the range (-1, 1).
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The inverse hyperbolic tangent of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Atanh(T x) noexcept;

	/**
	 * Computes the natural logarithm of a given number.
	 *
	 * \param x The input value, generally > 0.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The natural logarithm of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log(T x) noexcept;

	/**
	 * Computes the binary (base-2) logarithm of a given number.
	 *
	 * \param x The input value, generally > 0.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The base-2 logarithm of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log2(T x) noexcept;

	/**
	 * Computes the common (base-10) logarithm of a given number.
	 *
	 * \param x The input value, generally > 0.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The base-10 logarithm of \p x.
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log10(T x) noexcept;

	/**
	 * Computes the natural logarithm of (1 + x).
	 *
	 * \param x The input value, typically > -1.
	 *
	 * \tparam T The type of the input value.
	 *
	 * \returns The natural logarithm of (1 + \p x).
	 *
	 * \since v1.0.0
	 */
	template<typename T>
	ECM_NODISCARD constexpr T ECM_CALL Log1p(T x) noexcept;
} // namespace ecm::math

#endif // !_ECM_FUNCTIONS_H_
