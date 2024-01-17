#include "Zombie.hpp"

Zombie::Zombie(void)
{}

Zombie::~Zombie(void){
	std::cout << getName() << " has died of hunger!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string input)
{
	name = input;
}

std::string	Zombie::getName(void)
{
	return name;
}
