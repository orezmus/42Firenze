#include "Phonebook.hpp"
#include "Contact.hpp"
#include <limits>

void	add(Phonebook &phonebook)
{
	Contact contact;
	
	contact.setFirstName();
	contact.setLastName();
	contact.setNickName();
	contact.setPhoneNumber();
	contact.setDarkestSecret();
	phonebook.addContact(contact);
}

void	search(Phonebook &phonebook)
{
	int index;
	std::string str;
	
	phonebook.display();
	std::cout << "Insert index: ";
	std::cin >> str;
	std::stringstream(str) >> index;
	if (index < 1 || index > phonebook.getSize())
		std::cout << "Invalid index" << std::endl;
	else
		phonebook.searchContact(index - 1);
}

int	main(void) {
	Phonebook phonebook;
	std::string cmd;
	
	std::cout << "~~~Welcome My Awesome Phonebook~~" << std::endl;;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Enter command: ";
		std::cin >> cmd;
	
		if (cmd == "ADD")
			add(phonebook);
		else if (cmd == "SEARCH")
			search(phonebook);
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid Comamand" << std::endl;
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
		{
			std::cout << "Input error" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}
