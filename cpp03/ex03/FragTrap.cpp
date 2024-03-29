
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "(null)";
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "Default FragTrap created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap standart created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyted!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& p) : ClapTrap(p)
{
	_name = p._name;
	_health = p._health;
	_damage = p._damage;
	_energy = p._energy;
	*this = p;
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_health = other._health;
		_damage = other._damage;
		_energy = other._energy;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	if (_health > 0)
		std::cout << "FragTrap " << _name << " gives high five to everyone!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " unfornutaley is dead!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energy > 0 && _health > 0)
	{
		std::cout << "FragTrap " << _name << " attacts " << target << " causing " << _damage << " points of damage!" << std::endl;
		_energy--;
		printmsg(" remainin energy is: ");
		std::cout << _energy << std::endl;
	}
	else if (_health < 1)
		printmsg(" cannot attack because he is dead!\n");
	else
		std::cout << "FragTrap " << _name << " has no energy to attack!" << std::endl;
}

void	FragTrap::printmsg(std::string msg)
{
	std::cout << "FragTrap " << _name << msg;
}
