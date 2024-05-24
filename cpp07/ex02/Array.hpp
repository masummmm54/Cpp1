#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <exception>
#include <cstddef>


template <typename T>
class Array
{
private:
	T		*a;
	size_t	_size;
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array& p);
	Array& operator=(const Array& other);
	T& operator[](int i);
	size_t	size() const;

	class	OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

# include "Array.tpp"

#endif