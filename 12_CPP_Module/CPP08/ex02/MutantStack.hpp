#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack& operator=(const MutantStack &copy);
	~MutantStack();

	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
};

#include "MutantStack.tpp"

#endif
