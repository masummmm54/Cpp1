
#include "Phonebook.hpp"


int	main(int ac, char **av)
{
	PhoneBook	book;
	std::string	input;

	if (ac > 1)
		return (1);
	(void)av;
	while (1)
	{
		std::cout << CYAN << "Possible commands" << RESET << std::endl;
		std::cout << CYAN << "1.ADD 2.SEARCH 3.EXIT" << RESET << std::endl;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << std::endl;
				break;
			}
			continue;
		}
		if (input == "ADD" || input == "1")
			book.add();
		else if (input == "SEARCH" || input == "2")
			book.search();
		else if (input == "EXIT" || input == "3")
			break;
	}
	return (0);
}
