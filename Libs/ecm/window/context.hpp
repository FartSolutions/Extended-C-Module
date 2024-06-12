/*
 * \file context.h
 *
 * \brief This header defines base graphics functionalitites.
 */

#pragma once
#ifndef _ECM_CONTEXTBASE_H_
#define _ECM_CONTEXTBASE_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>
#include <ecm/math/vector2.hpp>
#include <ecm/types/color.h>

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
	struct ContextBase
	{
		virtual ~ContextBase() = default;
		virtual int32 Initialize(const Window window) = 0;
		virtual void Shutdown() = 0;

		virtual void ClearBuffers() = 0;
		virtual void SwapBuffers() = 0;

		virtual inline void SetColor(const ColorF& color);
		virtual inline void SetFPSLimit(const uint32 limit);
		virtual inline void SetVSyncMode(const int32 vsyncMode);
		virtual inline void SetViewport(const math::PointF& size,
			const math::PointF& pos = { 0.f, 0.f });

		inline ColorF GetColor() const;
		inline uint32 GetFPSLimit() const;
		inline int32 GetVSyncMode() const;
		inline float64 GetDeltaTime() const;
	protected:
		inline ContextBase();

		/*
		 * Limits the FPS if a limit is set and calculates deltatime.
		 *
		 * \since v1.0.0
		 */
		virtual inline void HandleTimings();
	protected:
		ColorF FrameColor;
		uint32 FPSLimit;
		int32 VSyncMode;
		float64 DeltaTime;
		math::PointF ViewportPosition;
		math::PointF ViewportSize;
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

#include "context.inl"

#endif // !_ECM_CONTEXTBASE_H_
