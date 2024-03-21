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
 * \file events.h
 *
 * \brief This header defines window event functionalitites.
 */

#pragma once
#ifndef _ECM_EVENTS_H_
#define _ECM_EVENTS_H_

#include <ecm/ecm_api.h>
#include <ecm/types/stdtypes.h>

#include <SDL2/SDL_events.h>

namespace ecm
{
	using Event = SDL_Event;

	/*
	 * \since v1.0.0
	 */
	extern ECM_WIN_API int32 PollEvent(Event* event);
} // namespace ecm

#endif // !_ECM_EVENTS_H_
