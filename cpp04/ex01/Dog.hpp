#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
private:
	Brain *brains;
public:
	Dog();
	~Dog();
	Dog(const Dog& p);
	Dog& operator=(const Dog& other);

	void	makeSound() const;
	Brain*	getBrain();
};


#endif
