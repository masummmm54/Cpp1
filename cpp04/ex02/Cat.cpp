
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") , brains(new Brain())
{
	std::cout << ">Cat constructor called!" << std::endl;
}

Cat::~Cat()
{
	delete brains;
	std::cout << ">Cat deconstructer called!" << std::endl;
}

Cat::Cat(const Cat& p) : Animal()
{
	*this = p;
	std::cout << ">Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << ">Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.getType();
		delete brains;
		brains = new Brain(*(other.brains));
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meovvv!!!!" << std::endl;
}

Brain* Cat::getBrain()
{
	return (brains);
}

