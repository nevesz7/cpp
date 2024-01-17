#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL)
{
	this->name = name;
}

HumanB::~HumanB()
{}

std::string	HumanB::getName()
{
	return name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon	HumanB::getWeapon()
{
	return *weapon;
}

void HumanB::attack()
{
	if (!this->weapon)
	{
		std::cout << this->name << " needs a weapon to attack" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}