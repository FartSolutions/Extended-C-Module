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
 * \file Vector2.h
 *
 * \brief This header defines an Vector2 and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR2_H_
#define _ECM_VECTOR2_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	/*
	 * \since v1.0.0
	 */
	struct ECM_API Vector2
	{
		enum Axis : uint8
		{
			AXIS_X = 0,
			AXIS_Y,
			AXIS_COUNT
		};
		union
		{
			struct
			{
				union
				{
					float32 x;
					float32 width;
				};
				union
				{
					float32 y;
					float32 height;
				};
			};
			float32 coord[2]{ 0.f };
		};

		constexpr Vector2();
		constexpr Vector2(float32 _x, float32 _y);
		constexpr Vector2(float32 _coord[2]);
	};

	using PointF = Vector2;
} // namespace ecm::math

#endif // !_ECM_VECTOR2_H_
