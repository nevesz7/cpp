#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Default")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Parameter WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "Copy WrongAnimal assignation called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor for WrongAnimal called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Growl" << std::endl;
}