#include <ECM/graphics/window.h>

#include <ECM/graphics/events.h>

#include <SDL2/SDL.h>
#include <vector>
#include <future>

namespace ecm
{
	namespace
	{
		struct window_info
		{
			bool is_closed{ true };
			bool is_focused{ false };
			SDL_Window* handle{ nullptr };
			uint32 sdl_id{ ID_Invalid };
			uint8 mode{ WINDOWMODE_NONE };
			uint32 style{ 0 };
		};

		std::vector<window_info>	windows;
		std::vector<id_type>		windows_available_slots;

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

		inline window_info get_info_from_id(id_type id)
		{
			if (ID_IsValid(id) && id < windows.size())
				return windows[id];
			return window_info{};
		}

		inline id_type get_id_from_sdl_id(const id_type id)
		{
			for (id_type i{ 0 }; i < windows.size(); i++)
			{
				if (!windows[i].is_closed && id == windows[i].sdl_id) return i;
			}
			return ID_Invalid;
		}

		inline SDL_Window* get_handle(id_type id)
		{
			return windows[id].handle;
		}

		inline void set_window_mode(id_type id, uint8 mode)
		{
			auto& info{ windows[id] };
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
			auto& info{ windows[id] };
			if (info.is_focused == true) return;
			SDL_RaiseWindow(static_cast<SDL_Window*>(windows[id].handle));
		}

