#ifndef UTILS_HPP
#define UTILS_HPP

# include <iterator_traits.hpp>

#define ENABLE_IF(x) typename ft::enable_if<!(ft::is_integral<x>::value), x>::type

namespace ft
{	
	template <class T>
	T* addressof( T &arg )
	{ return &arg; }

}


#endif