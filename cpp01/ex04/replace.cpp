
#include "replace.hpp"

Replace::Replace() {}

Replace::Replace (std::string infile, std::string finde, std::string rep)
{
	this->infile = infile;
	this->outfile = infile + ".replace";
	this->finde = finde;
	this->rep = rep;
}

Replace::~Replace () {}

void	Replace::replace_str(std::string str)
{
	size_t	pos = 0;
	size_t	len = finde.length();
	size_t	i = 0;

	while (str[i] != '\0')
	{
		pos = str.find(finde, i);
		if (pos == i && (pos == 0 || std::isspace(str[pos - 1])) && (std::isspace(str[pos + len]) || str[pos + len] == '\0'))
		{
			std::cout << rep;
			i += len;
		}
		if (str[i] != '\0')
			std::cout << str[i++];
	}
}

void	Replace::get_lines()
{

	std::string str;
	std::fstream fs;
	std::ofstream outputFile(outfile.c_str());

	fs.open(infile.c_str());
	if (outputFile.is_open())
	{
		std::cout.rdbuf(outputFile.rdbuf());
		while (1)
		{
			if (!std::getline(fs, str))
			{
				if (fs.eof())
					break ;
			}
			replace_str(str);
			std::cout << std::endl;
		}
	}
}
