/*
  Extended Cpp Module
  Copyright (C) 2024, Alexander Burkhardt <alexander@fürth.org>

  All rights reserved.

  Use of this source code (the "Software"), except for compilation as part of a
  binary compiled library and its use in conjunction with the binary compiled
  library, without the prior written permission of the copyright owner is
  strictly prohibited. Permission is granted to use the header files of this
  software and to link against the binary compiled library, provided that the
  following conditions are met:

  1. redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
  2. redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

  THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
  OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO
  EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING OUT OF THE USE OF THE SOFTWARE OR ANY OTHER DEALINGS IN THE SOFTWARE.
*/

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
		constexpr explicit Color(float32 _r, float32 _g, float32 _b, float32 _a);

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
		 * \return All channels as int32: 0xred'green'blue'alpha
		 *
		 * \since v1.0.0
		 */
		const int32 ToRGBA32() const;

		/*
		 * Returns the current object as RGBA32F-Color-Struct.
		 *
		 * \return Actual object as ColorF (RGBA32F format).
		 *
		 * \since v1.0.0
		 *
		 * \sa ColorF
		 */
		const ColorF ToRGBA32F() const;
	};

	extern ECM_API constexpr bool operator==(const Color& left, const Color& right);
	extern ECM_API constexpr bool operator!=(const Color& left, const Color& right);
	extern ECM_API constexpr Color operator+(const Color& left, const Color& right);
	extern ECM_API constexpr Color operator-(const Color& left, const Color& right);
	extern ECM_API constexpr Color operator*(const Color& left, const Color& right);
	extern ECM_API constexpr Color operator+=(const Color& left, const Color& right);
	extern ECM_API constexpr Color operator-=(const Color& left, const Color& right);
	extern ECM_API constexpr Color operator*=(const Color& left, const Color& right);

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
		constexpr explicit ColorF(float32 _r, float32 _g, float32 _b, float32 _a);

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
		 * \return All channels as int32: 0xred'green'blue'alpha
		 *
		 * \since v1.0.0
		 */
		const int32 ToRGBA32() const;

		/*
		 * Returns the current object as RGBA8888-Color-Struct.
		 *
		 * \return Actual object as Color (RGBA8888 format).
		 *
		 * \since v1.0.0
		 *
		 * \sa Color
		 */
		const Color ToRGBA8888() const;
	};
} // namespace ecm

#endif // !_ECM_COLOR_H_
