#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <type_traits>>

namespace ft {

	template <class T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		const operator T() { return v; } 
	};

	template <class T>
	struct is_integral : public integral_constant {


	};

};

#endif