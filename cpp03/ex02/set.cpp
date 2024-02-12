#include "ClapTrap.hpp"

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

//if amount is smaller than 0, attack is set to 0
void	ClapTrap::setAttackDamage(int amount)
{
	this->attackDamage = (amount < 0) ? 0 : amount;
}

//if amount is smaller than 0, HP is set to 0
void	ClapTrap::setHitPoints(int amount)
{
	this->hitPoints = (amount < 0) ? 0 : amount;
}

//if amount is smaller than 0, energy is set to 0
void	ClapTrap::setEnergyPoints(int amount)
{
	this->energyPoints = (amount < 0) ? 0 : amount;
}

//if amount is smaller than 0, maxhp is set to 0
void ClapTrap::setMaxHitPoints(int amount)
{
	this->maxHitPoints = (amount < 1) ? 1 : amount;
}