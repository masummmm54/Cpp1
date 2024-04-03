
#include "Character.hpp"

Character::Character() : ICharacter(), _name("null"), size(0), garbage_num(0)
{
	for (int i = 0; i < 4; i++)
		invent[i] = NULL;
	for (int i = 0; i < 256; i++)
		garbage[i] = NULL;
}


Character::Character(std::string name) : ICharacter(), _name(name), size(0), garbage_num(0)
{
	for (int i = 0; i < 4; i++)
		invent[i] = NULL;
	for (int i = 0; i < 256; i++)
		garbage[i] = NULL;
}


Character::~Character()
{
	for (int i = 0; i < size; i++)
	{
		delete invent[i];
	}
	for (int i = 0; i < garbage_num; i++)
	{
		delete garbage[i];
	}
}

Character::Character(const Character& other)
{
	_name = other._name;
	size = other.size;
	garbage_num = other.garbage_num;
	for (int i = 0; i < 4; i++)
	{
		if (other.invent[i])
			invent[i] = other.invent[i]->clone();
		else
			invent[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.garbage[i])
			garbage[i] = other.garbage[i]->clone();
		else
			garbage[i] = NULL;
	}
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		size = other.size;
		garbage_num = other.garbage_num;
		for (int i = 0; i < 4; i++)
		{
			if (invent[i])
				delete invent[i];
			if (other.invent[i])
				invent[i] = other.invent[i]->clone();
			else
				invent[i] = NULL;
		}
		for (int i = 0; i < 256; i++)
		{
			if (garbage[i])
				delete garbage[i];
			if (other.garbage[i])
				garbage[i] = other.garbage[i]->clone();
			else
				garbage[i] = NULL;
		}
	}
	return *this;
}

std::string const& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (size == 4)
	{
		delete m;
		std::cout << "Can't equip no more space left in the inventory for " << _name << std::endl;
	}
	else
		invent[size++] = m;
}

void Character::unequip(int idx)
{
	if (idx >= size || idx < 0)
		std::cout << "No materia on this inventory space for " << _name << std::endl;
	else if (idx < size && idx >= 0)
	{
		garbage[garbage_num++] = invent[idx];
		invent[idx] = NULL;
		for (; idx < size - 1; idx++)
		{
			invent[idx] = invent[idx + 1];
		}
		size--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < size && idx>= 0 && invent[idx])
		invent[idx]->use(target);
	else
		std::cout << "No materia on this inventory space for " << _name << std::endl;
}
