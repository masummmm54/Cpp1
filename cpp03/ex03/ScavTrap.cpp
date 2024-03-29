
#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "(null)";
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Default ScavTrap created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap standart created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyted!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& p) : ClapTrap(p)
{
	_name = p._name;
	_health = p._health;
	_damage = p._damage;
	_energy = p._energy;
	*this = p;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_health = other._health;
		_damage = other._damage;
		_energy = other._energy;
	}
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " guards the gate now!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy > 0 && _health > 0)
	{
		std::cout << "ScavTrap " << _name << " attacts " << target << " causing " << _damage << " points of damage!" << std::endl;
		_energy--;
		printmsg(" remainin energy is: ");
		std::cout << _energy << std::endl;
	}
	else if (_health < 1)
		printmsg(" cannot attack because he is dead!\n");
	else
		std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
}

void	ScavTrap::printmsg(std::string msg)
{
	std::cout << "ScavTrap " << _name << msg;
}
