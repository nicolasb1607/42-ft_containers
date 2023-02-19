#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

# include <cstddef>

namespace	ft {

	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag :			public input_iterator_tag {};
	struct	bidrectional_iterator_tag :		public forward_iterator_tag {};
	struct	random_access_iterator_tag :	public bidrectional_iterator_tag {};

	/* The iterator class template is a convenient base-class template to 
	use when implementing your own iterator. */

	template <typename Category, typename T, typename Difference = ptrdiff_t,
			typename Pointer = T*, typename Reference = T&>
	struct iterator {
		typedef T				value_type;
		typedef Difference		difference_type;
		typedef Category		iterator_category;
		typedef Pointer			pointer;
		typedef Reference		reference;
	};

	/* The iterator_traits class template declares traits for an iterator. 
	If you use the iterator class template as the base for your custom 
	iterator, you don’t need to specialize iterator_traits. If you are 
	writing a custom container or algorithm, you should always use 
	iterator_traits to obtain the traits of an iterator. If you use a 
	plain pointer as an iterator, the standard library specializes 
	iterator_traits for you. */

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	// Partial specialization for pointer types
	template <class T>
	struct iterator_traits<T*> {
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

	// Partial specialization for const pointer types
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
	};
}

#endif

