#include "Span.hpp"

Span::Span(){
}

Span::Span(unsigned int N){
	v_.reserve(N);
}

Span::Span(const Span &copy){
	v_ = copy.v_;
}

Span& Span::operator=(const Span &copy){
	if (this != &copy)
		v_ = copy.v_;
	return (*this);
}

Span::~Span(){
}

void Span::addNumber(int num) {
	if (v_.size() == v_.capacity())
		throw NoSpaceException();
	v_.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end) {
	std::vector<int>::iterator it = begin;
	if (v_.size() == v_.capacity())
		throw NoSpaceException();
	while (it != end)
	{
		v_.push_back(*it);
		if (v_.size() == v_.capacity())
			break;
		it++;
	}
}

int Span::shortestSpan() {
	if (v_.size() < 2)
		throw NotEnoughNumbersException();
	std::sort(v_.begin(), v_.end());
	int shortest = v_[1] - v_[0];
	for (size_t i = 0; i < v_.size() - 1; i++)
	{
		if (shortest > v_[i + 1] - v_[i])
			shortest = v_[i + 1] - v_[i];
	}
	return shortest;	
}

int Span::longestSpan() {
	if (v_.size() < 2)
		throw NotEnoughNumbersException();
	return *std::max_element(v_.begin(), v_.end()) - *std::min_element(v_.begin(), v_.end());
}
