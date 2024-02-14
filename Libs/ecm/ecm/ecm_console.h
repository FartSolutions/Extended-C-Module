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
 * \file ecm_console.h
 * 
 * \brief This header defines console functionalitites.
 */

#pragma once
#ifndef _ECM_CONSOLE_H_
#define _ECM_CONSOLE_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::console
{
	/*
	 * This structure defines colorcodes for the console fore- and background.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa Write
	 * \sa WriteLine
	 * \sa SetBackround
	 * \sa GetBackround
	 * \sa SetForeround
	 * \sa GetForeround
	 */
	typedef enum class ConsoleColor : uint8
	{
		BLACK = 0x0,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHTGRAY,
		DARKGRAY,
		LIGHTBLUE,
		LIGHTGREEN,
		LIGHTCYAN,
		LIGHTRED,
		LIGHTMAGENTA,
		YELLOW,
		WHITE
	} ConsoleColor;

	/*
	 * \param color the color you set for the console foreground.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa ConsoleColor
	 * \sa GetForeground
	 */
	extern ECM_API int32 SetForeground(ConsoleColor color);

	/*
	 * \returns the current foreground color as ConsoleColor.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa ConsoleColor
	 * \sa SetForeground
	 */
	extern ECM_API ConsoleColor GetForeground(void);

	/*
	 * \param color the color you set for the console background.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa ConsoleColor
	 * \sa GetBackround
	 */
	extern ECM_API int32 SetBackround(ConsoleColor color);

	/*
	 * \returns the current background color as ConsoleColor.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa ConsoleColor
	 * \sa SetBackround
	 */
	extern ECM_API ConsoleColor GetBackround(void);

	/*
	 * \param str the string that is output in the console.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa WriteLine
	 * \sa SetBackround
	 * \sa SetForeround
	 */
	extern ECM_API int32 Write(string str, ...);

	/*
	 * \param str the string that is output in the console.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa Write
	 * \sa SetBackround
	 * \sa SetForeround
	 */
	extern ECM_API int32 WriteLine(string str);

	/*
	 * \param str the string that is output in the console.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa WriteLine
	 * \sa SetBackround
	 * \sa SetForeround
	 */
	extern ECM_API int32 Write(wstring str);

	/*
	 * \param str the string that is output in the console.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa Write
	 * \sa SetBackround
	 * \sa SetForeround
	 */
	extern ECM_API int32 WriteLine(wstring str);

	/*
	 * \returns the key as int8 that was pressed after this funtion was called.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa Write
	 * \sa WriteLine
	 */
	extern ECM_API int8 ReadKey(void);

	/*
	 * \returns everything that was entered in the console when this function
	 *          was called, until the Return key is pressed, without '\n'.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa Write
	 * \sa WriteLine
	 */
	extern ECM_API string ReadLine(void);
} // namespace ecm::console

#endif // !_ECM_CONSOLE_H_
