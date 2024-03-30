
#include "ScavTrap.hpp"

int main ( void )
{

	ScavTrap a;

	ScavTrap c("dede");

	a = c;
	a.attack("anan");
	a.beRepaired(1);
	a.guardGate();
	a.takeDamage(120);
	a.guardGate();

	return (0);
}
