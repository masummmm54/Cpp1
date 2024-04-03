#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << ">WrongCat constructor called!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << ">WrongCat deconstructer called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& p) : WrongAnimal("WrongCat")
{
	type = p.getType();
	std::cout << ">WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << ">WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.getType();
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meovvvvvv!!!!!!!" << std::endl;
}
