#include "Array.hpp"


void	test()
{
	Array<char> str(6);
	Array<char> str2(6);

	try
	{
		str[0] = 'm';
		str[1] = 'a';
		str[2] = 's';
		str[3] = 'u';
		str[4] = 'm';
		str[5] = '\0';
		str2 = str;
		Array<char> str3(str);
		std::cout << str[0] << std::endl;
		std::cout << str2[0] << std::endl;
		std::cout << str3[0] << std::endl;
		str[0] = 'l';
		str2[0] = 's';
		std::cout << str[0] << std::endl;
		std::cout << str2[0] << std::endl;
		std::cout << str3[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


void	test2()
{
	Array<int> array(3);

	try
	{
		array[0] = 0;
		array[1] = 4;
		array[2] = 1;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main( void )
{
	test();
	test2();
	return (0);
}