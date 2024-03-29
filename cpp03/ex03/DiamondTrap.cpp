
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	_name = "(null)";
	std::cout << "Default DiamondTrap created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	_name = name;
	std::cout << "DiamondTrap standart created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyted!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& p) : ScavTrap(p), FragTrap(p)
{
	_name = p._name;
	_health = p._health;
	_damage = p._damage;
	_energy = p._energy;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		_health = other._health;
		_damage = other._damage;
		_energy = other._energy;
	}
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << _name << " is my name!" << std::endl;
}
