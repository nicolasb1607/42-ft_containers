#ifndef RBT_HPP
#define RBT_HPP

# include <iostream>
# include <functional>

# include "reverse_iterator.hpp"
# include "node.hpp"
# include "pair.hpp"
# include "make_pair.hpp"


namespace ft
{

	template <
			class Key,
			class T,
			class Compare = std::less<T>,
			class Alloc = std::allocator< Node<T> >
	>	class RedBlackTree
	{
		public:
			typedef Key					key_type;
			typedef T					mapped_type;
			typedef ft::pair<Key, T>	value_type;
			typedef Compare				key_compare;
			typedef Alloc				allocator_type;
			typedef Node<T>*			NodePtr;
			typedef std::size_t			size_type;


		protected:
			NodePtr 		root;
			NodePtr 		TNULL;
			allocator_type	_allocator;
			key_compare		_comp;
			

			// void initializeNULLNode(NodePtr node, NodePtr parent)
			// {
			// 	node->data = 0;
			// 	node->parent = parent;
			// 	node->left = _nullptr;
			// 	node->right = _nullptr;
			// 	node->color = BLACK;
			// }

			// // Preorder
			// void preOrderHelper(NodePtr node)
			// {
			// 	if (node != TNULL)
			// 	{
			// 		std::cout << node->data << " ";
			// 		preOrderHelper(node->left);
			// 		preOrderHelper(node->right);
			// 	}
			// }

			// // Inorder
			// void inOrderHelper(NodePtr node)
			// {
			// 	if (node != TNULL)
			// 	{
			// 		inOrderHelper(node->left);
			// 		std::cout << node->data << " ";
			// 		inOrderHelper(node->right);
			// 	}
			// }

			// // Post order
			// void postOrderHelper(NodePtr node)
			// {
			// 	if (node != TNULL)
			// 	{
			// 		postOrderHelper(node->left);
			// 		postOrderHelper(node->right);
			// 		std::cout << node->data << " ";
			// 	}
			// }

			

			// For balancing the tree after deletion
			void deleteFix(NodePtr x)
			{
				NodePtr s;
				while (x != root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								rightRotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							leftRotate(x->parent);
							x = root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rightRotate(x->parent);
							x = root;
						}
					}
				}
				x->color = BLACK;
			}

			void rbTransplant(NodePtr u, NodePtr v)
			{
				if (u->parent == _nullptr)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void deleteNodeHelper(NodePtr node, int key)
			{
				NodePtr z = TNULL;
				NodePtr x, y;
				while (node != TNULL)
				{
					if (node->data == key)
						z = node;
					if (node->data <= key)
						node = node->right;
					else
						node = node->left;
				}
				if (z == TNULL)
				{
					std::cout << "Key not found in the tree" << std::endl;
					return;
				}
				y = z;
				int y_original_color = y->color;
				if (z->left == TNULL)
				{
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == TNULL)
				{
					x = z->left;
					rbTransplant(z, z->left);
				}
				else
				{
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else
					{
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				delete z;
				if (y_original_color == BLACK)
					deleteFix(x);
			}

			// For balancing the tree after insertion
			void insertFix(NodePtr k)
			{
				NodePtr u;
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							leftRotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;

						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root)
						break;
				}
				root->color = BLACK;
			}

			void printHelper(NodePtr root, std::string indent, bool last)
		{
			if (root != TNULL)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->data.first << "/" << root->data.second << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		public :
		/*-----------------------------------------------------------------------------------
		|																					|
		|								CONSTRUCTOR	/ DESTRUCTOR							|
		|																					|
		-----------------------------------------------------------------------------------*/

			RedBlackTree()
			: root(_nullptr), TNULL(_nullptr), _allocator(allocator_type()), _comp(key_compare())
			{
				//Construction default Node
				TNULL = _allocator.allocate(1);
				_allocator.construct(TNULL, Node<T>(value_type()));

				TNULL->color = BLACK;
				root = TNULL;
			}
				
			~RedBlackTree()
			{}

		/*-----------------------------------------------------------------------------------
		|																					|
		|									MEMBER FUNCTION									|
		|																					|
		-----------------------------------------------------------------------------------*/


		/*-----------------------------------------------------------------------------------
		|									ELEMENT ACCESS									|
		-----------------------------------------------------------------------------------*/
			NodePtr find_key(const key_type& key)
			{
				NodePtr tmp = root;

				if(tmp == _nullptr)
					return NULL;
				while (tmp && tmp->data.first != key)
				{
					tmp = _comp(key, tmp->data) ? tmp->left : tmp->right;
					if(tmp == TNULL)
						return NULL;
				}
				return tmp;
			}
	

			NodePtr minimum(NodePtr node)
			{
				while (node->left != TNULL)
					node = node->left;
				return node;
			}

			NodePtr maximum(NodePtr node)
			{
				while (node->right != TNULL)
					node = node->right;
				return node;
			}

			NodePtr successor(NodePtr x)
			{
				if (x->right != TNULL)
					return minimum(x->right);
				NodePtr y = x->parent;
				while (y != TNULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x)
			{
				if (x->left != TNULL)
					return maximum(x->left);
				NodePtr y = x->parent;
				while (y != TNULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			void leftRotate(NodePtr x)
			{
				NodePtr y = x->right;
				x->right = y->left;
				if (y->left != TNULL)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == _nullptr)
					this->root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void rightRotate(NodePtr x)
			{
				NodePtr y = x->left;
				x->left = y->right;
				if (y->right != TNULL)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == _nullptr)
					this->root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			// Inserting a node
			std::pair<NodePtr, bool> insert(value_type& content)
			{
				NodePtr node = _allocator.allocate(1);
				_allocator.construct(node, Node<value_type>(content, TNULL, TNULL));

				NodePtr y = _nullptr;
				NodePtr x = this->root;

				while (x != TNULL)
				{
					y = x;
					if (_comp(node->data, x->data))
						x = x->left;
					else if (!_comp(node->data, x->data))
						x = x->right;
				}
				node->parent = y;
				if (y == _nullptr)
					root = node;
				else if (_comp(node->data, y->data))
					y->left = node;
				else
					y->right = node;
				if (node->parent == _nullptr)
				{
					node->color = 0;
					return ft::make_pair(node, true);
				}
				if (node->parent->parent == _nullptr)
					return ft::make_pair(node, true);
				insertFix(node);
			}

			NodePtr getRoot()
			{
				return this->root;
			}

			void deleteNode(int data)
			{
				deleteNodeHelper(this->root, data);
			}

			void printTree()
			{
				if (root)
				{
					printHelper(this->root, "", true);
				}
			}
		};

}

#endif
