#include <iostream>
#include <fstream>
#include <string>


int	main(int ac, char **av)
{
	std::string filename, s1, s2;
	std::string line;

	if (ac != 4)
	{
		std::cout << "Usage: " << av[0] << " <filename> <old str> <new str>" << std::endl;
		return (1);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	std::ifstream infile(filename.c_str());
	std::ofstream outfile((filename + ".replace").c_str(), 
				std::ofstream::out | std::ofstream::trunc);
	if (!infile || !outfile)
	{
		if (infile)
			infile.close();
		else if (outfile)
			outfile.close();
		std::cout << "Invalid File" << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		outfile << line << std::endl;
	}
	std::cout << "Replacement completed." << std::endl;
	infile.close();
	outfile.close();
	return (0);
}
