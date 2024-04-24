#include "Point.hpp"

void	checkBsp(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point))
		std::cout << "The point is inside the tringle." << std::endl;
	else
		std::cout << "The point is outside the tringle." << std::endl;
}

int	main( void ) 
{
	Point a1(0, 0);
	Point b1(4, 4);
	Point c1(4, 0);
	Point p1(4, 0);
	Point p2(2, 1);


	Point a2(5.5, -2.5);
	Point b2(2.5, -5.0);
	Point c2(1.5, -1.0);
	Point p3(3.5, -3.0);
	Point p4(5.0, -0.5);

	Fixed x1(8), y1(3);
	Fixed x2(5), y2(9);
	Fixed x3(1), y3(1);
	Fixed x4(4), y4(4);
	Fixed x5(4), y5(1);
	Point a3(x1, y1);
	Point b3(x2, y2);
	Point c3(x3, y3);
	Point p5(x4, y4);
	Point p6(x5, y5);

	checkBsp(a1, b1, c1, p1);
	checkBsp(a1, b1, c1, p2);
	checkBsp(a2, b2, c2, p3);
	checkBsp(a2, b2, c2, p4);
	checkBsp(a3, b3, c3, p5);
	checkBsp(a3, b3, c3, p6);

	return 0;
}
