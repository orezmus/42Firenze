#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main(void)
{
	std::cout << "<Create new Obj>" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	
	std::cout << std::endl;
	std::cout << "<Obj getType>" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "<Obj makeSound>" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	k->makeSound();
	std::cout << std::endl;
	std::cout << "<Free Objs>" << std::endl;
	delete k;
	delete wrong;
	
	delete i;
	delete j;
	delete meta;

	return 0; 
}
