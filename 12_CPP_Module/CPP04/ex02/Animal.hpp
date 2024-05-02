#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type_;
public:
	Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif