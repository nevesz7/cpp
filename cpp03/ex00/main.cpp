#include "ClapTrap.hpp"

int main(void) {
	std::cout << "Constructor messages: " << std::endl;
	ClapTrap	clap1;
	clap1.setName("one");
	ClapTrap	clap2("two");
	ClapTrap	copy(clap1);
	ClapTrap	copy2 = clap2;
	std::cout << std::endl;

	
}


attack  		<0 0 >0 >totalhp
takedmg 		<0 0 >0 >totalhp
be repaired 	<0 0 >0 >totalhp
standard constructor
name constructor
copy constructor
copy assignment 
set	name;
get	name;
set	hitPoints;
get	hitPoints;
set	energyPoints;
get	energyPoints;
set	attackDamage;
get	attackDamage;
set	maxHitPoints;
get	maxHitPoints;