#pragma once

#include "functions.hpp"

#include <cmath>
#include <limits>

namespace ecm::math
{
	// Basic functions

	template<typename T>
	constexpr T Abs(T x) noexcept
	{
		return x < static_cast<T>(0) ? -x : x;
	}

	template<typename T>
	constexpr T Trunc(T x) noexcept
	{
		return static_cast<T>(static_cast<long long>(x));
	}
	
	template<typename T>
	constexpr T Fact(T n) noexcept
	{
		T res{ static_cast<T>(1) };
		for (T i{ static_cast<T>(1) }; i <= n; ++i) {
			res *= i;
		}
		return res;
	}

	template<typename B, typename E>
	constexpr B Pow(B base, E exp) noexcept
	{
		return static_cast<B>(std::pow(base, exp));
	}

	template<typename T, typename U>
	constexpr T Fmod(T x, U y) noexcept
	{
		static_assert(std::numeric_limits<T>::is_iec559, "Type must be a floating type.");
		if (y == 0.0) {
			return std::numeric_limits<T>::quiet_NaN();
		}
		return static_cast<T>(x - Trunc(x / y) * y);
	}

	template<typename T>
	constexpr T Cbrt(T x) noexcept
	{
		return (x < 0 ? -1 : 1) * Pow(Abs(x), static_cast<T>(1) / static_cast<T>(3));
	}

	template<typename T>
	constexpr T Sqrt(T x) noexcept
	{
		if (x < 0) {
			return std::numeric_limits<T>::quiet_NaN();
		}
		T guess = static_cast<T>(x / 2.0);
		T previousGuess;
		const T epsilon = std::numeric_limits<T>::epsilon();
		do {
			previousGuess = guess;
			guess = static_cast<T>((guess + x / guess) / 2.0);
		} while (Abs(guess - previousGuess) > epsilon);
		return guess;
	}

	template<typename T>
	constexpr T Ceil(T x) noexcept
	{
		int64 intPart = static_cast<int64>(x);
		return static_cast<T>((x > intPart) ? intPart + 1 : intPart);
	}

	template<typename T>
	constexpr T Floor(T x) noexcept
	{
		int64 intPart = static_cast<int64>(x);
		return static_cast<T>((x < intPart) ? intPart - 1 : intPart);
	}

	template<typename T>
	constexpr T Exp(T x) noexcept
	{
		constexpr int32 maxIterations = 100;
		constexpr float64 epsilon = 1e-15;
		T term = 1;
		T sum = 1;
		for (int32 n{ 1 }; n < maxIterations; ++n) {
			term *= x / n;
			sum += term;
			if (Abs(term) < epsilon) {
				break;
			}
		}
		return sum;
	}

	template<typename T>
	constexpr T Frexp(T x, int32* e) noexcept
	{
		if (x == 0) {
			return 0;
		}
		int exponent = 0;
		T mantissa = x;
		while (Abs(mantissa) >= 1.0) {
			mantissa /= 2.0;
			exponent++;
		}
		while (Abs(mantissa) < 0.5) {
			mantissa *= 2.0;
			exponent--;
		}
		e = &exponent;
		return static_cast<T>(mantissa);
	}

	template<typename T, typename U>
	constexpr T Ldexp(T x, U n) noexcept
	{
		return static_cast<T>(x * (1ll << n));
	}

	template<typename T, typename U>
	constexpr T Hypot(T x, U y) noexcept
	{
		return Sqrt(static_cast<T>(x * x + y * y));
	}

	template<typename T>
	constexpr T Min(T x, T y) noexcept
	{
		return (x < y) ? x : y;
	}

	template<typename T>
	constexpr T Max(T x, T y) noexcept
	{
		return (x > y) ? x : y;
	}

	template<typename T>
	constexpr T Lerp(T x, T y, T t) noexcept
	{
		return x + ((y - x) * t);
	}

	template<typename T>
	constexpr T Clamp(T v, T min, T max) noexcept
	{
		return (v < min) ? min : (v > max) ? max : v;
	}

	// Trigonometry functions

	template<typename T>
	constexpr float64 DegToRad(T d) noexcept
	{
		return static_cast<float64>(d) * (DEF_PI / 180.0);
	}

	template<typename T>
	constexpr float64 RadToDeg(T r) noexcept
	{
		return (static_cast<float64>(r) * 180.0) / DEF_PI;
	}

	template<typename T>
	constexpr T Sin(T x) noexcept
	{
		return static_cast<T>(std::sin(x));
	}

	template<typename T>
	constexpr T Asin(T x) noexcept
	{
		return static_cast<T>(std::asin(x));
	}

	template<typename T>
	constexpr T Sinh(T x) noexcept
	{
		return static_cast<T>(std::sinh(x));
	}

	template<typename T>
	constexpr T Asinh(T x) noexcept
	{
		return static_cast<T>(std::asinh(x));
	}

	template<typename T>
	constexpr T Cos(T x) noexcept
	{
		return static_cast<T>(std::cos(x));
	}

	template<typename T>
	constexpr T Acos(T x) noexcept
	{
		return static_cast<T>(std::acos(x));
	}

	template<typename T>
	constexpr T Cosh(T x) noexcept
	{
		return static_cast<T>(std::cosh(x));
	}

	template<typename T>
	constexpr T Acosh(T x) noexcept
	{
		return static_cast<T>(std::acosh(x));
	}

	template<typename T>
	constexpr T Tan(T x) noexcept
	{
		return static_cast<T>(std::tan(x));
	}

	template<typename T>
	constexpr T Atan(T x) noexcept
	{
		return static_cast<T>(std::atan(x));
	}

	template<typename T>
	constexpr T Tanh(T x) noexcept
	{
		return static_cast<T>(std::tanh(x));
	}

	template<typename T>
	constexpr T Atanh(T x) noexcept
	{
		return static_cast<T>(std::atanh(x));
	}

	template<typename T>
	constexpr T Log(T x) noexcept
	{
		return static_cast<T>(std::log(x));
	}

	template<typename T>
	constexpr T Log2(T x) noexcept
	{
		return static_cast<T>(std::log2(x));
	}

	template<typename T>
	constexpr T Log10(T x) noexcept
	{
		return static_cast<T>(std::log10(x));
	}

	template<typename T>
	constexpr T Log1p(T x) noexcept
	{
		return static_cast<T>(std::log1p(x));
	}
} // namespace ecm::math
