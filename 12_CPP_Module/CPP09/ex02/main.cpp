#include "PmergeMe.hpp"
#include <cstdlib>

bool isInt(std::string const &str)
{
	if (str.empty() || ((!std::isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
		return (false);

	char    *p;
	std::strtol(str.c_str(), &p, 10);

	return (*p == 0);
}

int main(int ac, char **av) {
	if (ac < 2) 
	{
		std::cerr << "Usage: " << av[0] << " <input>" << std::endl;
		return 1;
	}

	for (int i = 1; i < ac; ++i)
	{
		if (!isInt(av[i]))
		{
			std::cerr << "Error: Invalid input '" << av[i] << "'" << std::endl;
			return (1);
		}
		if (std::atoi(av[i]) < 0)
		{
			std::cerr << "Error: Negative number '" << av[i] << "'" << std::endl;
			return (1);
		}
	}

	PmergeMe sorter(ac, av);

	std::cout << "Before: ";
	sorter.printSequence("vec");

	clock_t start = clock();
	sorter.sortVector();
	clock_t end = clock();
	double	vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	start = clock();
	sorter.sortList();
	end = clock();
	double	lstTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After:  ";
	sorter.printSequence("vec");

	std::cout << "Time to process a range of " << sorter.getVectorSize()
		<< " elements with std::vector: " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << sorter.getListSize()
		<< " elements with std::list: " << lstTime << " us" << std::endl;
	
	return (0);
}