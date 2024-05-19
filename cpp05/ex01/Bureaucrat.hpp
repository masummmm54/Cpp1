#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string.h>

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name_, int grade_);
	Bureaucrat(const Bureaucrat& p);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void				signForm(Form& form);
	const std::string	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bur);



#endif