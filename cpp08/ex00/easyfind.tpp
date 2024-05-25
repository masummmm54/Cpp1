#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& t, int i)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), i);
	if (t.end() != it)
		std::cout << "Element found in container: " << *it << std::endl;
	else
		throw std::invalid_argument("Element not found in container!");
	return (it);
}


#endif