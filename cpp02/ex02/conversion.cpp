#include "Fixed.hpp"

float	Fixed::toFloat( void ) const
{
	float	answer;

	answer = (float)rawBits / (float)(1 << fractBits);
	return (answer);
}

double	Fixed::toDouble( void ) const
{
	double	answer;

	answer = (double)rawBits / (double)(1 << fractBits);
	return (answer);
}

int	Fixed::toInt( void ) const
{
	int	answer;

	answer = rawBits >> Fixed::fractBits;
	return (answer);
}