
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <climits>

class RPN
{
private:
	RPN(const RPN& p);
	RPN& operator=(const RPN& other);
public:
	RPN();
	~RPN();
	void	calculate(std::string str);
};




#endif