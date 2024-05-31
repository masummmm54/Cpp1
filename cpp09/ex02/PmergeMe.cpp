
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) {(*this = p);}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

unsigned long long getCurrentTime()
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return (currentTime.tv_sec * 1000000) + currentTime.tv_usec;
}

void num_check(std::string str)
{
	std::string::iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it++;
	for (; it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
			throw std::invalid_argument("Error: non number argument: " + str);
	}
}

std::vector<int> argument_check(int ac, char **av)
{
	std::vector<int> vect;
	std::vector<std::string> check;
	double num;
	for (int i = 1; i != ac; i++)
	{
		num = atof(av[i]);
		if (num < 0)
			throw std::invalid_argument("Error: negative number.");
		if (num > INT_MAX || num < INT_MIN)
			throw std::invalid_argument("Error: overflow.");
		check.push_back(av[i]);
		vect.push_back(static_cast<int>(num));
	}
	std::vector<std::string>::iterator it;
	for (it = check.begin(); it != check.end(); it++)
		num_check(*it);
	return (vect);
}
