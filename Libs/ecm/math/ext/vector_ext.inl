#pragma once

#include "vector_ext.hpp"

namespace ecm::math
{
	// Lerp

	template<typename T, typename U, typename W, typename>
	constexpr Vector2_Base<T> Lerp(const Vector2_Base<T>& x, const Vector2_Base<U>& y, W t)
	{
		const auto dx{ y.x - x.x };
		const auto dy{ y.y - x.y };
		return Vector2_Base<T>(
			static_cast<T>(x.x + dx * t),
			static_cast<T>(x.y + dy * t));
	}

	template<typename T, typename U, typename W, typename>
	constexpr Vector3_Base<T> Lerp(const Vector3_Base<T>& x, const Vector3_Base<U>& y, W t)
	{
		const auto dx{ y.x - x.x };
		const auto dy{ y.y - x.y };
		const auto dz{ y.z - x.z };
		return Vector3_Base<T>(
			static_cast<T>(x.x + dx * t),
			static_cast<T>(x.y + dy * t),
			static_cast<T>(x.z + dz * t));
	}

	template<typename T, typename U, typename W, typename>
	constexpr Vector4_Base<T> Lerp(const Vector4_Base<T>& x, const Vector4_Base<U>& y, W t)
	{
		const auto dx{ y.x - x.x };
		const auto dy{ y.y - x.y };
		const auto dz{ y.z - x.z };
		const auto dw{ y.w - x.w };
		return Vector4_Base<T>(
			static_cast<T>(x.x + dx * t),
			static_cast<T>(x.y + dy * t),
			static_cast<T>(x.z + dz * t),
			static_cast<T>(x.w + dw * t));
	}

	template<typename T, typename U, typename W>
	constexpr Vector2_Base<T> Lerp(const Vector2_Base<T>& x, const Vector2_Base<U>& y, const Vector2_Base<W>& t)
	{
		const auto dx{ y.x - x.x };
		const auto dy{ y.y - x.y };
		return Vector2_Base<T>(
			static_cast<T>(x.x + dx * t.x),
			static_cast<T>(x.y + dy * t.y));
	}

	template<typename T, typename U, typename W>
	constexpr Vector3_Base<T> Lerp(const Vector3_Base<T>& x, const Vector3_Base<U>& y, const Vector3_Base<W>& t)
	{
		const auto dx{ y.x - x.x };
		const auto dy{ y.y - x.y };
		const auto dz{ y.z - x.z };
		return Vector3_Base<T>(
			static_cast<T>(x.x + dx * t.x),
			static_cast<T>(x.y + dy * t.y),
			static_cast<T>(x.z + dz * t.z));
	}

	template<typename T, typename U, typename W>
	constexpr Vector4_Base<T> Lerp(const Vector4_Base<T>& x, const Vector4_Base<U>& y, const Vector4_Base<W>& t)
	{
		const auto dx{ y.x - x.x };
		const auto dy{ y.y - x.y };
		const auto dz{ y.z - x.z };
		const auto dw{ y.w - x.w };
		return Vector4_Base<T>(
			static_cast<T>(x.x + dx * t.x),
			static_cast<T>(x.y + dy * t.y),
			static_cast<T>(x.z + dz * t.z),
			static_cast<T>(x.w + dw * t.w));
	}
} // namespace ecm::math
