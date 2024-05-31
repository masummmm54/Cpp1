
#include "BitcoinExchange.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
		return (error_msg("could not open file."), 1);
	try
	{
		BitcoinExchange Exchange(av[1]);
		Exchange.exchange();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	return (0);
}