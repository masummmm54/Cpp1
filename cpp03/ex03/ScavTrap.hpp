#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap& p);
	ScavTrap& operator=(const ScavTrap &other);

	void	attack(const std::string& target);
	void	guardGate(void);
	void	printmsg(std::string msg);
};




#endif
