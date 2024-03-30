
#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "(null)";
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << ">Default ScavTrap constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << ">Standart ScavTrap constructor has been called! " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << ">ScavTrap destroyted! " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& p) : ClapTrap(p)
{
	_name = p._name;
	_health = p._health;
	_damage = p._damage;
	_energy = p._energy;
	*this = p;
	std::cout << ">ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << ">ScavTrap Copy assignment operator called" << std::endl;
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
	if (_health > 0)
		std::cout << ">ScavTrap " << _name << " guards the gate now!" << std::endl;
	else
		std::cout << ">ScavTrap " << _name << " cannot guard the gate because it is unfornutaley dead!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy > 0 && _health > 0)
	{
		std::cout << ">ScavTrap " << _name << " attacts " << target << " causing " << _damage << " points of damage!";
		_energy--;
		std::cout << " | Reamaning energy is : ";
		std::cout << _energy << std::endl;
	}
	else if (_health < 1)
		printmsg(" cannot attack because he is dead!\n");
	else
		std::cout << ">ScavTrap " << _name << " has no energy to attack!" << " | Remanin energy is: " << _energy << std::endl;
}

void	ScavTrap::printmsg(std::string msg)
{
	std::cout << ">ScavTrap " << _name << msg;
}
