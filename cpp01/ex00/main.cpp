#include "Zombie.hpp"

int main(void)
{
	Zombie Blossom;
	Blossom.setName("Blossom");
	Blossom.announce();

	randomChump("Bubbles");

	Zombie *Buttercup = newZombie("Buttercup");
	Buttercup->announce();
	delete Buttercup;
}