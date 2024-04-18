#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	randomChump("Willy");
	zombie = newZombie("Billy");
	zombie->announce();

	delete zombie;
}
