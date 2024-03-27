
#include "Fixed.hpp"

int main( void )
{

	Fixed		a;
	Fixed const b(Fixed (5.05f) * Fixed( 2 ));
	Fixed		c (-4.45f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a , b) << std::endl;
	std::cout << b / c << std::endl;

	return (0);
}
