#pragma once
#ifndef _ECM_VECTOR_H_
#define _ECM_VECTOR_H_

#include <ecm/ecm_types.hpp>
#include <ecm/container/iterator.hpp>
#include <xutility>
#include <iostream>

namespace ecm::container
{
	template<typename _Ty>
	class vector_iterator : public iterator_base<_Ty>
	{
		using base = iterator_base<_Ty>;
	public:
		using pointer = typename base::pointer;
		using reference = typename base::reference;
	private:
		pointer _ptr;
	public:
		vector_iterator(pointer ptr)
			: _ptr{ ptr }
		{ }

		ECM_NODISCARD constexpr reference operator*() const
		{
			return *_ptr;
		}
		ECM_NODISCARD constexpr pointer operator->()
		{
			return _ptr;
		}
		// Prefix increment
		constexpr vector_iterator& operator++()
		{
			_ptr++;
			return *this;
		}
		// Postfix increment
		constexpr vector_iterator operator++(int)
		{
			vector_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		friend bool operator==
			(const vector_iterator& a, const vector_iterator& b)
		{
			return a._ptr == b._ptr;
		}
		friend bool operator!=
			(const vector_iterator& a, const vector_iterator& b)
		{
			return a._ptr != b._ptr;
		}
	};

	template<typename _Ty, bool destruct = true>
	class vector
	{
	public:
		// Default contructor. Doesn't allocate memory.
		vector() = default;
		// Constructor resizes the vector and initializes 'count' items.
		constexpr vector(uint32 count)
		{
			resize(count);
		}
		// Constructor resizes the vector and initializes 'count' items using 
		// 'value'.
		constexpr explicit vector(uint64 count, const _Ty& value)
		{
			resize(count, value);
		}

