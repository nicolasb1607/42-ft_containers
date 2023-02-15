#include "rbt.hpp"

#include <iostream>
#include <cstring>
#include <utility>

int main()
{
	ft::RedBlackTree<std::pair<int, std::string> > bst();

	std::pair<int, std::string> pair1 = std::make_pair<int, std::string>(1, "hello");

	bst.insert(pair1);
	return (0);
}
