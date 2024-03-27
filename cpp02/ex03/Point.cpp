
#include "Point.hpp"

Point::~Point() {}

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed &x1, const Fixed &y1) : x(x1), y(y1) {}

Point::Point(const Point& p) : x(p.x), y(p.y) {}

const Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Fixed Point::get_x() const
{
	return (this->x);
}

Fixed Point::get_y() const
{
	return (this->y);
}
