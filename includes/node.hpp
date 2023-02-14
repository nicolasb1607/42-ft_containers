
#ifndef NODE_HPP
#define NODE_HPP

# include <cstddef>

#define BLACK 0
#define RED 1

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
	: data(), parent(nullptr), left(nullptr), right(nullptr), color(BLACK)
	{}

	Node ( const T& data )
	: data(data), parent(nullptr), left(nullptr), right(nullptr), color(RED)
	{}

	Node ( const T& data, NodePtr left, NodePtr right)
	: data(data), parent(nullptr), left(left), right(right), color(RED)

};


#endif