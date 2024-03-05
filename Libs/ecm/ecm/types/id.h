/*
  Extended Cpp Module
  Copyright (C) 2024, Alexander Burkhardt <alexander@fürth.org>

  All rights reserved.

  Use of this source code (the "Software"), except for compilation as part of a
  binary compiled library and its use in conjunction with the binary compiled
  library, without the prior written permission of the copyright owner is
  strictly prohibited. Permission is granted to use the header files of this
  software and to link against the binary compiled library, provided that the
  following conditions are met:

  1. redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
  2. redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

  THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
  OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO
  EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING OUT OF THE USE OF THE SOFTWARE OR ANY OTHER DEALINGS IN THE SOFTWARE.
*/

/*
 * \file id.h
 *
 * \brief This header defines id functionalitites.
 */

#pragma once
#ifndef _ECM_ID_H_
#define _ECM_ID_H_

#include <ecm/ecm_api.h>
#include <type_traits>
#include <cassert>

namespace ecm
{
	/*
	 * Defines the data type for the IDs.
	 *
	 * \since v1.0.0
	 *
	 * \sa ID_Invalid
	 * \sa ID_IsValid
	 * \sa ID_Index
	 * \sa ID_Generation
	 * \sa ID_NewGeneration
	 */
	using id_type = ECM_ID_TYPE;

	/*
	 * A special value for invalid or unassigned IDs.
	 *
	 * \since v1.0.0
	 *
	 * \sa id_type
	 * \sa ID_IsValid
	 */
	constexpr id_type ID_Invalid{ ECM_ID_TYPE(-1) };

	namespace detail
	{
		/*
		 * These constants divide the id_type into two parts: one for the "generation"
		 * of an ID and one for the "index". This makes it possible to recycle objects
		 * by increasing the generation when an object is reused, while the index
		 * remains the same.
		 */
		constexpr uint32 generation_bits{ ECM_ID_GENERATIONBITS };
		constexpr uint32 index_bits{
			sizeof(id_type) * 8 - generation_bits };

		/*
		 * Bit masks for extracting the index or generation from an ID.
		 */
		constexpr id_type index_mask{
			(id_type{1} << index_bits) - 1 };
		constexpr id_type generation_mask{
			(id_type{1} << generation_bits) - 1 };

		/*
		 * A threshold that specifies how many deleted items must be present before a
		 * purge or reorganization is performed.
		 */
		constexpr uint32 min_deleted_elements{ ECM_ID_MINDELELEMENTS };

		/*
		 * Defines a type for the generation based on the number of bits reserved for
		 * the generation. This type is dynamically selected as u8, u16 or u32,
		 * depending on the number of reserved bits.
		 */
		using generation_type = std::conditional_t<generation_bits <= 16,
			std::conditional_t<generation_bits <= 8, uint8, uint16>, uint32>;

		static_assert(sizeof(generation_type) * 8 >= generation_bits);
		static_assert((sizeof(id_type) - sizeof(generation_type)) > 0);
	}

	/*
	 * Checks whether a given Id is valid, i.e. does not equal invalid_id.
	 *
	 * \param id The Id that is checked.
	 *
	 * \returns true if the id is a valid ID or false if not.
	 *
	 * \since v1.0.0
	 *
	 * \sa ID_type
	 * \sa ID_Invalid
	 * \sa ID_Index
	 * \sa ID_Generation
	 * \sa ID_NewGeneration
	 */
	inline constexpr bool ID_IsValid(const id_type id)
	{
		return id != ID_Invalid;
	}

	/*
	 * Extracts the index part of an ID.
	 *
	 * \param id The ID that is used to get the index.
	 *
	 * \returns The extracted index from id.
	 *
	 * \since v1.0.0
	 *
	 * \sa id_type
	 * \sa ID_Invalid
	 * \sa ID_IsValid
	 * \sa ID_Generation
	 * \sa ID_NewGeneration
	 */
	inline constexpr id_type ID_Index(const id_type id)
	{
		id_type index{ id & detail::index_mask };
		assert(index != detail::index_mask);
		return index;
	}

	/*
	 * Extracts the generation part of an ID.
	 *
	 * \param id The ID that is used to get the generation.
	 *
	 * \returns The extracted generation from id.
	 *
	 * \since v1.0.0
	 *
	 * \sa id_type
	 * \sa ID_Invalid
	 * \sa ID_IsValid
	 * \sa ID_Index
	 * \sa ID_NewGeneration
	 */
	inline constexpr id_type ID_Generation(const id_type id)
	{
		return (id >> detail::index_bits) & detail::generation_mask;
	}

	/*
	 * Increases the generation of an ID by 1, but retains the index.
	 * This is used to mark an ID as "renewed" without chaning its position.
	 *
	 * \param id The ID whose generation is increased.
	 *
	 * \returns The id with an increased generation.
	 *
	 * \since v1.0.0
	 *
	 * \sa id_type
	 * \sa ID_Invalid
	 * \sa ID_IsValid
	 * \sa ID_Index
	 * \sa ID_Generation
	 */
	inline constexpr id_type ID_NewGeneration(const id_type id)
	{
		const id_type generation{ ID_Generation(id) + 1 };
		assert(generation < ((uint64)1 << detail::generation_bits) - 1);
		return ID_Index(id) | (generation << detail::index_bits);
	}

#if ECM_DEBUG
	/*
	 * A macro for defining type-safe IDs that uses a structure in debug mode to
	 * ensure type safety and simply uses an alias for id_type in non-debug
	 * mode.
	 *
	 * \param name The name for the id type.
	 *
	 * \since v1.0.0
	 *
	 * \sa id_type
	 * \sa ID_Invalid
	 * \sa ID_IsValid
	 * \sa ID_Index
	 * \sa ID_Generation
	 */
#define ECM_DEFINE_IDTYPE(name)										\
	struct name final {												\
		constexpr explicit name(ecm::id_type id) : _id{ id } { }	\
		constexpr name() : _id{ ecm::ID_Invalid } { }				\
		constexpr operator ecm::id_type() const { return _id; }		\
	private:														\
		ecm::id_type _id; }
#else
	/*
	 * A macro for defining type-safe IDs that uses a structure in debug mode to
	 * ensure type safety and simply uses an alias for id_type in non-debug
	 * mode.
	 *
	 * \param name The name for the id type.
	 *
	 * \since v1.0.0
	 *
	 * \sa id_type
	 * \sa ID_Invalid
	 * \sa ID_IsValid
	 * \sa ID_Index
	 * \sa ID_Generation
	 */
#define ECM_DEFINE_IDTYPE(name) using name = ecm::id_type;
#endif
} // namespace ecm

#endif // !_ECM_ID_H_
