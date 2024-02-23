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
	 * \since v1.0.0
	 */
	struct ANSI
	{
		static inline constexpr const char* Reset = "\033[0m";

		static inline constexpr const char* FG_Black = "\033[30m";
		static inline constexpr const char* FG_Blue = "\033[34m";
		static inline constexpr const char* FG_Green = "\033[32m";
		static inline constexpr const char* FG_Cyan = "\033[36m";
		static inline constexpr const char* FG_Red = "\033[31m";
		static inline constexpr const char* FG_Magenta = "\033[35m";
		static inline constexpr const char* FG_Brown = "\033[33m";
		static inline constexpr const char* FG_LightGray = "\033[37m";
		static inline constexpr const char* FG_DarkGray = "\033[90m";
		static inline constexpr const char* FG_LightBlue = "\033[94m";
		static inline constexpr const char* FG_LightGreen = "\033[92m";
		static inline constexpr const char* FG_LightCyan = "\033[96m";
		static inline constexpr const char* FG_LightRed = "\033[91m";
		static inline constexpr const char* FG_LightMagenta = "\033[95m";
		static inline constexpr const char* FG_Yellow = "\033[93m";
		static inline constexpr const char* FG_White = "\033[97m";

		static inline constexpr const char* BG_Black = "\033[40m";
		static inline constexpr const char* BG_Blue = "\033[44m";
		static inline constexpr const char* BG_Green = "\033[42m";
		static inline constexpr const char* BG_Cyan = "\033[46m";
		static inline constexpr const char* BG_Red = "\033[41m";
		static inline constexpr const char* BG_Magenta = "\033[45m";
		static inline constexpr const char* BG_Brown = "\033[43m";
		static inline constexpr const char* BG_LightGray = "\033[47m";
		static inline constexpr const char* BG_DarkGray = "\033[100m";
		static inline constexpr const char* BG_LightBlue = "\033[104m";
		static inline constexpr const char* BG_LightGreen = "\033[102m";
		static inline constexpr const char* BG_LightCyan = "\033[106m";
		static inline constexpr const char* BG_LightRed = "\033[101m";
		static inline constexpr const char* BG_LightMagenta = "\033[105m";
		static inline constexpr const char* BG_Yellow = "\033[103m";
		static inline constexpr const char* BG_White = "\033[107m";
	};

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
	extern ECM_API int32 WriteLine(string str, ...);

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
	extern ECM_API int32 Write(wstring str, ...);

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
	extern ECM_API int32 WriteLine(wstring str, ...);

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

	/*
	 * \returns everything that was entered in the console when this function
	 *          was called, until the Return key is pressed, without '\n'.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa Write
	 * \sa WriteLine
	 */
	extern ECM_API wstring ReadLineW(void);
} // namespace ecm::console

#endif // !_ECM_CONSOLE_H_
