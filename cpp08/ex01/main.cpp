
#include "Span.hpp"



void test()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test1()
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test2()
{
	Span sp = Span(1);

	try
	{
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test3()
{
	Span sp = Span(100000);

	std::list<int> vect;
	for (int i = 0; i < 10000; i++)
		vect.push_back(i);

	try
	{
		sp.addContainer<std::list<int> >(vect.begin(), vect.end(), vect.size());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

int	main( void )
{
	test();
	test1();
	test2();
	test3();
	return (0);
}