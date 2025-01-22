#include <ECM/graphics/sdlrenderer.h>

#include <ECM/graphics/window.h>

#include <SDL2/SDL.h>

namespace ecm
{
	SDLRendererContext::SDLRendererContext()
	{
		_rendererContext = nullptr;
	}

	SDLRendererContext::~SDLRendererContext()
	{
	}

	int32 SDLRendererContext::Initialize(const Window window)
	{
		_rendererContext = SDL_CreateRenderer(
			window.GetHandle(), -1, SDL_RENDERER_ACCELERATED);
		SetCurrentContext(this);
		return 0;
	}

	void SDLRendererContext::Shutdown()
	{
		SDL_DestroyRenderer(_rendererContext);
	}

	void SDLRendererContext::ClearBuffers()
	{
		SetCurrentContext(this);
		ecm::Color c{ FrameColor };
		SDL_SetRenderDrawColor(_rendererContext, c.r, c.g, c.b, c.a);
		SDL_RenderClear(_rendererContext);
	}

	void SDLRendererContext::SwapBuffers()
	{
		SDL_RenderPresent(_rendererContext);
		this->HandleTimings();
		SetCurrentContext(nullptr);
	}

	void SDLRendererContext::SetVSyncMode(const int32 vsyncMode)
	{
		ContextBase::SetVSyncMode(vsyncMode);
		int32 vsync{ 0 };
		if (vsyncMode == VSYNC_ENABLED) vsync = 1;
		else if (vsyncMode == VSYNC_ADAPTIVE) vsync = 1;
		SDL_RenderSetVSync(_rendererContext, vsync);
	}

	void SDLRendererContext::SetViewport(const math::PointI& size,
		const math::PointI& pos)
	{
		ContextBase::SetViewport(size, pos);
		SDL_Rect rc{};
		rc.x = pos.x;
		rc.y = pos.y;
		rc.w = size.width;
		rc.h = size.height;
		SDL_RenderSetViewport(_rendererContext, &rc);
	}
} // namespace ecm
