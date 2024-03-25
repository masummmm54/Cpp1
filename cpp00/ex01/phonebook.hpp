#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	int			contact_num;
	int			index;
	Contact		contacts[8];
};


void	visuale_contact(std::string n);

#endif
