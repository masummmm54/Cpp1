
#include "Harl.hpp"


int main()
{
	Harl harl;
	std::string input;

	std::cout << "type 'EXIT' for exiting" << std::endl;
	std::cout << "DEBUG INFO WARNING ERROR" << std::endl;
	do
	{
		std::cin >> input;
		harl.complain(input);
	} while (input.compare("EXIT"));
	

	return (EXIT_SUCCESS);
}
