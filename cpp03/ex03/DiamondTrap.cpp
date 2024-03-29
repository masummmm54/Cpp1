
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	_name = "(null)";
	std::cout << "Default DiamondTrap created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	_name = name;
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;	
	std::cout << "DiamondTrap standart created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyted!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& p) : FragTrap(p), ScavTrap(p)
{
	_name = p._name;
	ScavTrap::_health = p.FragTrap::_health;
	ScavTrap::_energy = p.ScavTrap::_energy;
	FragTrap::_damage = p.FragTrap::_damage;
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
		ScavTrap::_health = other.FragTrap::_health;
		ScavTrap::_energy = other.ScavTrap::_energy;
		FragTrap::_damage = other.FragTrap::_damage;
	}
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap is " << _name << " and ClapTrapName is "<< FragTrap::ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}
