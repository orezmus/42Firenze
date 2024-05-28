#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    std::vector<int> v_;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span& operator=(const Span &copy);
    ~Span();

    void addNumber(int num);
    void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
    
    int shortestSpan();
    int longestSpan();

    class NoSpaceException : public std::exception {
        const char *what() const throw() {
            return "Span is full, cannot add more numbers.";
        }
    };

    class NotEnoughNumbersException : public std::exception {
        const char *what() const throw() {
            return "Not enough numbers to find a span.";
        }
    };
};

#endif