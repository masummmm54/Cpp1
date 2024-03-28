
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("some weapon");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("another weapon");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		club.setType("ansdjasdj");
		jim.attack();
	}
	return 0;
}
