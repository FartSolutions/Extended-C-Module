/*
 * \file ecm_stdinc.hpp
 *
 * \brief This header defines standard macros.
 */

#pragma once
#ifndef _ECM_STDINC_HPP_
#define _ECM_STDINC_HPP_

// Check C++ standards
#if defined(_MSVC_LANG)
#	if _MSVC_LANG >= 202002L
#		define ECM_HAS_CXX20 1
#	endif
#	if _MSVC_LANG >= 201703L
#		define ECM_HAS_CXX17 1
#	endif
#	if _MSVC_LANG >= 201402L
#		define ECM_HAS_CXX14 1
#	endif
#elif defined(__cplusplus)
#	if __cplusplus >= 202002L
#		define ECM_HAS_CXX20 1
#	endif
#	if __cplusplus >= 201703L
#		define ECM_HAS_CXX17 1
#	endif
#	if __cplusplus >= 201402L
#		define ECM_HAS_CXX14 1
#	endif
#endif // _MSVC_LANG

#ifndef ECM_HAS_CXX14
#	define ECM_HAS_CXX14 0
#endif // !ECM_HAS_CXX14
#ifndef ECM_HAS_CXX17
#	define ECM_HAS_CXX17 0
#endif // !ECM_HAS_CXX17
#ifndef ECM_HAS_CXX20
#	define ECM_HAS_CXX20 0
#endif // !ECM_HAS_CXX20

// OS and architechture configuration
#if defined(_WIN32) || defined(_MSC_VER)
// Configuration for Windows
#	define ECM_OS_WINDOWS 1
#	if defined(_WIN64)
#		define ECM_OS_X64 1
#	else
#		define ECM_OS_X86 1
#	endif // _WIN64
#elif defined(__GNUC__) || defined(__clang__)
// Configuration for UNIX
#	define ECM_OS_UNIX 1
#	if defined(__x86_64__) || defined(_M_X64) || defined(__ppc64__) || defined(__aarch64__) || defined(_WIN64)
#		define ECM_OS_X64 1
#	else
#		define ECM_OS_X86 1
#	endif // Check of 64-bit os
#else // __GNUC__
#	error No supported platform
#endif // _WIN32

// Debug configuration
#if defined(_DEBUG)
#	define ECM_DEBUG 1
#else
#	define ECM_DEBUG 0
#endif // _DEBUG

// ECM debug operation
#if ECM_DEBUG
#	define ECM_DEBUGOP(op) op
#else
#	define ECM_DEBUGOP(op)
#endif

// ECM assertion
#if ECM_DEBUG
#	include <assert.h>
#	define ECM_ASSERT(ex) assert(ex)
#else
#	define ECM_ASSERT(ex)
#endif // ECM_DEBUG

#define ECM_FALSE 0
#define ECM_TRUE 1
#define ECM_SUCCESS ECM_FALSE

#define ECM_SUCCEEDED(ret) (ret == ECM_SUCCESS)
#define ECM_FAILED(ret) (!ECM_SUCCEEDED(ret))

#define ECM_BIT(x) (1 << x)

#define ECM_FILE __FILE__
#define ECM_LINE __LINE__

// ECM alignement
#if ECM_OS_WINDOWS
#	define ECM_ALIGN(bytes) __declspec(align(bytes))
#	define ECM_ALIGNEDSTRUCT(bytes) struct ECM_ALIGN(bytes)
#	define ECM_ALIGNEDCLASS(bytes) class ECM_ALIGN(bytes)
#elif ECM_OS_UNIX
#	define ECM_ALIGN(bytes) __attribute__((aligned(bytes)))
#	define ECM_ALIGNEDSTRUCT(bytes) struct ECM_ALIGN(bytes)
#	define ECM_ALIGNEDCLASS(bytes) class ECM_ALIGN(bytes)
#else // ECM_OS_UNIX
#	define ECM_ALIGN(bytes)
#	define ECM_ALIGNEDSTRUCT(bytes) struct
#	define ECM_ALIGNEDCLASS(bytes) class
#endif // ECM_OS_WINDOWS

// ECM function calls
#if ECM_OS_WINDOWS
#	define ECM_CALL __cdecl
#	define ECM_STDCALL __stdcall
#elif ECM_OS_UNIX
#	define ECM_CALL __attribute__((cdecl))
#	define ECM_STDCALL __attribute__((stdcall))
#else // ECM_OS_UNIX
#	define ECM_CALL
#	define ECM_STDCALL
#endif // ECM_OS_WINDOWS

// Inline
#define ECM_INLINE inline
// Force inline
#if ECM_OS_WINDOWS
#	define ECM_FORCEINLINE __forceinline
#elif ECM_OS_UNIX
#	define ECM_FORCEINLINE inline __attribute__((always_inline))
#else
#	define ECM_FORCEINLINE ECM_INLINE
#endif // ECM_OS_WINDOWS

// Standard attribute deprecated
#if ECM_HAS_CXX17
#	define ECM_DEPRECATED(ex) [[deprecated(ex)]]
#elif ECM_HAS_CXX14
#	define ECM_DEPRECATED [[deprecated]]
#else
#	define ECM_DEPRECATED
#endif
// Standard attribute nodiscard
#if ECM_HAS_CXX20
#	define ECM_NODISCARD(ex) [[nodiscard(ex)]]
#elif ECM_HAS_CXX17
#	define ECM_NODISCARD [[nodiscard]]
#else
#	define ECM_NODISCARD
#endif
// Standard attribute maybe_unused
#if ECM_HAS_CXX17
#	define ECM_MAYBEUNUSED [[maybe_unused]]
#else
#	define ECM_MAYBEUNUSED
#endif
// Standard attribute fallthrough
#if ECM_HAS_CXX17
#	define ECM_FALLTHROUGH [[fallthrough]]
#else
#	define ECM_FALLTHROUGH
#endif
// Standard attribute likely/unlikely
#if ECM_HAS_CXX20
#	define ECM_LIKELY [[likely]]
#	define ECM_UNLIKELY [[unlikely]]
#else
#	define ECM_LIKELY
#	define ECM_UNLIKELY
#endif
// Standard attribute noreturn
#if ECM_OS_WINDOWS
#	define ECM_NORETURN __declspec(noreturn)
#elif ECM_OS_UNIX
#	define ECM_NORETURN __attribute__((noreturn))
#else // ECM_OS_UNIX
#	define ECM_NORETURN
#endif // ECM_OS_WINDOWS

#endif // !_ECM_STDINC_HPP_
