#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name_;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap& operator=(const DiamondTrap &copy);
    ~DiamondTrap();

	void attack(const std::string& target);
    void whoAmI();
	
};

#endif