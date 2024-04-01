#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
private:
	Brain* brains;
public:
	Cat();
	Cat(const Cat& p);
	~Cat();
	Cat& operator=(const Cat& other);

	void	makeSound() const = 0;
	Brain*	getBrain() = 0;
};






#endif
