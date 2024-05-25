
#include "Span.hpp"

Span::Span() : _n(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& p) : _n(getN())
{
	std::copy(p.getVect().begin, p.getVect().end, nums.begin());
}

Span& Span::operator=(const Span& other)
{
	if (this != *other)
	{
		_n = (other.getN());
		std::copy(other.getVect().begin, other.getVect().end, nums.begin());
	}
}

void	Span::addNumber(int n)
{
	if (nums.size() < _n)
		nums.push_back(n);
	else
		throw std::invalid_argument("Size limit reached cannot add!");
}

unsigned int Span::shortestSpan()
{

}

unsigned int Span::longestSpan()
{

}

unsigned int Span::getN()
{
	return (_n);
}

std::vector<int>	Span::getVect()
{
	return (nums);
}