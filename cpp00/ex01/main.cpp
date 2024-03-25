
#include "Phonebook.hpp"

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
					exit(0);
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
					exit(0);
			}
		}
	}
	return (input);
}


void	add(PhoneBook *book)
{
	book->contacts[book->index] = Contact(	take_input("Contact name: "),
											take_input("Contact last name: "),
											take_input("Contact nick name: "),
											take_input("Contact phone number: "),
											take_input("Contact darkest secret: "));
	std::cout << std::endl;
	if (book->contact_num < 8)
		book->contact_num++;
	if (book->index != 7)
		book->index++;
	else
		book->index = 0;
}


void	search(PhoneBook *book)
{
	int			index = 0;
	std::string	index_str;

	if (book->contact_num == 0)
	{
		std::cout << RED << "No contact registered!" << RESET << std::endl;
		return ;
	}
	std::cout << MAGENTA << " ------------------------------------------- " << RESET << std::endl;
	std::cout << MAGENTA << "|     Index|      Name| Last Name| Nick Name|" << RESET << std::endl;
	while (index < book->contact_num)
	{
		std::cout << MAGENTA << "|-------------------------------------------|" << RESET << std::endl;
		book->contacts[index].print_contac(index);
		index++;
	}
	std::cout << MAGENTA << " ------------------------------------------- " << RESET << std::endl;
	std::cout << BLUE << "Index number for contact: " << RESET << std::endl;
	if (!std::getline(std::cin, index_str))
	{
		if (std::cin.eof())
			exit(0);
	}
	index = atoi(index_str.c_str());
	if (index <= book->contact_num && index > 0)
		book->contacts[index - 1].show_contact();
	else 
		std::cout << RED << "Wrong index!\n" << RESET <<std::endl;
}

int	main(int ac, char **av)
{
	PhoneBook	book;
	std::string	input;
	book.contact_num = 0;
	book.index = 0;
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
				break;
			std::cin.clear();
			continue;
		}
		if (input == "ADD" || input == "1")
			add(&book);
		else if (input == "SEARCH" || input == "2")
			search(&book);
		else if (input == "EXIT" || input == "3")
			break;
	}
	return (0);
}
