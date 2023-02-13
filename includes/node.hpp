
#ifndef NODE_HPP
#define NODE_HPP

template <typename value_type>
struct Node
{

	typedef typename value_type::first	

	key_type	key;
	value_type	value;
	Node 		*parent;
	Node 		*left;
	Node 		*right;
	int			color;
};


#endif