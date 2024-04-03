

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

	ICharacter* me = new Character("masum");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob  = new Character("bob");

	Character som("som");
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	som.equip(tmp1);
	Character ash = som;
	tmp1 = src->createMateria("cure");
	som.equip(tmp1);

	som.use(0, *bob);
	som.use(1, *bob);
	ash.use(0, *bob);
	ash.use(1, *bob);

	me->use(0, *bob);
	me->use(0, *bob);
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-4, *bob);
	me->use(2, *bob);



	delete bob;
	delete me;
	delete src;


	return (0);
}
