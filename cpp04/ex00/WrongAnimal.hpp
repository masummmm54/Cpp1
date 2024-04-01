#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string Type);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &p);
	WrongAnimal& operator=(const WrongAnimal &other);

	std::string		getType() const;
	void			setType(std::string Type);
	void			makeSound() const;
};






#endif
