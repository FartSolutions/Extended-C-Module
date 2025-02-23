/*
 * \file context.h
 *
 * \brief This header defines a sdl renderer context.
 */

#pragma once
#ifndef _ECM_SDLRENDERER_H_
#define _ECM_SDLRENDERER_H_

#include <ECM/ECM_api.h>
#include <ECM/ECM_stdtypes.h>
#include <ECM/graphics/context.h>

#pragma warning(push)
#pragma warning(disable : 4275)

struct SDL_Renderer;
typedef struct SDL_Renderer SDL_Renderer;

namespace ecm
{
	/*
	 * \since v1.0.0
	 */
	class ECM_WIN_API SDLRendererContext : public ContextBase
	{
	public:
		SDLRendererContext();
		~SDLRendererContext();

		int32 Initialize(const Window window) override;
		void Shutdown() override;

		void ClearBuffers() override;
		void SwapBuffers() override;

		void SetVSyncMode(const int32 vsyncMode) override;
		void SetViewport(const math::PointI& size, const math::PointI& pos) override;
	private:
		SDL_Renderer* _rendererContext;
	};
} // namespace ecm

#pragma warning(pop)

#endif // !_ECM_SDLRENDERER_H_
