#include "ScavTrap.hpp"

void	print_scav(ScavTrap const& scav) {
	std::cout << "[ScavTrap]" << " | "
			<< std::setw(11) << scav.getName() << " | "
			<< std::setw(13) << scav.getEnergyPoints() << " | "
			<< std::setw(10) << scav.getHitPoints() << " | "
			<< std::setw(13) << scav.getAttackDamage() << std::endl;
}

int main(void) {
	std::cout << "Constructor messages: " << std::endl;
	ScavTrap	scav1;
	scav1.setName("ONE");
	ScavTrap	scav2("TWO");
	ScavTrap	copy1(scav1);
	ScavTrap	copy2 = scav2;

	std::cout << std::endl << "Robots after construction" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_scav(scav1);
	print_scav(scav2);
	print_scav(copy1);
	print_scav(copy2);
	std::cout << std::endl;

	copy1.setName("COPY1");
	copy2.setName("COPY2");


	scav1.attack(copy1.getName());
	copy1.takeDamage(scav1.getAttackDamage());
	scav1.attack(copy2.getName());
	copy2.takeDamage(scav1.getAttackDamage());

	scav2.attack(copy1.getName());
	copy1.takeDamage(scav2.getAttackDamage());
	scav2.setAttackDamage(100);
	scav2.attack(copy2.getName());
	copy2.takeDamage(scav2.getAttackDamage());

	std::cout << std::endl << "Robots after attacks" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_scav(scav1);
	print_scav(scav2);
	print_scav(copy1);
	print_scav(copy2);
	std::cout << std::endl;

	copy1.setEnergyPoints(0);
	std::cout << std::endl;

	scav1.guardGate();
	scav2.guardGate();
	copy1.guardGate();
	copy2.guardGate();
	std::cout << std::endl;
}