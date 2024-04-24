#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *brain_;
public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	~Dog();

	void makeSound() const;
};

#endif