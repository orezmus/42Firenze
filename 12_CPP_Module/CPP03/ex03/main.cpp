#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d1;
	DiamondTrap d2("Tom");
	DiamondTrap d3("Jerry");

	std::cout << std::endl;
	d2.attack("Jerry");
	d3.takeDamage(d2.getDamage());
	std::cout << std::endl;

	d2.whoAmI();
	std::cout << std::endl;

	d2.beRepaired(10);
	std::cout << std::endl;

	d2.guardGate();
	std::cout << std::endl;

	DiamondTrap d4(d2);
	DiamondTrap d5;
	d5 = d3;
	std::cout << std::endl;

	d4.attack("Tom");
	d5.takeDamage(d4.getDamage());
	std::cout << std::endl;

	d4.highFivesGuys();
	std::cout << std::endl;

	d4.attack("Jerry");
	d5.takeDamage(d4.getDamage());
	std::cout << std::endl;

	return 0;
}
