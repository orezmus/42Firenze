#include "Point.hpp"

Point::Point() : x_(0), y_(0) {

}
Point::Point(const float x, const float y) : x_(x), y_(y) {
}

Point::Point(const Point &copy) : x_(copy.x_), y_(copy.y_) {
}

Point& Point::operator=(const Point &copy) {
	const_cast<Fixed&>(x_) = copy.x_;
    const_cast<Fixed&>(x_) = copy.y_;
    return (*this);
}

Point::~Point(){

}

const Fixed& Point::getX(void) const {
    return x_;
}

const Fixed& Point::getY(void) const {
    return y_;
}