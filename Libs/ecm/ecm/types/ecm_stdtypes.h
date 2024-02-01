#pragma once
#ifndef _ECM_STDTYPES_H_
#define _ECM_STDTYPES_H_

#include <string>

namespace ecm
{
	// signed types
	using int8 = char;
	using int16 = short;
	using int32 = int;
	using int64 = long long;
	// unsigned types
	using uint8 = unsigned char;
	using uint16 = unsigned short;
	using uint32 = unsigned int;
	using uint64 = unsigned long long;
	// floating types
	using float32 = float;
	using float64 = double;
	using float128 = long double;
	// string types
	using string = std::string;
	using u16string = std::u16string;
	using u32string = std::u32string;
	using wstring = std::wstring;
} // namespace ecm

#endif // !_ECM_STDTYPES_H_
