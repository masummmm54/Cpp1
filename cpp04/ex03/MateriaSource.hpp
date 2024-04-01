
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

private:
	
public:
	MateriaSource();
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const& type);
};






#endif
