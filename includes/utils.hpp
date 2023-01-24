#ifndef UTILS_HPP
#define UTILS_HPP

# include <iterator_traits.hpp>

namespace ft
{	
	template <class T>
	T* addressof( T &arg )
	{ return &arg; }
}


#endif