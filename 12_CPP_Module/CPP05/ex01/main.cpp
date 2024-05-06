#include "Bureaucrat.hpp"

int main(void)
{
	try {
		std::cout << "==========test1==========" << std::endl;
		Bureaucrat a("test1", 10);
		Bureaucrat b("test2", -1); // GradeTooHighException
		std::cout << "Next Line" << std::endl; // Skip
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========test2==========" << std::endl;
		Bureaucrat b("test2", 151); // GradeTooLowException
		std::cout << "Next Line" << std::endl; // Skip
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========test3==========" << std::endl;
		Bureaucrat c("test3", 20);
		std::cout << c << std::endl; // output operator overloading
		c.increment(10); // grade : 10
		c.decrement(150); // grade : 160 -> GradeTooLowException
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}