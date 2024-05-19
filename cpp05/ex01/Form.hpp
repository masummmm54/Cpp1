#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string.h>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_issigned;
	const int			_grade;
	const int			_execute;

public:
	~Form();
	Form();
	Form(std::string name, const int grade, const int execute);
	Form(const Form& p);
	Form& operator=(const Form& other);

	bool				isSigned() const;
	int					getGrade() const;
	int					getExecute() const;
	const std::string	getName() const;
	void				beSigned(Bureaucrat& bur);
	void				setSigned();
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


std::ostream& operator<<(std::ostream& out, const Form& form);

#endif