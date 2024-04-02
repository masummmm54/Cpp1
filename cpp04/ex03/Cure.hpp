
#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	~Cure();
	Cure(const Cure& p);
	Cure& operator=(const Cure &other);

	AMateria* clone() const;
	void use(ICharacter& target);
};






#endif
