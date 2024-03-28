
#include "replace.hpp"

Replace::Replace() {}

Replace::Replace (std::string infile, std::string finde, std::string rep)
{
	this->infile = infile;
	this->outfile = infile + ".replace";
	this->to_find = finde;
	this->rep = rep;
}

Replace::~Replace () {}


std::string Replace::manupulate(std::string str)
{
	size_t	pos = 0;

	while (1)
	{
		pos = str.find(to_find, pos);
		if (pos == std::string::npos)
			break ;
		str.erase(pos, to_find.length());
		str.insert(pos, rep);
	}
	return (str);
}

int	Replace::replace()
{
	std::string str;
	std::ifstream fs;
	std::ofstream out;

	fs.open(infile.c_str());
	if (!fs.is_open())
	{
		std::cerr << "Error: Unable to open file: " << infile << std::endl;
		return (1);
	}
	out.open(outfile.c_str());
	if (!out.is_open())
	{
		std::cerr << "Error: Unable to open file: " << outfile << std::endl;
		return (1);
	}
	std::getline(fs, str, '\0');
	if (!to_find.empty())
		str = manupulate(str);
	out << str;
	return (0);
}
