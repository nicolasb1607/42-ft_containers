#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <iostream>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public :
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef	typename Container::const_reference	const_reference;

		protected :
			Container c;

		public:
		/*-----------------------------------------------------------------------------------
		|																					|
		|								CONSTRUCTOR	/ DESTRUCTOR							|
		|																					|
		-----------------------------------------------------------------------------------*/

		explicit stack(const container_type& ctnr = container_type())
		: c(ctnr)
		{}

		~stack()
		{}

		/*-----------------------------------------------------------------------------------
		|																					|
		|									MEMBER FUNCTION									|
		|																					|
		-----------------------------------------------------------------------------------*/

		stack& operator=(const stack& other)
		{
			if(this != &other)
			{
				this->c = other.c;
			}
			return *this;
		}

		/*-----------------------------------------------------------------------------------
		|									ELEMENT ACCESS									|
		-----------------------------------------------------------------------------------*/

		reference top()
		{
			return c.back();
		}

		const_reference top() const
		{
			return c.back();
		}
		/*-----------------------------------------------------------------------------------
		|									CAPACITY										|
		-----------------------------------------------------------------------------------*/

		bool empty() const
		{
			return c.empty();
		}

		size_type size() const
		{
			return c.size();
		}



		/*-----------------------------------------------------------------------------------
		|									MODIFIERS										|
		-----------------------------------------------------------------------------------*/

		void push(const value_type& val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

		template <class T1, class Container1>
		friend bool operator==(const ft::stack<T1, Container1>& lhs, const ft::stack<T1, Container1>& rhs);

		template <class T1, class Container1>
		friend bool operator<(const ft::stack<T1, Container1>& lhs, const ft::stack<T1, Container1>& rhs);

		
	};
		/*-----------------------------------------------------------------------------------
		|																					|
		|									NON-MEMBER FUNCTION								|
		|																					|
		-----------------------------------------------------------------------------------*/

	template <class T, class Container>
	inline bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
	inline bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class T, class Container>
	inline bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	inline bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Container>
	inline bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Container>
	inline bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>&rhs)
	{
		return !(lhs < rhs);
	}
}

#endif