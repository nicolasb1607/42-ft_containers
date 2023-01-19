#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft {

	/*
	The reverse_iterator class template is an adapter for a bidirectional
	or random access iterator to iterate the sequence in the opposite
	direction of the adapted iterator. In other words, if the adapted 
	iterator advances ...
	*/

	template <typename Iterator>
	class reverse_iterator : public ft::iterator<
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference>
	{

		protected :
			Iterator _current; 
			// Constructor provided by the compiler, called implicitly-declared constructors and operators (see iterators tag)
			// the underlying iterator of which base() returns a copy

		public :
			typedef Iterator												iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type		value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference		reference;
			typedef typename ft::iterator_traits<Iterator>::pointer			pointer;

			//Default constructor
			reverse_iterator() : _current() {};

			//Copy constructor
			explicit reverse_iterator(Iterator x) : _current(x) { };

			//Conversion constructor
			template <typename U> reverse_iterator(const reverse_iterator<U>& u) : _current(u.base()) { }

			Iterator	base() const { return _current };

			reference	operator*() const { Iterator tmp = _current; return *--tmp; }
			pointer		operator->() const { return &(operator*()); }

			// Prefix increment
			reverse_iterator&	operator++() { _current--; return *this; }
			// Postfix increment
			reverse_iterator	operator++(int) { reverse_iterator tmp = *this; --_current; return tmp; }
			// Prefix decrement
			reverse_iterator&	operator--() { _current++; return *this; }
			// Postfix decrement
			reverse_iterator	operator--(int) { reverse_iterator tmp = *this; ++_current; return tmp; }
			
			// Array subscription
			reference			operator[](difference_type n) const { return *(*this + n); }

			reverse_iterator	operator+(difference_type n) const { return (_current - n); }
			reverse_iterator& 	operator+=(difference_type n) { _current -= n; return (*this); }
			reverse_iterator	operator-(difference_type n) const { return (_current + n); }
			reverse_iterator&	operator-=(difference_type n) const { _current += n; return (*this); }
			
	};

	//Non-member function
	
	template<typename Iterator>
	inline bool 
	operator==(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)
	{ return (a.base() == b.base()); }
	
	template<typename Iterator>	
	inline bool
	operator<(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)
	{ return ( b.base() < a.base() ); }
	
	template<typename Iterator>	
	inline bool
	operator!=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)
	{ return !(a.base() == b.base()); }
	
	template<typename Iterator>	
	inline bool
	operator>(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)
	{ return (b < a); }

	template<typename Iterator>	
	inline bool
	operator<=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)
	{ return !(b < a); }
	
	
	template<typename Iterator>	
	inline bool
	operator>=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)
	{ return !(a < b); }

	template<typename Iterator1, typename Iterator2> 
	inline bool 
	operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return lhs.base() == rhs.base(); }
	
	template<typename Iterator1, typename Iterator2>
	inline bool
	operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return !(lhs == rhs); }
	
	template<typename Iterator1, typename Iterator2>
	inline bool
	operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return rhs.base() < lhs.base(); }
	
	template<typename Iterator1, typename Iterator2>
	inline bool
	operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return !(rhs < lhs); }
	
	template<typename Iterator1, typename Iterator2>
	inline bool
	operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return !(lhs < rhs); }
	
	template<typename Iterator1, typename Iterator2>
	inline bool
	operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return !(rhs < lhs); }
}

#endif