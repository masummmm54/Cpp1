
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	int		num = 12;
	Animal	*j[num];

	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
			j[i] = new Dog();
		else
			j[i] = new Cat();
	}

	j[0]->getBrain()->setIdea("masum--------------");
	std::cout << j[0]->getBrain()->getIdea(0) << std::endl;

	for (int i = 0; i < num; i++)
	{
		delete j[i];
	}

	Dog a;
	Dog b;

	a.getBrain()->setIdea("mausm");
	a.getBrain()->setIdea("neden boyle");
	a.getBrain()->setIdea("second idea");
	b = a;
	a.getBrain()->setIdea("third idea");
	a.getBrain()->setIdea("fourth idea");
	b.getBrain()->setIdea("random idea");


	std::cout << "a ----------- --------" << std::endl;
	std::cout << a.getBrain()->getIdea(0) << std::endl;
	std::cout << a.getBrain()->getIdea(1) << std::endl;
	std::cout << a.getBrain()->getIdea(2) << std::endl;
	std::cout << a.getBrain()->getIdea(3) << std::endl;
	std::cout << a.getBrain()->getIdea(4) << std::endl;
	std::cout << "b ----------- --------" << std::endl;
	std::cout << b.getBrain()->getIdea(0) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;
	std::cout << b.getBrain()->getIdea(2) << std::endl;
	std::cout << b.getBrain()->getIdea(3) << std::endl;
	std::cout << b.getBrain()->getIdea(4) << std::endl;


	return (0);
}

