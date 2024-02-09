#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	std::cout << "Initializing messages:" << std::endl;
	ClapTrap robot1("Wall-E");
	ScavTrap robot2;
	FragTrap robot3;
	FragTrap robot4("Eve");
	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Fights:" << std::endl;
	robot3.attack(robot4.getName());
	robot4.takeDamage(robot3.getAttackDamage());
	robot1.setAttackDamage(10);
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	std::cout << std::endl << robot1 << robot2 << robot3 << robot4 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Healing:" << std::endl;
	robot4.beRepaired(50);
	std::cout << std::endl << robot1 << robot2 << robot3 << robot4 << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Special function:" << std::endl;
	robot2.guardGate();
	robot3.highFiveGuys();
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Destruction messages:" << std::endl;
	return (0);
}