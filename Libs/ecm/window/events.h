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
	extern ECM_WIN_API int32 PollEvent(Event& event);
} // namespace ecm

#endif // !_ECM_EVENTS_H_
