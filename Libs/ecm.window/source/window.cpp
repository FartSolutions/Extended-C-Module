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
			SDL_Window* handle{ nullptr };
			uint32 sdl_id{ ID_Invalid };
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
		return 0;
	}

	uint8 Window::GetWindowMode() const
	{
		return 0;
	}

	void Window::SetWindowMode(uint8 mode) const
	{

	}

	bool Window::IsFocused() const
	{
		return false;
	}

	void Window::SetFocused() const
	{

	}

	const char* Window::GetTitle() const
	{
		return 0;
	}

	void Window::SetTitle(const char* title) const
	{

	}

	math::PointF Window::GetPosition() const
	{
		return math::PointF{};
	}

	void Window::SetPosition(math::PointF pos) const
	{

	}

	math::PointF Window::GetSize() const
	{
		return math::PointF{};
	}

	void Window::SetSize(math::PointF size) const
	{

	}
} // namespace ecm
