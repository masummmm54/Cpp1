
#include "ClapTrap.hpp"

int main ( void )
{

	ClapTrap a("muhammet");

	a.attack("masum");
	a.takeDamage(1);
	a.beRepaired(0);
	a.takeDamage(5);
	a.takeDamage(5);
	a.attack("masum");
	a.takeDamage(5);
	a.beRepaired(5);



	return (0);
}
