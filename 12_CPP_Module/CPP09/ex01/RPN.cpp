#include "RPN.hpp"

RPN::RPN() {
}


RPN::RPN(const RPN &copy) : tokens_(copy.tokens_) {
}

RPN& RPN::operator=(const RPN &copy) {
	if (this != &copy)
		tokens_ = copy.tokens_;
	return *this;
}

RPN::~RPN() {
}

bool RPN::isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isDigit(const std::string &token) {
	return (std::isdigit(token[0]));
}

int RPN::performOperator(std::string op, int a, int b) {
	int result;

	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	else
	{
		if (b == 0)
			std::runtime_error("Division by zero");
		result = a / b;
	}
	return result;
}

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && RPN::isOperator(token))
		{
			if (tokens_.size() < 2)
				throw std::runtime_error("Invalide expression");
			
			int b = tokens_.top();
			tokens_.pop();
			int a = tokens_.top();
			tokens_.pop();
			int result = performOperator(token, a, b);
			tokens_.push(result);
		}
		else if (token.size() == 1 && isDigit(token))
			tokens_.push(atof(token.c_str()));
		else
			throw std::runtime_error("Invalide token");
	}

	if (tokens_.size() != 1)
		throw std::runtime_error("Invalide expression");
	
	return tokens_.top();
}
