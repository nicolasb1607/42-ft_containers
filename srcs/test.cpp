#include "rbt.hpp"

#include <iostream>
#include <cstring>
#include <utility>

int main()
{
	ft::RedBlackTree<ft::pair<int, std::string> > bst;

	ft::pair<int, std::string> pair1 = ft::make_pair<int, std::string>(5, "brree");
	ft::pair<int, std::string> pair2 = ft::make_pair<int, std::string>(1, "hello");

	bst.insert(pair2);
	bst.insert(pair1);

	bst.printTree();
	return (0);
}
