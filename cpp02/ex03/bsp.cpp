
#include "Point.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (!is_triangle(a, b, c))
	{
		std::cout << "give me a triangle plsssss" << std::endl;
		return false;
	}

	Fixed alpha (((b.get_y() - c.get_y()) * (point.get_x() - c.get_x()) + (c.get_x() - b.get_x()) * (point.get_y() - c.get_y())) / ((b.get_y() - c.get_y())*(a.get_x() - c.get_x()) + (c.get_x() - b.get_x())*(a.get_y() - c.get_y())));
	Fixed beta (((c.get_y() - a.get_y())*(point.get_x() - c.get_x()) + (a.get_x() - c.get_x()) * (point.get_y() - c.get_y())) / ((b.get_y() - c.get_y())*(a.get_x() - c.get_x()) + (c.get_x() - b.get_x())*(a.get_y() - c.get_y())));
	Fixed gamma (Fixed(1) - alpha - beta);

	if ((Fixed(0) <= alpha && alpha <= Fixed(1)) && (Fixed(0) <= beta && beta <= Fixed(1)) && (Fixed(0) <= gamma && gamma <= Fixed(1)) && (alpha + beta + gamma == Fixed(1)))
		return (true);
	return (false);
}







Fixed	distance(Fixed x1, Fixed y1, Fixed x2, Fixed y2)
{
	Fixed presqrt;
	presqrt = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	return (Fixed(std::sqrt(presqrt.toFloat())));
}

bool is_triangle(Point const a, Point const b, Point const c)
{
	Fixed Ab = distance(a.get_x(), a.get_y(), b.get_x(), b.get_y());
	Fixed Bc = distance(b.get_x(), b.get_y(), c.get_x(), c.get_y());
	Fixed Ca = distance(c.get_x(), c.get_y(), a.get_x(), a.get_y());

	if (Ab + Bc <= Ca)
		return (false);
	else if (Bc + Ca <= Ab)
		return (false);
	else if (Ca + Ab <= Bc)
		return (false);
	return (true);
}

