

#include "iter.hpp"

void	test( void )
{
	char mas[6] = "masum";
	std::string arr[4] = {"muhammet", "masum", "kose"};
	::iter(mas, 5, printer<char>);
	::iter(arr, 3, printer<std::string>);
}

void	test2( void )
{
	int num[5] = {1,2,3,4};
	float num2[5] = {1.56, 2.67, 3.87, 4.12};
	::iter(num, 4, square<int>);
	::iter(num2, 4, square<float>);
}

int	main( void )
{
	test();
	test2();
	return (0);
}