#include "ClapTrap.hpp"

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getMaxHitPoints(void) const
{
	return (this->maxHitPoints);
}
