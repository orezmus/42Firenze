#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: AForm("Presidential", 25, 5), target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
	: AForm(copy), target_(copy.target_) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy)
	{
		AForm::operator=(copy);
		target_ = copy.target_;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	if (canExecute(executor))
		std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
