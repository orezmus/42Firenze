#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::Zombie(std::string name) : name_(name) {

}

void Zombie::announce(void) {
	std::cout << name_ << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name_ = name;
}

Zombie::~Zombie() {
	std::cout << name_ << " : is destructed" << std::endl;
}
