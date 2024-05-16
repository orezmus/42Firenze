#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	unsigned int fragHp_;
	unsigned int fragDamage_;
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
