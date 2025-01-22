/**
 * \file vector2.h
 *
 * \brief This header defines a two dimensional vector and functionalities.
 */

#pragma once
#ifndef _ECM_VECTOR_EXT_H_
#define _ECM_VECTOR_EXT_H_

#include <ECM/ECM_api.h>
#include <ECM/ECM_stdtypes.h>
#include <ECM/math/vector2.h>
#include <ECM/math/vector3.h>
#include <ECM/math/vector4.h>

#include <type_traits>

namespace ecm::math
{
	// Lerp

	/**
	 * Linearly interpolates between two 2D vectors, \p x and \p y, using a
	 * scalar factor \p t.
	 *
	 * This function computes the interpolation component-wise according to:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 * where \p x and \p y are 2D vectors, and \p t is a scalar.
	 *
	 * \tparam T The type of the elements in vector \p x.
	 * \tparam U The type of the elements in vector \p y.
	 * \tparam W The type of the interpolation factor \p t (must be arithmetic).
	 *
	 * \param x The starting 2D vector.
	 * \param y The ending 2D vector.
	 * \param t The interpolation factor, typically in the range \[0, 1\].
	 *
	 * \returns A 2D vector that is the result of the linear interpolation.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename W, typename = std::enable_if_t<std::is_arithmetic<W>::value>>
	ECM_NODISCARD constexpr Vector2_Base<T> ECM_CALL Lerp(const Vector2_Base<T>& x, const Vector2_Base<U>& y, W t);

	/**
	 * Linearly interpolates between two 3D vectors, \p x and \p y, using a
	 * scalar factor \p t.
	 *
	 * This function computes the interpolation component-wise according to:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 * where \p x and \p y are 3D vectors, and \p t is a scalar.
	 *
	 * \tparam T The type of the elements in vector \p x.
	 * \tparam U The type of the elements in vector \p y.
	 * \tparam W The type of the interpolation factor \p t (must be arithmetic).
	 *
	 * \param x The starting 3D vector.
	 * \param y The ending 3D vector.
	 * \param t The interpolation factor, typically in the range \[0, 1\].
	 *
	 * \returns A 3D vector that is the result of the linear interpolation.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename W, typename = std::enable_if_t<std::is_arithmetic<W>::value>>
	ECM_NODISCARD constexpr Vector3_Base<T> ECM_CALL Lerp(const Vector3_Base<T>& x, const Vector3_Base<U>& y, W t);

	/**
	 * Linearly interpolates between two 4D vectors, \p x and \p y, using a
	 * scalar factor \p t.
	 *
	 * This function computes the interpolation component-wise according to:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 * where \p x and \p y are 4D vectors, and \p t is a scalar.
	 *
	 * \tparam T The type of the elements in vector \p x.
	 * \tparam U The type of the elements in vector \p y.
	 * \tparam W The type of the interpolation factor \p t (must be arithmetic).
	 *
	 * \param x The starting 4D vector.
	 * \param y The ending 4D vector.
	 * \param t The interpolation factor, typically in the range \[0, 1\].
	 *
	 * \returns A 4D vector that is the result of the linear interpolation.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename W, typename = std::enable_if_t<std::is_arithmetic<W>::value>>
	ECM_NODISCARD constexpr Vector4_Base<T> ECM_CALL Lerp(const Vector4_Base<T>& x, const Vector4_Base<U>& y, W t);

	/**
	 * Linearly interpolates between two 2D vectors, \p x and \p y, using a 2D
	 * vector factor \p t.
	 *
	 * This function computes the interpolation component-wise according to:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 * where \p x and \p y are 2D vectors, and \p t is another 2D vector,
	 * allowing for separate interpolation factors per component.
	 *
	 * \tparam T The type of the elements in vector \p x.
	 * \tparam U The type of the elements in vector \p y.
	 * \tparam W The type of the elements in vector \p t.
	 *
	 * \param x The starting 2D vector.
	 * \param y The ending 2D vector.
	 * \param t The 2D interpolation factors, one for each component.
	 *
	 * \returns A 2D vector that is the result of the component-wise linear
	 *          interpolation.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename W>
	ECM_NODISCARD constexpr Vector2_Base<T> ECM_CALL Lerp(const Vector2_Base<T>& x, const Vector2_Base<U>& y, const Vector2_Base<W>& t);

	/**
	 * Linearly interpolates between two 3D vectors, \p x and \p y, using a 3D
	 * vector factor \p t.
	 *
	 * This function computes the interpolation component-wise according to:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 * where \p x and \p y are 3D vectors, and \p t is another 3D vector,
	 * allowing for separate interpolation factors per component.
	 *
	 * \tparam T The type of the elements in vector \p x.
	 * \tparam U The type of the elements in vector \p y.
	 * \tparam W The type of the elements in vector \p t.
	 *
	 * \param x The starting 3D vector.
	 * \param y The ending 3D vector.
	 * \param t The 3D interpolation factors, one for each component.
	 *
	 * \returns A 3D vector that is the result of the component-wise linear
	 *          interpolation.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename W>
	ECM_NODISCARD constexpr Vector3_Base<T> ECM_CALL Lerp(const Vector3_Base<T>& x, const Vector3_Base<U>& y, const Vector3_Base<W>& t);

	/**
	 * Linearly interpolates between two 4D vectors, \p x and \p y, using a 4D
	 * vector factor \p t.
	 *
	 * This function computes the interpolation component-wise according to:
	 * \f[
	 *   \text{Lerp}(x, y, t) = x + t \cdot (y - x)
	 * \f]
	 * where \p x and \p y are 4D vectors, and \p t is another 4D vector,
	 * allowing for separate interpolation factors per component.
	 *
	 * \tparam T The type of the elements in vector \p x.
	 * \tparam U The type of the elements in vector \p y.
	 * \tparam W The type of the elements in vector \p t.
	 *
	 * \param x The starting 4D vector.
	 * \param y The ending 4D vector.
	 * \param t The 4D interpolation factors, one for each component.
	 *
	 * \returns A 4D vector that is the result of the component-wise linear
	 *          interpolation.
	 *
	 * \since v1.0.0
	 */
	template<typename T, typename U, typename W>
	ECM_NODISCARD constexpr Vector4_Base<T> ECM_CALL Lerp(const Vector4_Base<T>& x, const Vector4_Base<U>& y, const Vector4_Base<W>& t);
} // namespace ecm::math

#include "vector_ext.inl"

#endif // !_ECM_VECTOR_EXT_H_
