#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string Type);
	virtual ~Animal();
	Animal(const Animal &p);
	virtual Animal& operator=(const Animal &other);

	std::string		getType() const;
	void			setType(std::string Type);
	virtual void	makeSound() const;
	virtual Brain*	getBrain();
};


#endif
