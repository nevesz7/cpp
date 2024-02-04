#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(void)
{
	this->rawBits = 0;
}

Fixed::Fixed(const int value)
{
	this->rawBits = value << Fixed::fractBits;
	return ;
}

Fixed::Fixed(const float value)
{
	this->rawBits = (int)roundf(value * (1 << Fixed::fractBits));
	return ;
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=( Fixed const &copied )
{
	if (this != &copied)
		this->rawBits = copied.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const 
{
	return (this->rawBits);
}

void	Fixed::setRawBits( int const rawBits )
{
	this->rawBits = rawBits;
}
