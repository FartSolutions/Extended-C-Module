#include <ecm/ecm_console.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace ecm::console
{
	namespace
	{
		static ConsoleColor foregroundColor{ ConsoleColor::LIGHTGRAY };
		static ConsoleColor BackgroundColor{ ConsoleColor::BLACK };

		inline int32 
			set_console_text_attribute(uint16 attrib)
		{
			HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
			if (SetConsoleTextAttribute(hConsole, attrib) == 0)
			{
				return ECM_FAILED;
			}
			return ECM_SUCCESS;
		}

		inline int32 
			set_console_colors()
		{
			uint8 fg{ static_cast<uint16>(foregroundColor) };
			uint8 bg{ static_cast<uint16>(BackgroundColor) };
			return set_console_text_attribute(fg + (bg << 4));
		}
	} // anonymous namespace

	// CONSOLE FLAGS

	int32 SetForeground(ConsoleColor color)
	{
		foregroundColor = color;
		return set_console_colors();
	}

	ConsoleColor GetForeground()
	{
		return foregroundColor;
	}

	int32 SetBackround(ConsoleColor color)
	{
		BackgroundColor = color;
		return set_console_colors();
	}

	ConsoleColor GetBackround()
	{
		return BackgroundColor;
	}

	// CONSOLE WRITER

	int32 Write(string str)
	{
		if (printf_s(str.c_str()) > 0)
		{
			return ECM_FAILED;
		}
		return ECM_SUCCESS;
	}

	int32 WriteLine(string str)
	{
		return Write(str + "\n");
	}

	int32 Write(wstring str)
	{
		if (wprintf_s(str.c_str()) > 0)
		{
			return ECM_FAILED;
		}
		return ECM_SUCCESS;
	}

	int32 WriteLine(wstring str)
	{
		return Write(str + L"\n");
	}

	// CONSOLE READER

	int8 ReadKey(void)
	{
		uint16 wChr{ _getwch() };
		wstring wStr = L"";
		wStr += wChr;
		Write(wStr);
		int8 chr{ '\0' };
		wctomb_s(0, &chr, 1, wChr);
		return chr;
	}
	
	string ReadLine(void)
	{
		char buf[MAX_PATH]{ "\0" };
		if (fgets(buf, MAX_PATH, stdin))
		{
			string res{ buf };
			return res.substr(0, res.size() - 2);
		}
		return "\0";
	}
} // namespace ecm::console
