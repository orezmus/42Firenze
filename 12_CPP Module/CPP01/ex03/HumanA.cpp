#include "HumanA.hpp"

Weapon default_weapon("default_weapon");

HumanA::HumanA() : weapon_(default_weapon) {

}


HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {

}

HumanA::~HumanA() {

}

void    HumanA::attack()
{
    std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;

}