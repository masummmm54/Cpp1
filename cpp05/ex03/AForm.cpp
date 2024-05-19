#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _issigned(false), _grade(150), _execute(150) {}

AForm::AForm(std::string name, const int grade, const int execute) : _name(name), _issigned(false), _grade(grade), _execute(execute)
{
	if (_grade < 1 || _execute < 1)
		throw AForm::GradeTooHighException();
	if (_grade > 150 || _execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& p) : _name(p.getName()), _issigned(p.isSigned()), _grade(p.getGrade()), _execute(p.getExecute()) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_issigned = other.isSigned();
	return (*this);
}

const char*	AForm::GradeTooLowException::what() const throw() {return ("Grade is too low!");}

const char*	AForm::GradeTooHighException::what() const throw() {return ("Grade is too high!");}

void AForm::print(std::ostream& out) const
{
	if (isSigned())
		out << getName() << " is signed! ";
	else
		out << getName() << " is not signed! ";

	out << " sign grade is " << getGrade() << ", execute grade is " << getExecute();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	form.print(out);
	return (out);
}

void	AForm::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > _grade)
		throw AForm::GradeTooLowException();
	else if (_issigned)
		std::cout << bur.getName() << " cant signed the " << _name << " because it is already signed!" << std::endl;
	else
	{
		std::cout << bur.getName() << " signed the " << _name << "!" << std::endl;
		setSigned();
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_issigned)
		std::cout << executor.getName() << " could not execute " << _name << " because is not signed yet!" << '\n';
	else if (executor.getGrade() > _grade)
		throw AForm::GradeTooLowException();
	else
		run_execute();
}

void	AForm::setSigned() {this->_issigned = true;}

const std::string AForm::getName() const {return (this->_name);}

int	AForm::getGrade() const {return (this->_grade);}

int	AForm::getExecute() const {return (this->_execute);}

bool	AForm::isSigned() const {return (this->_issigned);}
