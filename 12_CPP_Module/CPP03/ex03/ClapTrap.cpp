#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("defalut"), hp_(10), energy_(10), damage_(0) {
	std::cout << "ClapTrap " << name_ << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hp_(10), energy_(10), damage_(0) {
	std::cout << "ClapTrap named constructor called: " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	name_ = copy.name_;
	hp_ = copy.hp_;
	energy_ = copy.energy_;
	damage_ = copy.damage_;
	std::cout << "ClapTrap copy constructor called: " << name_ << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy){
	name_ = copy.name_;
	hp_ = copy.hp_;
	energy_ = copy.energy_;
	damage_ = copy.damage_;
	std::cout << "ClapTrap copy assignment operator called: " << name_ << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called: " << name_ << std::endl;
}

unsigned int ClapTrap::getDamage() const{
	return damage_;
}

bool ClapTrap::hasEnergy(void) const{
	if (energy_ < 1)
	{
		std::cout << "ClapTrap " << name_ << " has no energy point" << std::endl;
		return false;
	}
	return true;
}

bool ClapTrap::isAlive(void) const {
	if (hp_ < 1)
	{
		std::cout << "ClapTrap" << name_ << " is already dead" << std::endl;
		return false;
	}
	return true; 
}

void ClapTrap::attack(const std::string& target) {
	if (!isAlive() || !hasEnergy())
		return ;
	std::cout << "ClapTrap " << name_ << " attacks " << target;
	std::cout <<  ", causing " << damage_ << " point of damage" << std::endl;
	energy_--;
	std::cout << "ClapTrap " << name_ << " has energy point: " << energy_ << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!isAlive())
		return ;
	if (hp_ <= amount)
	{
		hp_ = 0;
		std::cout << "ClapTrap " << name_ << " has taken ";
		std::cout << amount << " point of damage" << std:: endl;
		std::cout << "ClapTrp " << name_ << " is dead" << std:: endl;
	}
	else
	{
		hp_ -= amount;
		std::cout << "ClapTrap " << name_ << " has taken ";
		std::cout << amount << " point of damage" << std:: endl;
		std::cout << "ClapTrap " << name_ << " has hit point: " << hp_ << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!isAlive() || !hasEnergy())
		return ;
	hp_ += amount;
	energy_--;
	std::cout << name_ << " is repaired " << amount << " hit point" <<std::endl;
	std::cout << "ClapTrap " << name_ << " has hit point: " << hp_ << std::endl;
	std::cout << "ClapTrap " << name_ << " has energy point: " << energy_ << std::endl;
}
