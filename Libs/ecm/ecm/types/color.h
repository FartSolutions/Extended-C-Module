/*
 * \file color.h
 *
 * \brief This header defines color functionalitites.
 */

#pragma once
#ifndef _ECM_COLOR_H_
#define _ECM_COLOR_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm
{
	struct Color;
	struct ColorF;

	/*
	 * This structure represents a color in RGBA8888 format.
	 *
	 * \since v1.0.0
	 *
	 * \sa ColorF
	 */
	struct ECM_API Color
	{
		enum : uint8
		{
			CHANNEL_RED = 0u,
			CHANNEL_GREEN,
			CHANNEL_BLUE,
			CHANNEL_ALPHA,
			CHANNELS_COUNT
		};
		union
		{
			struct
			{
				// red channel
				uint8 r;
				// green channel
				uint8 g;
				// blue channel
				uint8 b;
				// alpha channel
				uint8 a;
			};
			uint8 channels[4]{ 0, 0, 0, 0 };
		};

		/*
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr Color();

		/*
		 * This is a constructor.
		 *
		 * \param _r value for red channel: range[0, 255]
		 * \param _g value for green channel: range[0, 255]
		 * \param _b value for blue channel: range[0, 255]
		 * \param _a value for alpha channel: range[0, 255]
		 *
		 * \since v1.0.0
		 */
		constexpr explicit Color(uint8 _r, uint8 _g, uint8 _b, uint8 _a);

		/*
		 * This is a constructor.
		 *
		 * \param _r value for red channel: range[0.f, 1.f]
		 * \param _g value for green channel: range[0.f, 1.f]
		 * \param _b value for blue channel: range[0.f, 1.f]
		 * \param _a value for alpha channel: range[0.f, 1.f]
		 *
		 * \since v1.0.0
		 */
		constexpr explicit Color(
			float32 _r, float32 _g, float32 _b, float32 _a);

		/*
		 * This is a constructor.
		 *
		 * \param rgba32 the int32 value: 0xff'ff'ff'ff
		 *                             -> red'green'blue'alpha
		 *
		 * \since v1.0.0
		 */
		constexpr explicit Color(uint32 rgba32);

		/*
		 * This is a constructor.
		 *
		 * \param col an object of an RGBA32F-Color-Struct.
		 *
		 * \since v1.0.0
		 */
		constexpr explicit Color(const ColorF col);

		/*
		 * Returns the current channel variables in an int32.
		 *
		 * \returns All channels as int32: 0xred'green'blue'alpha.
		 *
		 * \since v1.0.0
		 */
		const int32 ToRGBA32() const;

		/*
		 * Returns the current object as RGBA32F-Color-Struct.
		 *
		 * \returns Actual object as ColorF (RGBA32F format).
		 *
		 * \since v1.0.0
		 *
		 * \sa ColorF
		 */
		const ColorF ToRGBA32F() const;
	};

	/*
	 * This operator checks if the two colors are the same.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns true if left is same as right, or false if not.
	 *
	 * \since v1.0.0
	 * 
	 * \sa Color
	 */
	extern ECM_API constexpr bool operator==(
		const Color& left, const Color& right);

	/*
	 * This operator checks if the two colors are not the same.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns true if left is not same as right, or false if.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr bool operator!=(
		const Color& left, const Color& right);

	/*
	 * This operator creates an new Color object, calculates the addition of two
	 * Color objects left and right component-wise and returns the newly created
	 * object.
	 * Channel values that are above 255 after adding are set to 255.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns A new Color object, which is the sum of left and right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr Color operator+(
		const Color& left, const Color& right);

	/*
	 * This operator creates an new Color object, calculates the subtracting of
	 * two Color objects left and right component-wise and returns the newly
	 * created object.
	 * Channel values that are below 0 after subtracting are set to 0.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns A new Color object calculated by subtracting left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr Color operator-(
		const Color& left, const Color& right);

	/*
	 * This operator creates an new Color object, calculates the multiplication
	 * of two Color objects left and right component-wise and returns the newly
	 * created object.
	 * Channel values are then divided by 255.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns A new Color object calculated by multiplying left by right.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr Color operator*(
		const Color& left, const Color& right);

	/*
	 * This operator adds the two Color objects left and right together and
	 * returns a reference to left.
	 * Channel values that are above 255 after adding are set to 255.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns After calculation a reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr Color& operator+=(
		Color& left, const Color& right);

	/*
	 * This operator subtracts the Color object left with right and returns a
	 * reference to left.
	 * Channel values that are below 0 after subtracting are set to 0.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns After calculation a reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr Color& operator-=(
		Color& left, const Color& right);

	/*
	 * This operator multiplies the two Color objects left with right and
	 * returns a reference to left.
	 * Channel values are then divided by 255.
	 *
	 * \param left Left color operand.
	 * \param left right color operand.
	 *
	 * \returns After calculation a reference to left.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	extern ECM_API constexpr Color& operator*=(
		Color& left, const Color& right);

	/*
	 * This structure represents a color in RGBA32F format.
	 *
	 * \since v1.0.0
	 *
	 * \sa Color
	 */
	struct ECM_API ColorF
	{
		enum : uint8
		{
			CHANNEL_RED = 0u,
			CHANNEL_GREEN,
			CHANNEL_BLUE,
			CHANNEL_ALPHA,
			CHANNELS_COUNT
		};
		union
		{
			struct
			{
				// Red channel
				float32 r;
				// Green channel
				float32 g;
				// Blue channel
				float32 b;
				// Alpha channel
				float32 a;
			};
			float32 channels[4]{ 0.f, 0.f, 0.f, 0.f };
		};

		/*
		 * This is the default constructor.
		 *
		 * \since v1.0.0
		 */
		constexpr ColorF();

		/*
		 * This is a constructor.
		 *
		 * \param _r value for red channel: range[0.f, 1.f]
		 * \param _g value for green channel: range[0.f, 1.f]
		 * \param _b value for blue channel: range[0.f, 1.f]
		 * \param _a value for alpha channel: range[0.f, 1.f]
		 *
		 * \since v1.0.0
		 */
		constexpr explicit ColorF(
			float32 _r, float32 _g, float32 _b, float32 _a);

		/*
		 * This is a constructor.
		 *
		 * \param _r value for red channel: range[0, 255]
		 * \param _g value for green channel: range[0, 255]
		 * \param _b value for blue channel: range[0, 255]
		 * \param _a value for alpha channel: range[0, 255]
		 *
		 * \since v1.0.0
		 */
		constexpr explicit ColorF(uint8 _r, uint8 _g, uint8 _b, uint8 _a);

		/*
		 * This is a constructor.
		 *
		 * \param rgba32 the int32 value: 0xff'ff'ff'ff
		 *                             -> red'green'blue'alpha
		 *
		 * \since v1.0.0
		 */
		constexpr explicit ColorF(uint32 rgba32);

		/*
		 * This is a constructor.
		 *
		 * \param col an object of an RGBA8888-Color-Struct.
		 *
		 * \since v1.0.0
		 */
		constexpr explicit ColorF(const Color col);

		/*
		 * Returns the current channel variables in an int32.
		 *
		 * \returns All channels as int32: 0xred'green'blue'alpha
		 *
		 * \since v1.0.0
		 */
		const int32 ToRGBA32() const;

		/*
		 * Returns the current object as RGBA8888-Color-Struct.
		 *
		 * \returns Actual object as Color (RGBA8888 format).
		 *
		 * \since v1.0.0
		 *
		 * \sa Color
		 */
		const Color ToRGBA8888() const;
	};
} // namespace ecm

#endif // !_ECM_COLOR_H_
