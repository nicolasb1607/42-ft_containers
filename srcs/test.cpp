// #include "rbt.hpp"
// #include "map.hpp"
#include <iostream>
#include <cstring>
#include <utility>

# include <map>

int main()
{
	// ft::RedBlackTree<int, ft::pair<int, std::string> > bst;

	// ft::pair<int, std::string> pair1 = ft::make_pair(5, "brree");
	// ft::pair<int, std::string> pair2 = ft::make_pair(10, "hello");
	// ft::pair<int, std::string> pair3 = ft::make_pair(3, "hello");

	// bst.insert(pair2);
	// bst.insert(pair1);
	// bst.insert(pair3);

	// int key = 10;
	// std::cout << "SEARCH function, value =" << key << " Content = " << bst.find_key(key)->data.first << std::endl;
	// bst.printTree();

	std::map<int, int> test;

	test.insert(std::make_pair(1, 1));
	test.insert(std::make_pair(2, 1));
	test.insert(std::make_pair(3, 1));
	test.insert(std::make_pair(4, 1));
	test.insert(std::make_pair(5, 1));
	
	std::map<int,int>::iterator it = test.begin();
	std::map<int,int>::iterator ite = test.end();

	while(it != ite)
	{
		std::cout << (*it).first << std::endl;
		it++;
	}
	it++;
	std::cout << (*it).first << std::endl;
	it++;
	std::cout << (*it).first << std::endl;

	std::cout << "Decrement" << std::endl; 
	while(it != test.begin())
	{
		std::cout << (*it).first << std::endl;
		it--;
	}
	std::cout << (*it).first << std::endl;
	it--;
	std::cout << (*it).first << std::endl;
	it--;
	std::cout << (*it).first << std::endl;
	it--;

	return (0);
}
