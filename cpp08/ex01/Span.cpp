
#include "Span.hpp"

Span::Span() : _n(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& p) : _n(getN())
{
	nums = p.getVect();
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = (other.getN());
		nums = other.getVect();
	}
	return (*this);
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
	if (nums.size() < 2)
		throw std::invalid_argument("Not enough elements inside span!");
	std::vector<int> sorted = nums;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>:: iterator it;
	int mindiff = *(std::max_element(nums.begin(), nums.end()));
	for (it = sorted.begin() + 1; it != sorted.end(); it++)
	{
		int dif = *it - *(it - 1);
		if (dif < mindiff)
			mindiff = dif;
	}
	return (mindiff);
}

unsigned int Span::longestSpan()
{
	if (nums.size() < 2)
		throw std::invalid_argument("Not enough elements inside span!");
	std::vector<int>::iterator it_max = std::max_element(nums.begin(), nums.end());
	std::vector<int>::iterator it_min = std::min_element(nums.begin(), nums.end());
	return (*it_max - *it_min);
}

unsigned int Span::getN() const
{
	return (_n);
}

std::vector<int>	Span::getVect() const
{
	return (nums);
}