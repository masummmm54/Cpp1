
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point = 0;
}

Fixed::Fixed(int const i)
{
	this->fixed_point = i << fractionalBits;
}

Fixed::Fixed(float const i)
{
	fixed_point = roundf(i * (1 << fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& p)
{
	this->setRawBits(p.getRawBits());
	*this = p;
}

Fixed& Fixed::operator=(const Fixed &other)
{
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

//comparison 
bool Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

//arithmetics
Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

// increment/decrement 

Fixed& Fixed::operator++( void )
{
	this->fixed_point += 1;
	return (*this);
}

Fixed& Fixed::operator--( void )
{
	this->fixed_point -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed t;

	t = *this;
	this->fixed_point += 1;
	return (t);
}

Fixed Fixed::operator--(int)
{
	Fixed t;

	t = *this;
	this->fixed_point -= 1;
	return (t);
}

// overloaded member functions

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}
