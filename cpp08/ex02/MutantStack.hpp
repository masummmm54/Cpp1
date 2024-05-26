
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>



template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& p);
	MutantStack& operator=(const MutantStack& other);

	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif
