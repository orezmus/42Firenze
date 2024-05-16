#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &copy) {
	static_cast<void>(copy);
}

Intern& Intern::operator=(const Intern &copy) {
	if (this != &copy)
		static_cast<void>(copy);
	return (*this);
}

static AForm* createShrubberyCreationForm(const std::string& target) {
	std::cout << "Intern creates shrubbery creation form. (" << target << ")" << std::endl;
	return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomyForm(const std::string& target) {
	std::cout << "Intern creates robotomy request form. (" << target << ")" << std::endl;
	return (new RobotomyRequestForm(target));
}

static AForm* createPresidentialPardonForm(const std::string& target) {
	std::cout << "Intern creates presidential pardon form. (" << target << ")" << std::endl;
	return (new PresidentialPardonForm(target));
}

Intern::~Intern() {
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*func[3])(const std::string &target) =
		{createShrubberyCreationForm, createRobotomyForm, createPresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (form[i] == name)
			return (func[i](target));
	}
	std::cout << "No form exists for the given name." << std::endl;
	return (NULL);
}
