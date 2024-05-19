
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	test1()
{
	try
	{
		AForm *pardonform = new PresidentialPardonForm("home");
		AForm *pardonform2 = new PresidentialPardonForm("MYHOME");

		PresidentialPardonForm pardonform3("MYSCHOOL");
		PresidentialPardonForm pardonform4(pardonform3);

		std::cout << *pardonform << std::endl;
		std::cout << *pardonform2 << std::endl;
		std::cout << pardonform3 << std::endl;
		std::cout << pardonform4 << std::endl;

		*pardonform = *pardonform2;
		std::cout << *pardonform << std::endl;

		delete pardonform;
		delete pardonform2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------\n";
}

void	test2()
{
	try
	{
		PresidentialPardonForm pardonform("MYASSISTANT");
		std::cout << pardonform << std::endl;
		Bureaucrat Boss("Boss", 1);
		pardonform.beSigned(Boss);
		pardonform.execute(Boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------------\n";
}

void	test3()
{
	try
	{
		RobotomyRequestForm pardonform("MYASSISTANT");
		std::cout << pardonform << std::endl;
		Bureaucrat Boss("Boss", 1);
		pardonform.beSigned(Boss);
		pardonform.execute(Boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------------\n";
}

void	test4()
{
	try
	{
		ShrubberyCreationForm pardonform("MYASSISTANT");
		std::cout << pardonform << std::endl;
		Bureaucrat Boss("Boss", 1);
		Bureaucrat Employee("Employee", 137);
		Boss.signForm(pardonform);
		std::cout << pardonform << std::endl;
		Employee.executeForm(pardonform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------------\n";
}

int	main()
{
	//test1();
	//test2();
	//test3();
	test4();

	return (0);
}
