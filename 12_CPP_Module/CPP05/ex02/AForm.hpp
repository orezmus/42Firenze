#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name_;
	bool signed_;
	const int gradeSign_;
	const int gradeExecute_;
public:
	AForm();
	AForm(std::string name, const int &gradeSign, const int &gradeExecute);
	AForm(const AForm &copy);
	AForm& operator=(const AForm &copy);
	virtual ~AForm();

	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSigned(Bureaucrat& br);

	virtual void execute(Bureaucrat const& executor) const = 0;
	bool canExecute(Bureaucrat const& executor) const;

	class GradeTooHighException : public std::exception {
	public:
	const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
	const char *what () const throw();
	};
	class NotSignedException : public std::exception {
	public:
	const char *what() const throw();
	};
	class OpenFailException : public std::exception {
	public:
	const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
