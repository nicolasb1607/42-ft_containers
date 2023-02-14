
#ifndef NODE_HPP
#define NODE_HPP

# include "nullptr.hpp"

#define BLACK 0
#define RED 1

using namespace ft;

template <typename T>
struct Node
{
	typedef Node<T>*	NodePtr;


	T		data;
	Node 	*parent;
	Node 	*left;
	Node 	*right;
	size_t	color;


	Node ()
	: data(), parent(_nullptr), left(_nullptr), right(_nullptr), color(BLACK)
	{}

	Node ( const T& data )
	: data(data), parent(_nullptr), left(_nullptr), right(_nullptr), color(RED)
	{}

	Node ( const T& data, NodePtr left, NodePtr right)
	: data(data), parent(_nullptr), left(left), right(right), color(RED)
	{}
};


#endif