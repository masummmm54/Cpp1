#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& p) : _name(p.getName()), _grade(p.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bur)
{
	out << Bur.getName() << ", bureaucrat grade " << Bur.getGrade();
	return (out);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {return ("Grade is too low!");}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {return ("Grade is too high!");}

const std::string Bureaucrat::getName() const {return (this->_name);}

int	Bureaucrat::getGrade() const {return (this->_grade);}


void	Bureaucrat::signForm(AForm& form)
{
	if (_grade > form.getGrade())
		std::cout << getName() << " couldn’t sign " << form.getName() << " because does not have enough grade!" << std::endl;
	else if (form.isSigned())
		std::cout << getName() << " couldn’t sign " << form.getName() << " because it is already signed!" << std::endl;
	else
	{
		std::cout << getName() << " signed " << form.getName() << "!" << std::endl;
		form.setSigned();
	}
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	if (_grade > form.getExecute())
		std::cout << getName() << " couldn’t execute " << form.getName() << " because does not have enough grade!" << std::endl;
	else if (!form.isSigned())
		std::cout << getName() << " couldn’t execute " << form.getName() << " because it is not signed!" << std::endl;
	else
	{
		std::cout << getName() << " executed " << form.getName() << "!" << std::endl;
		form.run_execute();
	}
}