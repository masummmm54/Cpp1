
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{

private:
	AMateria	*materias[4];
	int			index;
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& p);
	MateriaSource& operator=(const MateriaSource &other);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);
};


#endif
