#include "Point.hpp"

Point::Point() : x_(0), y_(0) {

}
Point::Point(const float x, const float y) : x_(x), y_(y) {
}

Point::Point(const Point &copy) : x_(copy.x_), y_(copy.y_) {
}

Point& Point::operator=(const Point &copy) {
	 = copy.getRawBits();
    return (*this);
}

Point::~Point(){

}
