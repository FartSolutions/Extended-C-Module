#pragma once
#ifndef _ECM_ITERATOR_H_
#define _ECM_ITERATOR_H_

#include <ecm/ecm_types.hpp>

namespace ecm::container
{
	template<typename _Ty>
	class iterator_base
	{
	public:
		using value_type = _Ty;
		using pointer = _Ty*;
		using reference = _Ty&;
		using diffrence_type = std::ptrdiff_t;
		using iterator_category = std::forward_iterator_tag;
	};
} // namespace ecm::container

#endif // !_ECM_ITERATOR_H_
