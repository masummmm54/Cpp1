

#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main ()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob  = new Character("bob");
	ICharacter* salim  = new Character("salim");

	me->use(0, *bob);
	me->unequip(0);
	me->use(0, *bob);
	salim->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-4, *bob);
	me->use(2, *salim);

	delete bob;
	delete me;
	delete src;
	delete salim;

	return (0);
}
