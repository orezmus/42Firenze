#include "Contact.hpp"

void Contact::setFirstName() {
	std::cout << "Firstname: ";
	std::cin >> firstName;
}

void Contact::setLastName() {
	std::cout << "Lastname: ";
	std::cin >> lastName;
}

void Contact::setNickName() {
	std::cout << "Nickname: ";
	std::cin >> nickName;
}

void Contact::setPhoneNumber() {
	std::cout << "Phone number: ";
	std::cin >> phoneNumber;
}

void Contact::setDarkestSecret() {
	std::cout << "Darkest secret: ";
	std::cin >> darkestSecret;
}

std::string Contact::getFirstName() {
	return (firstName);
}

std::string Contact::getLastName() {
	return (lastName);
}

std::string Contact::getNickName() {
	return (nickName);
}

std::string Contact::getPhoneNumber() {
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() {
	return (darkestSecret);
}