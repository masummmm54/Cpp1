
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : index(0)
{
	for (int i = 0; i < 4; i++)
	{
		materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < index; i++)
	{
		delete materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		index = other.index;
		for (int i = 0; i < other.index; i++)
		{
			if (materias[i])
				delete materias[i];
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (index == 4)
	{
		delete m;
		std::cout << "Can't learn more materias" << std::endl;
	}
	else
		materias[index++] = m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for(int i = 0; i < index && materias[i]; i++)
	{
		if (type == materias[i]->getType())
			return (materias[i]->clone());
	}
	return (0);
}
