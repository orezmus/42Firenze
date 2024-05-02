#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hp_ = 100;
	energy_ = 100;
	damage_ = 30;
	fragHp_ = hp_;
	fragDamage_ = damage_;
	std::cout << "FragTrap " << name_ << " constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hp_ = 100;
	energy_ = 100;
	damage_ = 30;
	fragHp_ = hp_;
	fragDamage_ = damage_;
	std::cout << "FragTrap named constructor called: " << name_ << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called: " << name_ << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy){
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		std::cout << "FragTrap copy assignment operator called: " << name_ << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called: " << name_ << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (!isAlive() || !hasEnergy())
		return ;
	std::cout << "FragTrap " << name_ << " attacks " << target;
	std::cout <<  ", causing " << damage_ << " point of damage" << std::endl;
	energy_--;
	std::cout << "FragTrap " << name_ << " has energy point : " << energy_ << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name_ << ": positive high fives request" << std::endl;
}
