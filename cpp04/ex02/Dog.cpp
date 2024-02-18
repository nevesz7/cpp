#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, this->brain->getIdea(i, "dog"));
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Parameter Dog constructor called" << std::endl;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, this->brain->getIdea(i, "dog"));
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Copy Dog constructor called" << std::endl;
    this->brain = new Brain(*(copy.getBrain()));
}

Dog& Dog::operator=(const Dog& dog) {
    std::cout << "Copy Dog assignation called" << std::endl;
    if (this != &dog) {
        this->type = dog.getType();
        delete this->brain;
        this->brain = new Brain(*(dog.getBrain()));
    }
    return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Destructor for Dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}