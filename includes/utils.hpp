#ifndef UTILS_HPP
#define UTILS_HPP

# include "iterator_traits.hpp"
# include "is_pair.hpp"

#define ENABLE_IF(x) typename ft::enable_if<!(ft::is_integral<x>::value), x>::type
#define ENABLE_IF_PAIR(x) typename ft::enable_if< (ft::is_pair<x>), x>::type

namespace ft
{	
	template <class T>
	T* addressof( T &arg )
	{ return &arg; }

}

#endif