

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
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob  = new Character("bob");

	Character ash("ash");
	Character dem("dem");
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	ash.equip(tmp1);
	dem = ash;
	Character som = ash;
	tmp1 = src->createMateria("cure");
	som.equip(tmp1);

	som.use(0, *bob); // should use ice 
	som.use(1, *bob); // should use cure
	ash.use(0, *bob); // should use ice 
	ash.use(1, *bob); // should not use cure since it is deep copy.

	me->use(0, *bob);
	me->use(0, *bob);
	me->unequip(0);
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
