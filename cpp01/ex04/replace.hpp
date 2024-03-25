#ifndef REPLACE_HPP
#define REPLACE_HPP


#include <fstream> 
#include <iostream>
#include <string>
#include <cctype>


class Replace
{
	private:
	std::string infile;
	std::string outfile;
	std::string finde;
	std::string rep;

	public:
	Replace(char **av);
	~Replace();

	void	get_lines();
	void	replace_str(std::string str);
};


#endif
