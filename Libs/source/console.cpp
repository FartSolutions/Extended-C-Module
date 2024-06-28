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
				return -1;
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

	int32 Write(string str, ...)
	{
		int32 retCode{ -1 };
		va_list args;
		va_start(args, str); // Initialize va_list
		if (!(vprintf_s(str.c_str(), args) > 0))
			retCode = ECM_SUCCESS;
		va_end(args); // Clean va_list
		return retCode;
	}

	int32 WriteLine(string str, ...)
	{
		str += "\n";
		int32 retCode{ -1 };
		va_list args;
		va_start(args, str); // Initialize va_list
		if (!(vprintf_s(str.c_str(), args) > 0))
			retCode = ECM_SUCCESS;
		va_end(args); // Clean va_list
		return retCode;
	}

	int32 Write(wstring str, ...)
	{
		int32 retCode{ -1 };
		va_list args;
		va_start(args, str); // Initialize va_list
		if (!(vwprintf_s(str.c_str(), args) > 0))
			retCode = ECM_SUCCESS;
		va_end(args); // Clean va_list
		return retCode;
	}

	int32 WriteLine(wstring str, ...)
	{
		str += L"\n";
		int32 retCode{ -1 };
		va_list args;
		va_start(args, str); // Initialize va_list
		if (!(vwprintf_s(str.c_str(), args) > 0))
			retCode = ECM_SUCCESS;
		va_end(args); // Clean va_list
		return retCode;
	}

	// CONSOLE READER

	int8 ReadKey(void)
	{
		uint16 wChr{ _getwch() };
		wstring wStr{ L"" };
		wStr += wChr;
		Write(wStr);
		int8 chr{ '\0' };
		wctomb_s(0, &chr, 1, wChr);
		return chr;

		/* Vorschlag ChatGPT für Unixsysteme:
		char ReadKeyUnix() {
			struct termios oldt, newt;
			tcgetattr(STDIN_FILENO, &oldt); // Hole aktuelle Terminal-Einstellungen
			newt = oldt; // Kopiere Einstellungen zur Modifikation
			newt.c_lflag &= ~(ICANON | ECHO); // Deaktiviere kanonische Eingabe und Echo
			tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Setze neue Einstellungen sofort
		
			char ch = getchar(); // Lese Zeichen ohne auf Enter zu warten
		
			tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Stelle alte Einstellungen wieder her
			std::cout << ch; // Optional: Echo Zeichen auf der Konsole
			return ch;
		}
		*/
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

	wstring ReadLineW(void)
	{
		wchar_t buf[MAX_PATH]{ L"\0" };
		if (fgetws(buf, MAX_PATH, stdin))
		{
			wstring res{ buf };
			return res.substr(0, res.size() - 2);
		}
		return L"\0";
	}
} // namespace ecm::console
