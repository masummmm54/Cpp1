
#include <iostream>
#include <ctype.h>
#include <string>

void	print(std::string s)
{
	size_t i = 0;
	while (i < s.length())
		std::cout << (char)toupper(s[i++]);
}


int	main(int ac, char **av)
{
	int i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (i < ac)
		print(av[i++]);
	std::cout << std::endl;
	return (0);
}
