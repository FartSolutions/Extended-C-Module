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
		virtual void Initialize(const Window window) = 0;
		virtual void Shutdown() = 0;

		virtual void ClearBuffers() = 0;
		virtual void SwapBuffers() = 0;

		virtual void SetColor(const ColorF& color) = 0;
		virtual void SetVsync(const int32 vsyncMode) = 0;
		virtual void SetViewport(const math::Vector2& size,
			const math::Vector2& pos) = 0;
	protected:
		ContextBase() = default;
	};
} // namespace ecm

#endif // !_ECM_CONTEXTBASE_H_
