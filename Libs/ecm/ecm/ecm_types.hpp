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
 * \file ecm_types.hpp
 *
 * \brief This header includes all the public types header.
 */

#pragma once
#ifndef _ECM_TYPES_HPP_
#define _ECM_TYPES_HPP_

#include "types/stdtypes.h"
#include "types/color.h"
#include "types/id.h"

#include <assert.h>

#define ECM_SUCCESS 0
#define ECM_FAILED 1

#define ECM_BIT(x) (1 << x)
#define ECM_ASSERT(ex) assert(ex)
#define ECM_NODISCARD [[nodiscard]]

#if ECM_DEBUG
#define ECM_DEBUGOP(op) op
#else
#define ECM_DEBUGOP(op)
#endif

#endif // !_ECM_TYPES_HPP_
