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
	 * This enumeration defines colorcodes for the console fore- and background.
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
	 * This structure defines some ansi codes for console formatting.
	 * It should be noted that not every console supports every ansi code.
	 *
	 * \since v1.0.0
	 *
	 * \sa Write
	 * \sa WriteLine
	 */
	struct ANSI
	{
		/* All attributes become turned off */
		static inline constexpr const char* Reset = "\033[0m";
		/* Sets text to bold */
		static inline constexpr const char* Bold = "\033[1m";
		/* Sets text to semi transparent */
		static inline constexpr const char* SemiTransparent = "\033[2m";
		/* Sets text to italic */
		static inline constexpr const char* Italic = "\033[3m";
		/* Sets text to underlined */
		static inline constexpr const char* Underlined = "\033[4m";
		/* Sets text to slow flashing */
		static inline constexpr const char* SlowBlink = "\033[5m";
		/* Sets text to fast flashing */
		static inline constexpr const char* RapidBlink = "\033[6m";
		/* Swaps the fore- and background */
		static inline constexpr const char* Swapped = "\033[7m";
		/* Sets text to invisble */
		static inline constexpr const char* Invisible = "\033[8m";

		/* Sets foreground to black */
		static inline constexpr const char* FG_Black = "\033[30m";
		/* Sets foreground to blue */
		static inline constexpr const char* FG_Blue = "\033[34m";
		/* Sets foreground to green */
		static inline constexpr const char* FG_Green = "\033[32m";
		/* Sets foreground to cyan */
		static inline constexpr const char* FG_Cyan = "\033[36m";
		/* Sets foreground to red */
		static inline constexpr const char* FG_Red = "\033[31m";
		/* Sets foreground to magenta */
		static inline constexpr const char* FG_Magenta = "\033[35m";
		/* Sets foreground to brown */
		static inline constexpr const char* FG_Brown = "\033[33m";
		/* Sets foreground to light gray */
		static inline constexpr const char* FG_LightGray = "\033[37m";
		/* Sets foreground to dark gray */
		static inline constexpr const char* FG_DarkGray = "\033[90m";
		/* Sets foreground to light blue */
		static inline constexpr const char* FG_LightBlue = "\033[94m";
		/* Sets foreground to light green */
		static inline constexpr const char* FG_LightGreen = "\033[92m";
		/* Sets foreground to light cyan */
		static inline constexpr const char* FG_LightCyan = "\033[96m";
		/* Sets foreground to light red */
		static inline constexpr const char* FG_LightRed = "\033[91m";
		/* Sets foreground to light magenta */
		static inline constexpr const char* FG_LightMagenta = "\033[95m";
		/* Sets foreground to yellow */
		static inline constexpr const char* FG_Yellow = "\033[93m";
		/* Sets foreground to white */
		static inline constexpr const char* FG_White = "\033[97m";

		/* Sets background to black */
		static inline constexpr const char* BG_Black = "\033[40m";
		/* Sets background to blue */
		static inline constexpr const char* BG_Blue = "\033[44m";
		/* Sets background to green */
		static inline constexpr const char* BG_Green = "\033[42m";
		/* Sets background to cyan */
		static inline constexpr const char* BG_Cyan = "\033[46m";
		/* Sets background to red */
		static inline constexpr const char* BG_Red = "\033[41m";
		/* Sets background to magenta */
		static inline constexpr const char* BG_Magenta = "\033[45m";
		/* Sets background to brown */
		static inline constexpr const char* BG_Brown = "\033[43m";
		/* Sets background to light gray */
		static inline constexpr const char* BG_LightGray = "\033[47m";
		/* Sets background to dark gray */
		static inline constexpr const char* BG_DarkGray = "\033[100m";
		/* Sets background to light blue */
		static inline constexpr const char* BG_LightBlue = "\033[104m";
		/* Sets background to light green */
		static inline constexpr const char* BG_LightGreen = "\033[102m";
		/* Sets background to light cyan */
		static inline constexpr const char* BG_LightCyan = "\033[106m";
		/* Sets background to light red */
		static inline constexpr const char* BG_LightRed = "\033[101m";
		/* Sets background to light magenta */
		static inline constexpr const char* BG_LightMagenta = "\033[105m";
		/* Sets background to yellow */
		static inline constexpr const char* BG_Yellow = "\033[103m";
		/* Sets background to white */
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
	 * \sa ANSI
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
	 * \sa ANSI
	 * \sa Write
	 * \sa SetBackround
	 * \sa SetForeround
	 */
	extern ECM_API int32 WriteLine(string str = "", ...);

	/*
	 * \param str the string that is output in the console.
	 * 
	 * \returns 0 on success or 1 on failure.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa ANSI
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
	 * \sa ANSI
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
