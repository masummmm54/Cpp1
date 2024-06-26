
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "---------------" << std::endl;

	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_i->makeSound();


	delete meta;
	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_i;
	return (0);
}
