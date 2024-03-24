#include "phonebook.hpp"

void	visuale_contact(std::string n)
{
	int	m = 0;

	while (m < 10)
	{
		if (n[m] != '\0')
		{
			if (m == 9)
				std::cout << YELLOW << "." << RESET;
			else
				std::cout << YELLOW << n[m] << RESET;
		}
		else
		{
			while (m++ < 10)
				std::cout << " ";
			break ;
		}
		m++;
	}
}

void	Contact::show_contact()
{
	std::cout << std::endl;
	std::cout << BLUE << "Name           : " << YELLOW << name << RESET << std::endl;
	std::cout << BLUE << "Last name      : " << YELLOW << last_name << RESET << std::endl;
	std::cout << BLUE << "Nick name      : " << YELLOW << nick_name << RESET << std::endl;
	std::cout << BLUE << "Phone number   : " << YELLOW << phone_number << RESET << std::endl;
	std::cout << BLUE << "Darkest secret : " << YELLOW << dark_secret << RESET << std::endl;
	std::cout << std::endl;
}

void	Contact::print_contac(int index)
{
	int	m = 0;
	std::cout << MAGENTA << "|" << RESET;
	std::cout << YELLOW << index + 1 << RESET;
	while (m < 9)
	{
		std::cout << " ";
		m++;
	}
	std::cout << MAGENTA << "|" << RESET;
	visuale_contact(name);
	std::cout << MAGENTA << "|" << RESET;
	visuale_contact(last_name);
	std::cout << MAGENTA << "|" << RESET;
	visuale_contact(nick_name);
	std::cout << MAGENTA << "|" << RESET;
	std::cout << std::endl;
}

Contact::Contact(std::string name, std::string last_name, std::string nick_name,
		std::string phone_number, std::string dark_secret)
{
	this->name = name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->dark_secret = dark_secret;
}

Contact::Contact()
{
	this->name = "(null)";
	this->last_name = "(null)";
	this->nick_name = "(null)";
	this->phone_number = "(null)";
	this->dark_secret = "(null)";
}
