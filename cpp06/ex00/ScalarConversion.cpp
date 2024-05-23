
#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion() {}

ScalarConversion::~ScalarConversion() {}

ScalarConversion::ScalarConversion(const ScalarConversion& p) {*this = p;}

ScalarConversion& ScalarConversion::operator=(const ScalarConversion& other) {(void)other; return (*this);}

void printer(std::string str) {std::cout << str;}

void	char_convert(double result)
{
	printer("char     : ");
	if (result >=  32 && result <= 126)
		std::cout << '\'' << static_cast<char>(result) << '\'' << '\n';
	else if ((result >= 0 && result < 32) || result == 127)
		printer("Non displayable\n");
	else
		printer("impossible\n");
}

void	int_convert(double result)
{
	printer("int      : ");
	if (result < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < result || std::isnan(result))
		printer("impossible\n");
	else
		std::cout << static_cast<int>(result) << '\n';
}

void	float_convert(double result)
{
	printer("float    : ");
	if (std::isnan(result) || std::isinf(result))
		std::cout << std::setprecision(1) << static_cast<float>(result) << 'f' << '\n';
	else if (result < std::numeric_limits<float>::lowest() || result > std::numeric_limits<float>::max())
		printer("impossible\n");
	else
		std::cout << std::setprecision(1) << static_cast<float>(result) << 'f' << '\n';
}

void	double_convert(double result)
{
	printer("double   : ");
	std::cout << std::setprecision(1) << static_cast<double>(result) << '\n';
}

std::string str_trim(std::string str)
{
	std::size_t	start = 0;
	std::size_t end = str.size();

	while (start < end && std::isspace(str[start]))
		start++;
	while (end > start && std::isspace(str[end]))
		end--;
	if (str[start] == '-' || str[start] == '+')
		start++;
	str = str.substr(start, end - start);
	end = str.size();
	if (str[end - 1] == 'f' && str != "inf")
		end--;
	return (str.substr(0, end));
}

void	check_string(std::string str)
{
	int	alpha = 0;
	int	dot = 0;

	if (str.length() == 1)
		return ;
	else
	{
		str = str_trim(str);
		if (str.empty())
			throw std::invalid_argument("Empty input!");
		if (str == "nan" || str == "inf")
			return ;
		for (std::size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '.')
				dot++;
			else if (!std::isdigit(str[i]))
				alpha++;
			if (dot > 1 || alpha > 0)
				throw std::invalid_argument("Invalid string!");
		}
	}
}

void	ScalarConversion::convert(std::string str)
{
	double result;

	check_string(str);
	if (str[1] == '\0' && !isdigit(str[0]))
		result = str[0];
	else
		result = atof(str.c_str());
	std::cout << std::fixed;
	char_convert(result);
	int_convert(result);
	float_convert(result);
	double_convert(result);
}
