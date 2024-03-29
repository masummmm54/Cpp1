
#include "ScavTrap.hpp"

int main ( void )
{

	ScavTrap a;
	ClapTrap b("masum");
	ScavTrap c("dede");

	a = c;
	a.attack("anan");
	a.guardGate();

	return (0);
}
