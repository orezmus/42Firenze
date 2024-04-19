#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;

	zombies = zombieHorde(10, "Xilly");
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	delete [] zombies;
}
