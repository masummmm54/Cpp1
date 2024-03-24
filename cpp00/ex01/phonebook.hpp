#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <ctype.h>
#include <string>
#include <cstdlib>

#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define YELLOW	"\x1b[33m"
#define BLUE	"\x1b[34m"
#define MAGENTA	"\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET	"\x1b[0m"

class Contact
{
	private:
	std::string		name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		dark_secret;

	public:
	Contact (std::string name, std::string last_name, std::string nick_name, std::string phone_number, std::string dark_secret);
	Contact ();
	~Contact () {}
	void	show_contact();
	void	print_contac(int index);
};

class PhoneBook
{
	public:
	PhoneBook() {}
	~PhoneBook() {
		std::cout << RED << "Phonebook closing..." << RESET << std::endl;
	}
	int			contact_num;
	int			index;
	Contact		contacts[8];
};


void	visuale_contact(std::string n);

#endif
