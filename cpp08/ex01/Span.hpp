#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
private:
	std::vector<int>	nums;
	size_t				_n;
public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span& p);
	Span& operator=(const Span& other);

	void				addNumber(int n);
	unsigned int		shortestSpan();
	unsigned int		longestSpan();
	unsigned int		getN();
	std::vector<int>	getVect();
};

#endif