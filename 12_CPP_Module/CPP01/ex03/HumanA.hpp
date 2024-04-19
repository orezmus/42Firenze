#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

class HumanA {
private:
	std::string name_;
	Weapon &weapon_;

public:
	HumanA();
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void    attack();
};

#endif
