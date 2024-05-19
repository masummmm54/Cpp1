#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default Form"), _issigned(false), _grade(150), _execute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, const int grade, const int execute) : _name(name), _issigned(false), _grade(grade), _execute(execute)
{
	if (_grade < 1 || _execute < 1)
		throw Form::GradeTooHighException();
	if (_grade > 150 || _execute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& p) : _name(p.getName()), _issigned(p.isSigned()), _grade(p.getGrade()), _execute(p.getExecute())
{
	std::cout << "Form copy assignment called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_issigned = other.isSigned();
	std::cout << "Form copy assignment operator is called" << std::endl;
	return (*this);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	if (form.isSigned())
		out << form.getName() << " is signed! ";
	else
		out << form.getName() << " is not signed! ";

	out << " sign grade is " << form.getGrade() << ", execute grade is " << form.getExecute();
	return (out);
}

void	Form::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > _grade)
		throw Form::GradeTooLowException();
	else if (_issigned)
		std::cout << bur.getName() << " cant signed the " << _name << " because it is already signed!" << std::endl;
	else
	{
		std::cout << bur.getName() << " signed the " << _name << "!" << std::endl;
		setSigned();
	}
}

void	Form::setSigned()
{
	this->_issigned = true;
}

const std::string Form::getName() const
{
	return (this->_name);
}

int	Form::getGrade() const
{
	return (this->_grade);
}

int	Form::getExecute() const
{
	return (this->_execute);
}

bool	Form::isSigned() const
{
	return (this->_issigned);
}

