#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("Robotomy", 72, 45), target_(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: AForm(copy), target_(copy.target_) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy)
	{
		AForm::operator=(copy);
		target_ = copy.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	srand(time(NULL));
	if (canExecute(executor))
	{
		std::cout << "Drrrrrrrrr.." << std::endl;
		if (rand() % 2)
			std::cout << getName() << " has been robotomized successfully." << std::endl;
		else
			std::cout << getName() << " has been failed robotomize," << std::endl;
	}
}

