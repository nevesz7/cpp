#include "ClapTrap.hpp"

void	print_clap(ClapTrap const& clap) {
	std::cout << "[ClapTrap]" << " | "
			<< std::setw(11) << clap.getName() << " | "
			<< std::setw(13) << clap.getEnergyPoints() << " | "
			<< std::setw(10) << clap.getHitPoints() << " | "
			<< std::setw(13) << clap.getAttackDamage() << std::endl;
}

int main(void) {
	std::cout << "Constructor messages: " << std::endl;
	ClapTrap	clap1;
	clap1.setName("ONE");
	ClapTrap	clap2("TWO");
	ClapTrap	copy1(clap1);
	ClapTrap	copy2 = clap2;

	std::cout << std::endl << "Robots after construction" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_clap(clap1);
	print_clap(clap2);
	print_clap(copy1);
	print_clap(copy2);
	std::cout << std::endl;

	copy1.setName("COPY1");
	copy2.setName("COPY2");
	clap1.setAttackDamage(-1);
	clap2.setAttackDamage(0);
	copy1.setAttackDamage(3);
	copy2.setAttackDamage(10);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAttackDamage());

	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());

	copy1.attack(copy2.getName());
	copy2.takeDamage(copy1.getAttackDamage());

	copy2.attack(copy1.getName());
	copy1.takeDamage(copy2.getAttackDamage());
	copy1.attack(copy2.getName());
	copy2.setEnergyPoints(0);
	copy2.attack(copy1.getName());

	clap1.setAttackDamage(50);

	clap1.attack(copy1.getName());
	copy1.takeDamage(clap1.getAttackDamage());

	clap1.attack(copy2.getName());
	copy2.takeDamage(clap1.getAttackDamage());

	std::cout << std::endl << "Robots after attacks" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_clap(clap1);
	print_clap(clap2);
	print_clap(copy1);
	print_clap(copy2);
	std::cout << std::endl;

	clap1.setMaxHitPoints(50);
	copy1.setHitPoints(10);

	clap1.beRepaired(100);
	clap2.beRepaired(10);
	copy1.beRepaired(-1);

	copy2.beRepaired(0);
	copy2.setHitPoints(1);
	copy2.beRepaired(0);
	copy2.setEnergyPoints(1);
	copy2.beRepaired(0);

	std::cout << std::endl << "Robots after repairs" << std::endl;
	std::cout << "   TYPE    |     NAME    | ENERGY POINTS | HIT POINTS | ATTACK DAMAGE" << std::endl;
	print_clap(clap1);
	print_clap(clap2);
	print_clap(copy1);
	print_clap(copy2);
	std::cout << std::endl;
}
