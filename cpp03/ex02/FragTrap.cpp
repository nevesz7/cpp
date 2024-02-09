#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "[FragTrap]Default constructor called" << std::endl;
	this->setName("Frag");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setMaxHitPoints(100);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[FragTrap]Name constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setMaxHitPoints(100);
}

FragTrap::FragTrap(FragTrap const& copy) : ClapTrap()
{
	std::cout << "[FragTrap]Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "[FragTrap]Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap]Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, FragTrap const &scav)
{
	out	<< "[FragTrap]\t" << scav.getName() << std::endl
				<< "Hit points: " << scav.getHitPoints() << std::endl
				<< "Energy points: " << scav.getEnergyPoints() << std::endl
				<< "Attack damage: " << scav.getAttackDamage() << std::endl;
	return (out);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[FragTrap]" << this->name << " is dead and can't attack." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is exausthed and can't attack."<< std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if (this->attackDamage > 0)
	{
		std::cout << "[FragTrap]" << this->name << " "
			<< 
		" attacks " << target
			<< "and deals " << this->attackDamage << " points of damage." << std::endl;
	}
	else 
	{
		std::cout << "[FragTrap]" << this->name << "tries to attack "
				<< target << " but deals no damage." << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	setHitPoints((amount < this->hitPoints) ? (this->hitPoints - amount) : 0);
	std::cout << "[FragTrap]" << this->name << " took " << amount
			<< " points of damage and now have " << this->hitPoints << " hit points." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[FragTrap]" << this->name << " is already dead and can't be repaired." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[FragTrap]" << this->name << " is exhausted and can't be repaired." << std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if (amount > 0)
	{
		setHitPoints((this->hitPoints + amount) < this->maxHitPoints ? (this->hitPoints + amount) : this->maxHitPoints);

		std::cout << "[FragTrap]" << this->name << " is repaired by " << amount 
		<< " and has now " << this->hitPoints << " hit points." << std::endl;
	}
	else
	{
		std::cout << "[FragTrap]" << this->name << " failed to be repaired and has " << 
		this->hitPoints << " hit points." << std::endl;
	}
}

void	FragTrap::HighFivesGuys(void)
{
	if (energyPoints <= 0)
	{
		std::cout << "[FragTrap]" << this->getName() << " is exhausted and can't enter High Five mode." << std::endl;
		return ;
	}
	if (hitPoints <= 0)
	{
		std::cout << "[FragTrap]" << this->getName() << " is dead and can't enter High Five mode." << std::endl;
		return ;
	}
	setEnergyPoints(energyPoints - 1);
	std::cout << "[FragTrap]" << this->getName() << " enters High Five mode." << std::endl << "~smack~\nThis was legen...wait for it...DARY!!" << std::endl;
}