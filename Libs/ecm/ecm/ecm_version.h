#pragma once
#ifndef _ECM_VERSION_H_
#define _ECM_VERSION_H_

#include "types/ecm_stdtypes.h"
#include "ecm_api.h"

#define ECM_VERSION_MAJOR 1
#define ECM_VERSION_MINOR 0
#define ECM_VERSION_PATCH 0

#define ECM_VERSION(v)					\
{										\
	(v).Major = ECM_VERSION_MAJOR;		\
	(v).Minor = ECM_VERSION_MINOR;		\
	(v).Patch = ECM_VERSION_PATCH;		\
}

#define ECM_VERSIONNUM(major, minor, patch)		\
	((major) * 1000 + (minor) * 100 + (patch))
#define ECM_VERSIONNUMV(v)								\
	ECM_VERSIONNUM((v).Major, (v).Minor, (v).Patch)

namespace ecm
{
	/*
	* \since v1.0.0
	*/
	typedef struct Version
	{
		uint8 Major;
		uint8 Minor;
		uint8 Patch;
	} Version;

	/*
	* \since v1.0.0
	*/
	extern ECM_API Version GetVersion(void);

	/*
	* \since v1.0.0
	*/
	extern ECM_API int32 GetVersionNumber(void);
} // namespace ecm

#endif // !_ECM_VERSION_H_