		inline bool get_closed(id_type id)
		{
			return windows[id].is_closed;
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

		inline void set_position(id_type id, math::PointI pos)
		{
			SDL_SetWindowPosition(
				static_cast<SDL_Window*>(windows[id].handle),
				pos.x, pos.y);
		}

		inline math::PointI get_position(id_type id)
		{
			math::PointI pos{ 0, 0 };
			SDL_GetWindowPosition(
				static_cast<SDL_Window*>(windows[id].handle),
				&pos.x, &pos.y);
			return pos;
		}

		inline void set_size(id_type id, math::PointI size)
		{
			SDL_SetWindowSize(
				static_cast<SDL_Window*>(windows[id].handle),
				size.x, size.y);
		}

		inline math::PointI get_size(id_type id)
		{
			math::PointI size{ 0, 0 };
			SDL_GetWindowSize(
				static_cast<SDL_Window*>(windows[id].handle),
				&size.width, &size.height);
			return size;
		}

		inline void internal_window_proc(SDL_Event e, uint32 sdlId)
		{
			id_type id{ get_id_from_sdl_id(sdlId) };
			window_info info{ get_info_from_id(id) };
			if (info.is_closed) return;

			if (e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
				info.is_focused = true;
			else if (e.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
				info.is_focused = false;
			else if (e.window.event == SDL_WINDOWEVENT_HIDDEN)
				info.mode = WINDOWMODE_NONE;
			else if (e.window.event == SDL_WINDOWEVENT_SHOWN)
				info.mode = WINDOWMODE_SHOWN;
			else if (e.window.event == SDL_WINDOWEVENT_MINIMIZED)
				info.mode = WINDOWMODE_MINIMIZED;
			else if (e.window.event == SDL_WINDOWEVENT_MAXIMIZED)
				info.mode = WINDOWMODE_MAXIMIZED;
			else if (e.window.event == SDL_WINDOWEVENT_CLOSE)
				windows[id].is_closed = true;
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

	SDL_Window* Window::GetHandle() const
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

	bool Window::IsClosed() const
	{
		if (IsValid() && _id < windows.size())
			return get_closed(_id);
		return true;
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

	math::PointI Window::GetPosition() const
	{
		if (IsValid() && _id < windows.size())
			return get_position(_id);
		return math::PointI{};
	}

	void Window::SetPosition(math::PointI pos) const
	{
		if (IsValid() && _id < windows.size())
			set_position(_id, pos);
	}

	math::PointI Window::GetSize() const
	{
		if (IsValid() && _id < windows.size())
			return get_size(_id);
		return math::PointI{};
	}

	void Window::SetSize(math::PointI size) const
	{
		if (IsValid() && _id < windows.size())
			set_size(_id, size);
	}

	Window CreateWindow(string title, math::PointI size, uint64 flags,
		uint8 mode, GraphicsAPI graphicsApi)
	{
		if (title.empty()) title = "ECM Window";
		if (size.x <= 0) size.x = 800;
		if (size.y <= 0) size.y = 600;

		window_info info{};
		// Set flags for GraphicsApi
		if (graphicsApi == GRAPHICSAPI_OPENGL) info.style |= SDL_WINDOW_OPENGL;
		// TODO: Check graphicsApi (SDL flags for OpenGL or Vulkan)

		// Set flags for WindowMode
		if (mode == WINDOWMODE_NONE) info.style |= SDL_WINDOW_HIDDEN;
		else if (mode == WINDOWMODE_SHOWN) info.style |= SDL_WINDOW_SHOWN;
		else if (mode == WINDOWMODE_MINIMIZED) info.style |= SDL_WINDOW_MINIMIZED;
		else if (mode == WINDOWMODE_MAXIMIZED) info.style |= SDL_WINDOW_MAXIMIZED;
		else if (mode == WINDOWMODE_FULLSCREEN) info.style |= SDL_WINDOW_FULLSCREEN;
		else if (mode == WINDOWMODE_FULLSCREEN_WINDOWED) info.style |= SDL_WINDOW_FULLSCREEN_DESKTOP;

		// Set flags for Window
		if (flags & WINDOWFLAG_FOREIGN) info.style |= SDL_WINDOW_FOREIGN;
		if (flags & WINDOWFLAG_BORDERLESS) info.style |= SDL_WINDOW_BORDERLESS;
		if (flags & WINDOWFLAG_RESIZABLE) info.style |= SDL_WINDOW_RESIZABLE;
		if (flags & WINDOWFLAG_UTILITY) info.style |= SDL_WINDOW_UTILITY;
		if (flags & WINDOWFLAG_TOOLTIP) info.style |= SDL_WINDOW_TOOLTIP;
		if (flags & WINDOWFLAG_POPUP_MENU) info.style |= SDL_WINDOW_POPUP_MENU;
		if (flags & WINDOWFLAG_ALLOW_HIGHDPI) info.style |= SDL_WINDOW_ALLOW_HIGHDPI;
		if (flags & WINDOWFLAG_ALWAYS_ON_TOP) info.style |= SDL_WINDOW_ALWAYS_ON_TOP;
		if (flags & WINDOWFLAG_SKIP_TASKBAR) info.style |= SDL_WINDOW_SKIP_TASKBAR;
		if (flags & WINDOWFLAG_INPUT_FOCUS) info.style |= SDL_WINDOW_INPUT_FOCUS;
		if (flags & WINDOWFLAG_MOUSE_FOCUS) info.style |= SDL_WINDOW_MOUSE_FOCUS;
		if (flags & WINDOWFLAG_MOUSE_GRABBED) info.style |= SDL_WINDOW_MOUSE_GRABBED;
		if (flags & WINDOWFLAG_MOUSE_CAPTURE) info.style |= SDL_WINDOW_MOUSE_CAPTURE;
		if (flags & WINDOWFLAG_KEYBOARD_GRABBED) info.style |= SDL_WINDOW_KEYBOARD_GRABBED;

		info.handle = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			size.x, size.y,
			info.style);

		if (!info.handle) {
			// TODO: ErrorLogging
			return Window{ ID_Invalid };
		}

		info.is_closed = false;
		info.mode = mode;
		info.sdl_id = SDL_GetWindowID(info.handle);

		return Window{ add_to_windows(info) };
	}

	void DestroyWindow(Window& window)
	{
		window_info info{ get_info_from_id(window.GetID()) };
		if (info.handle)
		{
			SDL_DestroyWindow(info.handle);
			remove_from_windows(window.GetID());
			window = Window{};
		}
	}

	int32 PollEvent(Event& e)
	{
		int32 sdlRes{ SDL_PollEvent(&e) };
		if (e.type == SDL_WINDOWEVENT)
			internal_window_proc(e, e.window.windowID);
		return sdlRes;
	}
} // namespace ecm
