
#pragma once

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

class Ice : public AMateria
{
private:
	
public:
	Ice();
	~Ice();
	Ice(const Ice& p);
	Ice& operator=(const Ice &other);

	AMateria* clone() const;
	void use(ICharacter& target);
};






#endif
