
#include "Contact.hpp"

Contact::~Contact ()
{
	std::cout << RED << "Contact deleted."<< RESET << std::endl;
}

int	all_num(std::string number)
{
	int i = 0;

	if (number[i] == '+')
		i++;
	while (number[i])
	{
		if (!(std::isdigit(number[i])))
			return (std::cout << RED << "Please enter a number" << RESET <<std::endl , 0);
		i++;
	}
	return(1);
}

std::string	take_input(std::string msg)
{
	std::string input;

	if (msg == "Contact phone number: ")
	{
		while (input.empty() || !all_num(input))
		{
			std::cout << GREEN << msg << RESET;
			if (!std::getline(std::cin, input))
			{
				if (std::cin.eof())
				{
					std::cout << std::endl;
					exit(0);
				}
				std::cin.clear();
			}
		}
	}
	else
	{
		while (input.empty())
		{
			std::cout << GREEN << msg << RESET;
			if (!std::getline(std::cin, input))
			{
				if (std::cin.eof())
				{
					std::cout << std::endl;
					exit(0);
				}
			}
		}
	}
	return (input);
}

void	Contact::get_name()
{
	this->name = take_input("Contact name: ");
}

void	Contact::get_last_name()
{
	this->last_name = take_input("Contact last name: ");
}

void	Contact::get_nick_name()
{
	this->nick_name = take_input("Contact nick name: ");
}

void	Contact::get_phone_number()
{
	this->phone_number = take_input("Contact phone number: ");
}

void	Contact::get_dark_secret()
{
	this->dark_secret = take_input("Contact darkest secret: ");
}

Contact::Contact()
{
	this->name = "(null)";
	this->last_name = "(null)";
	this->nick_name = "(null)";
	this->phone_number = "(null)";
	this->dark_secret = "(null)";
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

void	visuale_contact(std::string n)
{
	if (n.length() <= 10)
		std::cout << YELLOW << std::right << std::setw(10) << std::setfill(' ') << n.substr(0, 10) << RESET;
	else
		std::cout << YELLOW << std::right << std::setw(9) << std::setfill(' ') << n.substr(0, 9) << "." << RESET;
}

void	Contact::print_contac(int index)
{
	int	m = 0;
	std::cout << MAGENTA << "|" << RESET;
	while (m < 9)
	{
		std::cout << " ";
		m++;
	}
	std::cout << YELLOW << index + 1 << RESET;
	std::cout << MAGENTA << "|" << RESET;
	visuale_contact(name);
	std::cout << MAGENTA << "|" << RESET;
	visuale_contact(last_name);
	std::cout << MAGENTA << "|" << RESET;
	visuale_contact(nick_name);
	std::cout << MAGENTA << "|" << RESET;
	std::cout << std::endl;
}

