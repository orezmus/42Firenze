#include "Animal.hpp"

Animal::Animal() : type_("Animal"){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy){
	type_ = copy.type_;	
	std::cout << "Animal copy constructor called"  << std::endl;
}

Animal& Animal::operator=(const Animal &copy) {
	if (this != &copy)
	{
		type_ = copy.type_;
		std::cout << "Animal copy assignment operator called"  << std::endl;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


std::string Animal::getType() const {
	return type_;
}
