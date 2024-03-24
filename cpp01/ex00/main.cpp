#include "Zombie.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	Zombie *ziombe1 = newZombie("zombie11");
	ziombe1->announce();
	randomChump("zombie22");


	delete ziombe1;
	return (0);
}
