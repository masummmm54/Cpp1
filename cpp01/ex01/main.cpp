#include "Zombie.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int N = 13;

	Zombie *ziombe1 = zombieHorde(N, "zombie1");

	for (int i = 0; i < N; i++)
	{
		ziombe1[i].announce();
	}
	delete[] ziombe1;
	return (0);
}
