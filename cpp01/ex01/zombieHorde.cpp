#include "Zombie.hpp"

Zombie*	zombieHorde(int max)
{
	Zombie*	horde;

	horde = new Zombie[max];
	for (int index = 0; index < max; index++)
		horde[index].setName(NAMES[index]);
	return (horde);
}