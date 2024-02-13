#include "Animal.hpp"
#include "WrongAnimal.hpp"

std::string	Animal::getType(void) const
{
	return (this->type);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}