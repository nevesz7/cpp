#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void runPDFTest(void)
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete j;
delete i;
delete meta;
}

void runWrongAnimalTest(void)
{
	std::cout << std::endl << "Wrong animal tests:" << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* wrongCat2 = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongCat2->getType() << " " << std::endl;
	
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	wrongCat2->makeSound();
	// static_cast<WrongCat*>(wrongCat)->makeSound();

	delete wrongAnimal;
	delete wrongCat;
	delete wrongCat2;
}

void runNoPointerTest(void)
{
	std::cout << std::endl << "No ptr tests:" << std::endl;
	const Animal meta;
	const Animal dog("Dog");
	const Cat cat("Cat");

	std::cout << dog.getType() << " " << std::endl;
	std::cout << cat.getType() << " " << std::endl;

	// meta.makeSound();
	dog.makeSound();
	cat.makeSound();
}

void runNoPointerWrongAnimalTest(void)
{
	std::cout << std::endl << "No ptr wrong animal tests:" << std::endl;
	const WrongAnimal wrongMeta;
	const WrongAnimal wrongCat("Cat");
	const WrongCat wrongCat2("Cat");

	std::cout << wrongCat.getType() << " " << std::endl;
	std::cout << wrongCat2.getType() << " " << std::endl;

	// wrongMeta.makeSound();
	wrongCat.makeSound();
	wrongCat2.makeSound();
	// static_cast<WrongCat>(wrongCat)->makeSound();
}

void runNoConstTest(void)
{
	std::cout << std::endl << "No const tests:" << std::endl;
	Animal* meta = new Animal();
	Animal* dog = new Animal("Dog");
	Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	// meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	delete meta;
	delete dog;
	delete cat;
}

void runNoConstWrongAnimalTest(void)
{
	std::cout << std::endl << "No const wrongAnimal tests:" << std::endl;
	WrongAnimal* wrongMeta = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	WrongCat* wrongCat2 = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongCat2->getType() << " " << std::endl;

	// wrongMeta->makeSound();
	wrongCat->makeSound();
	static_cast<WrongCat*>(wrongCat)->makeSound();
	wrongCat2->makeSound();

	delete wrongMeta;
	delete wrongCat;
	delete wrongCat2;
}

int main(void)
{
	std::cout << "PDF tests:" << std::endl;
	runPDFTest();
	runWrongAnimalTest();
	
	runNoPointerTest();
	runNoPointerWrongAnimalTest();

	runNoConstTest();
	runNoConstWrongAnimalTest();
}