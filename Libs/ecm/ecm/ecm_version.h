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
* \file ecm_version.h
* 
* \brief This header defines the current ECM version.
*/

#pragma once
#ifndef _ECM_VERSION_H_
#define _ECM_VERSION_H_

#include "types/stdtypes.h"
#include "ecm_api.h"

/*
 * The version nums of the current version.
 * Format: "%d.%d.%d", MAJOR, MINOR, PATCH
 */
#define ECM_VERSION_MAJOR 1
#define ECM_VERSION_MINOR 0
#define ECM_VERSION_PATCH 0

/*
 * Macro that fills the version structure with the version of the library that
 * you have compiled. Note that if you have dynamicallyed linked this library,
 * you might have a slightly newer or older version at runtime. You can get the
 * version of dynamically linked library if you use ecm::GetVersion(), which,
 * unlike ECM_VERSION(), is not a macro.
 * 
 * \param v A pointer to a ecm::version struct to initialize.
 * 
 * \sa ecm::version
 * \sa ecm::GetVersion
 */
#define ECM_VERSION(v) {				\
	(v)->Major = ECM_VERSION_MAJOR;		\
	(v)->Minor = ECM_VERSION_MINOR;		\
	(v)->Patch = ECM_VERSION_PATCH; }

/*
 * This macro turns the version numbers into a numeric value.
 * (1, 2, 3) -> 0x1000203
 */
#define ECM_VERSIONNUM(major, minor, patch)		\
	((major) << 24 | (minor) << 8 | (patch) << 0)

 /*
  * This macro turns the version structure into a numeric value.
  * (1, 2, 3) -> 0x1000203
  */
#define ECM_VERSIONNUMV(v)								\
	ECM_VERSIONNUM((v).Major, (v).Minor, (v).Patch)

namespace ecm
{
	/*
	 * Stores the current version of the library in use.
	 * 
	 * \since v1.0.0
	 * 
	 * \sa ECM_VERSION
	 * \sa ecm::GetVersion
	 */
	typedef struct version
	{
		uint8 Major;
		uint8 Minor;
		uint8 Patch;
	} version;

	/*
	* Get the version of ECM that is linked against your program.
	* 
	* \since v1.0.0
	* 
	* \returns current compiled version as version struct
	* 
	* \sa \sa ecm::version
	*/
	extern ECM_API version GetVersion(void);

	/*
	* Get the version number of ECM that is linked against your program.
	* 
	* \since v1.0.0
	* 
	* \returns current compiled version as verion number
	*/
	extern ECM_API int32 GetVersionNumber(void);
} // namespace ecm

#endif // !_ECM_VERSION_H_
