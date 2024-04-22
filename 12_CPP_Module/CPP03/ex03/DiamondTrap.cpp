#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name_(ClapTrap::name_) {
	ClapTrap::name_ += "_clap_name";
    hp_ = FragTrap::hp_;
	energy_ = ScavTrap::energy_;
	damage_ = FragTrap::hp_;
	//guardMode = false;
	std::cout << "DiamondTrap " << name_ << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name) {
	hp_ = FragTrap::hp_;
	energy_ = ScavTrap::energy_;
	damage_ = FragTrap::hp_;
	//guardMode = false;
	std::cout << "DiamondTrap named constructor called: " << name_ << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy) {
	guardMode = copy.guardMode;
	std::cout << "DiamondTrap copy constructor called: " << name_ << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy){
	if (this != &copy)
	{
		guardMode = copy.guardMode;
		ClapTrap::operator=(copy);
		std::cout << "DiamondTrap copy assignment operator called: " << name_ << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called: " << name_ << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "Who am I?" << std::endl;  
    std::cout << "DiamondTrap name: " << name_ << std::endl;
    std::cout << "DiamondTrap's ClapTrap name: " << ClapTrap::name_ << std::endl;
}
