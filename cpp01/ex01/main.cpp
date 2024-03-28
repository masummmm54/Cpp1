#include "Zombie.hpp"

int	main(void)
{
	int N = 13;

	Zombie *ziombe1 = zombieHorde(N, "zombie11");

	for (int i = 0; i < N; i++)
	{
		ziombe1[i].announce();
	}
	delete[] ziombe1;
	return (0);
}
