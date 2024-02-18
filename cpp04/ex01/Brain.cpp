#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = copy;
}

Brain	&Brain::operator=(const Brain& brain)
{
	std::cout << "Copy Brain assignation called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = brain.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor for Brain called" << std::endl;
}

void	Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
	return ;
}