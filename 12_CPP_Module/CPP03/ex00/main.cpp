#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1("Tom");
	ClapTrap c2("Jerry");


	std::cout << std::endl;
	for (int i = 5; i > 0; i--)
	{
		c1.attack("Jerry");
		c2.takeDamage(c1.getDamage());
		std::cout << std::endl;
	}

	c1.beRepaired(10);
    std::cout << std::endl;

    ClapTrap c3(c1);
	ClapTrap c4;
    c4 = c2;
	std::cout << std::endl;
    while (c3.isAlive() && c4.isAlive() && c3.hasEnergy() && c4.hasEnergy())
	{
		c4.attack("Tom");
		c3.takeDamage(c4.getDamage());
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}