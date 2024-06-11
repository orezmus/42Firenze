#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

int main(void) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size :" << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "=====list test=====" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << "back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "size :" << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> l(lst);

	std::cout << "=====Operator Test=====" << std::endl;
	MutantStack<int> clone = mstack;
	MutantStack<int> assign;
	assign = mstack;

	it = clone.begin();
	ite = clone.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	it = assign.begin();
	ite = assign.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}
