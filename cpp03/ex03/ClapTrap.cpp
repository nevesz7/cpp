#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Clap"), hitPoints(10), energyPoints(10), attackDamage(0), maxHitPoints(10)
{
	std::cout << "[ClapTrap]Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) , maxHitPoints(10)
{
	std::cout << "[ClapTrap]Name constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "[ClapTrap]Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "[ClapTrap]Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->hitPoints = other.getHitPoints();
		this->energyPoints = other.getEnergyPoints();
		this->attackDamage = other.getAttackDamage();
		this->maxHitPoints = other.getMaxHitPoints();
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap]Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &clap)
{
	out	<< "[ClapTrap]\t" << clap.getName() << std::endl
				<< "Hit points: " << clap.getHitPoints() << std::endl
				<< "Energy points: " << clap.getEnergyPoints() << std::endl
				<< "Attack damage: " << clap.getAttackDamage() << std::endl;
	return (out);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[ClapTrap]" << this->name << " is dead and can't attack." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[ClapTrap]" << this->name << " is exausthed and can't attack."<< std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if (this->attackDamage > 0)
	{
		std::cout << "[ClapTrap]" << this->name << " "
			<< 
		" attacks " << target
			<< "and deals " << this->attackDamage << " points of damage." << std::endl;
	}
	else 
	{
		std::cout << "[ClapTrap]" << this->name << "tries to attack "
				<< target << " but deals no damage." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	setHitPoints((amount < this->hitPoints) ? (this->hitPoints - amount) : 0);
	std::cout << "[ClapTrap]" << this->name << " took " << amount
			<< " points of damage and now have " << this->hitPoints << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[ClapTrap]" << this->name << " is already dead and can't be repaired." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[ClapTrap]" << this->name << " is exhausted and can't be repaired." << std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if (amount > 0)
	{
		setHitPoints((this->hitPoints + amount) < this->maxHitPoints ? (this->hitPoints + amount) : this->maxHitPoints);

		std::cout << "[ClapTrap]" << this->name << " is repaired by " << amount 
		<< " and has now " << this->hitPoints << " hit points." << std::endl;
	}
	else
	{
		std::cout << "[ClapTrap]" << this->name << " failed to be repaired and has " << 
		this->hitPoints << " hit points." << std::endl;
	}
}