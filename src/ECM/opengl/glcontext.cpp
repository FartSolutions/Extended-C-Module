#include <ecm/opengl/glcontext.h>

#include <ECM/graphics/window.h>

#include <ECM/opengl/glad_gl4.6.h>
#include <SDL2/SDL.h>

namespace ecm::gl
{
	OpenGLContext::OpenGLContext()
	{
		_glContext = nullptr;
		_parentWindow = nullptr;
	}

	OpenGLContext::~OpenGLContext()
	{
	}

	int32 OpenGLContext::Initialize(const Window window)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		_glContext = SDL_GL_CreateContext(window.GetHandle());
		if (!_glContext) {
			// TODO: ErrorLogging
		}

		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			SDL_GL_DeleteContext(_glContext);
			// TODO: ErrorLogging
		}

		_parentWindow = window.GetHandle();
		SetCurrentContext(this);
		return 0;
	}

	void OpenGLContext::Shutdown()
	{
		SDL_GL_DeleteContext(_glContext);
	}

	void OpenGLContext::ClearBuffers()
	{
		SetCurrentContext(this);
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glClearColor(FrameColor.r, FrameColor.g, FrameColor.b, FrameColor.a);
	}

	void OpenGLContext::SwapBuffers()
	{
		SDL_GL_SwapWindow((SDL_Window*)_parentWindow);
		this->HandleTimings();
		SetCurrentContext(nullptr);
	}

	void OpenGLContext::SetVSyncMode(const int32 vsyncMode)
	{
		ContextBase::SetVSyncMode(vsyncMode);
		int32 vsync{ 0 };
		if (vsyncMode == VSYNC_ENABLED) vsync = 1;
		else if (vsyncMode == VSYNC_ADAPTIVE) vsync = -1;
		SDL_GL_SetSwapInterval(vsync);
	}

	void OpenGLContext::SetViewport(const math::PointI& size, const math::PointI& pos)
	{
		ContextBase::SetViewport(size, pos);
		glViewport(pos.x, pos.y, size.width, size.height);
	}
} // namespace ecm::gl
