
#include "Harl.hpp"

#define DEBUG  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO  "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING  "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month."
#define ERROR  "This is unacceptable! I want to speak to the manager now."

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << DEBUG << std::endl;
}
void	Harl::info(void)
{
	std::cout << INFO << std::endl;
}
void	Harl::warning(void)
{
	std::cout << WARNING << std::endl;
}
void	Harl::error(void)
{
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level)
{
	harl_funcs	functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4; i++)
		if (level == levels[i]) break;

	if (i < 4)
		(this->*functions[i])();

}
