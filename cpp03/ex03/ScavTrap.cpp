#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "[ScavTrap]Default constructor called" << std::endl;
	this->setName("Scav");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setMaxHitPoints(100);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ScavTrap]Name constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setMaxHitPoints(100);
}

ScavTrap::ScavTrap(ScavTrap const& copy) : ClapTrap()
{
	std::cout << "[ScavTrap]Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "[ScavTrap]Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap]Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ScavTrap const &scav)
{
	out	<< "[ScavTrap]\t" << scav.getName() << std::endl
				<< "Hit points: " << scav.getHitPoints() << std::endl
				<< "Energy points: " << scav.getEnergyPoints() << std::endl
				<< "Attack damage: " << scav.getAttackDamage() << std::endl;
	return (out);
}

//if scavTrap has no hp or energy, attack fails
//if attack is 0, it deals no damage
void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[ScavTrap]" << this->name << " is dead and can't attack." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[ScavTrap]" << this->name << " is exausthed and can't attack."<< std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if (this->attackDamage > 0)
	{
		std::cout << "[ScavTrap]" << this->name << " attacks " << target
			<< " and deals " << this->attackDamage << " points of damage." << std::endl;
	}
	else 
	{
		std::cout << "[ScavTrap]" << this->name << " tries to attack "
				<< target << " but deals no damage." << std::endl;
	}
}

//if damage is greater than current hp, hp is set to 0
//if damage is negative, 0 damage is taken
void	ScavTrap::takeDamage(unsigned int amount)
{
	amount = ((int)amount < 0) ? 0 : amount;
	setHitPoints((amount < this->hitPoints) ? (this->hitPoints - amount) : 0);
	std::cout << "[ScavTrap]" << this->name << " took " << amount
			<< " points of damage and now have " << this->hitPoints << " hit points." << std::endl;
}

//if scavTrap has no hp, no energy or amount <= 0, repair fails
//if amount is greater than 0 it heals, if it overheals, it caps at maxHP
void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "[ScavTrap]" << this->name << " is already dead and can't be repaired." << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "[ScavTrap]" << this->name << " is exhausted and can't be repaired." << std::endl;
		return ;
	}
	setEnergyPoints(this->energyPoints - 1);
	if ((int)amount > 0)
	{
		setHitPoints((this->hitPoints + amount) < this->maxHitPoints ? (this->hitPoints + amount) : this->maxHitPoints);

		std::cout << "[ScavTrap]" << this->name << " is repaired by " << amount 
		<< " and has now " << this->hitPoints << " hit points." << std::endl;
	}
	else
	{
		std::cout << "[ScavTrap]" << this->name << " failed to be repaired and has " << 
		this->hitPoints << " hit points." << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (energyPoints <= 0)
	{
		std::cout << "[ScavTrap]" << this->getName() << " is exhausted and can't enter Gate Keeper mode." << std::endl;
		return ;
	}
	if (hitPoints <= 0)
	{
		std::cout << "[ScavTrap]" << this->getName() << " is dead and can't enter Gate Keeper mode." << std::endl;
		return ;
	}
	setEnergyPoints(energyPoints - 1);
	std::cout << "[ScavTrap]" << this->getName() << " enters Gate Keeper mode." << std::endl << "YOU SHALL NOT PASS!!" << std::endl;
}
