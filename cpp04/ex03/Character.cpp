
#include "Character.hpp"

Character::Character() : ICharacter(), _name("null"), size(0)
{
	for (int i = 0; i < 4; i++)
		invent[i] = NULL;
}


Character::Character(std::string name) : ICharacter(), _name(name), size(0)
{
	for (int i = 0; i < 4; i++)
		invent[i] = NULL;
}


Character::~Character()
{
	for (int i = 0; i < size; i++)
	{
		delete invent[i];
	}
}

Character::Character(const Character& p)
{
	*this = p;
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		size = other.size;
		for (int i = 0; i < 4; i++)
		{
			delete invent[i];
			invent[i] = other.invent[i]->clone();
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
		std::cout << "No more space left in the inventory for " << _name << std::endl;
	else
		invent[size++] = m;
}

void Character::unequip(int idx)
{
	if (idx >= size || idx < 0)
		std::cout << "No materia on this inventory space for " << _name << std::endl;
	else if (idx < size && idx >= 0)
	{
		delete invent[idx];
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
