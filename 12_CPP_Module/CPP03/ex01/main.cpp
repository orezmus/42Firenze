#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap s0;
	ScavTrap s1("Tom");
	ScavTrap s2("Jerry");

	std::cout << std::endl;
	s1.attack("Jerry");
	s2.takeDamage(s1.getDamage());
	std::cout << std::endl;

	s2.beRepaired(10);
	std::cout << std::endl;

	s2.guardGate();
	std::cout << std::endl;

	ScavTrap s3(s1);
	ScavTrap s4;
	s4 = s2;
	std::cout << std::endl;

	s4.attack("Tom");
	s3.takeDamage(s4.getDamage());
	std::cout << std::endl;

	s0.attack("Jerry");
	s4.takeDamage(s0.getDamage());
	std::cout << std::endl;

	return 0;
}
