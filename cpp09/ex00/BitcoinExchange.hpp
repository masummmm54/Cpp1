
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string.h>
#include <algorithm>
#include <iomanip>

class BitcoinExchange
{
private:
	std::string _argv;
	std::map<double, float> rates;

	void	fill_rates();
	void	msg_print(std::string line, float value);
	int		check_value(float value, std::string rate, int flag);
	int		check_line(std::string line, int flag);
	int		check_headers(std::string line, int flag);
	void	get_dates();

public:
	BitcoinExchange();
	BitcoinExchange(std::string argv);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& p);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	std::string				getArgv() const;
	std::map<double, float>	getRates() const;
	void					exchange();
};

double		find_date_v(std::string date);
int			check_date(int y, int m, int d);
void		error_msg(std::string msg);
std::string	trimWhitespaces(std::string &str);

#endif