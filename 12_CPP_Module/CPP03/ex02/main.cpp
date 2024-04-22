#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap c1;
	ScavTrap s1("Tom");
	FragTrap f1("Jerry");

	std::cout << std::endl;
	s1.attack("Jerry");
	f1.takeDamage(s1.getDamage());
	std::cout << std::endl;

	s1.beRepaired(10);
	std::cout << std::endl;

	s1.guardGate();
	std::cout << std::endl;

	ScavTrap s2(s1);
	FragTrap f2;
	f2 = f1;
	std::cout << std::endl;

	f2.attack("Tom");
	s2.takeDamage(f2.getDamage());
	std::cout << std::endl;

	f1.highFivesGuys();
	std::cout << std::endl;

	c1.attack("Jerry");
	s2.takeDamage(c1.getDamage());
	std::cout << std::endl;

	return 0;
}
