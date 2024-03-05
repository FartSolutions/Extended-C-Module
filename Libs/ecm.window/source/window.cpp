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
		container::vector<id_type>		windows_available_ids;

		inline id_type add_to_windows()
		{
			id_type id{ ID_Invalid };
			return id;
		}

		inline void remove_from_windows(id_type id)
		{

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
} // namespace ecm
