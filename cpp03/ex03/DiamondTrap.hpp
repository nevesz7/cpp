#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string		name;
	public:
		DiamondTrap();
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const& copy);
		DiamondTrap	&operator=(DiamondTrap const& diamond);
		~DiamondTrap();

		void		whoAmI();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);		
		
		std::string		getName(void) const;
		void			setName(std::string name);
};

std::ostream &operator<<(std::ostream &out, DiamondTrap const &diamond);

#endif