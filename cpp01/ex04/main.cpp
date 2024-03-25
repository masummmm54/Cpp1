#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	Replace sed(av); 
	sed.get_lines();
	return 0;
}
