#include "Form.hpp"

Form::Form() : name_("annoymous"), signed_(false), gradeSign_(0), gradeExecute_(0) {
}

Form::Form(std::string name, const int &gradeSign, const int &gradeExecute) 
	: name_(name), signed_(false), gradeSign_(gradeSign), gradeExecute_(gradeExecute) {
	if (gradeSign_ < 1 || gradeExecute_ < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign_ > 150 || gradeExecute_ > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name_(copy.getName()), signed_(copy. getSigned()), 
	gradeSign_(copy.getGradeSign()), gradeExecute_(copy.getGradeExecute()) {
	if (gradeSign_ < 1 || gradeExecute_ < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign_ > 150 || gradeExecute_ > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &copy) {
	if (this != &copy)
	{
		*const_cast<std::string*>(&name_) = copy.getName();
		signed_ = copy.getSigned();
		*const_cast<int*>(&gradeSign_) = copy.getGradeSign();
		*const_cast<int*>(&gradeExecute_) = copy.getGradeExecute();
	}
	return (*this);
}

Form::~Form() {
}

std::string Form::getName() const {
	return name_;
}

bool Form::getSigned() const {
	return signed_;
}

int Form::getGradeSign() const {
	return gradeSign_;
}

int Form::getGradeExecute() const {
	return gradeExecute_;
}

void Form::beSigned(Bureaucrat& br) {
	if (br.getGrade() > gradeSign_)
		throw GradeTooLowException();
	signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too hight!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	std::cout << "---------Form---------\n"
		<< f.getName() << std::endl 
		<< "Sign Grade: " <<  f.getGradeSign() << std::endl
		<< "Execute Grade: " << f.getGradeExecute() << std::endl
		<< "Signed: " << (f.getSigned()? "O" : "X") << std::endl
		<< "----------------------";
	return os;
}
