#include "DiamondTrap.hpp"

void	print_diamond(DiamondTrap const& diamond) {
	std::cout << "[DiamondT]" << " | "
			<< std::setw(11) << diamond.getName() << " | "
			<< std::setw(13) << diamond.getEnergyPoints() << " | "
			<< std::setw(10) << diamond.getHitPoints() << " | "
			<< std::setw(13) << diamond.getAttackDamage() << std::endl;
}

int main(void) {
	std::cout << "Constructor messages: " << std::endl;
	DiamondTrap	diamond1;
	diamond1.setName("ONE");
	DiamondTrap	diamond2("TWO");
	DiamondTrap	copy1(diamond1);
	DiamondTrap	copy2 = diamond2;

	std::cout << std::endl << "Robots after construction" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_diamond(diamond1);
	print_diamond(diamond2);
	print_diamond(copy1);
	print_diamond(copy2);
	std::cout << std::endl;

	copy1.setName("COPY1");
	copy2.setName("COPY2");

	diamond1.attack(copy1.getName());
	copy1.takeDamage(diamond1.getAttackDamage());
	diamond1.attack(copy2.getName());
	copy2.takeDamage(diamond1.getAttackDamage());

	diamond2.attack(copy1.getName());
	copy1.takeDamage(diamond2.getAttackDamage());
	diamond2.setAttackDamage(100);
	diamond2.attack(copy2.getName());
	copy2.takeDamage(diamond2.getAttackDamage());

	std::cout << std::endl << "Robots after attacks" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_diamond(diamond1);
	print_diamond(diamond2);
	print_diamond(copy1);
	print_diamond(copy2);
	std::cout << std::endl;

	copy1.setEnergyPoints(0);

	diamond1.guardGate();
	diamond2.guardGate();
	copy1.guardGate();
	copy2.guardGate();
	std::cout << std::endl;

	diamond1.highFivesGuys();
	diamond2.highFivesGuys();
	copy1.highFivesGuys();
	copy2.highFivesGuys();
	std::cout << std::endl;

	diamond1.whoAmI();
	diamond2.whoAmI();
	copy1.whoAmI();
	copy2.whoAmI();
	std::cout << std::endl;
}