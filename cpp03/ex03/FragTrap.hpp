#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap& p);
	FragTrap& operator=(const FragTrap &other);

	void	attack(const std::string& target);
	void	highFivesGuys(void);
	void	printmsg(std::string msg);
};




#endif
