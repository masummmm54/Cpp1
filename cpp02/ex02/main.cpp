
#include "Fixed.hpp"
#include <iomanip>
#include <limits.h>

int main( void )
{

	Fixed		a;
	Fixed const b(Fixed (5.05f) * Fixed( 2 ));
	Fixed		c (8388607);
	Fixed		d (0.7f);

	std::cout << std::fixed;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	

	return (0);
}
