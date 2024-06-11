#include <ecm/window/sdlrenderer.h>

#include <ecm/window/window.h>

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

	void SDLRendererContext::Initialize(const Window window)
	{
		_rendererContext = SDL_CreateRenderer(
			window.GetHandle(), -1, SDL_RENDERER_ACCELERATED);
		SetCurrentContext(this);
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
		if (vsyncMode == ecm::VSYNC_ENABLED) vsync = 1;
		SDL_RenderSetVSync(_rendererContext, vsync);
	}

	void SDLRendererContext::SetViewport(const math::Vector2& size,
		const math::Vector2& pos)
	{
		ContextBase::SetViewport(size, pos);
		SDL_Rect rc{};
		rc.x = static_cast<int32>(pos.x);
		rc.y = static_cast<int32>(pos.y);
		rc.w = static_cast<int32>(size.width);
		rc.h = static_cast<int32>(size.height);
		SDL_RenderSetViewport(_rendererContext, &rc);
	}
} // namespace ecm
