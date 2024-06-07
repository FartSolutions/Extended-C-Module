#pragma once

#include "functions.hpp"

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
		if (y < 0.0) {
			return QuietNaN<_Ty>();
		}
		return x - Trunc(x / y) * y;
	}
} // namespace ecm::math
