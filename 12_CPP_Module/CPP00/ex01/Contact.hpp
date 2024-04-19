#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	void setFirstName();
	void setLastName();
	void setNickName();
	void setPhoneNumber();
	void setDarkestSecret();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
};

#endif
