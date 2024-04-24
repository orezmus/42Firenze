#include "Dog.hpp"

Dog::Dog() : Animal(), brain_(new Brain()){
	type_ = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	brain_ = new Brain(*copy.brain_);
	std::cout << "Dog copy constructor called"  << std::endl;
}

Dog& Dog::operator=(const Dog &copy) {
	if (this != &copy)
	{
		Animal::operator=(copy);
		*brain_ = *copy.brain_;
		std::cout << "Dog copy assignment operator called" << std::endl;
	}
	return (*this);
}

Dog::~Dog() {
	delete brain_;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "WangWang" << std::endl;
}