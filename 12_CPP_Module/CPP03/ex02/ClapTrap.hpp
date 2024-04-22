#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {
protected:
	std::string name_;
	unsigned int hp_;
	unsigned int energy_;
	unsigned int damage_;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap& operator=(const ClapTrap &copy);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	bool hasEnergy(void) const;
	bool isAlive(void) const;
	unsigned int getDamage() const;
};

#endif
