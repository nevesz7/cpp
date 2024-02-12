#include "DiamondTrap.hpp"

std::string	DiamondTrap::getName(void) const
{
	return (this->name);
}

void	DiamondTrap::setName(std::string name)
{
	this->name = name;
	ClapTrap::name = (name + "_clap_name");
}

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondT]Default constructor called" << std::endl;
	this->setName("Diamond");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	this->setMaxHitPoints(FragTrap::getMaxHitPoints());
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "[DiamondT]Name constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	this->setMaxHitPoints(FragTrap::getMaxHitPoints());
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondT]Copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "[DiamondT]Copy assignment operator called" << std::endl;
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
	std::cout << "[DiamondT]Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, DiamondTrap const &diamond)
{
	out	<< "[DiamondT]\t" << diamond.getName() << std::endl
				<< "Hit points: " << diamond.getHitPoints() << std::endl
				<< "Energy points: " << diamond.getEnergyPoints() << std::endl
				<< "Attack damage: " << diamond.getAttackDamage() << std::endl;
	return (out);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

//if damage is greater than current hp, hp is set to 0
//if damage is negative, 0 damage is taken
void	DiamondTrap::takeDamage(unsigned int amount)
{
	amount = ((int)amount < 0) ? 0 : amount;
	setHitPoints((amount < this->hitPoints) ? (this->hitPoints - amount) : 0);
	std::cout << "[DiamondT]" << this->name << " took " << amount
			<< " points of damage and now have " << this->hitPoints << " hit points." << std::endl;
}

//if DiamondTrap has no hp, no energy or amount <= 0, repair fails
//if amount is greater than 0 it heals, if it overheals, it caps at maxHP
void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[DiamondT]" << this->name << " is already dead and can't be repaired." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[DiamondT]" << this->name << " is exhausted and can't be repaired." << std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if ((int)amount > 0)
	{
		setHitPoints((this->hitPoints + amount) < this->maxHitPoints ? (this->hitPoints + amount) : this->maxHitPoints);

		std::cout << "[DiamondT]" << this->name << " is repaired by " << amount 
		<< " and has now " << this->hitPoints << " hit points." << std::endl;
	}
	else
	{
		std::cout << "[DiamondT]" << this->name << " failed to be repaired and has " << 
		this->hitPoints << " hit points." << std::endl;
	}
}

void DiamondTrap::whoAmI(void)
{
  std::cout << "[DiamondT]" << this->getName() << " says: \"My name is " << this->getName() << " and my ClapTrap name is " << ClapTrap::getName() << "\"." << std::endl;
}
