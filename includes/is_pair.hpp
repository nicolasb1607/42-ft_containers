#ifndef IS_PAIR_HPP
#define IS_PAIR_HPP

# include <cstddef>

# include "is_integral.hpp"
# include "pair.hpp"

namespace ft
{
	template <typename T>
	struct is_pair : ft::false_type
	{};

	template <typename T1, typename T2>
	struct is_pair< std::pair<T1, T2> > : ft::true_type
	{};

	template <typename T1, typename T2>
	struct is_pair< ft::pair<T1, T2> > : ft::true_type
	{};
}

#endif