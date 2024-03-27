#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);


	Replace sed(av[1], av[2], av[3]);
	if (sed.replace())
		return (1);
	return 0;
}
