
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}


HumanA::~HumanA() {}

void	HumanA::attack()
{
	if (!weapon.getType().empty())
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	else
		std::cout << this->name << " does not have a weapon " << this->weapon.getType() << std::endl;
}

