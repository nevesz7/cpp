#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
	private:
	int					rawBits;
	static const int	fractBits;

	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed	&operator=( Fixed const &fixed );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif