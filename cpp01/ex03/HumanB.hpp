#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB {
	private:
	std::string	name;
	Weapon	*weapon;

	public:
	HumanB(std::string name);
	~HumanB();
	std::string	getName();
	Weapon	getWeapon();
	void	setWeapon(Weapon &weapon);
	void	attack();
};

#endif