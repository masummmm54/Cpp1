#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie ()
{
	std::cout << this->name << "  destroyed" << std::endl;
}

Zombie::Zombie()
{
	this->name = "(null)";
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::add_name(std::string s)
{
	this->name = s;
}
