#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal
{
private:
	
public:
	Dog();
	~Dog();
	Dog(const Dog& p);
	Dog& operator=(const Dog& other);

	void	makeSound() const;
};




#endif
