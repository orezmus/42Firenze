#include "Fixed.hpp"

const int Fixed::bits_ = 8;

Fixed::Fixed() : fixedPoint_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	fixedPoint_ = copy.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &copy) {
	fixedPoint_ = copy.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint_;
}

void Fixed::setRawBits(int const raw) {
	fixedPoint_ = raw;
}
