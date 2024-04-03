#include "Dog.hpp"


Dog::Dog() : Animal("Dog") , brains(new Brain())
{
	std::cout << ">Dog Constructor called!" << std::endl;
}

Dog::~Dog()
{
	delete brains;
	std::cout << ">Dog Deconstructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal("Dog") , brains(new Brain(*(other.brains)))
{
	std::cout << ">Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << ">Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.getType();
		delete brains;
		brains = new Brain (*other.brains);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Hoav Hoav!!!!" << std::endl;
}

Brain* Dog::getBrain()
{
	return (brains);
}
