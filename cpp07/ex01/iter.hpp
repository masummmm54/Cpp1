#ifndef ITER_HPP
#define ITER_HPP


#include <iostream>

template <typename A, typename F>
void	iter(A *array, std::size_t len, F f)
{
	for(size_t i = 0; i < len ; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	square(T n)
{
	std::cout << n * n << '\n';
}


template <typename T>
void	printer(T n)
{
	std::cout << n << '\n';
}



#endif