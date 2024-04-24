#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
	for (int i = 0; i < 100; i++)
		ideas_[i] = copy.ideas_[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &copy) {
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			ideas_[i] = copy.ideas_[i];
		std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}