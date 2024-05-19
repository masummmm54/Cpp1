
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form form_random;
		Form form("form", 150, 150);
		Form form1("form1", 1, 1);
		Bureaucrat buro1("masum", 5);
		std::cout << "-----------------------\n";
		buro1.incrementGrade();
		std::cout << buro1 << '\n';
		std::cout << form << '\n';
		std::cout << form1 << '\n';
		form.beSigned(buro1);
		form_random.beSigned(buro1);
		buro1.signForm(form1);
		std::cout << form1 << '\n';
		std::cout << form << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------------\n";
	return (0);
}
