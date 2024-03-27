
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


std::string Replace::manupulate(std::string str)
{
	size_t	pos = 0;

	while (1)
	{
		pos = str.find(finde, pos);
		if (pos == std::string::npos)
			break ;
		str.erase(pos, finde.length());
		str.insert(pos, rep);
	}
	return (str);
}

int	Replace::replace()
{
	std::string str;
	std::ifstream fs;
	std::ofstream out;

	fs.open(infile);
	if (!fs.is_open())
	{
		std::cerr << "Error: Unable to open file: " << infile << std::endl;
		return (1);
	}
	out.open(outfile);
	if (!out.is_open())
	{
		std::cerr << "Error: Unable to open file: " << outfile << std::endl;
		return (1);
	}
	std::getline(fs, str, '\0');
	if (!finde.empty())
		str = manupulate(str);
	out << str;
	return (0);
}
