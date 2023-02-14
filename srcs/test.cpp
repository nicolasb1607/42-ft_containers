#include "rbt.hpp"

#include <iostream>
#include <cstring>
#include <utility>

int main()
{
	ft::RedBlackTree<std::pair<int, std::string> > bst();
	bst.insert(std::make_pair<int, std::string>(1, "hello"));
	bst.printTree();

	return (0);
}
