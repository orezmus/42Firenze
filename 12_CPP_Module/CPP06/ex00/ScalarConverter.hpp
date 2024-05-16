#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define SPECIAL 4

class ScalarConverter {
private:
    ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter& operator=(const ScalarConverter &copy);
	~ScalarConverter();
public:
    static void convert(const std::string& literal);
};

#endif