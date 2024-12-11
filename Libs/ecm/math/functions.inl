#pragma once

#include "functions.hpp"

#include <cmath>
#include <type_traits>

namespace ecm::math
{
	namespace
	{
		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// TODO: Move to another file, like "type_traits.hpp"
		template<typename _Ty>
		struct IsIntegral {
			static constexpr bool value = false;
		};
		template<>
		struct IsIntegral<bool> {
			static constexpr bool value = false;
		};
		template<>
		struct IsIntegral<int8> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<uint8> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<int16> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<uint16> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<int32> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<uint32> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<int64> {
			static constexpr bool value = true;
		};
		template<>
		struct IsIntegral<uint64> {
			static constexpr bool value = true;
		};
		template<typename _Ty>
		struct IsFloatingPoint {
			static constexpr bool Value = false;
		};
		template<>
		struct IsFloatingPoint<float32> {
			static constexpr bool Value = true;
		};
		template<>
		struct IsFloatingPoint<float64> {
			static constexpr bool Value = true;
		};
		template<>
		struct IsFloatingPoint<float128> {
			static constexpr bool Value = true;
		};
		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// TODO: Move to another file, like "utils.hpp"
		template<typename _Ty>
		inline _Ty QuietNaN() noexcept;
		template<>
		inline float32 QuietNaN() noexcept {
			union {
				uint32 i;
				float32 f;
			} u{};
			u.i = 0x4fc00000;
			return u.f;
		}
		template<>
		inline float64 QuietNaN() noexcept {
			union {
				uint64 i;
				float64 f;
			} u{};
			u.i = 0x7ff8000000000000;
			return u.f;
		}
		template<>
		inline float128 QuietNaN() noexcept {
			struct _Float128 {
				uint64 high;
				uint64 low;
			};
			_Float128 nan = { 0x7FFF800000000000, 0x0000000000000000 };
			float128 result;
			memcpy(&result, &nan, sizeof(result));
			return result;
		}
		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	} // anonymous namespace

	template<typename _Ty>
	_Ty Abs(_Ty const x) noexcept
	{
		return x < static_cast<_Ty>(0) ? -x : x;
	}

	template<typename _Ty>
	inline _Ty Trunc(_Ty const x) noexcept
	{
		return x < 0 ?
			static_cast<_Ty>(static_cast<long long>(x)) :
			static_cast<_Ty>(static_cast<long long>(x));
	}
	
	template<typename _Ty>
	_Ty Fact(_Ty n) noexcept
	{
		_Ty res{ static_cast<_Ty>(1) };
		for (_Ty i{ static_cast<_Ty>(1) }; i <= n; ++i) {
			res *= i;
		}
		return res;
	}

	template<typename _Ty_Base, typename _Ty_Exp>
	_Ty_Base Pow(_Ty_Base const base, _Ty_Exp const exp) noexcept
	{
		static_assert(IsIntegral<_Ty_Exp>::value,
			"Exponent must be an integral type");
		_Ty_Base res{ static_cast<_Ty_Base>(1) };
		for (_Ty_Exp i{ static_cast<_Ty_Exp>(0) }; i < Abs(exp); ++i) {
			res *= base;
		}
		if (exp < 0) {
			return static_cast<_Ty_Base>(1) / res;
		}
		return res;
	}

	template<typename _Ty>
	inline _Ty Fmod(_Ty const x, _Ty const y) noexcept
	{
		static_assert(IsFloatingPoint<_Ty>::Value,
			"Type must be a floating type");
		if (y == 0.0) {
			return QuietNaN<_Ty>();
		}
		return x - Trunc(x / y) * y;
	}

	template<typename T>
	constexpr float64 DegToRad(T d)
	{
		return static_cast<float64>(d) * (PI / 180.0);
	}

	template<typename T>
	constexpr float64 RadToDeg(T r)
	{
		return (static_cast<float64>(r) * 180.0) / PI;
	}

	template<typename T>
	constexpr T Sin(T x)
	{
		return static_cast<T>(std::sin(x));
	}

	template<typename T>
	constexpr T Asin(T x)
	{
		return static_cast<T>(std::asin(x));
	}

	template<typename T>
	constexpr T Sinh(T x)
	{
		return static_cast<T>(std::sinh(x));
	}

	template<typename T>
	constexpr T Asinh(T x)
	{
		return static_cast<T>(std::asinh(x));
	}

	template<typename T>
	constexpr T Cos(T x)
	{
		return static_cast<T>(std::cos(x));
	}

	template<typename T>
	constexpr T Acos(T x)
	{
		return static_cast<T>(std::acos(x));
	}

	template<typename T>
	constexpr T Cosh(T x)
	{
		return static_cast<T>(std::cosh(x));
	}

	template<typename T>
	constexpr T Acosh(T x)
	{
		return static_cast<T>(std::acosh(x));
	}

	template<typename T>
	constexpr T Tan(T x)
	{
		return static_cast<T>(std::tan(x));
	}

	template<typename T>
	constexpr T Atan(T x)
	{
		return static_cast<T>(std::atan(x));
	}

	template<typename T>
	constexpr T Tanh(T x)
	{
		return static_cast<T>(std::tanh(x));
	}

	template<typename T>
	constexpr T Atanh(T x)
	{
		return static_cast<T>(std::atanh(x));
	}

	template<typename T>
	constexpr T Log(T x)
	{
		return static_cast<T>(std::log(x));
	}

	template<typename T>
	constexpr T Log2(T x)
	{
		return static_cast<T>(std::log2(x));
	}

	template<typename T>
	constexpr T Log10(T x)
	{
		return static_cast<T>(std::log10(x));
	}

	template<typename T>
	constexpr T Log1p(T x)
	{
		return static_cast<T>(std::log1p(x));
	}
} // namespace ecm::math
