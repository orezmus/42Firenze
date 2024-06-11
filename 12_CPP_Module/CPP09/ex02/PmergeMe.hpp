#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

class PmergeMe {
private:
	std::vector<int> vec_;
	std::list<int> lst_;

	void mergeVector(std::vector<int> &vec);
	void mergeList(std::list<int> &lst);
public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &copy);
	~PmergeMe();

	void sortVector();
	void sortList();

	size_t getVectorSize() const;
	size_t getListSize() const;

	void printSequence(const std::string &flag);
};

#endif
