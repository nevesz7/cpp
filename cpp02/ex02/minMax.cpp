#include "Fixed.hpp"

Fixed const	&Fixed::min(Fixed &first, Fixed &second)
{
	std::cout << "regular min function called" << std::endl;
	if (first < second)
		return (first);
	else
		return (second);
}

Fixed const &Fixed::min(Fixed const &first, Fixed const &second)
{
	std::cout << "const min function called" << std::endl;
	if (first.toFloat() < second.toFloat())
		return (first);
	else
		return (second);
}

Fixed const &Fixed::max(Fixed &first, Fixed &second)
{
	std::cout << "regular max function called" << std::endl;
	if (first > second)
		return (first);
	else
		return (second);
}

Fixed const &Fixed::max(Fixed const &first, Fixed const &second)
{
	std::cout << "const max function called" << std::endl;
	if (first.toFloat() > second.toFloat())
		return (first);
	else
		return (second);
}