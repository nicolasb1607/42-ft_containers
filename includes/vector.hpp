#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cmath>
# include <stdexcept>

# include <iterator_traits.hpp>
# include <reverse_iterator.hpp>
# include <is_integral.hpp>
# include <enable_if.hpp>
# include <equal.hpp>
# include <utils.hpp>

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
			typedef const T*													const_iterator;
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


			inline int get_new_cap()
			{
				return (_capacity == 0) ? _capacity:(_capacity * 2);
			}

			void grow()
			{
				int new_cap = get_new_cap();
				reserve(new_cap);
			}

			void destroy_previous_content()
			{
				for (size_type n = 0; n < _size; n++)
				{
					_allocator.destroy(_begin + n);
				}
			}

			void delete_previous_instance()
			{
				destroy_previous_content();
				_allocator.deallocate(_begin, _size);
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
			{ 
				_begin = _allocator.allocate(1);
				_end = _begin;
			 }


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
				delete_previous_instance();
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

			vector& operator=(const vector& x)
			{
				if(this != &x)
				{
					this->clear();
					this->assign(x.begin(), x.end());
				}
				return *this;
			}

			template <class InputIterator>
			void assign(ENABLE_IF(InputIterator) first, InputIterator last)
			{
				size_type range_size = std::distance(first, last);
				if(range_size > _capacity)
				{
					while(range_size > _capacity)
						_capacity = get_new_cap();
					pointer new_begin = _allocator.allocate(_capacity);
					std::copy(first, last, new_begin);
					delete_previous_instance();
					_begin = new_begin;	
				}
				else
				{
					destroy_previous_content();
					std::copy(first, last, _begin);
				}
				_size = range_size;
				_end = end();
			}

			void assign(size_type n, const value_type& val)
			{
				if(n > _capacity)
				{
					while(n > _capacity)
						_capacity = get_new_cap();
					pointer new_begin = _allocator.allocate(_capacity);
					for (size_type i = 0; i < n; i++)
						_allocator.construct(new_begin + i, val);
					delete_previous_instance();
					_begin = new_begin;
				}
				else
				{
					destroy_previous_content();
					for (size_type i = 0; i < n; i++)
						_allocator.construct(_begin + i, val);
				}
				_size = n;
				_end = end();
			}

			allocator_type get_allocator() const { return _allocator; }


			/*-----------------------------------------------------------------------------------
			|									ELEMENT ACCESS									|
			-----------------------------------------------------------------------------------*/

			/*
			Access element.
			Return a reference to the element at position n in the vector
			*/
			reference at(size_type n) 
			{	
				if (!(n < size()))
					throw std::out_of_range("Cannot access the value");
				return (*(_begin + n));
			}
			const_reference at(size_type n) const 
			{
				if (!(n < size()))
					throw std::out_of_range("Cannot access the value");
				return (*(_begin + n));
			}

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
				if (new_cap > max_size())
					throw std::length_error("new_cap exceed the maximum size allocation possible");
				if (new_cap > _capacity)
				{
					pointer new_begin = _allocator.allocate(new_cap);
					iterator it = _begin;
					std::copy(it, _end, new_begin);
					delete_previous_instance();
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
				destroy_previous_content();
				_size = 0;
			}

			iterator insert(iterator position, const value_type& val)
			{
				if(_size + 1 > _capacity)
					_capacity = get_new_cap();				
				pointer new_begin = _allocator.allocate(_capacity);
				iterator old_it = _begin;
				iterator new_it = new_begin;
				new_it = std::copy(old_it, position - 1, new_it);
				_allocator.construct(new_it, val);
				while (old_it != position - 1)
					old_it++;
				std::copy(old_it, _end, ++new_it);
				delete_previous_instance();
				_size++;
				_begin = new_begin;
				_end = end();
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				while (_size + n > _capacity)
					_capacity = get_new_cap();				
				pointer new_begin = _allocator.allocate(_capacity);
				iterator old_it = _begin;
				iterator new_it = new_begin;
				new_it = std::copy(old_it, position - 1, new_it);
				for (size_type i = 0; i < n; i++ )
					_allocator.construct(new_it + i, val);
				while (old_it != position - 1)
					old_it++;
				std::copy(old_it, _end, new_it + n);
				delete_previous_instance();
				_size += n;
				_begin = new_begin;
				_end = end();
			}

			template <class InputIterator>
			void insert(iterator position, ENABLE_IF(InputIterator) first, InputIterator last)
			{
				difference_type range_size = last - first;
				while (_size + range_size > _capacity)
					_capacity = get_new_cap();				
				pointer new_begin = _allocator.allocate(_capacity);
				iterator old_it = _begin;
				iterator new_it = new_begin;
				new_it = std::copy(old_it, position - 1, new_it);
				std::copy(first, last, new_it);
				while (old_it != position - 1)
					old_it++;
				std::copy(old_it, _end, new_it + range_size);
				delete_previous_instance();
				_size += range_size;
				_begin = new_begin;
				_end = end();

			}

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
					for(iterator it = _begin + n; it != end(); it++)
						_allocator.destroy(it);
				}
				if (n > _size)
				{
					while (n > _capacity)
						_capacity = get_new_cap();
					reserve(_capacity);
					for (iterator it = end(); it != end() + (n - _size); it++ )
						_allocator.construct(it, val);					
				}
				_size = n;
			}

			void swap(vector& other)
			{
				pointer 		tmp_ptr;
				size_type		tmp_size;
				allocator_type	tmp_alloc;

				tmp_ptr = this->_begin;
				this->_begin = other.begin;
				other.begin = tmp_ptr;

				tmp_ptr = this->_end;
				this->_end = other._end;
				other._end = tmp_ptr;

				tmp_size = this->_size;
				this->_size = other._size;
				other._size = tmp_size;

				tmp_size = this->_capacity;
				this->_capacity = other._capacity;
				other._capacity = tmp_size;

				tmp_alloc = this->_allocator;
				this->_allocator = other._allocator;
				other._allocator = tmp_alloc;
			}
		};

		/*-----------------------------------------------------------------------------------
		|																					|
		|									NON-MEMBER FUNCTION								|
		|																					|
		-----------------------------------------------------------------------------------*/

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size() 
			&& ft::equal(lhs.begin(),lhs.end(), rhs.begin(), rhs.end())) 
			? true:false);
	}

	template <class T, class Alloc>
 	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs.size() < rhs.size()
			&& std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			? true:false);
	}
	
	template <class T, class Alloc>
 	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(rhs < lhs); }

	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return rhs < lhs; }

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs < rhs); }
}

#endif