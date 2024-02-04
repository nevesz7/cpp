#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &outputFile, Fixed const &f)
{
	outputFile << f.toFloat();
	return (outputFile);
}

bool Fixed::operator>(Fixed const &other)
{
	if (this->getRawBits() > other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const &other)
{
	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &other)
{
	if (this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &other)
{
	if (this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &other)
{
	if (this->getRawBits() == other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &other)
{
	if (this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(Fixed const &other)
{
	Fixed	add;

	add.setRawBits(this->getRawBits() + other.getRawBits());
	return add;
}

Fixed Fixed::operator-(Fixed const &other)
{
	Fixed	sub;

	sub.setRawBits(this->getRawBits() - other.getRawBits());
	return sub;	
}

Fixed Fixed::operator*(Fixed const &other)
{
	Fixed mult(this->toFloat() * other.toFloat());

	return mult;
}

Fixed Fixed::operator/(Fixed const &other)
{
	Fixed div(this->toFloat() / other.toFloat());

	return div;
}

Fixed &Fixed::operator++( void )
{
	this->rawBits++;
	return (*this);
}

Fixed &Fixed::operator--( void )
{
	this->rawBits--;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed non_increment(*this);
	this->rawBits++;
	return non_increment;
}

Fixed Fixed::operator--( int )
{
	Fixed non_decrement(*this);
	this->rawBits--;
	return non_decrement;
}