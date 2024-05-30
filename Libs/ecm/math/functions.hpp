/*
 * \file functions.h
 *
 * \brief This header defines mathematic functionalities.
 */

#pragma once
#ifndef _ECM_FUNCTIONS_H_
#define _ECM_FUNCTIONS_H_

#include <ecm/ecm_api.h>
#include <ecm/ecm_types.hpp>

namespace ecm::math
{
	/*
	 *
	 *
	 * \param n
	 *
	 * \return float128
	 */
	inline constexpr uint64 Fact(int32 n);
} // namespace ecm::math

#include "functions.inl"

#endif // !_ECM_FUNCTIONS_H_
