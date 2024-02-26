#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <string>

template <typename T>
class Array{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array();
		Array( unsigned int n );
		Array( Array const &src );
		~Array();
		Array	&operator=( Array const &src );
		T		&operator[]( int i );

		size_t	size() const;
		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template< typename T >
std::ostream& operator<<(std::ostream& output, Array<T> & array);

#include "Array.tpp"

#endif