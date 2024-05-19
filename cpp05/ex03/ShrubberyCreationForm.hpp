#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>
#include <cstdlib>

#define TREE1 "        ccee88oo\n" \
              "   C8O8O8Q8PoOb o8oo\n" \
              "  dOB69QO8PdUOpugoO9bD\n" \
              "CgggbU8OU qOp qOdoUOdcb\n" \
              "    6OuU  /p u gcoUodpP\n" \
              "      \\\\\\//  /douUP\n" \
              "        \\\\\\////\n" \
              "          |||/\\\n" \
              "          |||\\/\n" \
              "          |||||\n" \
              "    .....//||||\\.... "


#define TREE2 "       *\n" \
              "      / \\\n" \
              "     / * \\\n" \
              "    / * * \\\n" \
              "   / * * * \\\n" \
              "  / * * * * \\\n" \
              " / * * * * * \\\n" \
              "/ * * * * * * \\\n" \
              "      |||\n" \
              "      |||\n"


class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& p);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	void		print(std::ostream& out) const;
	std::string	getTarget() const;
	void		run_execute() const;
};





#endif