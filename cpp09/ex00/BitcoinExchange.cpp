
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _argv(NULL) {}

BitcoinExchange::BitcoinExchange(std::string argv) : _argv(argv) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& p) : _argv(p.getArgv()), rates(p.getRates()) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_argv = other.getArgv();
		rates = other.getRates();
	}
	return (*this);
}

std::string BitcoinExchange::getArgv() const {return (_argv);}

std::map<double, float> BitcoinExchange::getRates() const {return (rates);}

void	BitcoinExchange::fill_rates()
{
	double	date_v;
	float	value;
	std::string line;
	std::string date;
	std::string rate;
	std::ifstream file_1("data.csv");
	if (!file_1.is_open())
		throw std::invalid_argument("Error: could not open file: 'data.csv'");
	std::getline(file_1, line);
	if (!check_headers(line, 2))
		throw std::invalid_argument("Error: wrong header: 'data.csv'");
	while (std::getline(file_1, line))
	{
		if (line.find(',') == std::string::npos)
		{
			error_msg("bad input => " + line + ". data.csv.");
			continue;
		}
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, rate);
		date = trimWhitespaces(date);
		rate = trimWhitespaces(rate);
		value = atof(rate.c_str());
		if (!check_line(date, 0))
			continue;
		if (!check_value(value, rate, 0))
			continue;
		date_v = find_date_v(date);
		rates[date_v] = atof(rate.c_str());
	}
	file_1.close();
}

int BitcoinExchange::check_headers(std::string line, int flag)
{
	std::stringstream ss(line);
	std::string date;
	std::string rate;
	if (flag == 1)
	{
		std::getline(ss, date, '|');
		date = trimWhitespaces(date);
		std::getline(ss, rate);
		rate = trimWhitespaces(rate);
		if (date != "date" || rate != "value")
			return (false);
	}
	if (flag == 2)
	{
		std::getline(ss, date, ',');
		date = trimWhitespaces(date);
		std::getline(ss, rate);
		rate = trimWhitespaces(rate);
		if (date != "date" || rate != "exchange_rate")
			return (false);
	}
	return (true);
}

int BitcoinExchange::check_line(std::string date, int flag)
{
	std::string			line;
	std::stringstream	ss(date);
	std::string msg = flag ? "" : "data.csv : ";
	getline(ss, line, '-');
	int y = atol(line.c_str());
	if (!check_value(0, line, 0))
		return (false);
	getline(ss, line, '-');
	if (!check_value(0, line, 0))
		return (false);
	int m = atol(line.c_str());
	getline(ss, line);
	if (!check_value(0, line, 0))
		return (false);
	int d = atol(line.c_str());
	if (!check_date(y, m, d))
		return (error_msg("bad input => " + msg + date), false);
	return (true);
}

int BitcoinExchange::check_value(float value, std::string rate, int flag)
{
	std::string msg = flag ? "" : "data.csv";
	if (value < 0 && flag == 1)
		return (error_msg("not a positive number."), false);
	if (value > 1000 && flag == 1)
		return (error_msg("too large a number."), false);
	int dot = 0;
	for (size_t i = 0; i < rate.size(); i++)
	{
		if (rate[i] == '.')
			dot++;
		if ((!std::isdigit(rate[i]) && rate[i] != '.') || dot > 1)
			return (error_msg(rate + " not a number: " + msg), false);
	}
	return (true);
}

void	BitcoinExchange::get_dates()
{
	std::ifstream file_1(_argv.c_str());
	if (!file_1.is_open())
		throw std::invalid_argument("Error: could not open file.");
	std::string line;
	std::string date;
	std::string rate;
	float value;
	std::getline(file_1, line);
	if (!check_headers(line, 1))
		throw std::invalid_argument("Error: wrong header.");
	while (getline(file_1, line))
	{
		if (line.find('|') == std::string::npos)
		{
			error_msg("bad input => " + line);
			continue;
		}
		std::stringstream ss(line);
		getline(ss, date, '|');
		getline(ss, rate);
		date = trimWhitespaces(date);
		rate = trimWhitespaces(rate);
		value = atof(rate.c_str());
		if (!check_line(date, 1))
			continue;
		if (!check_value(value, rate, 1))
			continue;
		msg_print(date, value);
	}
	file_1.close();
}

void	BitcoinExchange::msg_print(std::string line, float value)
{
	double date = find_date_v(line);
	std::map<double, float>::iterator it = rates.begin();
	while (1)
	{
		if (rates.find(date) != rates.end())
			break;
		if (date < (it->first))
		{
			date = (it->first);
			break;
		}
		date--;
	}
	std::cout << line << " => " << value << " = " << value * rates[date] << std::endl;
}

void BitcoinExchange::exchange()
{
	fill_rates();
	if (rates.size() < 1)
		throw std::invalid_argument("Error: No value.");
	get_dates();
}

double	find_date_v(std::string date)
{
	double				value;
	std::string			line;
	std::stringstream	ss(date);

	getline(ss, line, '-');
	value = atol(line.c_str()) * 365;
	getline(ss, line, '-');
	value += atol(line.c_str()) * 30;
	getline(ss, line);
	value += atol(line.c_str());
	return (value);
}

std::string trimWhitespaces(std::string &str)
{
	size_t start = str.find_first_not_of(" \t\n\r");
	size_t end = str.find_last_not_of(" \t\n\r");

	if (start == std::string::npos || end == std::string::npos)
		return ("");
	return (str.substr(start, end - start + 1));
}

int check_date(int y, int m, int d)
{
	if (y < 1000 || y > 3000 || m < 0 || m > 12 || d < 0 || d > 31)
		return (false);
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) 
		return (false);
	if (m == 2)
	{
		bool leapYear = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
		if (d > (leapYear ? 29 : 28))
			return false;
	}
	return (true);
}

void	error_msg(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
}