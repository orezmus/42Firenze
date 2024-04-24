#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type_ = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called"  << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy)
	{
		WrongAnimal::operator=(copy);
		std::cout << "WrongCat copy assignment operator called" << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
