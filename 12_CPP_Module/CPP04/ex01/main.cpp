#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	Animal *animal[10];
	std::cout << "<Create new Obj array>" << std::endl;
	for(int i = 0; i < 6; i++)
	{
		if (i < 3)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << std::endl;

	std::cout << "<Create new Obj>" << std::endl;
	Dog *d1 = new Dog();
	std::cout << std::endl;

	std::cout << "<Create new Obj>" << std::endl;
	Dog *d2 = new Dog(*d1);
	std::cout << std::endl;

	std::cout << "<Create new Obj>" << std::endl;
	Dog *d3 = new Dog();
	std::cout << std::endl;

	std::cout << "<Assignation>" << std::endl;
	*d3 = *d2;

	std::cout << std::endl;
	std::cout << "<Free Objs>" << std::endl;
	delete d3;
	delete d2;
	delete d1;

	delete d;
	delete c;

	std::cout << std::endl;
	std::cout << "<Free Obj array>" << std::endl;
	for (int k = 0 ; k < 6 ; k++) {
		delete animal[k];
	}
	return 0;
}
