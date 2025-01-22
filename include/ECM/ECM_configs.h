#pragma once
#ifndef _ECM_CONFIGS_H_
#define _ECM_CONFIGS_H_

// #############################################################################
// Build configurations

#define ECM_ALL_DYNAMIC_BUILD 1

#if ECM_ALL_DYNAMIC_BUILD
#define ECM_DYNAMIC_BUILD 1
#define ECM_MATH_DYNAMIC_BUILD 1
#define ECM_ALG_DYNAMIC_BUILD 1
#define ECM_WIN_DYNAMIC_BUILD 1
#define ECM_GL_DYNAMIC_BUILD 1
#else
#define ECM_DYNAMIC_BUILD 0
#define ECM_MATH_DYNAMIC_BUILD 0
#define ECM_ALG_DYNAMIC_BUILD 0
#define ECM_WIN_DYNAMIC_BUILD 0
#define ECM_GL_DYNAMIC_BUILD 0
#endif // ECM_ALL_DYNAMIC_BUILD

// #############################################################################
// ID-System configurations

#ifndef ECM_ID_TYPE
#define ECM_ID_TYPE uint32
#endif
#ifndef ECM_ID_GENERATIONBITS
#define ECM_ID_GENERATIONBITS 8
#endif
#ifndef ECM_ID_MINDELELEMENTS
#define ECM_ID_MINDELELEMENTS 1024
#endif

#endif // !_ECM_CONFIGS_H_
