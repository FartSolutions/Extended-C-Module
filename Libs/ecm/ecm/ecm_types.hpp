#pragma once
#ifndef _ECM_TYPES_HPP_
#define _ECM_TYPES_HPP_

#include "types/stdtypes.h"

#include <assert.h>

#define ECM_ASSERT(ex) assert(ex)
#define ECM_NODISCARD [[nodiscard]]

#ifdef _DEBUG
#define ECM_DEBUGOP(op) op
#else
#define ECM_DEBUGOP(op)
#endif

#endif // !_ECM_TYPES_HPP_
