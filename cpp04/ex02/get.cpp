#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>

std::string	Animal::getType(void) const
{
	return (this->type);
}

std::string Brain::getIdea(void) const
{
	return (ideas[rand() % 100]);
}

std::string	Brain::getIdea(int index) const
{
	return(ideas[index]);
}

std::string	Brain::getIdea(int index, std::string type) const
{
	if (type == "cat")
		return (CAT_IDEAS[index]);
	else if (type == "dog")
		return (DOG_IDEAS[index]);
	else
		return ("No idea");
}

Brain*	Cat::getBrain(void) const
{
	return (brain);
}

std::string	Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}

Brain*	Dog::getBrain(void) const
{
	return (brain);
}

std::string	Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}
