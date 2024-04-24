#include "Point.hpp"

Point::Point() : x_(0), y_(0) {
}

Point::Point(const float x, const float y) : x_(x), y_(y) {
}

Point::Point(const Fixed x, const Fixed y) : x_(x), y_(y) {
}

Point::Point(const Point &copy) : x_(copy.x_), y_(copy.y_) {
}

Point& Point::operator=(const Point &copy) {
	const_cast<Fixed&>(x_) = copy.x_;
	const_cast<Fixed&>(y_) = copy.y_;
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

Fixed getArea(Point const a, Point const b, Point const c) {
	Fixed s = (a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY()) 
		- (a.getY() * b.getX() + b.getY() * c.getX() + c.getY() * a.getX());
	return (std::abs(s.getRawBits()));

}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	
	Fixed totalArea = getArea(a, b, c);
	Fixed subArea1 = getArea(a, b, point);
	Fixed subArea2 = getArea(a, point, c);
	Fixed subArea3 = getArea(point, b, c);
	
	if (subArea1 + subArea2 + subArea3 == totalArea)
	{
		if (subArea1 == 0  || subArea2 == 0 || subArea3 == 0)
			return (false);
		return (true);
	}
	return (false);
}
