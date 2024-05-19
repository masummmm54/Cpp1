
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& p) : AForm("RobotomyRequestForm", 72, 45), _target(p.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->_target = other.getTarget();
	return (*this);
}

void	RobotomyRequestForm::run_execute() const
{
	std::cout << "RRRRrRrrrRRRrrrrrRRrrrrrr" << std::endl;
	std::srand(time(0));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {return (_target);}

void RobotomyRequestForm::print(std::ostream& out) const
{
	if (isSigned())
		out << getName() << " is signed! ";
	else
		out << getName() << " is not signed! ";
	out << " sign grade is " << getGrade() << ", execute grade is " << getExecute();
	out << ", target is " << getTarget();
}