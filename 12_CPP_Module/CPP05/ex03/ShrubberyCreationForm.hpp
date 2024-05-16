#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string target_;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const& executor) const;
};

#endif
