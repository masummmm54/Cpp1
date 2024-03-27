
#include "Harl.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Give a paramater beetwen them:\nDEBUG INFO WARNING ERROR" << std::endl, 1);
	Harl harl;
	
	harl.complain(av[1]);


	return (0);
}
