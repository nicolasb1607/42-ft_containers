#ifndef ITERATOR_RBT_HPP
#define ITERATOR_RBT_HPP

# include "iterator_traits.hpp"
# include "nullptr.hpp"
# include "node.hpp"

namespace ft
{
	template <
			class T,
			class Node
	> class iterator_rbt
	{
		public :
			typedef typename ft::iterator<bidrectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<bidrectional_iterator_tag, T>::difference_type	diffrence_type;
			typedef typename ft::iterator<bidrectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<bidrectional_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<bidrectional_iterator_tag, T>::reference			reference;
			typedef Node																	node_type;
			typedef Node*																	node_pointer;
			typedef Node&																	node_reference;

		private :
			node_pointer	_current;
			node_pointer	_root;
			node_pointer	_TNULL;

		/*-----------------------------------------------------------------------------------
		|									PRIVATE MEMBER FUNCTION							|
		-----------------------------------------------------------------------------------*/

			node_pointer _max(const node_pointer& x)
			{
				if(!x)
					return (_nullptr);
				if (x == _TNULL)
					return _TNULL;
				else
				{
					node_pointer	tmp = x;

					while (tmp && tmp->right) 
						tmp = tmp->right;
					return tmp;
				}
			}

			node_pointer _min(const node_pointer& x)
			{
				if(!x)
					return (_nullptr);
				if (x == _root)
					return _root;
				else
				{
					node_pointer	tmp = x;

					while(tmp && tmp->left)
						tmp = tmp->left;
					return tmp;
				}
			}

			void _increment()
			{
				if (_current == _TNULL)
				{
					_current = _max(_root);
					return ;
				}
				node_pointer tmp = _current;
				if (tmp->right != _TNULL)
				{
					_current = _min(tmp->right);
					return ;
				}
				node_pointer p = tmp->parent;
				while (p != _nullptr && tmp == p->right)
				{
					tmp = p;
					p = p->parent;
				}
				if (p == _nullptr)
				{
					_current = _TNULL;
					return ;
				}
				_current = tmp;
			}

			void _decrement()
			{
				if (_current == _TNULL)
				{
					_current = _max(root);
					return ;
				}
				node_pointer tmp = _current;
				if (tmp->left != _nullptr)
				{
					_current = _max(tmp->left);
					return;
				}
				node_pointer p = tmp->parent;
				while (p != _nullptr && tmp == p->right)
				{
					tmp = p;
					p = p->parent;
				}
				if(p == _nullptr)
				{
					_current = _TNULL;
					return ;
				}
				_current = tmp;
			}

		public :
		/*-----------------------------------------------------------------------------------
		|																					|
		|								CONSTRUCTOR	/ DESTRUCTOR							|
		|																					|
		-----------------------------------------------------------------------------------*/

		//Default constructor
		iterator_rbt()
		: _current(_nullptr), _root(_nullptr), _TNULL(_nullptr)
		{}

		iterator_rbt( const node_pointer& current, const node_pointer& root, const node_pointer& end)
		: _current(current), _root(root), _TNULL(end)
		{}

		//Copy constructor
		iterator_rbt(const iterator_rbt& src)
		{
			this = src;
		}

		//Conversion constructor for const value
		operator iterator_rbt<const T, Node>()
		{
			return (iterator_rbt<const T, Node>(_current, _TNULL, _root));
		}

		~iterator_rbt()
		{}

		iterator_rbt	base() const { return _current; }


		iterator_rbt& operator=(const iterator_rbt& rhs)
		{
			if (this != &rhs)
			{
				this->_current = rhs._current;
				this->_root = rhs._root;
				this->_TNULL = rhs._TNULL;
			}
			return *this;
		}
		
		reference	operator*() { return _current->data; }
		pointer		operator->() const { return &(operator*()); }

		//Prefix increment
		iterator_rbt& operator++() { _increment(); return *this; }

		//Postfix increment
		iterator_rbt operator++(int) 
		{ 
			iterator_rbt tmp = *this;
			_increment();
			return tmp;			
		}

		//Prefix decrement
		iterator_rbt& operator--() { _decrement(); return *this;}

		//Postfix decrement
		iterator_rbt operator--(int)
		{
			iterator_rbt tmp = *this;
			_decrement();
			return tmp;
		}
	};

	/*-----------------------------------------------------------------------------------
	|																					|
	|									NON-MEMBER FUNCTION								|
	|																					|
	-----------------------------------------------------------------------------------*/

	template <typename T1, typename Node1>
	inline bool
	operator==( const iterator_rbt<T1, Node1>& lhs, const iterator_rbt<T1, Node1>& rhs)
	{ return lhs.base() == rhs.base(); }

	template <typename T1, typename Node1>
	inline bool
	operator!=( const iterator_rbt<T1, Node1>& lhs, const iterator_rbt<T1, Node1>& rhs)
	{ return !(lhs.base() == rhs.base()); }	
}

#endif 