#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void runPDFTest(void)
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;

return ;
}

void runCatIdeas(void)
{
	std::cout << std::endl << "Cat ideas:" << std::endl;
	const Animal* cat = new Cat();
	const Cat* cat2 = new Cat();
	Cat cat3;
	Cat cat4 = cat3;

	std::cout << std::endl;
	std::cout << cat->getType() << " thinks: " << static_cast<const Cat*>(cat)->getIdea(40) << std::endl;
	std::cout << cat2->getType() << " thinks: " << cat2->getIdea(02) << std::endl;
	std::cout << cat3.getType() << " thinks: " << cat3.getIdea(89) << std::endl;
	std::cout << cat4.getType() << " thinks: " << cat4.getIdea(22) << std::endl << std::endl;

	delete cat, delete cat2;
}

void runDogIdeas(void)
{
	std::cout << std::endl << "Dog ideas:" << std::endl;
	const Animal* dog = new Dog();
	const Dog* dog2 = new Dog();
	const Animal* dog3 = new Animal("Dog");

	std::cout << std::endl << dog->getType() << " thinks: " << static_cast<const Dog*>(dog)->getIdea(3) << std::endl;
	std::cout << dog2->getType() << " thinks: " << dog2->getIdea(14) << std::endl;
	std::cout << dog3->getType() << " thinks: " << static_cast<const Dog*>(dog)->getIdea(15) << std::endl << std::endl;
	
	delete dog, delete dog2, delete dog3;
}


void runArrayTest(void)
{
	std::cout << std::endl << "Array test:" << std::endl;
	Animal* animals[10];

	for (ulong i = 0; i < 10; i++)
	{
		animals[i++] = new Dog();
		animals[i] = new Cat();
	}

	std::cout << std::endl;
	for (ulong i = 0; i < 10; i++)
	{
		std::cout << (dynamic_cast<Cat*>(animals[i]) ? dynamic_cast<Cat*>(animals[i])->getType() + " thinks: " + dynamic_cast<Cat*>(animals[i])->getBrain()->getIdea() + " but 'says': " :
					dynamic_cast<Dog*>(animals[i]) ? dynamic_cast<Dog*>(animals[i])->getType() + " thinks: " + dynamic_cast<Dog*>(animals[i])->getBrain()->getIdea() + " but 'says': " :
					"") << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (ulong i = 0; i < 10; i++)
    {
        delete animals[i];
    }
}

int main(void)
{
	std::cout << "PDF tests:" << std::endl;
	runPDFTest();
	
	runDogIdeas();
	runCatIdeas();

	runArrayTest();
}