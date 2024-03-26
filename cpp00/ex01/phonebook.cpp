
#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_num = 0;
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << RED << "Phonebook closing..." << RESET << std::endl;
}

void	PhoneBook::add()
{
	system("clear");
	contacts[index].get_name();
	contacts[index].get_last_name();
	contacts[index].get_nick_name();
	contacts[index].get_phone_number();
	contacts[index].get_dark_secret();
	std::cout << std::endl;
	if (contact_num < 8)
		contact_num++;
	if (index != 7)
		index++;
	else
		index = 0;
}


void	PhoneBook::search()
{
	int			index = 0;
	std::string	index_str;

	system("clear");
	if (contact_num == 0)
	{
		std::cout << RED << "No contact registered!" << RESET << std::endl;
		return ;
	}
	std::cout << MAGENTA << " ------------------------------------------- " << RESET << std::endl;
	std::cout << MAGENTA << "|     Index|      Name| Last Name| Nick Name|" << RESET << std::endl;
	while (index < contact_num)
	{
		std::cout << MAGENTA << "|-------------------------------------------|" << RESET << std::endl;
		contacts[index].print_contac(index);
		index++;
	}
	std::cout << MAGENTA << " ------------------------------------------- " << RESET << std::endl;
	std::cout << BLUE << "Enter a index number for contact:\t" << RESET;
	if (!std::getline(std::cin, index_str))
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
	}
	index = atoi(index_str.c_str());
	if (index <= contact_num && index > 0)
		contacts[index - 1].show_contact();
	else 
		std::cout << RED << "Wrong index!\n" << RESET <<std::endl;
}
