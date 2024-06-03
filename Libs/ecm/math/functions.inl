#pragma once

#include "functions.hpp"
#include <cmath>

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
		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	} // anonymous namespace

	template<typename _Ty>
	_Ty Abs(_Ty const x) noexcept
	{
		return x < static_cast<_Ty>(0) ? -x : x;
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
} // namespace ecm::math
