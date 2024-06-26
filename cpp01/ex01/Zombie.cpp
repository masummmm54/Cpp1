#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie ()
{
	std::cout << this->name << " destroyed." << std::endl;
}

Zombie::Zombie() {}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::add_name(std::string s)
{
	this->name = s;
}

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombie[i].add_name(name);
	}
	return (zombie);
}
