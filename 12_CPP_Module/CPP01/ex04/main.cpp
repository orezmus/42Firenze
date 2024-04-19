#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string filename, s1, s2;
	std::string line;

	if (ac != 4)
	{
		std::cout << "Arguments Error" << std::endl;
		return ;
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	std::ifstream infile(filename);
	std::ofstream outfile(filename + ".replace", std::ofstream::out | std::ofstream::trunc);

	if (!infile || !outfile)
	{
		if (infile)
			infile.close();
		else if (outfile)
			outfile.close();
		std::cout << "Invalid File" << std::endl;
		return (0);
	}
	while (std::getline(infile, line))
	{
		size_t pos = line.find(s1);
		if (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
	}
	infile.close();
	outfile.close();
}
