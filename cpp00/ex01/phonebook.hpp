#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{

	private:
	int			contact_num;
	int			index;
	Contact		contacts[8];

	public:
	PhoneBook();
	~PhoneBook();
	void		search();
	void		add();
};


void	visuale_contact(std::string n);

#endif
