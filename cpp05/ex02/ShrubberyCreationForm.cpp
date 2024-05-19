
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& p) : AForm("ShrubberyCreationForm", 145, 137), _target(p.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->_target = other.getTarget();
	return (*this);
}

void	ShrubberyCreationForm::run_execute() const
{
	const std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile)
	{
		std::cerr << "Error opening file for writing: " << filename << std::endl;
		exit (1);
	}
	outfile << TREE1 << "\n\n";
	outfile << TREE2 << "\n\n";
	outfile.close();
}

std::string ShrubberyCreationForm::getTarget() const {return (_target);}

void ShrubberyCreationForm::print(std::ostream& out) const
{
	if (isSigned())
		out << getName() << " is signed! ";
	else
		out << getName() << " is not signed! ";
	out << " sign grade is " << getGrade() << ", execute grade is " << getExecute();
	out << ", target is " << getTarget();
}