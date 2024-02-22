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
 * \file stdtypes.h
 *
 * \brief This header defines some standard types.
 */

#pragma once
#ifndef _ECM_STDTYPES_H_
#define _ECM_STDTYPES_H_

#include <string>

namespace ecm
{
	// signed types
	/*
	 * Defines an signed 8-bit integer type.
	 * Can also be used as char or byte.
	 */
	using int8 = char;
	/*
	 * Defines an signed 16-bit integer type.
	 * Can also be used as wide-char.
	 */
	using int16 = short;
	/*
	 * Defines an signed 32-bit integer type.
	 */
	using int32 = int;
	/*
	 * Defines an signed 64-bit integer type.
	 */
	using int64 = long long;

	// unsigned types
	/*
	 * Defines an unsigned 8-bit integer type.
	 */
	using uint8 = unsigned char;
	/*
	 * Defines an unsigned 16-bit integer type.
	 */
	using uint16 = unsigned short;
	/*
	 * Defines an unsigned 32-bit integer type.
	 */
	using uint32 = unsigned int;
	/*
	 * Defines an unsigned 64-bit integer type.
	 */
	using uint64 = unsigned long long;

	// floating types
	/*
	 * Defines a 32-bit floating type.
	 */
	using float32 = float;
	/*
	 * Defines a 64-bit floating type.
	 */
	using float64 = double;
	/*
	 * Defines a 128-bit floating type.
	 */
	using float128 = long double;

	// string types
	/*
	 * Defines a string type, which is the STL string.
	 */
	using string = std::string;
	/*
	 * Defines a wide-string type, which is the STL wide-string.
	 */
	using wstring = std::wstring;
	/*
	 * Defines a uint16-string type, which is the STL uint16-string.
	 */
	using u16string = std::u16string;
	/*
	 * Defines a uint32-string type, which is the STL uint32-string.
	 */
	using u32string = std::u32string;
} // namespace ecm

#endif // !_ECM_STDTYPES_H_
