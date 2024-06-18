#pragma once
//#ifndef _ECM_CONTEXTBASE_INL_
//#define _ECM_CONTEXTBASE_INL_

#ifndef _ECM_CONTEXTBASE_H_
#include "context.hpp"
#endif

#include <thread>

namespace ecm
{
	inline void ContextBase::SetColor(const ColorF& color)
	{
		FrameColor = color;
	}

	inline void ContextBase::SetFPSLimit(const uint32 limit)
	{
		FPSLimit = limit;
		if (limit == 0) {
			_frameDuration = std::chrono::milliseconds{ 0 };
		}
		else {
			_frameDuration = std::chrono::milliseconds{ 1000 / limit };
		}
	}

	inline void ContextBase::SetVSyncMode(const int32 vsyncMode)
	{
		VSyncMode = vsyncMode;
	}

	inline void ContextBase::SetViewport(const math::PointI& size, const math::PointI& pos)
	{
		ViewportSize = size;
		ViewportPosition = pos;
	}

	inline ColorF ContextBase::GetColor() const
	{
		return FrameColor;
	}

	inline uint32 ContextBase::GetFPSLimit() const
	{
		return FPSLimit;
	}

	inline int32 ContextBase::GetVSyncMode() const
	{
		return int32();
	}

	inline float64 ContextBase::GetDeltaTime() const
	{
		return DeltaTime;
	}

	inline ContextBase::ContextBase()
	{
		FrameColor = ColorF{ 0x000000ff };
		FPSLimit = 0;
		VSyncMode = VSYNC_DISABLED;
		DeltaTime = 0.016666666666666666666666666;

		_frameDuration = std::chrono::milliseconds{ 0 };
		_frameStartTime = std::chrono::high_resolution_clock::now();
	}

	inline void ContextBase::HandleTimings()
	{
		auto frameEndTime = std::chrono::high_resolution_clock::now();
		auto workDuration = frameEndTime - _frameStartTime;
		// Limit fps
		if (FPSLimit != 0) {
			if (workDuration < _frameDuration) {
				auto sleepDuration = _frameDuration - workDuration;
				std::this_thread::sleep_for(sleepDuration);
			}
		}
		// Calculate deltatime
		std::chrono::duration<float64, std::ratio<1>> duration = workDuration;
		DeltaTime = duration.count();
		// Begin new frame
		_frameStartTime = std::chrono::high_resolution_clock::now();
	}
} // namespace ecm

//#endif // _ECM_CONTEXTBASE_INL_
