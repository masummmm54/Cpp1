#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <list>

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
	unsigned int		getN() const;
	std::vector<int>	getVect() const;

	template <typename T>
	void	addContainer(typename T::iterator it_begin, typename T::iterator it_end, size_t size)
	{
		if (size + nums.size() > _n)
			throw std::invalid_argument("Size limit reached cannot add!");
		nums.insert(nums.end(), it_begin, it_end);
	}
};

#endif