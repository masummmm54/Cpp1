#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "(null)";
	std::cout << ">WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type) : type(Type)
{
	std::cout << ">WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << ">WrongAnimal deconstructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& p)
{
	type = p.getType();
	*this = p;
	std::cout << ">WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << ">WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}


void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Barking" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::setType(std::string Type)
{
	type = Type;
}
