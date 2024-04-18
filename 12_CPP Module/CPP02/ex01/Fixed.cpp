#include "Fixed.hpp"

const int Fixed::bits_ = 8;

Fixed::Fixed() : fixedPoint_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) : fixedPoint_(0) {
	std::cout << "Int constructor called" << std::endl;
	fixedPoint_ = x << bits_;;
}

Fixed::Fixed(const float y) : fixedPoint_(0) {
	std::cout << "Float constructor called" << std::endl;
	fixedPoint_ = roundf(y * (1 << bits_));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = copy;
}

Fixed& Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPoint_ = copy.getRawBits();
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

float Fixed::toFloat(void) const {
	return (float)fixedPoint_ / (1 << bits_);
}

int Fixed::toInt(void) const {
	return fixedPoint_ >> bits_;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}