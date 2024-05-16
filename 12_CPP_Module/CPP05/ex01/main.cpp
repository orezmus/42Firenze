#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat b1("b1", 30);
	Bureaucrat b2("b2", 70);
	
	try
	{
		std::cout << "=========Test 1=========" << std::endl;
		Form f1("f1", 50, 70);
		

		b1.signForm(f1);
		b2.signForm(f1);
		std::cout << std::endl;

		std::cout << f1 << std::endl;
		std::cout << std::endl;
		Form f2("f2", 100, 151);
		
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=========Test 2=========" << std::endl;
		Form f3("f3", 50, 70);
		Form f4 = f3;

		b1.signForm(f3);
		b2.signForm(f4);
		std::cout << std::endl;

		std::cout << f3 << std::endl;
		std::cout << std::endl;
		std::cout << f4 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}