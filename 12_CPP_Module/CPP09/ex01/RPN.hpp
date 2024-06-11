#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN {
private:
	std::stack<int> tokens_;

	bool isOperator(const std::string &token);
	bool isDigit(const std::string &token);
	int performOperator(std::string op, int a, int b);
public:
	RPN();
	RPN(const RPN &copy);
	RPN& operator=(const RPN &copy);
	~RPN();

	int evaluate(const std::string &expression);
};

#endif
