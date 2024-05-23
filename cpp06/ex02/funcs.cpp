#include "funcs.hpp"

void	printer(std::string str)
{
	std::cout << str << '\n';
}

Base * generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		return (printer("A generated!"),new A());
		break;
	case 1:	
		return (printer("B generated!"), new B());
		break;
	case 2:
		return (printer("C generated!"), new C());
		break;
	default:
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		printer("A type");
	else if (dynamic_cast<B*>(p))
		printer("B type");
	else if (dynamic_cast<C*>(p))
		printer("C type");
	else
		std::cerr << "Unknown type" << '\n';
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		printer("A type");
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			printer("B type");
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				printer("C type");
			}
			catch(...)
			{
				std::cerr << "Unknown type" << '\n';
			}
		}
	}
}
