#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const& copy);
		FragTrap	&operator=(FragTrap const& frag);
		~FragTrap();

		void		highFiveGuys(void);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, FragTrap const &frag);

#endif