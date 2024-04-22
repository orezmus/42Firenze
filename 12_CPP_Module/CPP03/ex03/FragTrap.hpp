#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &copy);
    void attack(const std::string& target);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif