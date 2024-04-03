#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
	std::cout << ">Dog Constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << ">Dog Deconstructor called!" << std::endl;
}

Dog::Dog(const Dog& p) : Animal("Dog")
{
	*this = p;
	std::cout << ">Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << ">Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.getType();
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Hoav Hoav!!!!" << std::endl;
}
