#include "ScalarConverter.hpp"
#include <sstream>
# include <iomanip>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	static_cast<void>(copy);
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy) {
	if (this != &copy)
		static_cast<void>(copy);
	return (*this);
}

ScalarConverter::~ScalarConverter() {  
}


static bool checkChar(const std::string &literal) {
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return true;
	return false;
}

static bool checkPseudo(const std::string &literal) {
	if (literal == "nan" || literal == "nanf" || literal == "+inf" 
	|| literal == "+inff" || literal == "-inf" || literal == "-inff")
		return true;
	return false;
}

static bool checkDisplayable(int c) {
    if (c >= 32 && c <= 126)
        return true;
    return false;
}

void toChar(const std::string &literal) {
	std::cout << "char: ";
	if (checkChar(literal))
		std::cout << "'" << literal[1] << "'" << std::endl;
	else
	{
		std::istringstream input(literal);
		int i;
		if (input >> i && !checkPseudo(literal))
		{
			if (checkDisplayable(i))
				std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "Non displayble" << std::endl;
		}
	else
		std::cout << "impossible" << std::endl;
	}
}

void toInt(const std::string &literal) {
	std::cout << "int: ";
	if (checkChar(literal))
		std::cout << static_cast<int>(literal[1]) << std::endl;
	else
	{
		std::istringstream input(literal);
		int i;
		if (input >> i && !checkPseudo(literal))
			std::cout << i << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void toFloat(const std::string &literal) {
	std::cout << "float: " << std::fixed << std::setprecision(1);
	if (checkChar(literal))
		std::cout << static_cast<float>(literal[1]) << "f" << std::endl;
	else if (checkPseudo(literal))
	{
		if (literal == "nan" || literal == "nanf")
			std::cout << "nanf" << std::endl;
		else if (literal == "+inf" || literal == "+inff")
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		std::istringstream input(literal);
		float f;
		if (input >> f)
			std::cout << f << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

void toDouble(const std::string &literal) {
	std::cout << "double: " << std::fixed << std::setprecision(1);
	if (checkChar(literal))
		std::cout << static_cast<double>(literal[1]) << std::endl;
	else if (checkPseudo(literal))
	{
		if (literal == "nan" || literal == "nanf")
			std::cout << "nan" << std::endl;
		else if (literal == "+inf" || literal == "+inff")
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		std::istringstream input(literal);
		double d;
		if (input >> d)
			std::cout << d << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

void ScalarConverter::convert(const std::string &literal) {
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}
