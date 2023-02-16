#include "map.hpp"

#include <iostream>
#include <cstring>
#include <utility>

int main()
{
	ft::map<int, ft::pair<int, std::string> > bst;

	ft::pair<int, std::string> pair1 = ft::make_pair<int, std::string>(5, "brree");
	ft::pair<int, std::string> pair2 = ft::make_pair<int, std::string>(10, "hello");
	ft::pair<int, std::string> pair3 = ft::make_pair<int, std::string>(3, "hello");

	bst.insert(pair2);
	bst.insert(pair1);
	bst.insert(pair3);

	// int key = 10;
	// std::cout << "SEARCH function, value =" << key << " Content = " << bst.find_key(key)->data.first << std::endl;
	bst.printTree();
	return (0);
}
