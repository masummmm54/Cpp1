
#include "Point.hpp"

void	print(std::string msg)
{
	std::cout << msg <<std::endl;
}

int main( void )
{
	Point		a(1.5f, 2.7f);
	Point		b(-25.6f, 1.2f);
	Point		c(25.6f, 3.8f);
	Point		p(8.3f, 1.7f);

	bool is_triangle = bsp(a, b, c, p);

	if (is_triangle)
		std::cout << "INSIDE TRIANGLE." << std::endl;
	else
		std::cout << "NOT INSIDE TRIANGLE." << std::endl;
	return (0);
}
