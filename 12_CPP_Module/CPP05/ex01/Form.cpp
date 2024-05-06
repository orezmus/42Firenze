#include "Form.hpp"

Form::Form() : name_("annoymous"), signed_(false), gradeSign_(0), gradeExecute_(0) {
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, const int &gradeSign, const int &gradeExecute) 
    : name_(name), gradeSign_(gradeSign), gradeExecute_(gradeExecute) {
    if (gradeSign_ < 1 || gradeExecute_ < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign_ > 150 || gradeExecute_ > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &copy) {
    name_ = copy.getName();
    signed = copy.getSigned();
    gradeSign_ = copy.getGradeSign();
    gradeExecute_ = copy.getGradeExecute();
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &copy) {
    if (this != &copy)
    {
        name_ = copy.getName();
        grade_ = copy.getGrade();
        std::cout << "Form copy assignment operator called" << std::endl;
    }
    return (*this);
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}


bool Form::getSigned() const {
    return signed_;
}

int Form::getGradeSign() const{
    return gradeSign_;
}

int Form::getGradeExecute() const{
    return gradeExecute_;
}



std::ostream& operator<<(std::ostream& os, const Form& f) {
	std::cout << br.getName() << ", form grade " << br.getGrade();
	return os;
}