#include "Intern.hpp"

Intern::Intern() : type("Default")
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Copy Intern assignation called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor for Intern called" << std::endl;
}
