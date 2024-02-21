#include "ecm/types/color.h"

namespace ecm
{
	namespace
	{
		// TODO: In eine Mathematik Lib auslagern
		inline constexpr uint8 clamped_add(uint8 left, uint8 right)
		{
			const int32 res{ left + right };
			return static_cast<uint8>(res < 255 ? res : 255);
		}
		// TODO: In eine Mathematik Lib auslagern
		inline constexpr uint8 clamped_sub(uint8 left, uint8 right)
		{
			const int32 res{ left - right };
			return static_cast<uint8>(res > 0 ? res : 0);
		}
		// TODO: In eine Mathematik Lib auslagern
		inline constexpr uint8 scaled_mul(uint8 left, uint8 right)
		{
			const uint16 res{ static_cast<uint16>(uint16(left) * uint16(right)) };
			return static_cast<uint8>(res / 255ui16);
		}
	} // anonymous namespace

	// #########################################################################
	// Struct Color
	// #########################################################################

	constexpr Color::Color()
		: r{ 0 }, g{ 0 }, b{ 0 }, a{ 255 }
	{ }

	constexpr Color::Color(uint8 _r, uint8 _g, uint8 _b, uint8 _a)
		: r{ _r }, g{ _g }, b{ _b }, a{ _a }
	{ }

	constexpr Color::Color(float32 _r, float32 _g, float32 _b, float32 _a)
	{
		r = uint8(r * 255ui8);
		g = uint8(g * 255ui8);
		b = uint8(b * 255ui8);
		a = uint8(a * 255ui8);
	}

	constexpr Color::Color(uint32 rgba32)
	{
		r = (rgba32 >> 24) & 0xff;
		g = (rgba32 >> 16) & 0xff;
		b = (rgba32 >> 8) & 0xff;
		a = rgba32 & 0xff;
	}

	constexpr Color::Color(const ColorF col)
		: Color{ col.r, col.g, col.b, col.a }
	{ }

	const int32 Color::ToRGBA32() const
	{
		return (r << 24) | (g << 16) | (b << 8) | a;
	}

	const ColorF Color::ToRGBA32F() const
	{
		return ColorF{ float32(r) / 255.f,
					   float32(g) / 255.f,
					   float32(b) / 255.f,
					   float32(a) / 255.f };
	}

	// #########################################################################
	// Struct Color Operatoren
	// #########################################################################

	constexpr bool operator==(const Color& left, const Color& right)
	{
		if (left.r != right.r) return false;
		if (left.g != right.g) return false;
		if (left.b != right.b) return false;
		if (left.a != right.a) return false;
		return true;
	}
	
	constexpr bool operator!=(const Color& left, const Color& right)
	{
		return !(left == right);
	}

	constexpr Color operator+(const Color& left, const Color& right)
	{
		Color col{};
		col.r = clamped_add(left.r, right.r);
		col.g = clamped_add(left.g, right.g);
		col.b = clamped_add(left.b, right.b);
		col.a = clamped_add(left.a, right.a);
		return col;
	}

	constexpr Color operator-(const Color& left, const Color& right)
	{
		Color col{};
		col.r = clamped_sub(left.r, right.r);
		col.g = clamped_sub(left.g, right.g);
		col.b = clamped_sub(left.b, right.b);
		col.a = clamped_sub(left.a, right.a);
		return col;
	}

	constexpr Color operator*(const Color& left, const Color& right)
	{
		Color col{};
		col.r = scaled_mul(left.r, right.r);
		col.g = scaled_mul(left.g, right.g);
		col.b = scaled_mul(left.b, right.b);
		col.a = scaled_mul(left.a, right.a);
		return col;
	}

	// #########################################################################
	// Struct ColorF
	// #########################################################################

	constexpr ColorF::ColorF()
		: r{ 0.f }, g{ 0.f }, b{ 0.f }, a{ 1.f }
	{ }

	constexpr ColorF::ColorF(float32 _r, float32 _g, float32 _b, float32 _a)
		: r{ _r }, g{ _g }, b{ _b }, a{ _a }
	{ }

	constexpr ColorF::ColorF(uint8 _r, uint8 _g, uint8 _b, uint8 _a)
	{
		r = float32(_r / 255.f);
		g = float32(_g / 255.f);
		b = float32(_b / 255.f);
		a = float32(_a / 255.f);
	}

	constexpr ColorF::ColorF(uint32 rgba32)
	{
		r = ((rgba32 >> 24) & 0xff) / 255.f;
		g = ((rgba32 >> 16) & 0xff) / 255.f;
		b = ((rgba32 >> 8) & 0xff) / 255.f;
		a = (rgba32 & 0xff) / 255.f;
	}

	constexpr ColorF::ColorF(const Color col)
		: ColorF{ col.r, col.g, col.b, col.a }
	{ }

	const int32 ColorF::ToRGBA32() const
	{
		int32 rgba32{ (int32(r * 255) << 24) };
		rgba32 |= (int32(g * 255) << 16);
		rgba32 |= (int32(b * 255) << 8);
		rgba32 |= int32(a * 255);
		return rgba32;
	}

	const Color ColorF::ToRGBA8888() const
	{
		return Color{ uint8(r * 255ui8),
					  uint8(g * 255ui8),
					  uint8(b * 255ui8),
					  uint8(a * 255ui8) };
	}
} // namespace ecm
