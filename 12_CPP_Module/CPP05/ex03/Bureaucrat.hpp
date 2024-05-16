#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string name_;
    int grade_;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat &copy);
    ~Bureaucrat();
    
    std::string getName() const;
    int getGrade() const;
    void increment(int amount);
    void decrement(int amount);

    void signForm(AForm& f);
    void executeForm(AForm const& f);
    
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what () const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif
