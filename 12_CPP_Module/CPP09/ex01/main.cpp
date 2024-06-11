#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
		return (1);
	}

	std::string	expression = av[1];
	RPN	calculator;

	try
	{
		int	result = calculator.evaluate(expression);
		std::cout << result << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
