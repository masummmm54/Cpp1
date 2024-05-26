
#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& p)
{
	*this = p;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
	{
		this->c = other.c;
	}
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}



#endif