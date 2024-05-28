#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <class T>
class Array {
private:
	T *arr_;
	int size_;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array& operator=(const Array &copy);
	~Array();

	T& operator[](int index);
	const T& operator[](int index) const;
	
	int size() const;

	class OutOfBoundException : public std::exception{
	public:
		const char *what() const throw() {
			return "Out of Bounds";
		}
	};
};

#include "Array.tpp"

#endif
