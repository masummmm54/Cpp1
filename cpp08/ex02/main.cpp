
#include "MutantStack.hpp"
#include <list>
#include <vector>

void test()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}


void test1()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(12);
	mstack.push(8);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator it2 = mstack.end();


	std::cout << "values:    " << std::endl;
	std::cout << *it << std::endl;
	it2--;
	std::cout << *it2 << std::endl;
}


void test2()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int	main( void )
{
	std::cout << "------------------------------\n";
	test();
	std::cout << "------------------------------\n";
	test2();
	std::cout << "------------------------------\n";
	test1();
	std::cout << "------------------------------\n";

	return (0);
}