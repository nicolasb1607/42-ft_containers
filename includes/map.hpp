#ifndef MAP_HPP
#define MAP_HPP

# include <memory>
# include <functional>

# include "rbt.hpp"

/*
TODO:

	*RBT_iterator

	*Modify NODE structure to fit with construction of value_type

	*Set template for RBT

	*Add a RBT 

	- constructor
	- destructor
	- operator=
	- at
	- operator[]
	- begin
	- end
	- rbegin
	- rend
	- max_size
	- clear
	- insert
	- erase
	- swap
	- count
	- find
	- equal_range
	- lower_bound
	- upper_bound

	- RELATIVE OPERATOR


*/


namespace ft
{
	template <
			class Key,												//map::key_type
			class T,												//map::mapped_type
			class Compare = std::less<Key>,							//map::key_compare
			class Alloc = std::allocator< ft::pair<const Key, T> >	//map::allocator_type
	>	class map
	{

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{  
			friend class	map;
			
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object

			public:
				typedef bool			result_type;
				typedef value_type		first_argument_type;
				typedef value_type		second_argument_type;

				bool operator() (const value_type& x, const value_type& y) const
				{ return comp(x.first, y.first); }
		};

		public :
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef ft::pair<const Key, T>										value_type;
			typedef Compare														key_compare;
			typedef typename ft::map<Key, T, Compare, Alloc>::value_compare		value_compare;
			typedef Alloc														allocator_type;
			typedef ft::RedBlackTree<value_type, value_compare, allocator_type>	red_black_tree;
			typedef value_type&													reference;
			typedef const reference												const_reference;
			typedef value_type*													pointer;
			typedef const pointer												const_pointer; 
			typedef ft::iterator<bidrectional_iterator_tag, value_type>			iterator;
			typedef ft::iterator<bidrectional_iterator_tag, const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type			difference_type;
			typedef std::size_t													size_type;

		protected :
			value_compare	_comp;
			allocator_type	_allocator;
			red_black_tree	_rbt;
			size_type		_size;

		public :
		/*-----------------------------------------------------------------------------------
		|																					|
		|								CONSTRUCTOR	/ DESTRUCTOR							|
		|																					|
		-----------------------------------------------------------------------------------*/

			// Default Constructor
			explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			: _comp(comp), _allocator(alloc), _size(0)
			{
				_rbt = RedBlackTree();
			}

			// Range Constructor
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const keyp_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _comp(comp), _allocator(alloc), _size(0)
			{


			}

			//Copy Constructor
			map(const map& src)
			{
				*this = src;
			}

			~map()
			{
				
			}


		/*-----------------------------------------------------------------------------------
		|																					|
		|									MEMBER FUNCTION									|
		|																					|
		-----------------------------------------------------------------------------------*/
			map& operator= (const map& rhs)
			{
				if ( this != &rhs )
				{
					this->_allocator = rhs._allocator;
					this->_comp = rhs._comp;
					this->_size = rhs._size;

					//COPY RBT here 
				}
			}
						
			allocator_type get_allocator() const
			{ return _allocator; }


		/*-----------------------------------------------------------------------------------
		|									ELEMENT ACCESS									|
		-----------------------------------------------------------------------------------*/
		T& at ( const Key& key)
		{
			//Throw std::out_of_range
		}

		const T& at ( const Key& key ) const
		{
				//Throw std::out_of_range
		}

		T& operator[] ( const Key& key )
		{

		}

		/*-----------------------------------------------------------------------------------
		|									ITERATORS										|
		-----------------------------------------------------------------------------------*/

		/*-----------------------------------------------------------------------------------
		|									CAPACITY										|
		-----------------------------------------------------------------------------------*/
		bool empty() const
		{ return (_size == 0) ? true:false; }

		size_type size() const
		{ return _size; }

		size_type max_size() const
		{

		}
		
		/*-----------------------------------------------------------------------------------
		|									MODIFIERS										|
		-----------------------------------------------------------------------------------*/

		/*-----------------------------------------------------------------------------------
		|									LOOKUP											|
		-----------------------------------------------------------------------------------*/	
	
		/*-----------------------------------------------------------------------------------
		|									OBSERVERS										|
		-----------------------------------------------------------------------------------*/
	
		key_compare key_comp() const
		{ return key_comp(); }

		std::map::value_compare value_comp() const
		{ return _comp;	}
	
	
	}
		/*-----------------------------------------------------------------------------------
		|																					|
		|									NON-MEMBER FUNCTION								|
		|																					|
		-----------------------------------------------------------------------------------*/



}

#endif