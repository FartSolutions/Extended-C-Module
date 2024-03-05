#include <ecm/types/id.h>

#include <type_traits>

/*
The system is used to enable efficient and secure management of identifiers
(IDs) in software projects. By using generations, IDs can be reused without
causing conflicts with existing or previous instances. This enables efficient
use of memory and avoids problems with overlapping counters. The separation into
index and generation as well as the type safety through macros and debug
structures increase the reliability and maintainability of the code.
*/

namespace ecm
{
	namespace
	{
		/*
		 * These constants divide the id_type into two parts: one for the "generation"
		 * of an ID and one for the "index". This makes it possible to recycle objects
		 * by increasing the generation when an object is reused, while the index
		 * remains the same.
		 */
		//constexpr uint32 generation_bits{ 8 };
		//constexpr uint32 index_bits{
		//	sizeof(id_type) * 8 - generation_bits };

		/*
		 * Bit masks for extracting the index or generation from an ID.
		 */
		//constexpr id_type index_mask{
		//	(id_type{1} << index_bits) - 1 };
		//constexpr id_type generation_mask{
		//	(id_type{1} << generation_bits) - 1 };

		/*
		 * A threshold that specifies how many deleted items must be present before a
		 * purge or reorganization is performed.
		 */
		//constexpr uint32 min_deleted_elements{ 1024 };

		/*
		 * Defines a type for the generation based on the number of bits reserved for
		 * the generation. This type is dynamically selected as u8, u16 or u32,
		 * depending on the number of reserved bits.
		 */
		//using generation_type = std::conditional_t<generation_bits <= 16,
		//	std::conditional_t<generation_bits <= 8, uint8, uint16>, uint32>;

		//static_assert(sizeof(generation_type) * 8 >= generation_bits);
		//static_assert((sizeof(id_type) - sizeof(generation_type)) > 0);
	} // anonymous namespace

	constexpr bool ID_IsValid(const id_type id)
	{
		return id != ID_Invalid;
	}

	constexpr id_type ID_Index(const id_type id)
	{
		id_type index{ id & index_mask };
		ECM_ASSERT(index != index_mask);
		return index;
	}

	constexpr id_type ID_Generation(const id_type id)
	{
		return (id >> index_bits) & generation_mask;
	}

	constexpr id_type ID_NewGeneration(const id_type id)
	{
		const id_type generation{ ID_Generation(id) + 1 };
		ECM_ASSERT(generation < ((uint64)1 << generation_bits) - 1);
		return ID_Index(id) | (generation << index_bits);
	}
} // namespace ecm
