#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("Shurbbery", 145, 137), target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
	: AForm(copy), target_(copy.target_) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	if (this != &copy)
	{
		AForm::operator=(copy);
		target_ = copy.target_;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	if (canExecute(executor))
	{
		std::ofstream out;
		std::string shrubbery = "               ,@@@@@@@,\n"
					  "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
					  "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
					  "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
					  "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
					  "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
					  "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
					  "       |o|        | |         | |\n"
					  "       |.|        | |         | |\n"
					  "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
		out.open((getName() + "_shrubbery").c_str());
		//if (out.fail())
			//throw OpenFailException();
		out << shrubbery;
		out.close();
		std::cout << getName() << "_shrubbery file created." << std::endl;
	}
}