		template<typename _It, std::enable_if_t<std::_Is_iterator_v<_It>, int> = 0>
		constexpr explicit vector(_It first, _It last)
		{
			for (; first != last; ++first)
			{
				emplace_back(*first);
			}
		}
		// Copy-constructor. Constructs by copying another vector. The items in
		// the copied vector must be copyable.
		constexpr vector(const vector& o)
		{
			*this = o;
		}
		// Move-constructor. Constructs by moving another vector.
		// The original vector will be empty after move.
		constexpr vector(vector&& o)
			: _capacity{ o._capacity }, _size{ o._size }, _data{ o._data }
		{
			o.reset();
		}
		// Destructs the vector and its items as specified in template argument
		~vector()
		{
			destroy();
		}
		// Copy-assignment operator. Clears this vector and copies items from
		// another vector. The items must be copyable.
		constexpr vector& operator=(const vector& o)
		{
			ECM_ASSERT(this != std::addressof(o));
			if (this != std::addressof(o))
			{
				clear();
				reserve(o._size);
				for (auto& item : o)
				{
					emplace_back(item);
				}
				ECM_ASSERT(_size == o._size);
			}
			return *this;
		}
		// Move-assignment operator. Frees all resources in this vector and
		// moves the other vector into this one.
		constexpr vector& operator=(vector&& o)
		{
			ECM_ASSERT(this != std::addressof(o));
			if (this != std::addressof(o))
			{
				destroy();
				move(o);
			}
			return *this;
		}
		// Inserts an item at the end of the vector by copying 'value'.
		constexpr void push_back(const _Ty& value)
		{
			emplace_back(value);
		}
		// Inserts an item at the end of the vector by copying 'value'.
		constexpr void push_back(const _Ty&& value)
		{
			emplace_back(std::move(value));
		}
		// Copy- or move-constructs an item at the end of the vector.
		template<typename... params>
		constexpr decltype(auto) emplace_back(params&&... p)
		{
			if (_size == _capacity)
			{
				// Reserve 50% more
				reserve(((_capacity + 1) * 3) >> 1);
			}
			ECM_ASSERT(_size < _capacity);
			_Ty* const item{ new (std::addressof(_data[_size]))
								 _Ty(std::forward<params>(p)...) };
			++_size;
			return *item;
		}
		// Resizes the vector and initializes new items with their default
		// value.
		constexpr void resize(uint64 new_size)
		{
			static_assert(std::is_default_constructible<_Ty>::value,
				"Type must be default-constructible.");
			if (new_size > _size)
			{
				reserve(new_size);
				while (_size < new_size)
				{
					emplace_back();
				}
			}
			else if (new_size < _size)
			{
				if constexpr (destruct)
				{
					destruct_range(new_size, _size);
				}
				_size = new_size;
			}
			// Do nothing if new_size == _size.
			ECM_ASSERT(new_size == _size);
		}
		// Resizes the vector and initializes new items by copying 'value'.
		constexpr void resize(uint64 new_size, const _Ty& value)
		{
			static_assert(std::is_copy_constructible<_Ty>::value,
				"Type must be copy-constructible.");
			if (new_size > _size)
			{
				reserve(new_size);
				while (_size < new_size)
				{
					emplace_back(value);
				}
			}
			else if (new_size < _size)
			{
				if constexpr (destruct)
				{
					destruct_range(new_size, _size);
				}
				_size = new_size;
			}
			// Do nothing if new_size == _Size.
			ECM_ASSERT(new_size == _size);
		}
		// Allocates memory to contain the specified number of items.
		constexpr void reserve(uint64 new_capacity)
		{
			if (new_capacity > _capacity)
			{
				// NOTE: realoc() will automatically copy the data in the buffer
				//       if a new region of memory is allocated.
				void* new_buffer{ realloc(_data,new_capacity * sizeof(_Ty)) };
				ECM_ASSERT(new_buffer);
				if (new_buffer)
				{
					_data = static_cast<_Ty*>(new_buffer);
					_capacity = new_capacity;
				}
			}
		}
		// Removes the item at specified index.
		constexpr _Ty* const erase(uint64 index)
		{
			ECM_ASSERT(_data && index < _size);
			return erase(std::addressof(_data[index]));
		}
		// Removes the item at a specified location.
		constexpr _Ty* const erase(_Ty* const item)
		{
			ECM_ASSERT(_data && item >= std::addressof(_data[0]) &&
				item < std::addressof(_data[_size]));
			if constexpr (destruct) item->~_Ty();
			--_size;
			if (item < std::addressof(_data[_size]))
			{
				memcpy(item, item + 1,
					(std::addressof(_data[_size]) - item) * sizeof(_Ty));
			}
			return item;
		}
		// Same as erase() but faster because it just copies the last item.
		constexpr _Ty* const erase_unordered(uint64 index)
		{
			ECM_ASSERT(_data && index < _size);
			return erase_unordered(std::addressof(_data[index]));
		}
		// Same as erase() but faster because it just copies the last item.
		constexpr _Ty* const erase_unordered(_Ty* const item)
		{
			ECM_ASSERT(_data && item >= std::addressof(_data[0]) &&
				item < std::addressof(_data[_size]));
			if constexpr (destruct) item->~_Ty();
			--_size;
			if (item < std::addressof(_data[_size]))
			{
				memcpy(item, std::addressof(_data[_size]), sizeof(_Ty));
			}
			return item;
		}
		// Clears the vector and destructs items as specified in template
		// argument.
		constexpr void clear()
		{
			if constexpr (destruct)
			{
				destruct_range(0, _size);
			}
			_size = 0;
		}
		// Swaps two vectors.
		constexpr void swap(vector& o)
		{
			if (this != std::addressof(o))
			{
				auto temp{ std::move(o) };
				o.move(*this);
				move(temp);
			}
		}
		// Pointer to the start of data. Might be null.
		ECM_NODISCARD constexpr _Ty* data()
		{
			return _data;
		}
		// Pointer to the start of data. Might be null.
		ECM_NODISCARD constexpr _Ty* const data() const
		{
			return _data;
		}
		// Returns true if vector is empty.
		ECM_NODISCARD constexpr bool empty() const
		{
			return _size = 0;
		}
		// Returns the number of items in the vector.
		ECM_NODISCARD constexpr uint64 size() const
		{
			return _size;
		}
		// Returns the current capacity of the vector.
		ECM_NODISCARD constexpr uint64 capacity() const
		{
			return _capacity;
		}
		// Indexing operator. Returns a reference to the item at specified
		// index.
		ECM_NODISCARD constexpr _Ty& operator[](uint64 index)
		{
			ECM_ASSERT(_data && index < _size);
			return _data[index];
		}
		// Indexing operator. Returns a constant reference to the item at
		// specified index.
		ECM_NODISCARD constexpr const _Ty& operator[](uint64 index) const
		{
			ECM_ASSERT(_data && index < _size);
			return _data[index];
		}
		// Returns a reference to the first item. Will fault the application if
		// called when the vector is empty.
		ECM_NODISCARD constexpr _Ty& front()
		{
			ECM_ASSERT(_data && _size);
			return _data[0];
		}
		// Returns a constant reference to the first item. Will fault the
		// application if called when the vector is empty.
		ECM_NODISCARD constexpr const _Ty& front() const
		{
			ECM_ASSERT(_data && _size);
			return _data[0];
		}
		// Returns a reference to the last item. Will fault the application if
		// called when the vector is empty.
		ECM_NODISCARD constexpr _Ty& back()
		{
			ECM_ASSERT(_data && _size);
			return _data[_size - 1];
		}
		// Returns a constant reference to the last item. Will fault the
		// application if called when the vector is empty.
		ECM_NODISCARD constexpr const _Ty& back() const
		{
			ECM_ASSERT(_data && _size);
			return _data[_size - 1];
		}
		// Returns a pointer to the first item. Returns null when vector is
		// empty.
		ECM_NODISCARD constexpr _Ty* begin()
		{
			return std::addressof(_data[0]);
		}
		// Returns a constant pointer to the first item. Returns null when
		// vector is empty.
		ECM_NODISCARD constexpr const _Ty* begin() const
		{
			return std::addressof(_data[0]);
		}
		// Returns a pointer to the last item. Returns null when vector is
		// empty.
		ECM_NODISCARD constexpr _Ty* end()
		{
			ECM_ASSERT(!(_data == nullptr && _size > 0));
			return std::addressof(_data[_size]);
		}
		// Returns a constant pointer to the last item. Returns null when vector
		// is empty.
		ECM_NODISCARD constexpr const _Ty* end() const
		{
			ECM_ASSERT(!(_data == nullptr && _size > 0));
			return std::addressof(_data[_size]);
		}
	private:
		constexpr void move(vector& o)
		{
			_capacity = o._capacity;
			_size = o._size;
			_data = o._data;
			o.reset();
		}
		constexpr void reset()
		{
			_capacity = 0;
			_size = 0;
			_data = nullptr;
		}
		constexpr void destruct_range(uint64 first, uint64 last)
		{
			ECM_ASSERT(destruct);
			ECM_ASSERT(first <= _size && last <= _size && first <= last);
			if (_data)
			{
				for (; first != last; ++first)
				{
					_data[first].~_Ty();
				}
			}
		}
		constexpr void destroy()
		{
			ECM_ASSERT([&]
				{ return _capacity ? _data != nullptr : _data == nullptr; }());
			clear();
			_capacity = 0;
			if (_data) free(_data);
			_data = nullptr;
		}
	private:
		uint64	_capacity{ 0 };
		uint64	_size{ 0 };
		_Ty*	_data{ nullptr };
	};

