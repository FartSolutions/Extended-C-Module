/*
 * \file context.h
 *
 * \brief This header defines base graphics functionalitites.
 */

#pragma once
#ifndef _ECM_CONTEXTBASE_H_
#define _ECM_CONTEXTBASE_H_

#include <ECM/ECM_api.h>
#include <ECM/ECM_stdtypes.h>
#include <ECM/math/vector.h>
#include <ECM/ECM_color.h>

// TODO: Change to own or boost or other
#include <chrono>

namespace ecm
{
	struct Window;

	/*
	 * \since v1.0.0
	 */
	enum VSyncMode {
		VSYNC_DISABLED,
		VSYNC_ENABLED,
		VSYNC_ADAPTIVE
	};

	/*
	 * \since v1.0.0
	 */
	struct ECM_WIN_API ContextBase
	{
		virtual ~ContextBase() = default;
		virtual int32 Initialize(const Window window) = 0;
		virtual void Shutdown() = 0;

		virtual void ClearBuffers() = 0;
		virtual void SwapBuffers() = 0;

		virtual void SetColor(const ColorF& color);
		virtual void SetFPSLimit(const uint32 limit);
		virtual void SetVSyncMode(const int32 vsyncMode);
		virtual void SetViewport(const math::PointI& size,
			const math::PointI& pos = { 0, 0 });

		ColorF GetColor() const;
		uint32 GetFPSLimit() const;
		int32 GetVSyncMode() const;
		float64 GetDeltaTime() const;
	protected:
		ContextBase();

		/*
		 * Limits the FPS if a limit is set and calculates deltatime.
		 *
		 * \since v1.0.0
		 */
		virtual void HandleTimings();
	protected:
		ColorF FrameColor;
		uint32 FPSLimit;
		int32 VSyncMode;
		float64 DeltaTime;
		math::PointI ViewportPosition;
		math::PointI ViewportSize;
	private:
		std::chrono::milliseconds _frameDuration;
		std::chrono::steady_clock::time_point _frameStartTime;
	};

	/*
	 *
	 *
	 * \since v1.0.0
	 */
	ECM_WIN_API ContextBase* GetCurrentContext();

	/*
	 *
	 *
	 * \since v1.0.0
	 */
	ECM_WIN_API void SetCurrentContext(ContextBase* context);
} // namespace ecm

#endif // !_ECM_CONTEXTBASE_H_
