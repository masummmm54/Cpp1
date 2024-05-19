
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
	AForm* shrubbery(std::string target);
	AForm* robotomy(std::string target);
	AForm* presidential(std::string target);
public:
	Intern();
	~Intern();
	Intern(const Intern& p);
	Intern& operator=(const Intern& other);
	AForm* makeForm(std::string name, std::string target);
};

typedef AForm* (Intern::*Intern_funcs) (const std::string);





#endif