
#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& p) {(*this = p);}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

float convertNum(char c)
{
	float value = c;
	return (value - '0');
}

float operation(float a, float b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '*')
		return (b * a);
	else if (op == '-')
		return (b - a);
	else if (op == '/' && a != 0)
		return (b / a);
	else if (op == '/' && a == 0)
		throw std::invalid_argument("Error: division by zero not possible!");
	else
		return (INT_MIN);
}

int isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

int	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	else
		return (false);
}

void	RPN::calculate(std::string str)
{
	std::string::iterator it;
	std::stack<float> _stack;
	float a,b;
	for (it = str.begin(); it != str.end(); it++)
	{
		if (isOperator(*it) == true)
		{
			if (_stack.size() < 2)
				throw std::invalid_argument("Error: too many operators!");
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(operation(a, b, *it));
		}
		else if (isNumber(*it) == true)
			_stack.push(convertNum(*it));
		else if (std::isspace(*it))
			continue;
		else
			throw std::invalid_argument("Error: invalid argument!");
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::invalid_argument("Error: too many operands!");
}

