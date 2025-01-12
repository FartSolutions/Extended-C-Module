/**
 * \file ecm_api.h
 *
 * \brief This header defines the apis.
 */

#pragma once
#ifndef _ECM_API_H_
#define _ECM_API_H_

#include <ECM/ECM_configs.h>
#include <ECM/ECM_stdinc.h>

// API export/import macros
#if ECM_OS_WINDOWS
#	define ECM_DEF_API_EXPORT __declspec(dllexport)
#	define ECM_DEF_API_IMPORT __declspec(dllimport)
#elif ECM_OS_UNIX
#	define ECM_DEF_API_EXPORT __attribute__((visibility("default")))
#	define ECM_DEF_API_IMPORT __attribute__((visibility("default")))
#else // ECM_OS_UNIX
#	define ECM_DEF_API_EXPORT
#	define ECM_DEF_API_IMPORT
#endif // ECM_OS_WINDOWS

// Dynamic build configuration: ecm.dll
#if ECM_DYNAMIC_BUILD
#	if ECM_DYNAMIC_EXPORT
#		define ECM_API ECM_DEF_API_EXPORT
#	else
#		define ECM_API ECM_DEF_API_IMPORT
#	endif // ECM_DYNAMIC_EXPORT
#else
#	define ECM_API
#endif // ECM_DYNAMIC_BUILD

// Dynamic build configuration: ecm.math.dll
#if ECM_MATH_DYNAMIC_BUILD
#	if ECM_MATH_DYNAMIC_EXPORT
#		define ECM_MATH_API ECM_DEF_API_EXPORT
#	else
#		define ECM_MATH_API ECM_DEF_API_IMPORT
#	endif // ECM_MATH_DYNAMIC_EXPORT
#else
#	define ECM_MATH_API
#endif // ECM_MATH_DYNAMIC_BUILD

// Dynamic build configuration: ecm.algorithm.dll
#if ECM_ALG_DYNAMIC_BUILD
#	if ECM_ALG_DYNAMIC_EXPORT
#		define ECM_ALG_API ECM_DEF_API_EXPORT
#	else
#		define ECM_ALG_API ECM_DEF_API_IMPORT
#	endif // ECM_ALG_DYNAMIC_EXPORT
#else
#	define ECM_ALG_API
#endif // ECM_ALG_DYNAMIC_BUILD

// Dynamic build configuration: ecm.window.dll
#if ECM_WIN_DYNAMIC_BUILD
#	if ECM_WIN_DYNAMIC_EXPORT
#		define ECM_WIN_API ECM_DEF_API_EXPORT
#	else
#		define ECM_WIN_API ECM_DEF_API_IMPORT
#	endif // ECM_WIN_DYNAMIC_EXPORT
#else
#	define ECM_WIN_API
#endif // ECM_WIN_DYNAMIC_BUILD

// Dynamic build configuration: ecm.opengl.dll
#if ECM_GL_DYNAMIC_BUILD
#	if ECM_GL_DYNAMIC_EXPORT
#		define ECM_GL_API ECM_DEF_API_EXPORT
#	else
#		define ECM_GL_API ECM_DEF_API_IMPORT
#	endif // ECM_GL_DYNAMIC_EXPORT
#else
#	define ECM_GL_API
#endif // ECM_GL_DYNAMIC_BUILD

#endif // !_ECM_API_H_
