
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& p);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void		print(std::ostream& out) const;
	std::string	getTarget() const;
	void		run_execute() const;
};



#endif