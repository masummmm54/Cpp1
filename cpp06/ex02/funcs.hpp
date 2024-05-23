#ifndef FUNCS_HPP
#define FUNCS_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

# include <iostream>
# include <cstdlib>
# include <ctime>

void	printer(std::string str);
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif