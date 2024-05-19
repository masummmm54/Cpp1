#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string.h>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_issigned;
	const int			_grade;
	const int			_execute;

public:
	AForm();
	AForm(std::string name, const int grade, const int execute);
	AForm& operator=(const AForm& other);
	AForm(const AForm& p);
	virtual	~AForm();

	bool				isSigned() const;
	int					getGrade() const;
	int					getExecute() const;
	const std::string	getName() const;
	void				beSigned(Bureaucrat& bur);
	void				setSigned();
	void				execute(Bureaucrat const & executor) const;
	virtual void		run_execute() const = 0;
	virtual void		print(std::ostream& out) const;
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif