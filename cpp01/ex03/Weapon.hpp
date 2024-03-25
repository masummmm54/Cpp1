
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
	std::string	type;

	public:
	Weapon		();
	Weapon		(std::string tpye);
	~Weapon		();
	void		setType(std::string type);
	std::string	getType();
};

#endif
