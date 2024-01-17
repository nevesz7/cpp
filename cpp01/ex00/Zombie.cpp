#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(void){
	std::cout << get_name() << " has died of hunger!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string input)
{
	name = input;
}

std::string	Zombie::get_name(void)
{
	return name;
}