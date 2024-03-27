
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i)
{
	this->fixed_point = i << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const i)
{
	fixed_point = std::roundf(i * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& p)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(p.getRawBits());
	*this = p;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_point = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

int Fixed::getRawBits() const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

int Fixed::toInt( void ) const
{
	return this->fixed_point >> fractionalBits;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float> (this->getRawBits()) / (1 << fractionalBits));
}
