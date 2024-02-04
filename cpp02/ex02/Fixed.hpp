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
		bool operator>(Fixed const &other);
		bool operator<(Fixed const &other);
		bool operator>=(Fixed const &other);
		bool operator<=(Fixed const &other);
		bool operator==(Fixed const &other);
		bool operator!=(Fixed const &other);
		Fixed operator+(Fixed const &other);
		Fixed operator-(Fixed const &other);
		Fixed operator*(Fixed const &other);
		Fixed operator/(Fixed const &other);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		static Fixed const &min(Fixed &first, Fixed &second);
		static Fixed const &max(Fixed &first, Fixed &second);
		static Fixed const &min(Fixed const &first, Fixed const &second);
		static Fixed const &max(Fixed const &first, Fixed const &second);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);

#endif