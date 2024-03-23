
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <ctype.h>
#include <string>
#include <cstdlib>

void	visuale_contact(std::string n);
void	visuale_contact(std::string n);

class Contact
{
	private:
	std::string		name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		dark_secret;

	public:
	void	show_contact()
	{
		std::cout << std::endl;
		std::cout << "Name:           " << name << std::endl;
		std::cout << "Last name:      " << last_name << std::endl;
		std::cout << "Nick name:      " << nick_name << std::endl;
		std::cout << "Phone number:   " << phone_number << std::endl;
		std::cout << "Darkest secret: " << dark_secret << std::endl;
		std::cout << std::endl;
	}

	void	print_contac(int index)
	{
		int	m = 0;
		std::cout << "|";
		std::cout << index + 1;
		while (m < 9)
		{
			std::cout << " ";
			m++;
		}
		std::cout << "|";
		visuale_contact(name);
		std::cout << "|";
		visuale_contact(last_name);
		std::cout << "|";
		visuale_contact(nick_name);
		std::cout << "|";
		std::cout << std::endl;
	}

	void add_name(std::string s)
	{
		name = s;
	}
	void add_last_name(std::string s)
	{
		last_name = s;
	}
	void add_nick_name(std::string s)
	{
		nick_name = s;
	}
	void add_phone_number(std::string s)
	{
		phone_number = s;
	}
	void add_dark_secret(std::string s)
	{
		dark_secret = s;
	}
};

class PhoneBook
{
	public:
	int			contact_num;
	int			index;
	Contact		*contacts;
};

#endif
