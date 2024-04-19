#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Phonebook
{
private:
	Contact contacts[8];
	int	size;
public:
	Phonebook();
	void addContact(Contact contact);
	void searchContact(int index);
	void display();
	void printTable(std::string info);
	int getSize();
};

#endif
