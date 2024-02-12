#include "FragTrap.hpp"

void	print_frag(FragTrap const& frag) {
	std::cout << "[FragTrap]" << " | "
			<< std::setw(11) << frag.getName() << " | "
			<< std::setw(13) << frag.getEnergyPoints() << " | "
			<< std::setw(10) << frag.getHitPoints() << " | "
			<< std::setw(13) << frag.getAttackDamage() << std::endl;
}

int main(void) {
	std::cout << "Constructor messages: " << std::endl;
	FragTrap	frag1;
	frag1.setName("ONE");
	FragTrap	frag2("TWO");
	FragTrap	copy1(frag1);
	FragTrap	copy2 = frag2;

	std::cout << std::endl << "Robots after construction" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_frag(frag1);
	print_frag(frag2);
	print_frag(copy1);
	print_frag(copy2);
	std::cout << std::endl;

	copy1.setName("COPY1");
	copy2.setName("COPY2");

	frag1.attack(copy1.getName());
	copy1.takeDamage(frag1.getAttackDamage());
	frag1.attack(copy2.getName());
	copy2.takeDamage(frag1.getAttackDamage());

	frag2.attack(copy1.getName());
	copy1.takeDamage(frag2.getAttackDamage());
	frag2.setAttackDamage(100);
	frag2.attack(copy2.getName());
	copy2.takeDamage(frag2.getAttackDamage());

	std::cout << std::endl << "Robots after attacks" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_frag(frag1);
	print_frag(frag2);
	print_frag(copy1);
	print_frag(copy2);
	std::cout << std::endl;

	copy1.setEnergyPoints(0);

	frag1.highFivesGuys();
	frag2.highFivesGuys();
	copy1.highFivesGuys();
	copy2.highFivesGuys();
	std::cout << std::endl;
}