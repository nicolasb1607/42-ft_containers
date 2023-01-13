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
		
		public :
			typedef Iterator												iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference		reference;
			typedef typename ft::iterator_traits<Iterator>::pointer			pointer;

			reverse_iterator();
			explicit reverse_iterator(Iterator x);
			template <typename U> reverse_iterator(const reverse_iterator<U>& u);

			Iterator	base() const; // Explicit
			reference	operator*() const;
			pointer		operator->() const; 

			reverse_iterator&	operator++();
			reverse_iterator	operator++(int);
			reverse_iterator&	operator--();
			reverse_iterator	operator--(int);
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator& 	operator+=(difference_type n);
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator&	operator-=(difference_type n) const;
			
			reference			operator[](difference_type n) const;

	};

	template <typename Iterator>
	inline reverse_iterator<Iterator>::reverse_iterator()
	{
	}

};

#endif