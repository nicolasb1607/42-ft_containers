#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cmath>

# include <iterator_traits.hpp>
# include <reverse_iterator.hpp>
# include <is_integral.hpp>
# include <enable_if.hpp>
# include <utils.hpp>


//DEBUG

#include <iostream>


/*
TODO
	- assign
	- insert
	- operator=
	- resize
	- swap


	EXCEPTION std::out_of_range for instance 
	RELATIONAL OPERATORS
	SWAP VECTOR
*/


namespace ft
{
	template< class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename Alloc::reference									reference;
			typedef typename Alloc::const_reference								const_reference;
			typedef typename Alloc::pointer										pointer;
			typedef typename Alloc::const_pointer								const_pointer;
			typedef T*															iterator;
			typedef const iterator												const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef std::size_t													size_type;

		protected :
			allocator_type	_allocator;
			pointer			_begin;
			pointer			_end;
			size_type		_size;
			size_type		_capacity;


			int get_new_cap()
			{
				return (_capacity == 0) ? _capacity:(_capacity * 2);
			}

			void grow()
			{
				int new_cap = get_new_cap();
				reserve(new_cap);
			}


		public :

			/*-----------------------------------------------------------------------------------
			|																					|
			|								CONSTRUCTOR	/ DESTRUCTOR							|
			|																					|
			-----------------------------------------------------------------------------------*/

