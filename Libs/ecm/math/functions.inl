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
		return x < 0 ?
			static_cast<T>(static_cast<long long>(x)) :
			static_cast<T>(static_cast<long long>(x));
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
		static_assert(std::numeric_limits<E>::is_integer, "Exponent must be an integral type.");
		B res{ static_cast<B>(1) };
		for (E i{ static_cast<E>(0) }; i < Abs(exp); ++i) {
			res *= base;
		}
		if (exp < 0) {
			return static_cast<B>(1) / res;
		}
		return res;
	}

	template<typename T>
	constexpr T Fmod(T x, T y) noexcept
	{
		static_assert(std::numeric_limits<T>::is_iec559, "Type must be a floating type.");
		if (y == 0.0) {
			return std::numeric_limits<T>::quiet_NaN();
		}
		return x - Trunc(x / y) * y;
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
