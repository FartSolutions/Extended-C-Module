#pragma once
#ifndef _ECM_API_H_
#define _ECM_API_H_

#include "ecm_configs.h"

#if _DEBUG
#define ECM_DEBUG 1
#else
#define ECM_DEBUG 0
#endif

#if _WIN32
#define ECM_OS_WINDOWS 1
#if _WIN64
#define ECM_OS_X64 1
#else
#define ECM_OS_X86 1
#endif // _WIN64
#else
#error No supported platform
#endif // _WIN32

#if ECM_OS_WINDOWS

#if ECM_DYNAMIC_BUILD
#if ECM_DYNAMIC_EXPORT
#define ECM_API __declspec(dllexport)
#else
#define ECM_API __declspec(dllimport)
#endif // ECM_DYNAMIC_EXPORT
#else
#define ECM_API
#endif // ECM_DYNAMIC_BUILD

#if ECM_MATH_DYNAMIC_BUILD
#if ECM_MATH_DYNAMIC_EXPORT
#define ECM_MATH_API __declspec(dllexport)
#else
#define ECM_MATH_API __declspec(dllimport)
#endif // ECM_MATH_DYNAMIC_EXPORT
#else
#define ECM_MATH_API
#endif // ECM_MATH_DYNAMIC_BUILD

#if ECM_ALG_DYNAMIC_BUILD
#if ECM_ALG_DYNAMIC_EXPORT
#define ECM_ALG_API __declspec(dllexport)
#else
#define ECM_ALG_API __declspec(dllimport)
#endif // ECM_ALG_DYNAMIC_EXPORT
#else
#define ECM_ALG_API
#endif // ECM_ALG_DYNAMIC_BUILD

#if ECM_WIN_DYNAMIC_BUILD
#if ECM_WIN_DYNAMIC_EXPORT
#define ECM_WIN_API __declspec(dllexport)
#else
#define ECM_WIN_API __declspec(dllimport)
#endif // ECM_WIN_DYNAMIC_EXPORT
#else
#define ECM_WIN_API
#endif // ECM_WIN_DYNAMIC_BUILD

#if ECM_GL_DYNAMIC_BUILD
#if ECM_GL_DYNAMIC_EXPORT
#define ECM_GL_API __declspec(dllexport)
#else
#define ECM_GL_API __declspec(dllimport)
#endif // ECM_GL_DYNAMIC_EXPORT
#else
#define ECM_GL_API
#endif // ECM_GL_DYNAMIC_BUILD

#endif

#endif // !_ECM_API_H_
