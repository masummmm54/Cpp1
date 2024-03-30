# ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	~Point();
	Point();
	Point(const Point& p);
	Point(const Fixed &x1, const Fixed &y1);
	Point& operator=(const Point &other);
	Fixed get_x() const;
	Fixed get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
bool is_triangle(Point const a, Point const b, Point const c);
Fixed	distance(Fixed x1, Fixed x2, Fixed y1, Fixed y2);

#endif
