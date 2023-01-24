#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>

# include <iterator_traits.hpp>
# include <reverse_iterator.hpp>
# include <is_integral.hpp>
# include <enable_if.hpp>
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
			typedef const iterator												const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef std::size_t													size_type;

		private :
			allocator_type	_allocator;
			pointer			_start;
			pointer			_end; // Pas sur d en avoir besoin, a voir pour la suite
			size_type		_size;
			size_type		_capacity;


		public :

			/*-----------------------------------------------------------------------------------
			|																					|
			|									CONSTRUCTOR										|
			|																					|
			-----------------------------------------------------------------------------------*/

			// Default Constructor   == TEST OK
			explicit vector(const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _start(NULL), _end(NULL), _size(0), _capacity(0)
			{ _start = _allocator.allocate(1); }


			// Fill Constructor == FURTHER TEST NEEDED
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _start(NULL), _end(NULL), _size(n), _capacity(n)
			{
				_start = _allocator.allocate(n);
				_end = _start + n;
				for(size_type i = 0; i < n; i++)
				{
					_allocator.construct(_start + i, val);
				}
			}

			//Range Constructor
			template <class InputIterator>
			vector(ENABLE_IF(InputIterator) first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _start(NULL), _end(NULL)
			{
				_size = std::distance(first, last);
				_capacity = _size;
				_start = _allocator.allocate(_size);
				_end = _start + _size;
				for (difference_type i = 0; first != _end; first++, i++)
				{
					_allocator.construct(_start + i, *first);
				}
			}

			//Copy Constructor == FURTHER TEST NEEDED
			vector(const vector& src)
			: _allocator(src._allocator), _start(NULL), _end(NULL), _size(src._size),
			_capacity(src._capacity)
			{
				_start = _allocator.allocate(_size);
				_end = _start + _size;
				for(size_type i = 0; i < _size; i++)
				{
					_allocator.construct(_start + i, *(src._start + i));
				}
			}


			/*-----------------------------------------------------------------------------------
			|																					|
			|									MEMBER FUNCTION									|
			|																					|
			-----------------------------------------------------------------------------------*/

			size_type capacity() const { return _capacity; }
		};
}

#endif