	template<typename _Ty, bool destruct = true>
	class vector_it
	{
	public:
		using iterator = vector_iterator<_Ty>;
	public:
		// Default contructor. Doesn't allocate memory.
		vector_it() = default;
		// Constructor resizes the vector and initializes 'count' items.
		constexpr vector_it(uint32 count)
		{
			resize(count);
		}
		// Constructor resizes the vector and initializes 'count' items using 
		// 'value'.
		constexpr explicit vector_it(uint64 count, const _Ty& value)
		{
			resize(count, value);
		}

		template<typename _It, std::enable_if_t<std::_Is_iterator_v<_It>, int> = 0>
		constexpr explicit vector_it(_It first, _It last)
		{
			for (; first != last; ++first)
			{
				emplace_back(*first);
			}
		}
		// Copy-constructor. Constructs by copying another vector. The items in
		// the copied vector must be copyable.
		constexpr vector_it(const vector_it& o)
		{
			*this = o;
		}
		// Move-constructor. Constructs by moving another vector.
		// The original vector will be empty after move.
		constexpr vector_it(vector_it&& o)
			: _capacity{ o._capacity }, _size{ o._size }, _data{ o._data }
		{
			o.reset();
		}
		// Destructs the vector and its items as specified in template argument
		~vector_it()
		{
			destroy();
		}
		// Copy-assignment operator. Clears this vector and copies items from
		// another vector. The items must be copyable.
		constexpr vector_it& operator=(const vector_it& o)
		{
			ECM_ASSERT(this != std::addressof(o));
			if (this != std::addressof(o))
			{
				clear();
				reserve(o._size);
				for (auto& item : o)
				{
					emplace_back(item);
				}
				ECM_ASSERT(_size == o._size);
			}
			return *this;
		}
		// Move-assignment operator. Frees all resources in this vector and
		// moves the other vector into this one.
		constexpr vector_it& operator=(vector_it&& o)
		{
			ECM_ASSERT(this != std::addressof(o));
			if (this != std::addressof(o))
			{
				destroy();
				move(o);
			}
			return *this;
		}
		// Inserts an item at the end of the vector by copying 'value'.
		constexpr void push_back(const _Ty& value)
		{
			emplace_back(value);
		}
		// Inserts an item at the end of the vector by copying 'value'.
		constexpr void push_back(const _Ty&& value)
		{
			emplace_back(std::move(value));
		}
		// Copy- or move-constructs an item at the end of the vector.
		template<typename... params>
		constexpr decltype(auto) emplace_back(params&&... p)
		{
			if (_size == _capacity)
			{
				// Reserve 50% more
				reserve(((_capacity + 1) * 3) >> 1);
			}
			ECM_ASSERT(_size < _capacity);
			_Ty* const item{ new	(std::addressof(_data[_size]))
									_Ty(std::forward<params>(p)...) };
			++_size;
			return *item;
		}
		// Resizes the vector and initializes new items with their default
		// value.
		constexpr void resize(uint64 new_size)
		{
			static_assert(std::is_default_constructible<_Ty>::value,
				"Type must be default-constructible.");
			if (new_size > _size)
			{
				reserve(new_size);
				while (_size < new_size)
				{
					emplace_back();
				}
			}
			else if (new_size < _size)
			{
				if constexpr (destruct)
				{
					destruct_range(new_size, _size);
				}
				_size = new_size;
			}
			// Do nothing if new_size == _size.
			ECM_ASSERT(new_size == _size);
		}
		// Resizes the vector and initializes new items by copying 'value'.
		constexpr void resize(uint64 new_size, const _Ty& value)
		{
			static_assert(std::is_copy_constructible<_Ty>::value,
				"Type must be copy-constructible.");
			if (new_size > _size)
			{
				reserve(new_size);
				while (_size < new_size)
				{
					emplace_back(value);
				}
			}
			else if (new_size < _size)
			{
				if constexpr (destruct)
				{
					destruct_range(new_size, _size);
				}
				_size = new_size;
			}
			// Do nothing if new_size == _Size.
			ECM_ASSERT(new_size == _size);
		}
		// Allocates memory to contain the specified number of items.
		constexpr void reserve(uint64 new_capacity)
		{
			if (new_capacity > _capacity)
			{
				// NOTE: realoc() will automatically copy the data in the buffer
				//       if a new region of memory is allocated.
				void* new_buffer{ realloc(_data,new_capacity * sizeof(_Ty)) };
				ECM_ASSERT(new_buffer);
				if (new_buffer)
				{
					_data = static_cast<_Ty*>(new_buffer);
					_capacity = new_capacity;
				}
			}
		}
		// Removes the item at specified index.
		constexpr _Ty* const erase(uint64 index)
		{
			ECM_ASSERT(_data && index < _size);
			return erase(std::addressof(_data[index]));
		}
		// Removes the item at a specified location.
		constexpr _Ty* const erase(_Ty* const item)
		{
			ECM_ASSERT(_data && item >= std::addressof(_data[0]) &&
				item < std::addressof(_data[_size]));
			if constexpr (destruct) item->~_Ty();
			--_size;
			if (item < std::addressof(_data[_size]))
			{
				memcpy(item, item + 1,
					(std::addressof(_data[_size]) - item) * sizeof(_Ty));
			}
			return item;
		}
		// Same as erase() but faster because it just copies the last item.
		constexpr _Ty* const erase_unordered(uint64 index)
		{
			ECM_ASSERT(_data && index < _size);
			return erase_unordered(std::addressof(_data[index]));
		}
		// Same as erase() but faster because it just copies the last item.
		constexpr _Ty* const erase_unordered(_Ty* const item)
		{
			ECM_ASSERT(_data && item >= std::addressof(_data[0]) &&
				item < std::addressof(_data[_size]));
			if constexpr (destruct) item->~_Ty();
			--_size;
			if (item < std::addressof(_data[_size]))
			{
				memcpy(item, std::addressof(_data[_size]), sizeof(_Ty));
			}
			return item;
		}
		// Clears the vector and destructs items as specified in template
		// argument.
		constexpr void clear()
		{
			if constexpr (destruct)
			{
				destruct_range(0, _size);
			}
			_size = 0;
		}
		// Swaps two vectors.
		constexpr void swap(vector_it& o)
		{
			if (this != std::addressof(o))
			{
				auto temp{ std::move(o) };
				o.move(*this);
				move(temp);
			}
		}
		// Pointer to the start of data. Might be null.
		ECM_NODISCARD constexpr _Ty* data()
		{
			return _data;
		}
		// Pointer to the start of data. Might be null.
		ECM_NODISCARD constexpr _Ty* const data() const
		{
			return _data;
		}
		// Returns true if vector is empty.
		ECM_NODISCARD constexpr bool empty() const
		{
			return _size = 0;
		}
		// Returns the number of items in the vector.
		ECM_NODISCARD constexpr uint64 size() const
		{
			return _size;
		}
		// Returns the current capacity of the vector.
		ECM_NODISCARD constexpr uint64 capacity() const
		{
			return _capacity;
		}
		// Indexing operator. Returns a reference to the item at specified
		// index.
		ECM_NODISCARD constexpr _Ty* operator[](uint64 index)
		{
			ECM_ASSERT(_data && index < _size);
			return _data[index];
		}
		// Indexing operator. Returns a constant reference to the item at
		// specified index.
		ECM_NODISCARD constexpr const _Ty& operator[](uint64 index) const
		{
			ECM_ASSERT(_data && index < _size);
			return _data[index];
		}
		// Returns a reference to the first item. Will fault the application if
		// called when the vector is empty.
		ECM_NODISCARD constexpr _Ty& front()
		{
			ECM_ASSERT(_data && _size);
			return _data[0];
		}
		// Returns a constant reference to the first item. Will fault the
		// application if called when the vector is empty.
		ECM_NODISCARD constexpr const _Ty& front() const
		{
			ECM_ASSERT(_data && _size);
			return _data[0];
		}
		// Returns a reference to the last item. Will fault the application if
		// called when the vector is empty.
		ECM_NODISCARD constexpr _Ty& back()
		{
			ECM_ASSERT(_data && _size);
			return _data[_size - 1];
		}
		// Returns a constant reference to the last item. Will fault the
		// application if called when the vector is empty.
		ECM_NODISCARD constexpr const _Ty& back() const
		{
			ECM_ASSERT(_data && _size);
			return _data[_size - 1];
		}
		// Returns a iterator to the first item. Returns null when vector is
		// empty.
		ECM_NODISCARD constexpr iterator begin()
		{
			return iterator(_data);
		}
		// Returns a constant iterator to the first item. Returns null when
		// vector is empty.
		ECM_NODISCARD constexpr const iterator begin() const
		{
			return iterator(_data);
		}
		// Returns a iterator to the last item. Returns null when vector is
		// empty.
		ECM_NODISCARD constexpr iterator end()
		{
			ECM_ASSERT(!(_data == nullptr && _size > 0));
			return iterator(_data + _size);
		}
		// Returns a constant iterator to the last item. Returns null when vector
		// is empty.
		ECM_NODISCARD constexpr const iterator end() const
		{
			ECM_ASSERT(!(_data == nullptr && _size > 0));
			return iterator(_data + _size);
		}
	private:
		constexpr void move(vector_it& o)
		{
			_capacity = o._capacity;
			_size = o._size;
			_data = o._data;
			o.reset();
		}
		constexpr void reset()
		{
			_capacity = 0;
			_size = 0;
			_data = nullptr;
		}
		constexpr void destruct_range(uint64 first, uint64 last)
		{
			ECM_ASSERT(destruct);
			ECM_ASSERT(first <= _size && last <= _size && first <= last);
			if (_data)
			{
				for (; first != last; ++first)
				{
					_data[first].~_Ty();
				}
			}
		}
		constexpr void destroy()
		{
			ECM_ASSERT([&]
				{ return _capacity ? _data != nullptr : _data == nullptr; }());
			clear();
			_capacity = 0;
			if (_data) free(_data);
			_data = nullptr;
		}
	private:
		uint64	_capacity{ 0 };
		uint64	_size{ 0 };
		_Ty* _data{ nullptr };
	};

