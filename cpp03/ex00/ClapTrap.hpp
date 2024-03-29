#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	long int		_health;
	unsigned int	_energy;
	unsigned int	_damage;
public:
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &p);
	ClapTrap& operator=(const ClapTrap &other);
	//functions
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	//self
	void			printmsg(std::string msg);
};


#endif
