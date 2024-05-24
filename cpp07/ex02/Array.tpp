#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : a(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : a(new T[n]), _size(n) {}


template <typename T>
Array<T>::~Array()
{
	if (a != NULL)
		delete[] this->a;
	this->a = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(const Array<T>& p) : a(new T[p.size()]), _size(p.size())
{
	for (size_t i = 0; i < p.size(); i++)
	{
		a[i] = p.a[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		if (a != NULL)
			delete []a;
		this->a = new T[other.size()];
		this->_size = other.size();
		for (size_t i = 0; i < other.size(); i++)
		{
			a[i] = other.a[i];
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](int i)
{
	if (i < 0 || i >= static_cast<int>(_size))
		throw Array<T>::OutOfBoundsException();
	return (a[i]);
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw() { return ("Index out of bounds"); }

template <typename T>
size_t	Array<T>::size() const
{
	return (this->_size);
}

#endif