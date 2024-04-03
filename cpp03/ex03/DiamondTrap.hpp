#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public FragTrap, public ScavTrap
{
private:
	std::string _name;
	using FragTrap::_damage;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& p);
	DiamondTrap& operator=(const DiamondTrap &other);

	void	whoAmI(void);
	using ScavTrap::attack;

};




#endif
