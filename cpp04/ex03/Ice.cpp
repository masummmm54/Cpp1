
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& p) : AMateria("ice")
{
	*this = p;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}


AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
