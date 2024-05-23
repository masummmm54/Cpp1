

#include "ScalarConversion.hpp"


int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Wrong argument size");
		ScalarConversion::convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}