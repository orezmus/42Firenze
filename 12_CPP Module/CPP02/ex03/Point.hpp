#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point {
private:
    const Fixed x_;
    const Fixed y_;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &copy);
    Point& :operator=(const Point &copy);
    ~Point();
};

bool bsp(Point const a, Point const b, Pint const c, Point const point);

#endif