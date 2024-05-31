
#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <climits>
#include <ctime>

class PmergeMe
{
private:
	PmergeMe(const PmergeMe& p);
	PmergeMe& operator=(const PmergeMe& other);
public:
	PmergeMe();
	~PmergeMe();

	template <typename T>
	void merge_cont(T &left, T &right, T &vect)
	{
		size_t leftsize = vect.size() / 2;
		size_t rightsize = vect.size() - leftsize;
		size_t i = 0, l = 0, r = 0;

		while (l < leftsize && r < rightsize)
		{
			if (left[l] < right[r])
				vect[i++] = left[l++];
			else
				vect[i++] = right[r++];
		}
		while (l < leftsize)
			vect[i++] = left[l++];
		while (r < rightsize)
			vect[i++] = right[r++];
	}

	template <typename T>
	void sortCont(T &vect)
	{
		size_t size = vect.size();
		if (size <= 1) return ;
		size_t middle = size / 2;
		T left(middle);
		T right(size - middle);

		size_t i = 0, j = 0;
		for (; i < size; i++)
		{
			if (i < middle)
				left[i] = vect[i];
			else
			{
				right[j] = vect[i];
				j++;
			}
		}
		sortCont(left);
		sortCont(right);
		merge_cont(left, right, vect);
	}
};

std::vector<int>	argument_check(int ac, char **av);
void				num_check(std::string str);
unsigned long long	getCurrentTime();

template <typename T>
void	printContainer(T t)
{
	typename T::iterator it;
	for (it = t.begin(); it != t.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != t.end())
			std::cout << " ";
	}
}

#endif