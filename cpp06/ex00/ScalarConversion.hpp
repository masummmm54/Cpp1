
#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cerrno>
#include <cstring>

class ScalarConversion
{
private:
	ScalarConversion();
	~ScalarConversion();
	ScalarConversion(const ScalarConversion& p);
	ScalarConversion& operator=(const ScalarConversion& other);
public:
	static void	convert(std::string str);
};








#endif