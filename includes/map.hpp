#ifndef MAP_HPP
#define MAP_HPP

# include <memory>
# include <functional>

# include <pair.hpp>
# include <reverse_iterator.hpp>


namespace ft
{
	template <
			class Key,												//map::key_type
			class T,												//map::mapped_type
			class Compare = std::less<Key>,							//map::key_compare
			class Alloc = std::allocator< ft::pair<const Key, T> >	//map::allocator_type
	>	class map
	{
		protected :
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare					key_compare;
			typedef 
			typedef std::size_t				size_type;
			typedef ft


	}


}

#endif