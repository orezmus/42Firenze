#include "AForm.hpp"

AForm::AForm() : name_("annoymous"), signed_(false), gradeSign_(0), gradeExecute_(0) {
}

AForm::AForm(std::string name, const int &gradeSign, const int &gradeExecute) 
	: name_(name), signed_(false), gradeSign_(gradeSign), gradeExecute_(gradeExecute) {
	if (gradeSign_ < 1 || gradeExecute_ < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign_ > 150 || gradeExecute_ > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name_(copy.getName()), signed_(copy. getSigned()), 
	gradeSign_(copy.getGradeSign()), gradeExecute_(copy.getGradeExecute()) {
	if (gradeSign_ < 1 || gradeExecute_ < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign_ > 150 || gradeExecute_ > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm &copy) {
	if (this != &copy)
	{
		*const_cast<std::string*>(&name_) = copy.getName();
		signed_ = copy.getSigned();
		*const_cast<int*>(&gradeSign_) = copy.getGradeSign();
		*const_cast<int*>(&gradeExecute_) = copy.getGradeExecute();
	}
	return (*this);
}

AForm::~AForm() {
}

std::string AForm::getName() const {
	return name_;
}

bool AForm::getSigned() const {
	return signed_;
}

int AForm::getGradeSign() const {
	return gradeSign_;
}

int AForm::getGradeExecute() const {
	return gradeExecute_;
}

void AForm::beSigned(Bureaucrat& br) {
	if (br.getGrade() > gradeSign_)
		throw GradeTooLowException();
	signed_ = true;
}

bool AForm::canExecute(Bureaucrat const& executor) const {
	if (getSigned() && executor.getGrade() <= getGradeExecute())
		return true;
	return false;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too hight!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Form is not signed!";
}

const char *AForm::OpenFailException::what() const throw() {
	return "File open failed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	std::cout << "---------Form---------\n"
		<< f.getName() << std::endl 
		<< "Sign Grade: " <<  f.getGradeSign() << std::endl
		<< "Execute Grade: " << f.getGradeExecute() << std::endl
		<< "Signed: " << (f.getSigned()? "O" : "X") << std::endl
		<< "----------------------";
	return os;
}
