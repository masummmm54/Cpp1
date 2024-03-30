
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _name("(null)")
{
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << ">Default DiamondTrap contructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << ">Standart DiamondTrap constructor called! " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << ">DiamondTrap destroyted!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& p) : ClapTrap(p._name + "_clap_trap") ,FragTrap(p), ScavTrap(p)
{
	_name = p._name;
	_health = p.FragTrap::_health;
	_energy = p.ScavTrap::_energy;
	_damage = p.FragTrap::_damage;
	std::cout << ">DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << ">DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		_health = other.FragTrap::_health;
		_energy = other.ScavTrap::_energy;
		_damage = other.FragTrap::_damage;
	}
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << ">DiamondTrap name is : " << _name << " and ClapTrap name is : "<< ClapTrap::_name << std::endl;
}
