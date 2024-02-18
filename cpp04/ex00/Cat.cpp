#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Parameter Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = copy;
}

Cat	&Cat::operator=(const Cat& cat)
{
	std::cout << "Copy Cat assignation called" << std::endl;
	if (this != &cat)
		this->type = cat.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor for Cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}