#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Parameter Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = copy;
}

Dog	&Dog::operator=(const Dog& dog)
{
	std::cout << "Copy Dog assignation called" << std::endl;
	if (this != &dog)
		this->type = dog.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor for Dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}