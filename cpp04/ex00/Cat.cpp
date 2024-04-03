
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << ">Cat constructor called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << ">Cat deconstructer called!" << std::endl;
}

Cat::Cat(const Cat& p) : Animal("cat")
{
	type = p.getType();
	std::cout << ">Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << ">Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.getType();
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meovvv!!!!" << std::endl;
}
