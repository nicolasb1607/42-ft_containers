#ifndef UTILS_HPP
#define UTILS_HPP

# include <iterator_traits.hpp>

namespace ft
{
	template <class InputIter>
	typename ft::iterator_traits<InputIter>::difference_type distance(InputIter first, InputIter last)
	{ return last - first; }
	

	template <class T>
	T* addressof( T &arg )
	{ return &arg; }
}


#endif