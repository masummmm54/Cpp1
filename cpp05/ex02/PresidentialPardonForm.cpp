
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : AForm("PresidentialPardonForm", 25, 5), _target(p.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->_target = other.getTarget();
	return (*this);
}

void	PresidentialPardonForm::run_execute() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << '\n';
}

std::string PresidentialPardonForm::getTarget() const {return (_target);}

void PresidentialPardonForm::print(std::ostream& out) const
{
	if (isSigned())
		out << getName() << " is signed! ";
	else
		out << getName() << " is not signed! ";
	out << " sign grade is " << getGrade() << ", execute grade is " << getExecute();
	out << ", target is " << getTarget();
}