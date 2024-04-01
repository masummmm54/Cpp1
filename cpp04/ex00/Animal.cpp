#include "Animal.hpp"

Animal::Animal()
{
	type = "(null)";
	std::cout << ">Default Animal constructor called!" << std::endl;
}

Animal::Animal(std::string Type) : type(Type)
{
	std::cout << ">Standart Animal constructor called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << ">Animal deconstructor called!" << std::endl;
}

Animal::Animal(const Animal& p)
{
	type = p.getType();
	*this = p;
	std::cout << ">Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << ">Animal Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}


void	Animal::makeSound() const
{
	std::cout << "Animal Barking" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::setType(std::string Type)
{
	type = Type;
}
