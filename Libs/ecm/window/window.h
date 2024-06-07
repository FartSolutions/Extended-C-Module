/*
 * \file window.h
 *
 * \brief This header defines window functionalitites.
 */

#pragma once
#ifndef _ECM_WINDOW_H_
#define _ECM_WINDOW_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>
#include <ecm/math/vector2.hpp>

/*
 * \brief For SDL_Window from sdl2.dll.
 *
 * \since v1.0.0
 */
typedef struct SDL_Window SDL_Window;

namespace ecm
{
	/*
	 * \since v1.0.0
	 * 
	 * \sa Window
	 * \sa WindowInitInfo
	 */
	enum WindowMode : uint8
	{
		WINDOWMODE_NONE = 0,
		WINDOWMODE_SHOWN,
		WINDOWMODE_MINIMIZED,
		WINDOWMODE_MAXIMIZED,
		WINDOWMODE_FULLSCREEN_WINDOWED,
		WINDOWMODE_FULLSCREEN,
	} WINDOWMODE_;

	/*
	 * \since v1.0.0
	 * 
	 * \sa Window
	 */
	enum WindowFlag : uint32
	{
		/* window not created by SDL */
		WINDOWFLAG_FOREIGN = ECM_BIT(0),
		/* no window decoration */
		WINDOWFLAG_BORDERLESS = ECM_BIT(1),
		/* window can be resized */
		WINDOWFLAG_RESIZABLE = ECM_BIT(2),
		/* window should be treated as a utility window */
		WINDOWFLAG_UTILITY = ECM_BIT(3),
		/* window should be treated as a tooltip */
		WINDOWFLAG_TOOLTIP = ECM_BIT(4),
		/* window should be treated as a popup menu */
		WINDOWFLAG_POPUP_MENU = ECM_BIT(5),
		WINDOWFLAG_ALLOW_HIGHDPI = ECM_BIT(6),
		/* window should always be above others */
		WINDOWFLAG_ALWAYS_ON_TOP = ECM_BIT(7),
		/* window should not be added to the taskbar */
		WINDOWFLAG_SKIP_TASKBAR = ECM_BIT(8),
		/* window has input focus */
		WINDOWFLAG_INPUT_FOCUS = ECM_BIT(9),
		/* window has mouse focus */
		WINDOWFLAG_MOUSE_FOCUS = ECM_BIT(10),
		/* window has grabbed mouse input */
		WINDOWFLAG_MOUSE_GRABBED = ECM_BIT(11),
		/* window has mouse captured (unrelated to MOUSE_GRABBED) */
		WINDOWFLAG_MOUSE_CAPTURE = ECM_BIT(12),
		/* window has grabbed keyboard input */
		WINDOWFLAG_KEYBOARD_GRABBED = ECM_BIT(13),
		/* equivalent to SDL_WINDOW_MOUSE_GRABBED for compatibility */
		WINDOWFLAG_INPUT_GRABBED = WINDOWFLAG_MOUSE_GRABBED
	};

	/*
	 * \since v1.0.0
	 * 
	 * \sa Window
	 */
	enum GraphicsAPI : uint8
	{
		GRAPHICSAPI_NONE = 0,
		GRAPHICSAPI_SDLRENDERER,
	};

	/*
	 * \since v1.0.0
	 * 
	 * \sa WindowModes
	 * \sa WindowInitInfo
	 */
	struct ECM_WIN_API Window
	{
		/*
		 * \since v1.0.0
		 * 
		 * \sa Window
		 */
		constexpr explicit Window(id_type id);
		/*
		 * \since v1.0.0
		 * 
		 * \sa Window
		 */
		constexpr Window();
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		constexpr bool IsValid() const;
		/*
		 * \returns
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		constexpr id_type GetID() const;
		/*
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		SDL_Window* GetHandle() const;
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		uint8 GetWindowMode() const;
		/*
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		void SetWindowMode(uint8 mode) const;
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		bool IsClosed() const;
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		bool IsFocused() const;
		/*
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		void SetFocused() const;
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		const char* GetTitle() const;
		/*
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		void SetTitle(const char* title) const;
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		math::PointF GetPosition() const;
		/*
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		void SetPosition(math::PointF pos) const;
		/*
		 * \returns 
		 *
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		math::PointF GetSize() const;
		/*
		 * \since v1.0.0
		 *
		 * \sa Window
		 */
		void SetSize(math::PointF size) const;
	private:
		id_type _id;
	};

	/*
	 * \since v1.0.0
	 *
	 * \param title 
	 * \param size 
	 * \param flags 
	 * \param mode 
	 * \param graphicsApi 
	 *
	 * \returns 
	 */
	extern ECM_WIN_API Window CreateWindow(string title,
		math::PointF size, uint64 flags = 0, WindowMode mode = WINDOWMODE_NONE,
		GraphicsAPI graphicsApi = GRAPHICSAPI_NONE);
	// TODO: CreateWindow: replace PointF with Point

	/*
	 * \since v1.0.0
	 *
	 * \param window 
	 */
	extern ECM_WIN_API void DestroyWindow(Window& window);
} // namespace ecm

#endif // !_ECM_WINDOW_H_
