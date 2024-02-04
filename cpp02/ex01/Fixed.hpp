#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {
	private:
	int					rawBits;
	static const int	fractBits;

	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& copy);
		Fixed	&operator=(Fixed const &fixed);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);


#endif