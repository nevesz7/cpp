#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const& copy);
		ScavTrap	&operator=(ScavTrap const& scav);
		~ScavTrap();

		void		guardGate();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, ScavTrap const &scav);

#endif