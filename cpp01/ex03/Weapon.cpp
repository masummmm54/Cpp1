
#include "Weapon.hpp"

std::string Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon() {
	this->type = "(null)";
}
