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
		 * This is the default constructor.
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
		 * This is the default constructor.
		 *
		 * \param rgba32 the int32 value: 0xff'ff'ff'ff
		 *                             -> red'green'blue'alpha
		 * 
		 * \since v1.0.0
		 */
		constexpr explicit Color(uint32 rgba32);

		/*
		 * 
		 * 
		 * \return All channels as int32: 0xred'green'blue'alpha
		 * 
		 * \since v1.0.0
		 */
		const int32 ToInt32() const;

		/*
		 * 
		 * 
		 * \return Actual object as ColorF (RGBA32F format).
		 * 
		 * \since v1.0.0
		 * 
		 * \sa ColorF
		 */
		const ColorF ToRGBA32F() const;
	};

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
				float32 r;
				float32 g;
				float32 b;
				float32 a;
			};
			float32 channels[4]{ 0.f, 0.f, 0.f, 0.f };
		};
	};
} // namespace ecm

#endif // !_ECM_COLOR_H_
