#include "Animal.hpp"

Animal::Animal(void) : type("Default")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Parameter Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "Copy Animal constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal& copy)
{
	std::cout << "Copy Animal assignation called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor for Animal called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Growl" << std::endl;
}