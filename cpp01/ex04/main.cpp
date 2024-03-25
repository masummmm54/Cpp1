#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	std::string args[5];

	args[0] = av[0];
	args[1] = av[1];
	args[2] = av[2];
	args[3] = av[3];
	args[4] = '\0';
	Replace sed(args);
	sed.get_lines();
	return 0;
}
