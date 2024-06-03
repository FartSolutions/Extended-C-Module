/*
 * \file functions.hpp
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
	 * This function calculates the absolute value of a given input.
	 *
	 * \param x Input value of type _Ty.
	 *
	 * \returns The absolute value of the input x.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	inline _Ty ECM_CALL Abs(_Ty const x) noexcept;

	/*
	 * This function calculates the factorial of a given input.
	 *
	 * \param n Input value of type _Ty.
	 *
	 * \returns The factorial of the input n.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty>
	inline _Ty ECM_CALL Fact(_Ty const n) noexcept;

	/*
	 * This function calculates the power of a base raised to an exponent.
	 *
	 * \param base The base value of type _Ty_Base.
	 * \param exp The exponent value of type _Ty_Exp.
	 *
	 * \returns The result of raising base to the power of exp.
	 *
	 * \since v1.0.0
	 */
	template<typename _Ty_Base, typename _Ty_Exp>
	inline _Ty_Base ECM_CALL Pow(_Ty_Base const base,
		_Ty_Exp const exp) noexcept;
} // namespace ecm::math

#include "functions.inl"

#endif // !_ECM_FUNCTIONS_H_
