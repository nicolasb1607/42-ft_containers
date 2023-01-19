#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	/*
	std::pair is a class template that provides a way to store 
	two heterogeneous objects as a single unit. A pair is 
	a specific case of a std::tuple with two elements
	*/
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		//Constructor
		pair()
		: first(), second() { }

		//Copy constructor
		pair(const T1& a, const T2& b)
		: first(a), second(b) { }

		/* 
		Conversion constructor (allow to construct 
		the class with different type, but might experience 
		some lose in precision if type are not compatible)
		*/
		template <class U1, class U2>
		pair(const pair<U1, U2>& p)
		: first(p.first), second(p.second) { }

		~pair() { }

		pair& operator=( const pair& other ) 
		{
			if (this != &other) 
			{
				first = other.first;
				second = other.second;
			}
			return (*this);
		}
	};
	
	template <class T1, class T2>
	inline bool
	operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) 
	{ return (x.first == y.first && x.second == y.second); }

	template <class T1, class T2>
	inline bool
	operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return (x.first < y.first || (!( y.first , x.first)) && x.second < y.second); }

	template <class T1, class T2>
	inline bool
	operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return !( x == y ); }

	template <class T1, class T2>
	inline bool
	operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return y < x; }

	template <class T1, class T2>
	inline bool
	operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return !(y < x); }

	template <class T1, class T2>
	inline bool
	operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{ return !(x < y); }
}


#endif