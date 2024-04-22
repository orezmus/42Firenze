#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
	bool guardMode;

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &copy);
	~ScavTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);

	void guardGate();
};

#endif
