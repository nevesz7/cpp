#include "Zombie.hpp"

int	main()
{
	int		max = 15;
	Zombie	*horde;

	horde = zombieHorde(max);
	for (int i = 0; i < max; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}