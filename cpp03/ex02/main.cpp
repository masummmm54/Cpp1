
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ( void )
{

	FragTrap a("masum");
	a.highFivesGuys();
	a.attack("enemy");
	a.beRepaired(1);
	a.takeDamage(120);
	a.highFivesGuys();

	return (0);
}
