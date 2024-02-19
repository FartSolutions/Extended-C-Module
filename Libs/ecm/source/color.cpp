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

	const int32 Color::ToInt32() const
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
} // namespace ecm
