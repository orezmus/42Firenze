#include "Fixed.hpp"

const int Fixed::bits_ = 8;

Fixed::Fixed() : fixedPoint_(0) {
}

Fixed::Fixed(const int x) : fixedPoint_(0) {
	fixedPoint_ = x << bits_;;
}

Fixed::Fixed(const float y) : fixedPoint_(0) {
	fixedPoint_ = roundf(y * (1 << bits_));
}

Fixed::Fixed(const Fixed &copy) {
	(*this) = copy;
}

Fixed& Fixed::operator=(const Fixed &copy) {
	fixedPoint_ = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
}

//===================================================//

int Fixed::getRawBits(void) const {
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

//===================================================//

bool Fixed::operator>(const Fixed& num) const{
	return fixedPoint_ > num.getRawBits();
}

bool Fixed::operator<(const Fixed& num) const{
	return fixedPoint_ < num.getRawBits();
}

bool Fixed::operator>=(const Fixed& num) const{
	return fixedPoint_ >= num.getRawBits();
}

bool Fixed::operator<=(const Fixed& num) const{
	return fixedPoint_ <= num.getRawBits();
}

bool Fixed::operator==(const Fixed& num) const{
	return fixedPoint_ == num.getRawBits();
}

bool Fixed::operator!=(const Fixed& num) const{
	return fixedPoint_ != num.getRawBits();
}

//===================================================//

Fixed Fixed::operator+(const Fixed& num) const{
	return Fixed(this->toFloat() + num.toFloat());
}
Fixed Fixed::operator-(const Fixed& num) const{
	return Fixed(this->toFloat() - num.toFloat());
}
Fixed Fixed::operator*(const Fixed& num) const{
	return Fixed(this->toFloat() * num.toFloat());
}
Fixed Fixed::operator/(const Fixed& num) const{
	return Fixed(this->toFloat() / num.toFloat());
}

//===================================================//

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;

}
Fixed& Fixed::operator++() {
	++fixedPoint_;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}
Fixed& Fixed::operator--() {
	--fixedPoint_;
	return *this;
}

//===================================================//

Fixed& Fixed::min(Fixed &f1, Fixed &f2){
	if (f1.getRawBits() < f2.getRawBits()) 
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2){
	if (f1.getRawBits() < f2.getRawBits()) 
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed & f2){
	if (f1.getRawBits() > f2.getRawBits()) 
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2){
	if (f1.getRawBits() > f2.getRawBits()) 
		return f1;
	return f2;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