	template<typename _Ty, template<typename, bool> typename _Ct>
	class free_vector_base
	{
		static_assert(sizeof(_Ty) >= sizeof(uint32));
	public:
		free_vector_base() = default;
		explicit free_vector_base(uint32 count)
		{
			_array.reserve(count);
		}
		~free_vector_base()
		{
			ECM_ASSERT(!_size);
		}
		template<class... params>
		constexpr uint32 add(params&&... p)
		{
			uint32 id{ 0xffff'ffffu };
			if (_next_free_index == 0xffff'ffffu)
			{
				id = (uint32)_array.size();
				_array.emplace_back(std::forward<params>(p)...);
			}
			else
			{
				id = _next_free_index;
				ECM_ASSERT(id < _array.size() && already_removed(id));
				_next_free_index =
					*(const uint32* const)std::addressof(_array[id]);
			}
			++_size;
			return id;
		}
		constexpr void remove(uint32 id)
		{
			ECM_ASSERT(id < _array.size() && !already_removed(id));
			_Ty& item{ _array[id] };
			item.~_Ty();
			ECM_DEBUGOP(memset(std::addressof(_array[id]), 0xcc, sizeof(_Ty)));
			*((uint32* const)std::addressof(_array[id])) = _next_free_index;
			_next_free_index = id;
			--_size;
		}
		constexpr uint32 size() const
		{
			return _size;
		}
		constexpr uint32 capacity() const
		{
			return _array.capacity();
		}
		constexpr bool empty() const
		{
			return _size == 0;
		}
		ECM_NODISCARD constexpr _Ty& operator[](uint32 id)
		{
			ECM_ASSERT(id < _array.size() && !already_removed(id));
			return _array[id];
		}
		ECM_NODISCARD constexpr const _Ty& operator[](uint32 id) const
		{
			ECM_ASSERT(id < _array.size() && !already_removed(id));
			return _array[id];
		}
		constexpr bool already_removed(uint32 id)
		{
			if constexpr (sizeof(_Ty) > sizeof(uint32))
			{
				uint32 i{ sizeof(uint32) };
				const uint8* const p{
					(const uint8* const)std::addressof(_array[id]) };
				while ((p[i] == 0xcc) && (i < sizeof(_Ty))) ++i;
				return i == sizeof(_Ty);
			}
			return true;
		}
	private:
		_Ct<_Ty, true>	_array;
		uint32			_next_free_index{ 0xffff'ffffu };
		uint32			_size{ 0 };
	};

	template<typename _Ty>
	using free_vector = free_vector_base<_Ty, vector>;
	template<typename _Ty>
	using free_vector_it = free_vector_base<_Ty, vector_it>;
} // namespace ecm::container

#endif // !_ECM_VECTOR_H_
