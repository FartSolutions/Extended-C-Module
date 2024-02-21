#include "ecm/types/color.h"

namespace ecm
{
	constexpr Color::Color()
		: r{ 0 }, g{ 0 }, b{ 0 }, a{ 255 }
	{ }

	constexpr Color::Color(uint8 _r, uint8 _g, uint8 _b, uint8 _a)
		: r{ _r }, g{ _g }, b{ _b }, a{ _a }
	{ }

	constexpr Color::Color(uint32 rgba32)
	{
		r = (rgba32 >> 24) & 0xff;
		g = (rgba32 >> 16) & 0xff;
		b = (rgba32 >> 8) & 0xff;
		a = rgba32 & 0xff;
	}

	const int32 Color::ToRGBA32() const
	{
		return (r << 24) | (g << 16) | (b << 8) | a;
	}

	const ColorF Color::ToRGBA32F() const
	{
		return ColorF{ float(r) / 255.f,
					   float(g) / 255.f,
					   float(b) / 255.f,
					   float(a) / 255.f };
	}

	constexpr ColorF::ColorF()
		: r{ 0.f }, g{ 0.f }, b{ 0.f }, a{ 1.f }
	{ }

	constexpr ColorF::ColorF(float32 _r, float32 _g, float32 _b, float32 _a)
		: r{ _r }, g{ _g }, b{ _b }, a{ _a }
	{ }

	constexpr ColorF::ColorF(uint32 rgba32)
	{
		r = ((rgba32 >> 24) & 0xff) / 255.f;
		g = ((rgba32 >> 16) & 0xff) / 255.f;
		b = ((rgba32 >> 8) & 0xff) / 255.f;
		a = (rgba32 & 0xff) / 255.f;
	}

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
