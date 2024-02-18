#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main ()
{
	// Animal test;
	Cat cat;
	Dog dog;

	std::cout << std::endl;
	std::cout << cat.getType() << " is thinking: \"" << cat.getIdea(42) << "\" but says: " << std::endl;
	std::cout << dog.getType() << " is thinking: \"" << dog.getIdea(42) << "\" but says: " << std::endl;

	std::cout << std::endl << "----------------- Default destructors:-----------------" << std::endl;
}