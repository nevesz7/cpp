#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		unsigned int	maxHitPoints;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap	&operator=(ClapTrap const& clap);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		unsigned int	getMaxHitPoints(void) const;

		void			setName(std::string name);
		void			setHitPoints(int amount);
		void			setEnergyPoints(int amount);
		void			setAttackDamage(int amount);
		void			setMaxHitPoints(int amount);
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &clap);

#endif