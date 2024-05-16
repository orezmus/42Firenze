#include "ScalarConverter.hpp"
#include <sstream>

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


void ScalarConverter::convert(const std::string &literal) {
    if (isCharLiteral(literal))
        std::cout << "'" << literal[1] << "'" << std::encl;
    else
    {
        std::istringstream
    }
}