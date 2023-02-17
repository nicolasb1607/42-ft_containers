#ifndef SET_HPP
#define SET_HPP

# include <cstddef>

namespace ft
{
	template <
			class Key, 
			class Compare = std::less<Key>,
			class Allocator = std::allocator<Key>
	> class set
	{
		public :
			typedef Key									key_type;
			typedef Key									mapped_type;
			typedef std::size_t							size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef Compare								key_compare;
			typedef Compare								value_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename const Allocator::pointer	const_pointer;
			typedef ft::bidrectional_iterator_tag		iterator;
			typedef ft


	};

}

#endif