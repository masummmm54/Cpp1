#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public FragTrap, public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& p);
	DiamondTrap& operator=(const DiamondTrap &other);

    using ScavTrap::attack;
	void	whoAmI(void);
    using FragTrap::hitPoints;
    using FragTrap::attackDamage;
    using ScavTrap::energyPoints;

};




#endif
