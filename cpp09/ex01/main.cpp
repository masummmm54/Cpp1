
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Error: wrong argument size!" << std::endl, 1);
	try
	{
		RPN rpn;
		rpn.calculate(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	return (0);
}