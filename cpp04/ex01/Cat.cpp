#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, this->brain->getIdea(i, "cat"));
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Parameter Cat constructor called" << std::endl;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, this->brain->getIdea(i, "cat"));
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Copy Cat constructor called" << std::endl;
    this->brain = new Brain(*(copy.getBrain()));
}

Cat& Cat::operator=(const Cat& cat) {
    std::cout << "Copy Cat assignation called" << std::endl;
    if (this != &cat) {
        this->type = cat.getType(); 
        delete this->brain;
        this->brain = new Brain(*(cat.getBrain()));
    }
    return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Destructor for Cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}