#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("annoymous"), grade_(150) {
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
    if (grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    name_ = copy.getName();
    grade_ = copy.getGrade();
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
    {
        name_ = copy.getName();
        grade_ = copy.getGrade();
        std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::increment(int amount) {
    grade_ -= amount;
    if (grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement(int amount) {
    grade_ += amount;
    if (grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too hight!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br) {
	std::cout << br.getName() << ", bureaucrat grade " << br.getGrade();
	return os;
}