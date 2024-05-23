
#include "funcs.hpp"


int	main(void)
{
	Base *p;
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
	delete p;
	}
	Base *m = new D;
	identify(m);
	identify(*m);

	return (0);
}