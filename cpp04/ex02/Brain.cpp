
#include "Brain.hpp"

Brain::Brain()
{
	num = 0;
	std::cout << ">Brain constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << ">Brain deconstructer called!" << std::endl;
}

Brain::Brain(const Brain& p)
{
	num = p.num;
	for (int i = 0; i < 100; i++)
		ideas[i] = p.ideas[i];
	std::cout << ">Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << ">Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		num = other.num;
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void	Brain::setIdea(std::string str)
{
	if (num < 100)
		ideas[num++] = str;
	else
		num = 0;
}

std::string	Brain::getIdea(int i)
{
	return (ideas[i]);
}
