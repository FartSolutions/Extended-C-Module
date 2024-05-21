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
 * \sa version
 * \sa GetVersion
 */
#define ECM_VERSION(v) {				\
	(v)->Major = ECM_VERSION_MAJOR;		\
	(v)->Minor = ECM_VERSION_MINOR;		\
	(v)->Patch = ECM_VERSION_PATCH; }

/*
 * This macro turns the version numbers into a numeric value.
 * (1, 2, 3) -> 0x1000203
 *
 * \sa GetVersionNumber
 */
#define ECM_VERSIONNUM(major, minor, patch)		\
	((major) << 24 | (minor) << 8 | (patch) << 0)

/*
 * This macro turns the version structure into a numeric value.
 * (1, 2, 3) -> 0x1000203
 *
 * \sa GetVersionNumber
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
	 * \sa GetVersion
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
	 * \sa version
	 * \sa GetVersionNumber
	 */
	extern ECM_API version GetVersion(void);

	/*
	 * Get the version number of ECM that is linked against your program.
	 *
	 * \since v1.0.0
	 *
	 * \returns current compiled version as verion number
	 *
	 * \sa GetVersion
	 */
	extern ECM_API int32 GetVersionNumber(void);
} // namespace ecm

#endif // !_ECM_VERSION_H_