			// Default Constructor
			explicit vector(const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _begin(NULL), _end(NULL), _size(0), _capacity(0)
			{ _begin = _allocator.allocate(1); }


			// Fill Constructor
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _begin(NULL), _end(NULL), _size(n), _capacity(n)
			{
				_begin = _allocator.allocate(n);
				_end = _begin + n;
				for(size_type i = 0; i < n; i++)
				{
					_allocator.construct(_begin + i, val);
				}
			}

			//Range Constructor
			template <class InputIterator>
			vector(ENABLE_IF(InputIterator) first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _begin(NULL), _end(NULL)
			{
				_size = std::distance(first, last);
				_capacity = _size;
				_begin = _allocator.allocate(_size);
				_end = _begin + _size;
				for (difference_type i = 0; first != _end; first++, i++)
				{
					_allocator.construct(_begin + i, *first);
				}
			}

			//Copy Constructor
			vector(const vector& src)
			: _allocator(src._allocator), _begin(NULL), _end(NULL), _size(src._size),
			_capacity(src._capacity)
			{
				_begin = _allocator.allocate(_size);
				_end = _begin + _size;
				for(size_type i = 0; i < _size; i++)
				{
					_allocator.construct(_begin + i, *(src._begin + i));
				}
			}

			~vector()
			{
				for (size_type n = 0; n < _size; n++)
				{
					_allocator.destroy(_begin + n);
				}
				_allocator.deallocate(_begin, _size);
			}

			/*-----------------------------------------------------------------------------------
			|																					|
			|									MEMBER FUNCTION									|
			|																					|
			-----------------------------------------------------------------------------------*/

			/*
			Any elements held in the containe before the call are destroyed and replaced by newly
			constructed elements
			This causes an automatic reallocation of the allocated storage space if -and only if-
			the new vector _size surpasses the current vector capacity
			*/
			// void assign(size_type n, const value_type& val)
			// {
			// 	//Scenario 1 (n >= dst._size && n < dst._capacity)
			// 	//Replace the content of dst by src content
				
			// 	//Scenario 2 (n <= dst._size && n < dst._capacity)
			// 	//Replace the content of dst by src content
			// 	//Destroy the rest of dst content

			// 	//Scenario 3 (n >= dst._size && n > dst._capacity)
			// 	//Create a tmp vector allocate and construct it
			// 	//Destroy && deallocate dst vector
			// }

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last)
			// {}

			



			allocator_type get_allocator() const { return _allocator; }


			/*-----------------------------------------------------------------------------------
			|									ELEMENT ACCESS									|
			-----------------------------------------------------------------------------------*/

			/*
			Access element.
			Return a reference to the element at position n in the vector
			*/
			reference at(size_type n) { return (*(_begin + n)); }
			const_reference at(size_type n) const { return (*(_begin + n)); }

			reference operator[](size_type pos) { return (*(_begin + pos)); }
			const_reference operator[](size_type pos) const { return (*(_begin + pos)); }

			reference front() { return *_begin; }
			const_reference front() const { return *_begin; }
			
			reference back() { return *(_end - 1); }
			const_reference back() const { return *(_end - 1); }

			/*-----------------------------------------------------------------------------------
			|									ITERATORS										|
			-----------------------------------------------------------------------------------*/

			iterator begin() { return _begin; }
			const_iterator begin() const { return _begin; }

			iterator end() { return _begin + _size; }
			const_iterator end() const { return _begin + _size; }

			reverse_iterator rbegin() { return reverse_iterator(begin()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(begin()); }

			reverse_iterator rend() { return reverse_iterator(end()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(end()); }

			/*-----------------------------------------------------------------------------------
			|									CAPACITY										|
			-----------------------------------------------------------------------------------*/

			bool empty() const { return ((_size == 0) ? true:false); }
			size_type size() const { return _size; }
			size_type max_size() const { return _allocator.max_size(); }
			size_type capacity() const { return _capacity; }

			void reserve(size_type new_cap)
			{
				if (new_cap > _capacity)
				{
					pointer new_begin = _allocator.allocate(new_cap);
					iterator it = _begin;
					std::copy(it, _end, new_begin);
					for (size_type n = 0; n < _size; n++)
					{
						_allocator.destroy(_begin + n);
					}
					_allocator.deallocate(_begin, _size);
					_capacity = new_cap;
					_begin = new_begin;
					_end = _begin + _size;
				}
			}


			/*-----------------------------------------------------------------------------------
			|										MODIFIERS									|
			-----------------------------------------------------------------------------------*/

			void clear()
			{
				for (size_type n = 0; n < _size; n++)
					{
						_allocator.destroy(_begin + n);
					}
				_size = 0;
				_begin = NULL;
				_end = NULL;
			}


			//THROW OUT OF RANGE ??????
			iterator insert(iterator position, const value_type& val)
			{
				int new_cap = _capacity;
				if(_size + 1 > _capacity)
					new_cap = get_new_cap();				
				pointer new_begin = _allocator.allocate(new_cap);
				iterator old_it = _begin;
				iterator new_it = new_begin;
				new_it = std::copy(old_it, position - 1, new_it);
				_allocator.construct(new_it, val);
				while (old_it != position - 1)
					old_it++;
				std::copy(old_it, _end, ++new_it);
				_size++;
				_begin = new_begin;
				_end = end();
				_capacity = new_cap;
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				int new_cap = _capacity;
				while (_size + n > _capacity)
					new_cap = get_new_cap();				
				pointer new_begin = _allocator.allocate(new_cap);
				iterator old_it = _begin;
				iterator new_it = new_begin;
				new_it = std::copy(old_it, position - 1, new_it);
				_allocator.construct(new_it, val);
				while (old_it != position - 1)
					old_it++;
				std::copy(old_it, _end, ++new_it);
				_size++;
				_begin = new_begin;
				_end = end();
				_capacity = new_cap;
			}

			// template <class InputIterator>
			// void insert(iterator position, ENABLE_IF(InputIterator) first, InputIterator last)
			// {

			// }

			iterator erase(iterator pos)
			{
				if (pos == _end)
					return (end());
				else
				{
					for(iterator tmp = pos ; tmp != end(); tmp++)
					{
						_allocator.destroy(tmp);
						_allocator.construct(tmp, *(tmp + 1));
					}
					_size--;
					_end = end();
					return(pos);
				}
			}


			iterator erase(iterator first, iterator last)
			{
				if (first == last)
					return (last);
				else
				{
					ptrdiff_t diff = last - first;
					for(iterator it = first; it != last; it++)
						_allocator.destroy(it);
					for(iterator it = first; (it + diff) != end(); it++)
						_allocator.construct(it, *(it + diff));
					_size -= diff;
					_end = end();
					return(first);
				}
			}

			void push_back(const T& value)
			{
				if (_size + 1 > _capacity)
				{
					grow();
					_allocator.construct(_end, value);
				}
				else
					_allocator.construct(_end, value);
				_size++;
				_end = _begin + _size;
			}

			void pop_back()
			{
				_allocator.destroy(_end - 1);
				_size--;
				_end = _begin + _size;
			}


			/*
			Reduce the size of the vector without changing its capacity, unless the _size
			*/
			void resize( size_type n, value_type val = value_type())
			{
				if (n < _size)
				{

				}
				if (n > _size)
				{

				}
			}

			// void resize( size_type count, T value = T() )
			// {

			// }
		};


		/*-----------------------------------------------------------------------------------
		|																					|
		|									NON-MEMBER FUNCTION								|
		|																					|
		-----------------------------------------------------------------------------------*/



}

#endif