
#include "easyfind.hpp"


int	main( void )
{
	std::vector<int> vect;
	std::list<int> list;

	for (int i = 0; i < 10000; i++)
	{
		vect.push_back(i);
		list.push_back(i);
	}

	try
	{
		::easyfind(vect, 10000 - 1);
		::easyfind(list, 10005);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}