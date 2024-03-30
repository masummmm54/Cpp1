
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("(null)"), _health(10), _energy(10), _damage(0)
{
	std::cout << ">Default ClapTrap constructor has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : _name(n), _health(10), _energy(10), _damage(0)
{
	std::cout << ">Standart ClapTrap constructor has been called! " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << ">ClapTrap " << _name << " destroyed! " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& p)
{
	std::cout << ">Copy constructor called" << std::endl;
	_name = p._name;
	_health = p._health;
	_damage = p._damage;
	_energy = p._energy;
	*this = p;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << ">Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_health = other._health;
		_damage = other._damage;
		_energy = other._energy;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy > 0 && _health > 0)
	{
		std::cout << ">ClapTrap " << _name << " attacts " << target << " causing " << _damage << " points of damage!";
		_energy--;
		std::cout << " | Remaining energy is : ";
		std::cout << _energy << std::endl;
	}
	else if (_health < 1)
		printmsg(" cannot attack because he is dead!\n");
	else
		std::cout << ">ClapTrap " << _name << " has no energy to attack!" << " | Remanin energy is: " << _energy << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_health > 0)
	{
		_health -= amount;
		printmsg(" has taken damage point of : ");
		std::cout << amount;
		if (_health > 0)
		{
			std::cout << " | Remaining health is : ";
			std::cout << _health << std::endl;
		}
		else
			std::cout << " | It is dead!" << std::endl;
	}
	else
		printmsg(" has already dead you cruel!\n");
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy >= 1 && _health > 0)
	{
		_energy--;
		_health += amount;
		printmsg(" repaired itself amount of : ");
		std::cout << amount;
		std::cout << " | Remaining energy is : ";
		std::cout << _energy;
		std::cout << " | Current healt is : ";
		std::cout << _health << std::endl;
	}
	else if (_health < 1)
		printmsg(" cannot heal because it is dead!\n");
	else
		printmsg(" has no energy to repair!\n");
}

void	ClapTrap::printmsg(std::string msg)
{
	std::cout << ">ClapTrap " << _name << msg;
}
