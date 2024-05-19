
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& p) {(void)p;}
Intern& Intern::operator=(const Intern& other) {(void)other; return *this;}

AForm* Intern::shrubbery(std::string target){return (new ShrubberyCreationForm(target));}
AForm* Intern::robotomy(std::string target) {return (new RobotomyRequestForm(target));}
AForm* Intern::presidential(std::string target) {return (new PresidentialPardonForm(target));}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *form = NULL;
	Intern_funcs functions[3] = {&Intern::shrubbery, &Intern::robotomy, &Intern::presidential};
	std::string		forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	for (i = 0; i < 3 && forms[i] != name; i++);
	if (i < 3)
	{
		form = (this->*functions[i])(target);
		std::cout << "Intern creates " << form->getName() << '\n';
	}
	else
		std::cout << "Intern could not create " << name << '\n';
	return (form);
}