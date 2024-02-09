#include "DiamondTrap.hpp"

std::string	DiamondTrap::getName(void) const
{
	return (this->name);
}

void	DiamondTrap::setName(std::string name)
{
	this->name = name;
}

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap]Default constructor called" << std::endl;
	this->setName("Diamond");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	this->setMaxHitPoints(FragTrap::getMaxHitPoints());
	ClapTrap::name = (this->getName() + "_clap_name");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "[DiamondTrap]Name constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	this->setMaxHitPoints(FragTrap::getMaxHitPoints());
	ClapTrap::name = (this->getName() + "_clap_name");
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap]Copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "[DiamondTrap]Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
		ClapTrap::name = (this->getName() + "_clap_name");
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap]Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, DiamondTrap const &diamond)
{
	out	<< "[DiamondTrap]\t" << diamond.getName() << std::endl
				<< "Hit points: " << diamond.getHitPoints() << std::endl
				<< "Energy points: " << diamond.getEnergyPoints() << std::endl
				<< "Attack damage: " << diamond.getAttackDamage() << std::endl;
	return (out);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	setHitPoints((amount < this->hitPoints) ? (this->hitPoints - amount) : 0);
	std::cout << "[DiamondTrap]" << this->name << " took " << amount
			<< " points of damage and now have " << this->hitPoints << " hit points." << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[DiamondTrap]" << this->name << " is already dead and can't be repaired." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[DiamondTrap]" << this->name << " is exhausted and can't be repaired." << std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	setHitPoints((this->hitPoints + amount) < this->maxHitPoints ? (this->hitPoints + amount) : this->maxHitPoints);

	std::cout << "[DiamondTrap]" << this->name << " is repaired by " << amount 
		<< " and has now " << this->hitPoints << " hit points." << std::endl;
}

void DiamondTrap::whoAmI(void)
{
  std::cout << "[DiamondTrap]" << this->getName() << " says: \"My name is " << this->getName() << " and my ClapTrap name is " << ClapTrap::getName() << "\"." << std::endl;
}
