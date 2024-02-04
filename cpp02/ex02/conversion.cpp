#include "Fixed.hpp"

float	Fixed::toFloat( void ) const
{
	float	answer;

	answer = (float)rawBits / (float)(1 << fractBits);
	return (answer);
}

int	Fixed::toInt( void ) const
{
	int	answer;

	answer = rawBits >> Fixed::fractBits;
	return (answer);
}