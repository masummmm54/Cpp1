
#include "Bureaucrat.hpp"

int	main()
{


	try
	{
		Bureaucrat one("buro0", -5);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat two("buro1", 5);
		two.incrementGrade();
		std::cout << two << std::endl;
		two.decrementGrade();
		two.decrementGrade();
		std::cout << two << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat three("buro2", 150);
		three.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat four("buro3", 157);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
