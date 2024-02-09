#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "Initializing messages:" << std::endl;
	DiamondTrap	robot1;
	DiamondTrap	robot2("Wall-E");
	DiamondTrap	robot3(robot2);
	std::cout << std::endl << robot1 << robot2 << robot3 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Fights:" << std::endl;
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	std::cout << std::endl << robot1 << robot2 << robot3 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Healing:" << std::endl;
	robot2.beRepaired(50);
	std::cout << std::endl << robot1 << robot2 << robot3 << std::endl;
	std::cout << robot1.ClapTrap::getName() << std::endl;
	std::cout << robot1.ScavTrap::getName() << std::endl;
	std::cout << robot1.FragTrap::getName() << std::endl;
	std::cout << robot1.DiamondTrap::getName() << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Special function:" << std::endl;
	robot1.HighFivesGuys();
	robot1.whoAmI();
	robot2.HighFivesGuys();
	robot2.whoAmI();
	robot3.whoAmI();
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Destruction messages:" << std::endl;
	return (0);
}