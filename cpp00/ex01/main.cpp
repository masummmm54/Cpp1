#include "phonebook.hpp"

class Contact
{
	public:
	std::string		name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		dark_secret;
};

class PhoneBook
{
	public:
	int			contact_num;
	int			index;
	Contact		*contacts;
};

void	add(PhoneBook *book)
{
	std::string		name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		dark_secret;
	std::cout << "Contact name: ";
	while (name.empty())
		std::getline(std::cin, name);
	std::cout << "Contact last name: ";
	while (last_name.empty())
		std::getline(std::cin, last_name);
	std::cout << "Contact nick name: ";
	while (nick_name.empty())
		std::getline(std::cin, nick_name);
	std::cout << "Contact phone number: ";
	while (phone_number.empty())
		std::getline(std::cin, phone_number);
	std::cout << "Contact darkest secret: ";
	while (dark_secret.empty())
		std::getline(std::cin, dark_secret);
	std::cout << std::endl;
	book->contacts[book->index].name = name;
	book->contacts[book->index].last_name = last_name;
	book->contacts[book->index].nick_name = nick_name;
	book->contacts[book->index].phone_number = phone_number;
	book->contacts[book->index].dark_secret = dark_secret;
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

void	print_contac(Contact n, int index)
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
	visuale_contact(n.name);
	std::cout << "|";
	visuale_contact(n.last_name);
	std::cout << "|";
	visuale_contact(n.nick_name);
	std::cout << "|";
	std::cout << std::endl;
}

void	show_contact(Contact n)
{
	std::cout << std::endl;
	std::cout << "Name:           " << n.name << std::endl;
	std::cout << "Last name:      " << n.last_name << std::endl;
	std::cout << "Nick name:      " << n.nick_name << std::endl;
	std::cout << "Phone number:   " << n.phone_number << std::endl;
	std::cout << "Darkest secret: " << n.dark_secret << std::endl;
	std::cout << std::endl;
}

void	search(PhoneBook *book)
{
	int	index = 0;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|Index     |Name      |Last Name |Nick Name |" << std::endl;
	while (index < book->contact_num)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		print_contac(book->contacts[index], index);
		index++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "Index number for contact: " << std::endl;
	std::cin >> index;
	if (index <= book->contact_num && index > 0)
		show_contact(book->contacts[index - 1]);
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
			std::cout << "EXIT command" << std::endl;
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
