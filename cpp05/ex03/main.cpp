
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	test1()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	if (rrf == NULL)
		exit(1);
	Bureaucrat Boss("Boss", 1);
	std::cout << *rrf << '\n';
	rrf->beSigned(Boss);
	rrf->execute(Boss);
	delete rrf;
}
void	test2()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf == NULL)
		exit(1);
	Bureaucrat Boss("Boss", 1);
	std::cout << *rrf << '\n';
	rrf->beSigned(Boss);
	rrf->execute(Boss);
	delete rrf;
}
void	test3()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (rrf == NULL)
		exit(1);
	Bureaucrat Boss("Boss", 1);
	std::cout << *rrf << '\n';
	rrf->beSigned(Boss);
	rrf->execute(Boss);
	delete rrf;
}
void	test4()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("blabla", "Bender");
		if (rrf == NULL)
			return ;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int	main()
{
	test1();
	test2();
	test3();
	test4();

	return (0);
}
