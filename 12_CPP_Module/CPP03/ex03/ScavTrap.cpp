#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hp_ = 100;
	energy_ = 50;
	damage_ = 20;
	guardMode = false;
	std::cout << "ScavTrap " << name_ << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hp_ = 100;
	energy_ = 50;
	damage_ = 20;
	guardMode = false;
	std::cout << "ScavTrap named constructor called: " << name_ << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	guardMode = copy.guardMode;
	std::cout << "ScavTrap copy constructor called: " << name_ << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy){
	if (this != &copy)
	{
		guardMode = copy.guardMode;
		ClapTrap::operator=(copy);
		std::cout << "ScavTrap copy assignment operator called: " << name_ << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called: " << name_ << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (!isAlive() || !hasEnergy())
		return ;
	std::cout << "ScavTrap " << name_ << " attacks " << target;
	std::cout <<  ", causing " << damage_ << " point of damage" << std::endl;
	energy_--;
	std::cout << "ScavTrap " << name_ << " has energy point: " << energy_ << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (!isAlive())
		return ;
	if (guardMode)
	{
		std::cout << "ScavTrap " << name_ << " cannot be attacked: ";
		std::cout << name_ << " is in Gatekeeper mode" << std:: endl;
	}
	else
		ClapTrap::takeDamage(amount);
}

void ScavTrap::guardGate() {
	if (hp_ > 0)
	{
		guardMode = true;
		std::cout << "ScavTrap " << name_ << " is now in Gatekeeper mode" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name_ << " is not in Gatekeeper mode" << std::endl;
}
