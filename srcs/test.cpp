# include "vector.hpp"
// #else
// # include <vector>
// #endif /* !defined(STD) */

#include <iostream>
#include <list>

#define TESTED_NAMESPACE ft
// #define TESTED_NAMESPACE std
#define TESTED_TYPE std::string
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type


template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSize(vct);

	std::cout << " Ici 1" << std::endl;

	checkErase(vct, vct.erase(vct.begin() + 2));
	// std::cout << " Ici 2" << std::endl;

	// checkErase(vct, vct.erase(vct.begin()));
	// std::cout << " Ici 3" << std::endl;
	// checkErase(vct, vct.erase(vct.end() - 1));
	// std::cout << " Ici 4" << std::endl;

	// checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	// std::cout << " Ici 5" << std::endl;
	// checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));
	// std::cout << " Ici 6" << std::endl;

	// vct.push_back("Hello");
	// vct.push_back("Hi there");
	// printSize(vct);
	// checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	// vct.push_back("ONE");
	// vct.push_back("TWO");
	// vct.push_back("THREE");
	// vct.push_back("FOUR");
	// printSize(vct);
	// checkErase(vct, vct.erase(vct.begin(), vct.end()));

	return (0);
}
