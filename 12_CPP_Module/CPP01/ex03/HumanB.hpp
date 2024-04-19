#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

class HumanB {
private:
	std::string name_;
	Weapon *weapon_;

public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void    setWeapon(Weapon &weapon);
	void    attack();
};

#endif
