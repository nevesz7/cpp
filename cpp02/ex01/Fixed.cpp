#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = value << Fixed::fractBits;
	return ;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = (int)roundf(value * (1 << Fixed::fractBits));
	return ;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( Fixed const &copied )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copied)
		this->rawBits = copied.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

void	Fixed::setRawBits( int const rawBits )
{
	this->rawBits = rawBits;
}

std::ostream &operator<<(std::ostream &outputFile, Fixed const &f)
{
	outputFile << f.toFloat();
	return (outputFile);
}