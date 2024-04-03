
#include "DiamondTrap.hpp"

void ClapTrap::PrintStatus( void )
{
    std::cout << std::endl;
    std::cout << "-----Health status------" << std::endl;
    std::cout << _health << ": Hit points = " << _health << " Energy points = "
        << _energy << " Attack damage = " << _damage << std::endl;
    std::cout << "------------------------"  << std::endl;
    std::cout << std::endl;
}
int main( void )
{
    DiamondTrap FirstPerson("Dave");
    FirstPerson.whoAmI();
    FirstPerson.PrintStatus();
    DiamondTrap SecondPerson("Jimmy");
    SecondPerson = FirstPerson;
    SecondPerson.PrintStatus();
    FirstPerson.attack("Johnno");
    DiamondTrap ThirdPerson = FirstPerson;
    ThirdPerson.PrintStatus();
    ThirdPerson.takeDamage(20);
}
