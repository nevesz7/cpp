#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(NULL)
{
	this->weapon = &weapon;
	this->name = name;
}

HumanA::~HumanA()
{}

std::string	HumanA::getName()
{
	return name;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon	HumanA::getWeapon()
{
	return *weapon;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}