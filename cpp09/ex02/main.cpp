
#include "PmergeMe.hpp"


int	main(int ac, char **av)
{
	PmergeMe sort;
	double time_vec = 0;
	double time_deq = 0;
	std::vector<int> vect;
	std::deque<int> deq;
	std::clock_t start_time;
	try
	{
		if (ac <= 1)
			throw std::invalid_argument("Error: wrong argument size!");
		vect = argument_check(ac, av);
		std::copy(vect.begin(), vect.end(), std::back_inserter(deq));
		std::cout << "Before: ";
		printContainer(vect);
		std::cout << '\n';
		start_time = std::clock();
		sort.sortCont(vect);
		time_vec = std::clock() - start_time;
		start_time = std::clock();
		sort.sortCont(deq);
		time_deq = std::clock() - start_time;
		std::cout << "After:  ";
		printContainer(vect);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << "Time to process a range of " << vect.size() << " with std::vector : " << time_vec << " μs" << '\n';
	std::cout << "Time to process a range of " << deq.size() << " with std::deque  : " << time_deq << " μs" << '\n';
	return (0);
}

// Time to process a range of 3000 elements with std::[..] : 62.14389 us