#include "phonebook.hpp"


int	all_num(std::string number)
{
	int i = 0;

	while (number[i])
	{
		if (!(std::isdigit(number[i])))
			return (0);
		i++;
	}
	return(1);
}

void	add(PhoneBook *book)
{
	std::string		name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		dark_secret;

	while (name.empty())
	{
		std::cout << "Contact name: ";
		std::getline(std::cin, name);
	}
	while (last_name.empty())
	{
		std::cout << "Contact last name: ";
		std::getline(std::cin, last_name);
	}
	while (nick_name.empty())
	{
		std::cout << "Contact nick name: ";
		std::getline(std::cin, nick_name);
	}
	while (phone_number.empty() || !all_num(phone_number))
	{
		std::cout << "Contact phone number: ";
		std::getline(std::cin, phone_number);
	}	
	while (dark_secret.empty())
	{
		std::cout << "Contact darkest secret: ";
		std::getline(std::cin, dark_secret);
	}
	std::cout << std::endl;
	book->contacts[book->index].add_name(name);
	book->contacts[book->index].add_last_name(last_name);
	book->contacts[book->index].add_nick_name(nick_name);
	book->contacts[book->index].add_phone_number(phone_number);
	book->contacts[book->index].add_dark_secret(dark_secret);
	if (book->contact_num < 8)
		book->contact_num++;
	if (book->index != 7)
		book->index++;
	else
		book->index = 0;
}

void	visuale_contact(std::string n)
{
	int	m = 0;

	while (m < 10)
	{
		if (n[m] != '\0')
		{
			if (m == 9)
				std::cout << ".";
			else
				std::cout << n[m];
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

void	search(PhoneBook *book)
{
	int	index = 0;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|Index     |Name      |Last Name |Nick Name |" << std::endl;
	while (index < book->contact_num)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		book->contacts[index].print_contac(index);
		index++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "Index number for contact: " << std::endl;
	std::cin >> index;
	if (index <= book->contact_num && index > 0)
		book->contacts[index - 1].show_contact();
	else 
		std::cout << "Wrong index.\n" << std::endl;
}

int	main(int ac, char **av)
{
	PhoneBook	book;
	std::string	input;
	book.contacts = new Contact[8];
	book.contact_num = 0;
	book.index = 0;
	(void)ac;
	(void)av;
	std::cout << "Possible commands" << std::endl;
	while (1)
	{
		int	com = 0;
		std::cout << "1.ADD 2.SEARCH 3.EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD" || input == "1")
			com = 1;
		else if (input == "SEARCH" || input == "2")
			com = 2;
		else if (input == "EXIT" || input == "3")
			com = 3;
		switch (com)
		{
			case 1:
			add(&book);
			break;
			case 2:
			search(&book);
			break;
			case 3:
			std::cout << "Exiting phonebook." << std::endl;
			delete[] (book.contacts);
			exit(0);
			break;
			default:
			break;
		}
		input.clear();
		std::cin.clear();
	}
	return (0);
}
