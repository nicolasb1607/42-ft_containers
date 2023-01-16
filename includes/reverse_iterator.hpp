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

			reverse_iterator() : _current() {};
			explicit reverse_iterator(Iterator x) : _current(x) {};
			template <typename U> reverse_iterator(const reverse_iterator<U>& u);

			Iterator	base() const { return _current}; // Returns the underlying base iterator.

			reference	operator*() const { return *_current; }
			pointer		operator->() const { return _current; }

			// Prefix increment
			reverse_iterator&	operator++() { _current--; return *this; }
			// Postfix increment
			reverse_iterator	operator++(int) { Iterator tmp = *this; --(*this); return tmp; }
			// Prefix decrement
			reverse_iterator&	operator--() { _current++; return *this; }
			// Postfix decrement
			reverse_iterator	operator--(int) { Iterator tmp = *this; ++(*this); return tmp; }
			
			// Array subscription
			reference			operator[](difference_type n) const { return (_current + n); }

			reverse_iterator	operator+(difference_type n) const { return (_current - n); }
			reverse_iterator& 	operator+=(difference_type n) { _current -= n; return (*this); }
			reverse_iterator	operator-(difference_type n) const { return (_current + n); }
			reverse_iterator&	operator-=(difference_type n) const { _current += n; return (*this); }
			
			friend bool			operator==(const reverse_iterator<Iterator>&, const reverse_iterator<Iterator>&);
			friend bool			operator!=(const reverse_iterator<Iterator>&, const reverse_iterator<Iterator>&);
			friend bool			operator<(const reverse_iterator<Iterator>&, const reverse_iterator<Iterator>&);
			friend bool			operator<=(const reverse_iterator<Iterator>&, const reverse_iterator<Iterator>&);
			friend bool			operator>(const reverse_iterator<Iterator>&, const reverse_iterator<Iterator>&);
			friend bool			operator>=(const reverse_iterator<Iterator>&, const reverse_iterator<Iterator>&);
	};

	//Non-member function
	
	template<typename Iterator>	inline bool operator==(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return (a._current == b._current); }
	template<typename Iterator>	inline bool operator!=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return (a._current != b._current); }
	template<typename Iterator>	inline bool operator<(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return (a._current > b._current); }
	template<typename Iterator>	inline bool operator<=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return (a._current >= b._current); }
	template<typename Iterator>	inline bool operator>(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return (a._current < b._current); }
	template<typename Iterator>	inline bool operator>=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return (a._current <= b._current); }


	template<typename Iterator1, typename Iterator2> inline bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }
	template<typename Iterator1, typename Iterator2> inline bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
	template<typename Iterator1, typename Iterator2> inline bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }
	template<typename Iterator1, typename Iterator2> inline bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }
	template<typename Iterator1, typename Iterator2> inline bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }
	template<typename Iterator1, typename Iterator2> inline bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }
	

};

#endif