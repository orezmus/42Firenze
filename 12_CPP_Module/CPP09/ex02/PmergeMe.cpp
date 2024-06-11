#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int ac, char **av) {
	for(int i = 1; i < ac; ++i)
	{
		int num = atoi(av[i]);
		vec_.push_back(num);
		lst_.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy) : vec_(copy.vec_), lst_(copy.lst_) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy)
	{
		vec_ = copy.vec_;
		lst_ = copy.lst_;
	}
	return *this;
	}

PmergeMe::~PmergeMe() {
}

void PmergeMe::mergeVector(std::vector<int> &vec) {
	if (vec.size() <= 1)
		return ;

	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

	mergeVector(left);
	mergeVector(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

void PmergeMe::mergeList(std::list<int> &lst) {
	if (lst.size() <= 1)
		return ;

	std::list<int> left, right;
	size_t count = 0;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		if (count < lst.size() / 2)
			left.push_back(*it);
		else
			right.push_back(*it);
		count++;
	}

	mergeList(left);
	mergeList(right);

	lst.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(lst));
	}

void PmergeMe::sortVector() {
	mergeVector(vec_);
}

void PmergeMe::sortList() {
	mergeList(lst_);
}

size_t PmergeMe::getVectorSize() const {
	return vec_.size();
}

size_t PmergeMe::getListSize() const {
	return lst_.size();
}

void PmergeMe::printSequence(const std::string &flag) {
	if (flag == "vec")
	{
		for (std::vector<int>::iterator it = vec_.begin(); it != vec_.end(); ++it)
			std::cout << *it << " ";
	}
	else
	{
		for (std::list<int>::iterator it = lst_.begin(); it != lst_.end(); ++it)
			std::cout << *it << " ";
	}
	std::cout << std::endl;

}
