#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
	class vector
	{
		private:
			typedef vector<T, Allocator> _Base;

		public :
			typedef typename _Base::reference		reference;
			typedef typename _Base::const_reference	const_refernce;
			typedef typename 	reference;
			typedef typename 

	}
}

#endif