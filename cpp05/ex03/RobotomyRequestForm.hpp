
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& p);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void		print(std::ostream& out) const;
	std::string	getTarget() const;
	void		run_execute() const;
};



#endif