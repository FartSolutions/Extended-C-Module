/*
 * \file events.h
 *
 * \brief This header defines window event functionalitites.
 */

#pragma once
#ifndef _ECM_GLCONTEXT_H_
#define _ECM_GLCONTEXT_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>
#include <ecm/window/context.hpp>

#pragma warning(push)
#pragma warning(disable : 4275)

namespace ecm::gl
{
	/*
	 * \since v1.0.0
	 */
	class ECM_GL_API OpenGLContext : public ContextBase
	{

	};
} // namespace ecm::gl

#pragma warning(pop)

#endif // _ECM_GLCONTEXT_H_
