#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class Cat : public Animal
{
private:

public:
	Cat();
	~Cat();
	Cat(const Cat& p);
	Cat& operator=(const Cat& other);

	void	makeSound() const;
};






#endif
