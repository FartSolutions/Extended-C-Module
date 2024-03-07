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
 * \file window.h
 *
 * \brief This header defines window functionalitites.
 */

#pragma once
#ifndef _ECM_WINDOW_H_
#define _ECM_WINDOW_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>
#include <ecm/math/Vector2.h>

namespace ecm
{
	/*
	 * \since v1.0.0
	 * 
	 * \sa Window
	 * \sa WindowInitInfo
	 */
	enum WindowModes : uint8
	{
		WINDOWMODE_NONE = 0,
		WINDOWMODE_MINIMIZED,
		WINDOWMODE_MAXIMIZED,
		WINDOWMODE_FULLSCREEN_WINDOWED,
		WINDOWMODE_FULLSCREEN,
	} WINDOWMODE_;

	/*
	 * \since v1.0.0
	 * 
	 * \sa WindowModes
	 * \sa Window
	 */
	struct WindowInitInfo
	{

	};

	/*
	 * \since v1.0.0
	 * 
	 * \sa WindowModes
	 * \sa WindowInitInfo
	 */
	struct ECM_WIN_API Window
	{
		constexpr explicit Window(id_type id);
		constexpr Window();
		constexpr bool IsValid() const;
		constexpr id_type GetID() const;

		void* GetHandle() const;
		uint8 GetWindowMode() const;
		void SetWindowMode(uint8 mode) const;
		bool IsFocused() const;
		void SetFocused() const;
		const char* GetTitle() const;
		void SetTitle(const char* title) const;
		math::PointF GetPosition() const;
		void SetPosition(math::PointF pos) const;
		math::PointF GetSize() const;
		void SetSize(math::PointF size) const;
	private:
		id_type _id;
	};
} // namespace ecm

#endif // !_ECM_WINDOW_H_
