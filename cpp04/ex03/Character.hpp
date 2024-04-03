
#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria	*invent[4];
	AMateria	*garbage[256];
	int			size;
	int			garbage_num;

public:
	Character();
	~Character();
	Character(std::string name);
	Character(const Character& p);
	Character& operator=(const Character &other);

	std::string const& getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};







#endif
