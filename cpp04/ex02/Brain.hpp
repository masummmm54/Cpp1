#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>

class Brain
{
private:
	std::string ideas[100];
	size_t		num;
public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);

	void		setIdea(std::string str);
	std::string	getIdea(int i);
};





#endif
