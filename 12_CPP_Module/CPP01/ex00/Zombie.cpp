#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) : name_(name) {
}

void Zombie::announce(void) {
	std::cout << name_ << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << name_ << " : is destructed" << std::endl;
}
