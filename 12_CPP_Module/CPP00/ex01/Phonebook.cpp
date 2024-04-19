#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook(){
	size = 0;
}
void Phonebook::addContact(Contact contact)
{
	contacts[size % 8] = contact;
	size++;
}
	
void Phonebook::searchContact(int index) {
	std::cout << "FirstName: " << contacts[index].getFirstName() << std::endl;
	std::cout << "LastName: " << contacts[index].getLastName() << std::endl;
	std::cout << "NickName: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[index].getNickName() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getNickName() << std::endl;
}

void Phonebook::printTable(std::string info) {
	std::cout << std::setw(10);
	if (info.empty() || info.length() == 0)
		std::cout << "Invalid information" << std::endl;
	if (info.length() >= 10)
		std::cout << info.substr(0, 9) + '.' << "|";
	else
		std::cout << info << "|";
}

void Phonebook::display() {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "FirstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "NickName" << "|" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0; i < getSize(); i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		printTable(contacts[i].getFirstName());
		printTable(contacts[i].getLastName());
		printTable(contacts[i].getNickName());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Phonebook::getSize() {
	if (size >= 8)
		return 8;
	return size;
}
