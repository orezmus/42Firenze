#include "Cat.hpp"

Cat::Cat() : Animal(), brain_(new Brain()){
	type_ = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	brain_ = new Brain(*copy.brain_);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy) {
	if (this != &copy)
	{
		Animal::operator=(copy);
		*brain_ = *copy.brain_;
		std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat() {
	delete brain_;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}