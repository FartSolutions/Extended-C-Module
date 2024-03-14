#include "ecm/window/window.h"

#include <ecm/container/vector.hpp>
#include <SDL2/SDL.h>
#include <future>

namespace ecm
{
	namespace
	{
		struct window_info
		{
			bool is_active{ false };
			bool is_focused{ false };
			SDL_Window* handle{ nullptr };
			uint32 sdl_id{ ID_Invalid };
			uint8 mode{ WINDOWMODE_NONE };
		};

		container::vector<window_info>	windows;
		container::vector<id_type>		windows_available_slots;

		inline id_type add_to_windows(window_info info)
		{
			id_type id{ ID_Invalid };
			if (windows_available_slots.empty())
			{
				id = id_type(windows.size());
				windows.emplace_back(info);
			}
			else
			{
				id = windows_available_slots.back();
				windows_available_slots.pop_back();
				ECM_ASSERT(id != ID_Invalid);
				windows[id] = info;
			}
			return id;
		}

		inline void remove_from_windows(id_type id)
		{
			ECM_ASSERT(id < windows.size());
			windows_available_slots.emplace_back(id);
		}

		inline id_type get_id_from_sdl_id(const id_type id)
		{
			for (id_type i{ 0 }; i < windows.size(); i++)
			{
				if (windows[i].is_active && i == windows[id].sdl_id) return i;
			}
			return ID_Invalid;
		}

		inline void* get_handle(id_type id)
		{
			return windows[id].handle;
		}

		inline void set_window_mode(id_type id, uint8 mode)
		{
			auto info{ windows[id] };
			if (info.mode == mode) return;
			uint32 flag{ 0 };
			switch (mode)
			{
			case WINDOWMODE_NONE: flag = SDL_WINDOW_SHOWN; break;
			case WINDOWMODE_MINIMIZED: flag = SDL_WINDOW_MINIMIZED; break;
			case WINDOWMODE_MAXIMIZED: flag = SDL_WINDOW_MAXIMIZED; break;
			case WINDOWMODE_FULLSCREEN: flag = SDL_WINDOW_FULLSCREEN; break;
			case WINDOWMODE_FULLSCREEN_WINDOWED: flag = SDL_WINDOW_FULLSCREEN_DESKTOP; break;
			}
			SDL_SetWindowFullscreen(
				static_cast<SDL_Window*>(windows[id].handle), flag);
		}

		inline uint8 get_window_mode(id_type id)
		{
			return windows[id].mode;
		}

		inline void set_focused(id_type id)
		{
			auto info{ windows[id] };
			if (info.is_focused == true) return;
			SDL_RaiseWindow(static_cast<SDL_Window*>(windows[id].handle));
		}

		inline bool get_focused(id_type id)
		{
			return windows[id].is_focused;
		}

		inline void set_title(id_type id, const char* title)
		{
			SDL_SetWindowTitle(
				static_cast<SDL_Window*>(windows[id].handle), title);
		}

		inline const char* get_title(id_type id)
		{
			return SDL_GetWindowTitle(
				static_cast<SDL_Window*>(windows[id].handle));
		}

		inline void set_position(id_type id, math::PointF pos)
		{
			SDL_SetWindowPosition(
				static_cast<SDL_Window*>(windows[id].handle),
				static_cast<int32>(pos.x),
				static_cast<int32>(pos.y));
		}

		inline math::PointF get_position(id_type id)
		{
			int32 x{ 0 }, y{ 0 };
			SDL_GetWindowPosition(
				static_cast<SDL_Window*>(windows[id].handle),
				&x, &y);
			return math::PointF{
				static_cast<float32>(x),
				static_cast<float32>(y) };
		}

		inline void set_size(id_type id, math::PointF size)
		{
			SDL_SetWindowSize(
				static_cast<SDL_Window*>(windows[id].handle),
				static_cast<int32>(size.x),
				static_cast<int32>(size.y));
		}

		inline math::PointF get_size(id_type id)
		{
			int32 w{ 0 }, h{ 0 };
			SDL_GetWindowSize(
				static_cast<SDL_Window*>(windows[id].handle),
				&w, &h);
			return math::PointF{
				static_cast<float32>(w),
				static_cast<float32>(h) };
		}
	} // anonymous namespace

	// #########################################################################
	// Struct Window

	constexpr Window::Window(id_type id)
		: _id{ id }
	{ }

	constexpr Window::Window()
		: _id{ ID_Invalid }
	{ }

	constexpr bool Window::IsValid() const
	{
		return ID_IsValid(_id);
	}
	
	constexpr id_type Window::GetID() const
	{
		return _id;
	}

	void* Window::GetHandle() const
	{
		if (IsValid() && _id < windows.size())
			return get_handle(_id);
		return 0;
	}

	uint8 Window::GetWindowMode() const
	{
		if (IsValid() && _id < windows.size())
			return get_window_mode(_id);
		return uint8(-1);
	}

	void Window::SetWindowMode(uint8 mode) const
	{
		if (IsValid() && _id < windows.size())
			set_window_mode(_id, mode);
	}

	bool Window::IsFocused() const
	{
		if (IsValid() && _id < windows.size())
			return get_focused(_id);
		return false;
	}

	void Window::SetFocused() const
	{
		if (IsValid() && _id < windows.size())
			set_focused(_id);
	}

	const char* Window::GetTitle() const
	{
		if (IsValid() && _id < windows.size())
			return get_title(_id);
		return 0;
	}

	void Window::SetTitle(const char* title) const
	{
		if (IsValid() && _id < windows.size())
			set_title(_id, title);
	}

	math::PointF Window::GetPosition() const
	{
		if (IsValid() && _id < windows.size())
			return get_position(_id);
		return math::PointF{};
	}

	void Window::SetPosition(math::PointF pos) const
	{
		if (IsValid() && _id < windows.size())
			set_position(_id, pos);
	}

	math::PointF Window::GetSize() const
	{
		if (IsValid() && _id < windows.size())
			return get_size(_id);
		return math::PointF{};
	}

	void Window::SetSize(math::PointF size) const
	{
		if (IsValid() && _id < windows.size())
			set_size(_id, size);
	}

	Window CreateWindow(string title, math::PointF size, uint64 flags,
		WindowMode mode, GraphicsAPI graphicsApi)
	{
		if (title.empty()) title = "ECM Window";
		if (size.x <= 0.f) size.x = 800;
		if (size.y <= 0.f) size.y = 600;

		uint32 sdlFlags{ 0 };
		// Set flags for GraphicsApi
		// TODO: Check graphicsApi (SDL flags for OpenGL or Vulkan)

		// Set flags for WindowMode

		// Set flags for Window

		SDL_Window* window = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			static_cast<int32>(size.x), static_cast<int32>(size.y),
			sdlFlags);

		return Window{};
	}
} // namespace ecm
