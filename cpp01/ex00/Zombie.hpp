#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <ctype.h>
#include <string>
#include <cstdlib>


class Zombie
{
	private:
	std::string name;

	public:
	Zombie ();
	Zombie (std::string name);

	void	add_name(std::string s);
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);


#endif
