#pragma once
#ifndef _ECM_CONFIGS_H_
#define _ECM_CONFIGS_H_

#define ECM_ALL_DYNAMIC_BUILD 1

#if ECM_ALL_DYNAMIC_BUILD
#define ECM_DYNAMIC_BUILD 1
#else
#define ECM_DYNAMIC_BUILD 0
#endif // ECM_ALL_DYNAMIC_BUILD

#endif // !_ECM_CONFIGS_H_
