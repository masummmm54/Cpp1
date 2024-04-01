
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
private:
	
public:
	Ice();
	~Ice();

	std::string const & getType() const;

	AMateria* clone() const;
	void use(ICharacter& target);
};






#endif
