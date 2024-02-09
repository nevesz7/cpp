#include "ClapTrap.hpp"

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	this->hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->energyPoints = amount;
}

void ClapTrap::setMaxHitPoints(unsigned int amount)
{
	this->maxHitPoints = amount;
}