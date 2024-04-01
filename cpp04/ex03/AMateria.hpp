#ifndef AMATERIA_HPP
#define AMETRERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:


public:
	AMateria();
	AMateria(std::string const& type);
	~AMateria();


	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};









#endif
